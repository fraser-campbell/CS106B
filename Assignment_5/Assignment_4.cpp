// Problem 1: Big-0
// a) O(n^2)
// b) O(1)
// c) O(log2 n)
// d) O(2^n)


// Problem 5:
#include <vector>
#include <iostream>
using namespace std;


void algorithm1(vector<int> store){
	int max = 0;
	int index = 0;

	for(int i=0; i<store.size(); i++){ //Define right finger
		for(int j=0; j<=i; j++){ //Define left finger
			int sum = 0;
			// cout << "i: " << i << " j: " << j << endl;
			for(int k=j; k<=i; k++){
				index++;
				sum += store[k];
			}
			// cout << "current sum: " << sum << endl;
			if(sum > max){ max = sum; }
		}
	}

	cout << "ALGO 1" << endl;
	cout << "total max algo 1: " << max << endl;
	cout << "total iters algo 1: " << index << endl;
}


void algorithm2(vector<int> store){
	int max = 0;
	int index = 0;

	for(int i=0; i<store.size(); i++){ //Goes from beginning to end --- L = 0 to N
		int sum = 0;
		for(int j=store.size()-i; j<store.size(); j++ ){ //Goes from --- U = L to N
			sum = sum + store[j];
			index++;
			if(sum > max){ max = sum; }
		}
	}
	cout << "ALGO 2" << endl;
	cout << "total max algo 2: " << max << endl;
	cout << "total iters algo 2: " << index << endl;	
}


int CleverAlgo(vector<int> my_vector){
	int max = my_vector.at(0);
	int middle = 0;
	for(int i = 1; i < my_vector.size(); i++){

		if(my_vector.at(i) > 0){ //If positice we want to know whether to include it in max or replace max with it
			if(max + middle + my_vector.at(i) > max && max + middle + my_vector.at(i) > my_vector.at(i)){ //Include in max
				max = max + my_vector.at(i) + middle;
				middle = 0;
			}
			else { //if((middle + max) < 0) ------ //Replace max with it
				max = my_vector.at(i);
				middle = 0;
			}
		}
		else{
			middle += my_vector.at(i); //Updating middle in the case that new element is negative
		}
	}
	cout << "CLEVER ALGO" << endl;
	cout << "total max clever algo: " << max << endl;
	return max;
}



int main(){

vector<int> store;
store.push_back(2);
store.push_back(-5);
store.push_back(12);
store.push_back(9);
store.push_back(-3);
store.push_back(10);

double start = double(clock()) / CLOCKS_PER_SEC;
algorithm1(store);
double finish = double(clock()) / CLOCKS_PER_SEC;
double elapsed = finish - start;
cout << "Elapsed time: " << elapsed << endl;
cout << endl;


start = double(clock()) / CLOCKS_PER_SEC;
algorithm2(store);
finish = double(clock()) / CLOCKS_PER_SEC;
elapsed = finish - start;
cout << "Elapsed time: " << elapsed << endl;
cout << endl;


start = double(clock()) / CLOCKS_PER_SEC;
CleverAlgo(store);
finish = double(clock()) / CLOCKS_PER_SEC;
elapsed = finish - start;
cout << "Elapsed time: " << elapsed << endl;
cout << endl;

}





