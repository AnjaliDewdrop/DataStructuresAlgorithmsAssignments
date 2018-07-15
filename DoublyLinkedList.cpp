//Doubly Linked List Methods
//Anjali Thatte
//Winter 2018


#include "DoublyLinkedList.hpp"
#include<iostream>
using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
	value = data;
	next = NULL;
	prev = NULL;
	
}

DoublyLinkedList::DoublyLinkedList()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	while(!size_==0)
		remove_front();
		
	if(size_==0)
		return;                  //i don't think you need this section (if size_==0...return) *AHT
}

bool DoublyLinkedList::empty() const
{
	if (size_ == 0)
		return true;
	return false;
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

void DoublyLinkedList::print() const
{
	Node* print = head_;
	for(int i=0;i<size_;i++)
	{
		cout << "[" << print->value << "] ";
		print = print->next;
	}
}

bool DoublyLinkedList::insert_front(DataType value)
{
	//check if full 
	if(size_== CAPACITY)
		return false;
		

	//check if empty
	else if(size_==0)                   //should not need else if and else; won't influence code output but can be redundant *AHT
	{
		Node* newNode = new Node(value);
		head_= newNode;
		tail_= newNode;
		size_++;
		
		newNode= NULL;
		return true;
	}
	else
	{
		Node* newNode = new Node(value);
		newNode->next=head_;
		head_->prev=newNode;
		
		head_=newNode;
		size_++;
		
		newNode= NULL;
		return true;
	}
	//return insert(value, 0);     *AHT this comment can be removed
}

bool DoublyLinkedList::remove_front()
{
	if(size_==0)
		return false;
		
	else if(size_==1)
	{
		delete head_;
		
		head_=NULL;
		tail_=NULL;
		
		size_--;
		return true;
	}
	else
	{
		Node* temp=head_;
		head_=head_->next;
		head_->prev=NULL;
		
		delete temp;
		temp=NULL;
		size_--;
		return true;
	}
	//return remove(0);         //*AHT Can get rid of this
}

bool DoublyLinkedList::insert_back(DataType value)
{
	if(size_== CAPACITY)
		return false;
	
	//check if empty
	else if(size_==0)
	{
		Node* newNode = new Node(value);
		head_= newNode;
		tail_= newNode;
		size_++;
		
		newNode= NULL;
		return true;
	}
	else
	{
		Node* newNode = new Node(value);
		newNode->prev=tail_;
		tail_->next=newNode;
		
		tail_=tail_->next;
		
		//*AHT newNode=NULL; 
		//CORRECTED
		newNode=NULL;
		
		size_++;           
		return true;
	}
	//return insert(value, size_);  //*AHT can remove this
}

bool DoublyLinkedList::remove_back()
{
	if(size_==1)
		return remove_front();
	else
	{
		Node* temp=tail_->prev;
		temp->next=NULL;
		delete tail_;
		tail_=temp;
			
		temp=NULL;
			
		size_--;
		return true;		
	}		

	//return remove(size_-1);  //*AHT can remove this
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	//check if full or index is greater than size
	if(size_== CAPACITY || index > size_)
		return false;
	
	//check if empty
	else if(size_==0)
	{
		return insert_front(value);
	}
	else if(index==0)
	{
		return insert_front(value);
	}
	
	else if(index==size_)
	{
		return insert_back(value);
	}
	else
	{
		Node* newNode = new Node(value);
		Node* temp = getNode(index);
		
		newNode->prev=temp->prev;
		newNode->next=temp;
		temp->prev=newNode;
		newNode->prev->next=newNode;
		
		size_++;
		temp=NULL;
		return true;
	}
}

bool DoublyLinkedList::remove(unsigned int index)
{
	if(index>=size_)
		return false;
		
	else if(size_==1)
	{
		return remove_front();
	}
	else if(index==0)
	{
		return remove_front();
	}
	else if(index==size_-1)
	{
		return remove_back();
	}
	else
	{
		Node* tempPre=getNode(index-1);
		Node* tempAft=getNode(index+1);
		
		tempPre->next=tempAft;
		tempAft->prev=tempPre;
		
		Node* temp=getNode(index);
		temp->prev=NULL;
		temp->next=NULL;
		
		delete temp;      //*AHT Not sure but i don't hink you need temp->prev=NULL and temp->next = NULL if you are deleting temp anyway
		temp=NULL;
		tempPre=NULL;
		tempAft=NULL;
		size_--;
		return true;
	}
}

unsigned int DoublyLinkedList::search(DataType value) const
{
	//*AHTPersonalNote
	//OBJ: return index of value found value
	Node* search = head_;
	
	for(int i=0;i<size_;i++)
	{
		if(value == search->value)
			return i;
			
		search=search->next;
	}
	return size_;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	//*AHTPersonalNote
	//OBJ: return value at the given index param
	if(index>=size_)
		return tail_->value;
		
	Node* select = head_;
	
	for(int i=0;i<index;i++)
	{
		select=select->next;
	}
	return select->value;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	if(index>=size_)
		return false;
		
	else
	{
		Node* replace = getNode(index);
		
		replace->value=value;
		
		replace=NULL;
		
		return true;
	}
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	if(index>=size_)
		return NULL;
	
	Node* get = head_;
	for(int i=0;i<index;i++)
	{
		get=get->next;
	}
	return get;
}

bool DoublyLinkedList::full() const
{
	if(size_== CAPACITY)
		return true;
	return false;
}
