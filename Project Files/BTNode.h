#ifndef BTNODE_H_
#define BTNODE_H_
#include <sstream>

/** A node for a Binary Tree. */
struct BTNode
{
	// Data Fields
	char letter;
	BTNode* left;
	BTNode* right;
    std::string morse;
	// Constructor
    BTNode(){
        letter = '0';
        left = NULL;
        right = NULL;
        morse ="";
    }


	// Destructor (to avoid warning message)
	~BTNode() {}

};



#endif
