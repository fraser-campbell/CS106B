/*
 *  File: pqueue.cpp
 *  ----------------
 *
 *  Created by Fraser Campbell on 5/12/14
 *
 */

 #include " pqueue.h"
 #include <iostream>
 using namespace std;

 PQueue::PQueue()
 {
 	head = NULL;
 }

 PQueue::~PQueue()
 {
 	// delete the entire list

 }

 int PQueue::size()
 {
 // check size
 	cellT * tracking;
 	tracking = head;
 	int size_counter = 0;
 	while(tracking != NULL){
 		size_counter++;
 		// cout << size_counter << endl;
 		tracking = tracking->next;
 	}
 	return size_counter;
 }

bool PQueue::isEmpty()
 {
 // check is empty
 	return (head == NULL);
 }

 void PQueue::enqueue(int newElem)
 {
	 // check if the list has any elements
	 cellT *newCell  = new cellT;
	 if(isEmpty()){ //If no input in the list
	 	newCell->val = newElem;
	 	newCell->next = NULL;
	 	head = newCell;
	 	return;

	 } else { //Separate the case of length 1 and do before the while loop
	 	cellT *curr_pointer = head; //Loop through list and keep track of current pointer
	 	if(curr_pointer->val < newElem){ //If the current pointers/ cells/ value is less than insert cell
	 		cout << curr_pointer->val;
	 		cout << " Check current pointer value" << endl;
	 		newCell->val = newElem;
	 		newCell->next = curr_pointer; //wire forward
	 		head = newCell; //wire backward
	 		// delete curr_pointer; ///???????
	 		return;
	 	}
	 	curr_pointer = curr_pointer->next; //increment the current pointer by one
	 	cellT *prev_pointer = head; //insert a second pointer to track wiring backwards
	 	
	 	while(curr_pointer != NULL){ //loop through all cells
	 		if(curr_pointer->val < newElem){
	 		 	newCell->val = newElem;
	 			newCell->next = curr_pointer; //wire forward
	 			prev_pointer->next = newCell; //wire backward
	 			// delete curr_pointer; ///???????
	 			// delete prev_pointer; ///???????	
	 			return;
	 		}
	 		prev_pointer = prev_pointer->next;
	 		curr_pointer = curr_pointer->next;
	 	}
	 	//This is the case where the new cell should go at the very end
	 	 	newCell->val = newElem;
	 		newCell->next = NULL; //wire forward
	 		prev_pointer->next = newCell; //wire backward?????????
	 		// delete curr_pointer; ///???????
	 		// delete prev_pointer; ///???????	
	 		return;
	 }
 
 }

  int PQueue::dequeueMax()
 {
 	if(isEmpty()){ return -1;}// Error("pop empty stack");
 	else{
	 	int top = head->val;
	 	cout << top;
	 	cout << " value of top" << endl;
	 	cellT *old = head;
	 	head = head->next;
	 	delete old;
	 	return top;
 	}
 }


