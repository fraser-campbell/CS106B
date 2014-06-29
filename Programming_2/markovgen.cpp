/*
 * File: markovgen.cpp
 * --------------------------
 * Name: Fraser Campbell
 * 
 */


#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

 
using namespace std;

typedef map<string, vector<char> > markov_dict;

double random(vector<char> vec){
	return (rand()/(RAND_MAX+1.0))*vec.size();
}

void open_file(string file, vector<char> &storage){
	ifstream input_stream; //Initialise an input stream
	input_stream.open(file); //Attach a file to our input stream

	if(!input_stream.is_open()){ //Check if file could not open
		cerr << "couldn't open the file: " + file << endl;
	}

	while(true){
		string lines;
		getline(input_stream, lines);
		if(input_stream.fail()){
			cout << "stream failed" << endl;
			break;
		}
		for(int i=0; i<lines.length(); i++){
			storage.push_back(lines[i]);
		}
	}
}

void create_map(markov_dict &dict_markov, vector<char> &storage, int model, string &max_freq){
	int max_freq_int = 0;
	stringstream ss;
	for(vector<char>::iterator itr=storage.begin(); itr !=(storage.end()-model); ++itr){
		cout << "--------" << endl;
		string s;
		for(int i=0; i<model; i++){
			cout << *(itr+i) << endl;
			s += *(itr+i);
		}

		char next_char = *(itr + model); //character after string sequence
			vector<char> chars_that_follow;
			chars_that_follow.push_back(next_char); //only too be used if the key doesn't already exist
			if(dict_markov.find(s) != dict_markov.end()){  // i.e. a key already exists for this
				dict_markov[s].push_back(next_char); // push the next char to this vector
			}
			else{
				dict_markov.insert(make_pair(s, chars_that_follow)); //create a new key/ value pair
				if(dict_markov[s].size()>max_freq_int){
					max_freq_int = 	dict_markov[s].size();
					max_freq = s;
				}
			}
	}
	cout << "no error" << endl;
}

void Printdict(markov_dict &dict_markov){
	vector<char> print_vec;
	for(markov_dict::iterator iter=dict_markov.begin(); iter != dict_markov.end(); ++iter){
		print_vec = dict_markov[iter->first];
		cout << "Character: " << iter -> first << "  Value: ";
		for(vector<char>::iterator itr = print_vec.begin(); itr != print_vec.end(); ++itr){
			cout << *itr << " ";
		}
		cout << endl;
	}
}

void Random_text(markov_dict dict_markov, string max_freq, int length_text){
	string key_str;
	string value;
	for(int i=0; i<length_text; i++){
		if(i == length_text) return;

		if(i == 0){
			key_str = max_freq;
			value = dict_markov[max_freq][static_cast<unsigned int>(random(dict_markov[max_freq]))];
			cout << key_str;
		}

		else {
			key_str = key_str.substr(1, key_str.length()-1).append(value);
			value = dict_markov[key_str][static_cast<unsigned int>(random(dict_markov[key_str]))];
		}

		cout << value;
	}
	cout << endl;

}

int main(){
srand(static_cast<unsigned int>(time(NULL))); // this casts the rand() to an int

string file; // read in the file
int model = 10; // version of the model

string max_freq = " "; //String to begin with

vector<char> storage; //Store all characters in the file
markov_dict dict_markov; //stores occurence of markov chains

cout << "Enter the file to be markov model generated: " << endl;
getline(cin, file);
open_file(file, storage);
create_map(dict_markov, storage, model, max_freq);
Printdict(dict_markov);
cout << max_freq << endl;


Random_text(dict_markov, max_freq, 1000);


return 0;
}


