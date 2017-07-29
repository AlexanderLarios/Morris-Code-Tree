// Main
#include <iostream>
#include <fstream>
#include <sstream>
#include "BTNode.h"
using std::cout;
using std::string;
using std::endl;

// Declare our first root Node
BTNode* root = new BTNode();

// declare input and functions
std::fstream fin;

void addNode();
// adds the data to a node, navigates their based on Morse code.
// can create new nodes along the way.

bool codeSearch(std::string &code, char character, BTNode * root);
// Traverses the binary tree recursively searching for the character
// to translate into morse. Returns a string of the morse code.

char morseTraversal(std::string s, BTNode *&p);
// uses the morse code to navigate to the letter. returns the letter.


int main()
{
    //read in morse file, use addnode() to create the tree
    fin.open("morse.txt");
    if (!fin.fail())
	{
        while(fin.good())
		{
            //Read in morse and add to tree
            addNode();
    }

	// begin encode. We encode the word test to the new string translation
    string toEncode = "test";
    string translation = "";

	// For loop to call codesearch
    for(int i=0; i<toEncode.length(); i++)
	{
        codeSearch(translation, toEncode[i], root);
    }
	// cout what we started with, and what we ended with.
        std::cout << "Encode: " << toEncode << endl;
        std::cout << translation << endl;

		// reset root
        BTNode*traversal = root;

		// use a string stream to input the translated string and find its translation
        std::istringstream ss(translation);

		// letter will be the morse code line, and its translation will be stored in decoded
        string letter;
		string decoded = "";

		// the string stream grabs the item and inputs it into letter, using a space as a delimiter
        while (std::getline(ss,letter,' '))
        {
			BTNode*traversal = root;
            decoded += morseTraversal(letter, traversal);
        }
       
		// then cout the original, and what we made.
        std::cout << "Decode: " <<  translation << endl;
        std::cout << decoded << endl;
        system("pause");
		// end program
	return 0;
    }
}

// Creates tree
void addNode(){

	// early variables
    std::string str;
    char letter;
    std::string morse;
    BTNode* cursor = root;

	//grab a line from the file
    getline(fin,str);

	// store the letter
    letter = str[0];

	// grab just the morse code
    morse = str.substr(1,str.length());

	// for each character in the morse code, navigate left or right. If no node is there, create it.
    for(int i=1; i<str.length(); i++)
	{
        if(str[i] == '_')
		{
            if(cursor->right == NULL)
			{
                cursor->right =  new BTNode();
            }
			cursor = cursor->right;
        }
        else if(str[i] == '.')
		{
            if(cursor->left == NULL)
			{
                cursor->left =  new BTNode();
            }
			cursor = cursor->left;
        }
        else
		{
            std::cout << "bad input" << endl;
        }
    }
	// the pointer will have arrived at the node. We assign the values.
    cursor->letter = letter;
    cursor->morse = morse;
    
    
}


// recursively searches the binary tree for the node matching the letter it is input with
bool codeSearch(string &code, char character, BTNode * root)
{
	// checks to see if it is on the node
    if (root->letter == character)
    {
		// if so, assigns code, sets to true so that nothing else is checked.
        code = code + root->morse + ' ';
        return true;
    }
    else
    {
		// if not found, set check to false
        bool check = false;
		// look left
        if (root->left != NULL)
        {
            check = codeSearch(code, character, root->left);
        }
		// if the letter wasn't found, look right
        if (check == false && root->right != NULL)
        {
            check = codeSearch(code, character, root->right);
        }
		// return check
        return check;
    }
}

// navigates the binary tree using the morse code as a guide
char morseTraversal(string s, BTNode *&p)
{
	// end condition, if the morse code string is empyt
    if (s.length() == 0)
        return p->letter;
	// otherwise check the first character, and move left or right
	// then reduce the string starting with the next letter
	// call again
    else if (s[0] == '.')
    {
        p = p->left;
        return morseTraversal(s.substr(1, 10), p);
    }
    else if (s[0]== '_')
    {
        p = p->right;
        return morseTraversal(s.substr(1, 10), p);
    }
}
