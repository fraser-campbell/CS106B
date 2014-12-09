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
 	head  = new cellT;
 	head->next = NULL; //Initialise empty cell to point to NULL initially
 	head->stored = 0;
 }

 PQueue::~PQueue()
 {
 	while(head->next != NULL){ //While there is always something connected to our current position
 		cellT *temp = head -> next; //Create a temp pointer to store the next array
 		delete head; //delete curr
 		head = temp;
 	}
 	delete head;
 }

 int PQueue::size()
 {
 // check size
 	cellT * tracking;
 	tracking = head;
 	int size_counter = 0;
 	while(tracking != NULL){
 		size_counter = size_counter + tracking->stored;
 		tracking = tracking->next;
 	}
 	return size_counter;
 }

bool PQueue::isEmpty()
 {
 	return (head->stored == 0); //There are no elements in the first array
 }

 void PQueue::enqueue(int newElem)
 {
 		curr_pos = head; //keep track of the curr_pos throughout

 		 if(curr_pos->stored == 0){ //This is the case of the very first element in the queue
 			curr_pos->store[0] = newElem;
 			curr_pos->stored = 1;
 			return;
 		}

 		int added = 0;
 		//Iterate until pointer is pointing to the cell which we want to input our value into
 		while(curr_pos != NULL && added == 0){
 			cout << "here1" << endl;
 			if(curr_pos->next != NULL && curr_pos->next->store[0] > newElem){ 
 				curr_pos = curr_pos->next;
 			}
 			else {
 				cout << "here2" << endl;
 				if(curr_pos->stored%(arr_size) == 0){ //need to split cell
		 			split(curr_pos);
		 		}
		 		else {
		 			cout << "here3" << endl;
		 			//Loop through elemets insert newelem and shuffle existing elements along
 					for(int i = curr_pos->stored-1; i >= 0; i--){
 						cout << "here4" << endl;
 						if(newElem > curr_pos->store[i]){ // Shuffle array elements along
 							curr_pos->store[i+1] = curr_pos->store[i];
 						} else { //Should always find space to insert the newELem in this array
 							cout << "here5" << endl;
 							curr_pos->store[i+1] = newElem;
 							cout << curr_pos->store[i+1] << " what is this element at " << i+1 << endl;
 							curr_pos->stored++;
 							added++;
 							break;
 						}
 					}
		 		}
 			}
 		}
 }


 void PQueue::split(cellT * curr_pos){ //NB: insert position is 0,1,2,3,4
 	//Need to create a new struct which the curr_pos points too
 	cellT * newCell  = new cellT; //Create new cell
 	if(curr_pos->next != NULL){ //If not at the end of the list
 		cellT * tmp_ptr = curr_pos->next; //store the next cell pointer
 		newCell->next = tmp_ptr; //wire fwd
  		newCell->stored = 0; //Set stored equal to 0
 		curr_pos->next = newCell; //wire bkwd
 	} else {
 		newCell->next = NULL; // i.e. new insert is at the end of a linked list
 		newCell->stored = 0; //Set stored equal to 0
 		curr_pos->next = newCell; //Make the previous cell point to the new cell
 	}

 	int split_int = (int) arr_size/2;
 	int counter = 0;
 	for (int j=split_int; j<=arr_size-1; j++){
 		newCell->store[counter] = curr_pos->store[j];
 		counter++;
 	}
 	newCell->stored = counter;
 	curr_pos->stored = split_int;
 	cout << "split first cell size " << curr_pos->stored << endl;
 	cout << "split second cell size " << newCell->stored << endl;
 }



  int PQueue::dequeueMax()
 {
 	if(isEmpty()){ return -1;} // Error("pop empty queue"); //Trying to pop when nothing in the queue
 	else{
 		int dequeue_int = head->store[0];
 		cout <<  head->store[0];
	 	cout << " value of top" << endl;
	 	cout <<  head->store[1];
	 	cout << " value of second top" << endl;
	 	cout <<  head->store[2];
	 	cout << " value of third top" << endl;
	 	for(int i=0; i <= head->stored-2; i++){
	 		cout << "deleting" << endl;
	 		head->store[i] = head->store[i+1];
	 	}
	 	head->stored = (head->stored - 1) ;//Update stored to represent new position
	 	if(head->stored == 0 && head->next!=NULL){ //Need to rewire the pointers and remove, unless 1st array
		 	cellT *old = head;
		 	head = head->next;
	 		delete old;
	 	}
 		return dequeue_int;
 	}
 }


