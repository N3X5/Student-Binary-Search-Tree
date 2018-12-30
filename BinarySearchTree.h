#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Student.h"

#include <string>
#include<vector>

class BinarySearchTree 
{
private:
	//Node struct used by the BST; Data is of type Student
	struct Node
	{
		Student student;
		Node* left;
		Node* right;
	};

	Node* root; //Root of the BST

	void deleteTree(Node*); //Function to delete the whole tree by a given root; used by destructor
	Node* findMinNode(Node*); //Function to find the min node of the whole tree by a given root (used by remove func)

	Node* insert(Student, Node*); //Function to insert student record to a BST defined by its root; return is the root of the modified BST
	Node* remove(Student, Node*, bool&); //Function to remove a student record from a BST defined by its root; return is the root of the modified BST
	Node* find(unsigned long long, Node*); //Function to find the node containing a student record in a BST defined by its root; return is the node containing the found record || nullptr if no record is found
	void traverseTreeInOrder(Node*, std::vector<Student>&); //Traverse a BST defined by its root in order and append all of the data to a vector
public:
	BinarySearchTree(); //Constructor to init the root
	~BinarySearchTree(); //Destructor to call deleteTree func

	//Public functions, which call the internal functions commented above
	//These funcs always call the relevant recursive internal functions with the root as their node* arg
	void insert(Student);
	bool remove(Student);
	Student find(unsigned long long);
	std::vector<Student> traverseTreeInOrder();
};

#endif

