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
testqueue.enqueue(1);
testqueue.enqueue(3);
testqueue.enqueue(2);

cout << testqueue.isEmpty() << endl;
cout << "This is the test of compile" << endl;
cout << testqueue.dequeueMax() << endl;
// cout << testqueue.size() << endl;
cout << testqueue.dequeueMax() << endl;
// cout << testqueue.size() << endl;
cout << testqueue.dequeueMax() << endl;

cout << testqueue.isEmpty() << endl;

	return 0;
}