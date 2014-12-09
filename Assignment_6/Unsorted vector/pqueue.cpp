/*
 *  File: pqueue.cpp
 *  ----------------
 *
 *  Created by Fraser Campbell on 5/12/14
 *
 */

 #include " pqueue.h"

 PQueue::PQueue()
 {
 	//Nothing to create in constructor
 }

 PQueue::~PQueue()
 {
 	// delete the entire list

 }

 int PQueue::size()
 {
 // check size
 	return vec_queue.size();
 }

bool PQueue::isEmpty()
 {
 // check is empty
 	if(vec_queue.empty()){
 		return 1;
 	} else {
 		return 0;
 	}
 }

 void PQueue::enqueue(int newElem)
 {
 // check is empty
 	return vec_queue.push_back(newElem);
 }

  int PQueue::dequeueMax()
 {
 	if(isEmpty()){
 		return -1;
 	}

 // check is empty
 	int Max_index = 0;
 	int Max_value = 0;
 	for(int i=0; i<vec_queue.size(); i++){
 		if(vec_queue[i] >= Max_value){
 			Max_value = vec_queue[i];
 			Max_index = i;
 		}
 	}
 	vec_queue.erase(vec_queue.begin() + Max_index);
 	return Max_value;
 }


