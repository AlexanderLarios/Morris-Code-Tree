#ifndef BTNODE_H_
#define BTNODE_H_

// this file was found within the binary tree files on blackboard.
// it was altered by adding an additional data point.

/** A node for a Binary Tree. */
struct BTNode
{
	// Data Fields
	char letter;
	BTNode* left;
	BTNode* right;
	// added this string to assign the actual morse code
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
