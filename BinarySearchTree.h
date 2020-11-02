#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "node.h"
#include "bintree.h"


/* 	Weizheng Jiang
	z1861817
	csci340 section2
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/



template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    void Insert(const T &x);       // inserts node with value x
    bool Search(const T &x) const; // searches leaf with value x
    bool Remove(const T &x);       // removes leaf with value x
private:
    void _Insert(Node<T> *&, const T &);      // private version of insert
    bool _Search(Node<T> *, const T &) const; // private version of search
    void _Remove(Node<T> *&, const T &);      // private version of remove
    bool _Leaf(Node<T> *) const;          // checks if node is leaf
};

template <class T>
void BinarySearchTree<T> :: Insert(const T &x)
{
	//simply call the private version of insert and pass the root and value x
	_Insert(this -> root,x);
}

template <class T>
bool BinarySearchTree<T> :: Search(const T &x) const
{
	//call the _Search function and pass the root and value x, if the value x is found and it is a leaf, then return true
	return _Search(this -> root, x);
}

template <class T>
bool BinarySearchTree<T> :: Remove(const T &x)
{
	if(Search(x) == true)
	{
		//if the leaf is found, then call the _Remove function to remove the leaf
		//and return true; otherwise, return false
		_Remove(this->root,x);
		return true;
	}
	else
		return false;
}

template <class T>
void BinarySearchTree<T> :: _Insert(Node<T> *&ptr, const T &x) 
{
	//if the node is not null. If the value x is smaller than the current node, then
	//move to the left. If the value is bigger than the current node, then move to the right
	if(ptr != NULL)
	{
		if(x < ptr -> data)
			_Insert(ptr -> left,x);
		else if(x > ptr -> data)
			_Insert(ptr -> right,x);
	}
	else
	{
		//assign a new node with NULL
		ptr = new Node<T>(x);
		ptr -> left = ptr -> right = nullptr;
	}
}

template <class T>
bool BinarySearchTree<T> :: _Search(Node<T> *ptr, const T &x) const
{
	//if current is NULL,return false;
	if( ptr == NULL)
		return false;
	//if the value x = current node, and it is a leaf. Then return true;
	else if( (ptr -> data == x) && _Leaf(ptr) == true)
		return true;
	//if the value x is bigger than current node, then move to the left
	else if(ptr -> data > x)
		return _Search(ptr -> left, x);
	//if the value x is smaller than current node, then move to the right
	else if(ptr -> data < x)
		return _Search(ptr -> right, x);
	//if the value x is not found in the BST, then return false;
	else 
		return false;
}

template <class T>
void BinarySearchTree<T> :: _Remove(Node<T> *& ptr, const T &x)
{
	if(ptr != NULL)
	{
		//if the value = current node, delete the node and assign it to NULL
		if(ptr -> data == x)
		{
			delete ptr;
			ptr = NULL;
		}
		//if the value is bigger than current node, move to the left
		else if(ptr -> data > x)
			_Remove(ptr -> left,x);
		//if the value is smaller than current node, move to the right
		else if(ptr -> data < x)
			_Remove(ptr -> right,x);
	}

	else
		return;

}



template <class T>
bool BinarySearchTree<T> :: _Leaf(Node<T> *ptr) const
{
	//if the current node is NULL, return false;
	if(ptr == NULL)
		return false;
	//if the current node has no child, return true
	else if(ptr -> left == NULL && ptr -> right == NULL)
		return true;
	else
		return false;
}



#endif

	


