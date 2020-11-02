#ifndef H_BINARYTREE
#define H_BINARYTREE

#include "node.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

template <typename T> class BinaryTree{

public:
    BinaryTree();                                      // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    void         Inorder(void (*)(const T&));          // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorder()
};



//call the default constructor, let the root node = 0
template <class T>
BinaryTree <T>::BinaryTree(){root = 0;}

//call the _getsize function to get the tree's size
template <class T>
unsigned BinaryTree <T>::getSize() const
{
	return _getSize(root);

}

//call _getheight to get the tree's height
template <class T>
unsigned BinaryTree <T>::getHeight() const
	{return _getHeight(root);}

//call _insert function to insert new node into the tree


//call _Inorder to do the inorder travesal
template <class T>
void BinaryTree <T>::Inorder(void(*x)(const T&))
	{_Inorder(root, x);}


template <class T>
unsigned BinaryTree <T>::_getSize(Node <T>* ptr) const
{
	//if the node is null, then the size is 0
	if(ptr == NULL)
		return 0;
	else
		return (_getSize(ptr -> left) + 1 + _getSize(ptr -> right));
}
		

template <class T>
unsigned BinaryTree <T>::_getHeight (Node <T>* ptr) const
	{
	if(ptr == 0 )
		//if Node ptr is 0 height is 0 so return 0
		return 0;
	else
		{
		int leftHeight = _getHeight(ptr->left);
		int rightHeight = _getHeight(ptr->right);
		
		//determines which side of the tree is longer and returns that +1 to include the root
		if(leftHeight > rightHeight)
			return 1+leftHeight;
		else
			return 1+rightHeight;
		}
	}



template <class T>
void BinaryTree <T>::_Inorder(Node <T>* ptr, void(*x)(const T&))
{
	//visit the left node first, then visit the root node, then visit the right node
	if( ptr != NULL)
	{
		_Inorder( ptr -> left, x);
		x( ptr -> data);
		_Inorder( ptr -> right, x);
	}
}




#endif // End of H_BINARYTREE
