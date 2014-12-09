/*
 *  File: pqueue.h
 *  ----------------
 *
 *  Created by Fraser Campbell on 5/12/14
 *
 */
#ifndef pqueue_h
#define pqueue_h

#include <vector>
 using namespace std;

class PQueue
{
 public:
	PQueue();
	~PQueue();
	int size();
	bool isEmpty();
	void enqueue(int newElem);
	int dequeueMax();

private:
	vector<int> vec_queue;
};

#endif