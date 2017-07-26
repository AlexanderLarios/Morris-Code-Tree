// Main
#include <iostream>
#include <fstream>
#include <string>
#include "BTNode.h"
#include "Binary_Tree.h"
#include "morse.txt"
using namespace std;

int main()
{
    Binary_Tree<char> morseTree;
    fstream fin;
    fin.open("morse.txt");
    if (!fin.fail()){
        while(fin.good()){
            string str;
            char letter;
            string morse;
            BTNode* root = morseTree.getRoot();
            BTNode* cursor = root;
            getline(fin,str);
            letter = str[0];
            morse = str.substr(1,str.length());
            for(int i=1; i<str.length(); i++){
                if(str[i] == '_'){
                    if(cursor->right == NULL){
                        cursor->right =  new BTNode() ;
                    }
                }
            }
        }
    }
	return 0;
}
