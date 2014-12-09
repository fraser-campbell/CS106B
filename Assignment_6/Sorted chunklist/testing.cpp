/*
 *  File: testing.cpp
 *  ----------------
 *
 * Created by Fraser Campbell on 5/12/14
 * This file is written to test the implementation of pqueue.cpp
 *
 */

#include <iostream>
#include " pqueue.h"
using namespace std;

int main(){


	PQueue testqueue;
	// testqueue.enqueue(1);
	testqueue.enqueue(3);
	testqueue.enqueue(2);
	testqueue.enqueue(1);
	testqueue.enqueue(3);
	testqueue.enqueue(2);
	// testqueue.enqueue(4);
	// testqueue.enqueue(3);

	// cout << testqueue.size();
	// cout << " Testing size" << endl;
	// cout << testqueue.isEmpty();
	// cout << " Testing if empty" << endl;

	cout << testqueue.dequeueMax();
	cout << " Dequeue first one" << endl;
	// cout << testqueue.size();
	// cout << " Testing size" << endl;

	cout << testqueue.dequeueMax();
	cout << " Dequeue second one"  << endl;

	cout << testqueue.dequeueMax();
	cout << " Dequeue third one" << endl;
	// cout << testqueue.size();
	// cout << " Testing size" << endl;

	cout << testqueue.dequeueMax();
	cout << " A bridge to far" << endl;

	cout << testqueue.dequeueMax();
	cout << " Again" << endl;

	return 0;
}