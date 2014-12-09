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
	static const int arr_size = 4; //Constant defning the size of the array

	struct cellT { //Struct for the cells in the linked list
		int store[4];
		cellT * next;
		int stored;
	};

	cellT * curr_pos; //Current position of pointer used in functions
	cellT * head; //Pointer to the head of the linked list
	
	//HELPER FUNCTIONS FOR IMPLEMENTATION
	void split(cellT * curr_pos); //private split cell function
};

#endif