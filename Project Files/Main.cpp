// Main
#include <iostream>
#include <fstream>
#include <sstream>
#include "BTNode.h"
using std::cout;
using std::string;
using std::endl;

BTNode* root = new BTNode();
std::fstream fin;
void addNode();
bool codeSearch(std::string &code, char letter, BTNode * root);
char morseTraversal(std::string s, BTNode *&p);


int main()
{
    //read in morse file
    fin.open("morse.txt");
    if (!fin.fail()){
        while(fin.good()){
            //Read in morse and add to tree
            addNode();
    }
    string toEncode = "test";
    string translation = "";
    for(int i=0; i<toEncode.length(); i++){
        codeSearch(translation, toEncode[i], root);
        }
        std::cout << "Encode: " << toEncode << endl;
        std::cout << translation << endl;
        BTNode*traversal = root;
        std::stringstream ss(translation);
        string letter;
        while (ss >> letter)
        {
            morseTraversal(letter, traversal);
        }
       
        std::cout << "Decode: " <<  translation << endl;
        std::cout << traversal << endl;
        
        
        system("pause");
	return 0;
    }
}
void addNode(){
    std::string str;
    char letter;
    std::string morse;
    BTNode* cursor = root;
    getline(fin,str);
    letter = str[0];
    morse = str.substr(1,str.length());
    for(int i=1; i<str.length(); i++){
        if(str[i] == '_'){
            if(cursor->right == NULL){
                cursor->right =  new BTNode();
                cursor = cursor->right;
            }
        }
        else if(str[i] == '.'){
            if(cursor->left == NULL){
                cursor->left =  new BTNode();
                cursor = cursor->left;
            }
        }
        else{
            std::cout << "bad input" << endl;
        }
    }
    cursor->letter = letter;
    cursor->morse = morse;
    
    
}
bool codeSearch(string &code, char letter, BTNode * root)
{
    if (root->letter == letter)
    {
        code += root->morse + ' ';
        return true;
    }
    else
    {
        bool check = false;
        if (root->left != NULL)
        {
            check = codeSearch(code, letter, root->left);
        }
        if (check == false && root->right != NULL)
        {
            check = codeSearch(code, letter, root->right);
        }
        return check;
    }
}
char morseTraversal(string s, BTNode *&p)
{
    if (s.length() == 0)
        return p->letter;
    else if (s[0] == '.')
    {
        p = p->left;
        return morseTraversal(s.substr(1, 10), p);
    }
    else
    {
        p = p->right;
        return morseTraversal(s.substr(1, 10), p);
    }
}
