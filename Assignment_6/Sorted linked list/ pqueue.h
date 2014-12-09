/*
 *  File: pqueue.h
 *  ----------------
 *
 *  Created by Fraser Campbell on 5/12/14
 *
 */
#ifndef pqueue_h
#define pqueue_h

// using namespace std;

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
	struct cellT {
		int val;
		cellT * next;
	};
	
	cellT * head;
};

#endif