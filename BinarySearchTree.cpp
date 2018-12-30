#include "BinarySearchTree.h"

#include <iostream>
#include <string>

using namespace std;

//Delete a BST defined by its root
void BinarySearchTree::deleteTree(Node* node)
{
		if (node != nullptr) //If a root isn't NULL
		{
			deleteTree(node->left); //Delete its left subtree
			deleteTree(node->right); //Delete its right subtree

			delete node; //Delete a root
		}
}

//Find the min node of a BST defined by its root
BinarySearchTree::Node* BinarySearchTree::findMinNode(Node* node)
{
	//If the root is NULL => return it
	if (node == nullptr)
		return nullptr;
	else if (node->left == nullptr) //If the smaller left subtree is NULL => root is the smallest node
		return node;
	else //Find the min node of the left subtree
		return findMinNode(node->left);
}

//Insert a node into a BST defined by its root
BinarySearchTree::Node* BinarySearchTree::insert(Student s, Node* node)
{
	if (node == nullptr) //If the root is NULL; create a new root & insert the relevant data into it
	{
		node = new Node;
		node->student = s;
		node->left = nullptr;
		node->right = nullptr;
	}
	else if (s.FN < node->student.FN) //If the given FN is smaller than the current root FN; insert the student into left subtree
		node->left = insert(s, node->left);
	else if (s.FN > node->student.FN) //If the given FN is larger than the current root FN; insert the student into right subtree
		node->right = insert(s, node->right);

	return node; //Return the root (It has now been modified || one of its subtrees have been modified)
}

//Remove a node from a BST defined by its root; a referance to a flag indicates if a node in the chain of recursive call was indeed deleted
BinarySearchTree::Node* BinarySearchTree::remove(Student s, Node* node, bool &successful)
{
	Node* temp;

	if (node == nullptr) //If the root is NULL => nothing to delete
		return nullptr;
	else if (s.FN < node->student.FN) //If the given student FN is less than the one in the root => we will delete in the left subtree
		node->left = remove(s, node->left, successful);
	else if (s.FN > node->student.FN) //If the given student FN is greater that the one in the root => we will delete in the right subtree
		node->right = remove(s, node->right, successful);
	else if (node->left && node->right) //We have to delete the root & there are two subtrees
	{
		temp = findMinNode(node->right); //Find the min node of the right subtree & store it in the temp node
		node->student = temp->student; //Set the new student of the root as the one of the min node in the right subtree
		node->right = remove(node->student, node->right, successful); //Delete the now duplicate node from the right subtree & set its new root
	}
	else //We have found a root to delete which has either one or zero subtrees
	{
		temp = node; //Set the temp node to the current root, which is to be deleted

		if (node->left == nullptr) //If we don't have a left subtree => Set the root to the root of the right subtree
			node = node->right;
		else if (node->right == nullptr) //If we don't have a right subtree => Set the root to the root of the left subtree
			node = node->left;

		delete temp; //Delete the old root

		successful = 1; //Deletion has been performed; remove operation was a success
	}

	return node; //Return the root (It has now been deleted || one of its subtrees has been modified)
}

//Find a node based on a given FN in a BST defined by its root & return it
BinarySearchTree::Node* BinarySearchTree::find(unsigned long long FN, Node* node)
{
	//If the root is NULL => return it
	if (node == nullptr)
		return nullptr;
	else if (FN < node->student.FN) //If the given FN is less that the one of the root => explore the left subtree
		return find(FN, node->left);
	else if (FN > node->student.FN) //If the given FN is greater than the one of the root => explore the right subtree
		return find(FN, node->right);
	else //The root is a match => return it
		return node;
}

//Traverse a BST defined by its root in order; add its node data to a vector
void BinarySearchTree::traverseTreeInOrder(Node* node, vector<Student> &result)
{
	//If the root is NULL => no data to be added to the given vector
	if (node == nullptr)
		return;

	//Traverse the left subtree
	traverseTreeInOrder(node->left, result);
	result.push_back(node->student); //Add the root data to the given vector
	traverseTreeInOrder(node->right, result); //Traverse the right subtree
}

//Init our root as NULL
BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

//Delete the BST
BinarySearchTree::~BinarySearchTree()
{
	deleteTree(root);
}

//Insert a student into the BST and set the current root as the modified BST returned by insert
void BinarySearchTree::insert(Student s)
{
	root = insert(s, root);
}

//Remove a student from the BST and set the current root as the modified BST returned by remove
bool BinarySearchTree::remove(Student s)
{
	bool successful = 0; //Flag to check if we actually remove something

	root = remove(s, root, successful);

	return successful; //Return the flag, so that the user may now if something was actually done
}

//Find a student in the BST and return them by a given FN; A student is always returned (blank student record if no match was found)
Student BinarySearchTree::find(unsigned long long FN)
{
	Node* result = find(FN, root); //Get the node containing the matching student

	if (result == nullptr) //If we don't have a valid node; return a blank student
		return Student();
	else //Return the student of the found node
		return result->student;
}

//Traverse the BST in order & add traversed student records to a vector; return that vector to the user
vector<Student> BinarySearchTree::traverseTreeInOrder()
{
	vector<Student> result;

	traverseTreeInOrder(root, result);

	return result;
}
