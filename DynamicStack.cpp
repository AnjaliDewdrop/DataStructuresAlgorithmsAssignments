
//Dynamic Stack Methods
//Anjali Thatte
//Winter 2018


#include <iostream>
#include <cstdlib>
#include "DynamicStack.hpp"

using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	size_ = 0;
	capacity_ = 16;
	init_capacity_ = capacity_;
	items_ = new StackItem[capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	if(capacity==0)
		capacity_ = 16;
	
	else
	{
		size_ = 0;
		capacity_ = capacity;
		init_capacity_ = capacity_;
		items_ = new StackItem[capacity_];
	}
}

DynamicStack::~DynamicStack()
{
	delete [] items_;
}

bool DynamicStack::empty() const
{
	if(size_==0)
		return true;
	
	return false;
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if(size_>=capacity_)
	{
		StackItem* temp = new StackItem[capacity_*2];
		capacity_ *= 2;
		
		for (int i=0; i<size_; i++)
			temp[i]=items_[i];

		delete [] items_;
		items_ = temp;
		items_[size_] = value;
		size_++;
	}
	else
	{
		items_[size_] = value;
		size_ ++;
	}	
}

StackItem DynamicStack::pop()
{
	if(size_ == 0)
		return EMPTY_STACK;
	
	else
	{
		if((size_-1) <= (capacity_/4) && (capacity_/ 2) >= init_capacity_)
		{
		StackItem* temp = new StackItem[capacity_/2];
		capacity_ /= 2;
		
		for (int i=0; i<size_; i++)
			temp[i]=items_[i];

		delete [] items_;
		items_ = temp;
		size_--;
		return items_[size_];
		}
		
		size_--;
		return items_[size_];
	}
}

StackItem DynamicStack::peek() const
{
	if(size_==0)
		return EMPTY_STACK;
	
	return items_[size_-1];
}

void DynamicStack::print() const
{
	for(int i=size_-1; i<=0; i--)
		cout << items_[i] << endl;
}
