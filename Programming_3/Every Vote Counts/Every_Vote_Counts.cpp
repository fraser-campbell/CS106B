/*
 * File: Every_Vote_Counts.cpp
 * --------------------------
 * Name: Fraser Campbell
 * Section: [TODO: enter section leader here] 
 * 
 */

 #include <string>
 #include <iostream>
 #include <vector>

 using namespace std;

int CountCriticalVotesImpl(vector<int> soFar, vector<int> rest, int decisive_val, int &counter, int votes_sum);

int Count_vec(vector<int> blocks){
	int sum = 0;
	for(vector<int>::iterator itr=blocks.begin(); itr!=blocks.end(); ++itr){
		sum+=*itr;
	}
	return sum;
}

int CountCriticalVotes(vector<int> &blocks, int blockIndex){
 	//Remove the relevant block and pass it's value to function
 	int decisive_val = blocks.at(blockIndex); //Decisive vote value considered
 	int votes_sum = Count_vec(blocks); //Sum of votes in current block
 	vector<int> rest = blocks;
 	rest.erase(rest.begin()+blockIndex);
 	int counter = 0; //Count of decisive votes
 	vector<int> soFar; //Empty soFar vector
 	return CountCriticalVotesImpl(soFar, rest, decisive_val, counter, votes_sum);
}

int CountCriticalVotesImpl(vector<int> soFar, vector<int> rest, int decisive_val, int &counter, int votes_sum){
	if(rest.empty()){
		int current_total = Count_vec(soFar); // Current voting setup
		if((current_total + decisive_val) > votes_sum/2 and current_total <= votes_sum/2) counter+=1; //Increment counter by one if adding decisive_val is decisive
	} 
	//Remainder of the recursion
	else if(rest.size()>0){ //If states left to assign then assign them
		int last_element = rest.back();
		rest.pop_back(); //Remove element from rest
		soFar.push_back(last_element);
		CountCriticalVotesImpl(soFar, rest, decisive_val, counter, votes_sum);
		soFar.pop_back();
		CountCriticalVotesImpl(soFar, rest, decisive_val, counter, votes_sum);
	}
	return counter;
}

int main(){

vector<int> blocks;
blocks.push_back(4);
blocks.push_back(2);
blocks.push_back(7);
blocks.push_back(4);

cout << CountCriticalVotes(blocks, 3) << endl;
// cout<< blocks.size() << endl;
cout << CountCriticalVotes(blocks, 1) << endl;

}




