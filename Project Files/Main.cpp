// Main
#include <iostream>
#include <fstream>
#include <string>
#include "BTNode.h"
#include "morse.txt"
using namespace std;

BTNode* root;
fstream fin;
void createTree();
int main()
{
    
    fin.open("morse.txt");
    if (!fin.fail()){
        while(fin.good()){
            createTree();
    }
    
	return 0;
    }
}

void createTree(){
    string str;
    char letter;
    string morse;
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
            cout << "bad input" << endl;
        }
    }
    cursor->letter = letter;
    cursor->morse = morse;
    
    
}
