//Priority Queue Methods
//Anjali Thatte
//Winter 2018


#include "PriorityQueue.hpp"
#include <cstdlib>
#include<iostream>

// Implement the functions here.
using namespace std;

typedef PriorityQueue::DataType DataType;

PriorityQueue::PriorityQueue(unsigned int capacity)
{
	heap_ = new DataType[capacity +1];
	capacity_ = capacity;
	size_ = 0;
}
PriorityQueue::~PriorityQueue()
{
	delete [] heap_;
	size_ = 0;
}
bool PriorityQueue::enqueue(DataType val)
{
	if(!full())
	{
		int i = size_ + 1;
		//add to bottom right-most leaf
		while(val > heap_[i/2] && i/2 != 0)
		{
			heap_[i] = heap_[i/2];
			i /= 2;
		}
		heap_[i] = val;
		size_++;
		return true;
	}
	return false;	
	
}
bool PriorityQueue::dequeue()
{
	if(!empty())
	{
		int i = 1;
		//finds parent of last leaf, and brings greater values up
		while(2*i < size_)
		{
			if(heap_[2*i] > heap_[2*i +1])
			{
				heap_[i] = heap_[2*i];
				i *= 2;
			}
			else
			{
				heap_[i] = heap_[2*i +1];
				i = i*2 +1;
			}
		}
		heap_[i] = heap_[size_];
		heap_[size_] = 0; //\
		
		//swap if greater than parent
		while(i != size_ && heap_[i/2] < heap_ [i])
		{
			int val = heap_[i];
			heap_[i] = heap_[i/2];
			heap_[i/2] = val;
			i /= 2;
		}
		size_--;
		return true;
	}
	return false;
}
bool PriorityQueue::empty() const
{
	return (size_ == 0);
}
bool PriorityQueue::full() const
{
	return (size_ == capacity_);
}
unsigned int PriorityQueue::size() const
{
	return size_;
}
DataType PriorityQueue::max() const
{
	return heap_[1];
}
void PriorityQueue::print() const
{
	for(int i = 1; i < size_; i++)
		cout << heap_[i] << " ";
	cout << endl;
}
