
//Circular Queue Methods
//Anjali Thatte
//Winter 2018

#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	items_ = new QueueItem[16];
	head_=0;
	tail_=0;
	capacity_=16;
	size_=0;
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	capacity_=capacity;
	items_ = new QueueItem[capacity_];
	head_=0;
	tail_=1;
	size_=0;
}

CircularQueue::~CircularQueue()
{
	delete [] items_;
	items_=NULL;
}

bool CircularQueue::empty() const
{    
	if (size_==0)
	{
		return EMPTY_QUEUE;
	}
	return false;
}

bool CircularQueue::full() const
{
	if (size_==capacity_)
	{
		return true;
	}
	return false;
}

int CircularQueue::size() const
{
	return size_;  
}

bool CircularQueue::enqueue(QueueItem value)
{
	if (size_==capacity_)
	{
		return false;
	}
	items_[tail_]=value;
	tail_=(tail_+1)%capacity_;
	size_++;
	return true;
}

QueueItem CircularQueue::dequeue()
{
	if (size_==0)
	{
		return EMPTY_QUEUE;
	}
	QueueItem x = items_[head_];
	head_=(head_+1)%capacity_;
	size_--;
	return x;
	 
}

QueueItem CircularQueue::peek() const
{
	if (size_==0)
	{
		return EMPTY_QUEUE;
	}
	return items_[head_];
}

void CircularQueue::print() const
{
	for (int i=head_; i<tail_; i++)
	{
		std::cout<<items_[i];
		
	}
}
