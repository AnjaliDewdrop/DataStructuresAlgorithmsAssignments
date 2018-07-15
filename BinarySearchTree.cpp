//Binary Tree Methods
//Anjali Thatte
//Winter 2018


#include <cstdlib>
#include<iostream>
#include<queue>
#include "BinarySearchTree.hpp"

using namespace std;
typedef BinarySearchTree::DataType DataType;

BinarySearchTree::Node::Node(DataType newval)
{
	val = newval;
	left = NULL;
	right = NULL;
}
BinarySearchTree::BinarySearchTree()
{
	root_ = NULL;
	size_ = 0;
}
BinarySearchTree::~BinarySearchTree()
{
	std::queue<Node*> queue;
    queue.push(root_);
    while(!queue.empty()){
        if(queue.front() != NULL){
            queue.push(queue.front() -> left);
            queue.push(queue.front() -> right);
            delete queue.front();
        }
        queue.pop();
    }
}
bool BinarySearchTree::insert(DataType val)
{
	if(size_ == 0)
	{
		root_ = new Node(val);
		size_++;
		return true;
	}
	else
	{
		Node *temp = root_;
		while(val != temp->val)
		{
			//go left
			if(val < temp->val)
			{
				//find until there's no child
				if(temp->left == NULL)
				{
					temp->left = new Node(val);
					size_++;
					return true;
				}
				temp = temp->left;
			}
			//go right
			else
			{
				//find until there's no child
				if(temp->right == NULL)
				{
					temp->right = new Node(val);
					size_++;
					return true;
				}
				temp = temp->right;
			}
		}
		return false;
	}
}
bool BinarySearchTree::remove(DataType val)
{
	Node* temp = root_;
	while(temp != NULL && val && val != temp->val)
	{
		if(val < temp->val)
			temp = temp->left;
		else
			temp = temp->right;
	}

	if(temp == NULL) return false;
	//if two children
	else
	{
		if(temp->left != NULL && temp->right != NULL)
		{
			//find min in right subtree
			Node* minR = temp->right;
			while(minR->left != NULL)
				minR = minR->left;
				
			DataType newval = minR->val;
			if(remove(minR->val))
			{
				temp->val = newval;
				return true;
			}	
		}
		//left child
		else if(temp->left != NULL)
		{
			Node* swap = temp->left;
			temp->val = swap->val;
			
			temp->left = swap->left;
			temp->right = swap->right;
			delete swap;
			swap = NULL;
		}
		//right child
		else if(temp->right != NULL)
		{
			Node* swap = temp->right;
			temp->val = swap->val;
			
			temp->right = swap->right;
			temp->left = swap->left;
			delete swap;
			swap = NULL;
		}
		else if(temp == root_)
		{
			delete root_;
			root_ = NULL;
		}
		else
		{
			Node* parent = root_;
			while(parent->right != temp && parent->left != temp)
			{
				if(val < parent->val)
					parent = parent->left;
				else
					parent = parent->right;
			}
			if(temp == parent->right)
				parent->right = NULL;
			else
				parent->left = NULL;
			delete temp;
			temp = NULL;
		}
		size_--;
		return true;
	}
}
bool BinarySearchTree::exists(DataType val) const
{
	Node *temp = root_;
	while(temp != NULL)
	{
		if(val == temp->val) return true;
		else if(val < temp->val)
			temp = temp->left;
		else
			temp = temp->right;
	}
}
DataType BinarySearchTree::min() const
{
	Node* temp = root_;
	while(temp->left != NULL)
		temp = temp->left;
	return temp->val;
}
DataType BinarySearchTree::max() const
{
	Node* temp = root_;
	while(temp->right != NULL)
		temp = temp->right;
	return temp->val;
}
unsigned int BinarySearchTree::size() const
{
	return size_;
}
unsigned int BinarySearchTree::depth() const
{
	if(root_->left == NULL && root_->right == NULL)
		return 0;
	if(root_ == NULL)
		return -1;
	else
		return getNodeDepth(root_);
}
void BinarySearchTree::print() const
{
//	if(temp == NULL)
//		return;
//	
//	print(temp->left);
//	cout << temp->val << " ";
//	print(temp->right);
}
int BinarySearchTree::getNodeDepth(BinarySearchTree::Node* n) const
{
	if(n == NULL || (n->right == NULL && n->left == NULL))
		return 0;
	else
	{
		unsigned int l = 0;
		unsigned int r = 0;
		if(n->right != 0)
			l = 1 + getNodeDepth(n->right);
		if(n->left != 0)
			r = 1 + getNodeDepth(n->left);
		
		if(l > r)
			return l;
		else
			return r;
	}
}

