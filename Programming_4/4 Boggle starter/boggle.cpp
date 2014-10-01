/* File: boggle.cpp
 * ----------------
 * 
 * Fraser Campbell
 */
 
// #include "genlib.h"
// #include "simpio.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
#include <map>
#include <fstream>
#include <sstream>
#include <set> // Needed for STL set and multiset.


// #include "extgraph.h"
 using namespace std;
 typedef vector<vector<string> > board; //This is the data store for the board
 typedef map<string, vector<string> > dictionary; //This is the data store for the board
 typedef set<string> score_words;
 struct pointT {
 	int row;
 	int col;
};

string StandardCubes[16]  = 
{"AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS", "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
 "DISTTY", "EEGHNW", "EEINSU", "EHRTVW", "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"};
 
string BigBoggleCubes[25]  = 
{"AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM", "AEEGMU", "AEGMNN", "AFIRSY", 
"BJKQXZ", "CCNSTW", "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT", "DHHLOR", 
"DHLNOR", "EIIITT", "EMOTTT", "ENSSSU", "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"};

void GiveInstructions()
{
    cout << endl << "The boggle board is a grid onto which I will randomly distribute " 
	 << "cubes. These 6-sided cubes have letters rather than numbers on the faces, " 
	 << "creating a grid of letters on which you try to form words. You go first, " 
	 << "entering all the words you can find that are formed by tracing adjoining " 
	 << "letters. Two letters adjoin if they are next to each other horizontally, " 
	 << "vertically, or diagonally. A letter can only be used once in the word. Words "
	 << "must be at least 4 letters long and can only be counted once. You score points "
	 << "based on word length: a 4-letter word is worth 1 point, 5-letters earn 2 "
	 << "points, and so on. After your puny brain is exhausted, I, the super computer, "
	 << "will find all the remaining words and double or triple your paltry score." << endl;
	
    cout << "\nHit return when you're ready..."<< endl;
    // GetLine();
}

static void Welcome()
{
    cout << "Welcome!  You're about to play an intense game of mind-numbing Boggle. " 
	 << "The good news is that you might improve your vocabulary a bit.  The "
	 << "bad news is that you're probably going to lose miserably to this little "
	 << "dictionary-toting hunk of silicon.  If only YOU had a gig of RAM..." << endl << endl;
}

void CheckPrint_choose_face(board & game_board){
	vector< vector<string> >::iterator row;
	vector<string>::iterator col;
	for(row = game_board.begin(); row != game_board.end(); row++){
		cout << "" << endl;
		for(col = row->begin(); col != row->end(); col++){
			int row_char = rand() % (game_board.size());
			string temp = *col;
			*col = temp[row_char];
			cout << *col << " " ;
		}
	}
	cout << " " << endl;
}

void CheckPrint(board & game_board){
	vector< vector<string> >::iterator row;
	vector<string>::iterator col;
	for(row = game_board.begin(); row != game_board.end(); row++){
		cout << "" << endl;
		for(col = row->begin(); col != row->end(); col++){
			cout << *col << " " ;
		}
	}
	cout << " " << endl;
}



void Printdict(dictionary &dict){
	vector<string> print_vec; //This will hold the word values for printing in a vector
	for(dictionary::iterator iter=dict.begin(); iter != dict.end(); ++iter){
		print_vec = dict[iter->first];
		cout << "Character: " << iter -> first << "  Value: ";
		for(vector<string>::iterator itr = print_vec.begin(); itr != print_vec.end(); ++itr){
			cout << *itr << " ";
		}
		cout << endl;
	}
}

void Printwords(score_words & words){

	cout << "The following words were found: " << endl;
	for(score_words::iterator iter=words.begin(); iter != words.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl;
}

// --------------------------------------Set's up the board--------------------------------------------------------------------------

//Function to create board data structure
board Create_GameBoardLoop(int size, string array[]){
	board game_board;
	vector<string> new_vec; 
	int numCols = sqrt(size);
	for(int i = 0; i < size; i++){
		if(i == 0){
			new_vec.push_back(array[i]);
			// cout << i << " if" << endl;
		} else if((i+1) % numCols == 0) {
			new_vec.push_back(array[i]);
			game_board.push_back(new_vec);
			new_vec.clear(); 
			// cout << i << " else if" << endl;		
		}
		else{
			new_vec.push_back(array[i]);
			// cout << i << " else" << endl;
		}
	}
	return game_board;
}

//Function deals with different size of boards
board Create_GameBoard(int size){
	board game_board;
	if(size == 16){
		game_board = Create_GameBoardLoop(16, StandardCubes);
	}
	else{
		game_board = Create_GameBoardLoop(25, BigBoggleCubes);
	}

	// CheckPrint(game_board);
	return game_board;
};


//Main function to create boards
board CreateBoard(int size){
	board game_board;
	int numRows = sqrt(size);
	int numCols = sqrt(size);
	game_board = Create_GameBoard(size);
	for (int row = 0; row < numRows; row++){
		// cout << "here" << endl;
		for (int col = 0; col < numCols; col++){
	 // choose randomRow from range [row, numRows-1]
			int row_rand = rand() % (numRows-1);     // rand number in the range row to numRows-1
			// cout << row_rand;
		// choose randomCol from range [col, numCols-1]
			int col_rand = rand() % (numCols-1);     // rand number in the range row to numRows-1
		// swap element at row,col with element at randomRow, randomCol
			// cout << col_rand << endl;

			string temp = game_board[row_rand][col_rand];
			// cout << temp << endl;
			game_board[row_rand][col_rand] = game_board[row][col];
			game_board[row][col] = temp;
		}
	}
		CheckPrint_choose_face(game_board);
		return game_board;
}

// ---------------------------------------------Set's up the dictionary----------------------------------------------------------------

void Add_to_dict(string lines, dictionary & dict){
	// cout << lines.substr(0,2) << endl;
	string start = lines.substr(0,2);
	// If key exists in MAP push key and value into MAP
	if(dict.find(start) != dict.end()){  // i.e. a key already exists for this
		dict[start].push_back(lines); // push the next char to this vector
	} else {
		vector<string> words;
		words.push_back(lines); //only too be used if the key doesn't already exist
		dict.insert(make_pair(start, words)); //create a new key/ value pair
	}
};


void open_file(string file, dictionary & dict){
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
		// for(int i=0; i<lines.length(); i++){
		// 	storage.push_back(lines[i]);
		// }
		Add_to_dict(lines, dict);
	}
	// Printdict(dict);
}

// ---------------------------------------------Human Enter Words----------------------------------------------------------------

bool check_word_dict(string word, dictionary dict){
	string start = word.substr(0,2);
	if(dict.find(start) != dict.end()){  // i.e. a key already exists for the beginning od this word
		for(vector<string>::iterator itr = dict[start].begin(); itr != dict[start].end(); ++itr){
			if(*itr == word){
				return true; // This word exists in the dictionary
			}
		}
	}
	return false; //If word not in dict false
}

bool check_new_word(string word, score_words score){
	if(score.find(word) != score.end()){ //Already exists in score set
		return false;
	}
	return true; //Does not exist in score set
}


bool check_word_recur(string word, board game_board, pointT pos){

	if(word.size() == 0){ return true; } //BASE CASE - If the word is completed
	for (int col=-1; col<2; col++){ //Iterare through the columns around the current point
		for (int row=-1; row<2; row++){ //Iterare through the rows around the current point
			int new_row = pos.row+row; //Create new ints for the row and column indices
			int new_col = pos.col+col;
			if( new_col > -1 && new_col < game_board.size() && new_row> -1 && new_row < game_board.size() ) { //Not outside Walls

				if(game_board[new_row][new_col] == word.substr(0,1)) { //If cube is the next char in word

					pos.col = new_col; // MAKING CHANGES TO DATA STRUCTS
					pos.row = new_row;
					string first_char = word.substr(0,1);
					game_board[new_row][new_col] = "!"; //This to make sure don't back track

					if(check_word_recur(word.erase(0,1), game_board, pos)){
						return true;
					}
					else{
						pos.col -= col; // REVERSING CHANGES TO DATA STRUCTS
						pos.row -= row; 
						word.insert(0,first_char);
						game_board[new_row][new_col] = first_char;
					}
				}
			}
		}
	}
	return false;
}



bool check_word_board(string word, board game_board){ //Identify all the possible strt points on the board
	vector< vector<string> >::iterator row;
	vector<string>::iterator col;
	int index = 0;

	string first_char = word.substr(0,1);

	for(row = game_board.begin(); row !=game_board.end(); row++){
		for(col = row->begin(); col != row->end(); col++, index++){

			if(*col == first_char){ //If the cube on grid is the first character of the word
				pointT pos;
				pos.col = index % game_board.size(); //This is the col number
				pos.row = (int)index / game_board.size(); //This is the row number
				game_board[pos.row][pos.col] = "!"; // MAKING CHANGES TO DATA STRUCTS

				if(check_word_recur(word.erase(0,1), game_board, pos)){ //This checks for the word minus first letter
					return true; } //If it finds the word from this start point it returns true
				
				word.insert(0,first_char); // REVERSING CHANGES TO DATA STRUCTS
				game_board[pos.row][pos.col] = first_char;
			}
		}
	}
	return false; //Return False if we have been unable to find a solution
}



void add_word_score(string word, score_words & human_score){
	human_score.insert(word);
};



void Human_Score(dictionary dict, score_words & human_score, board game_board){
	while(true){
		string word;
		cout << "Enter the word you see? ";
		getline(cin, word);
		if(word == ""){
			break;
		} else {							
			if(check_word_dict(word, dict) && check_new_word(word, human_score) && check_word_board(word, game_board)){
				add_word_score(word, human_score);
				cout << "Word is valid" << endl;	
			} else {
				cout << "Word not valid try something else" << endl;
			}	
		}
	}
}

// ---------------------------------------------Computer Find Words----------------------------------------------------------------

bool check_key_exists(string curr_word, dictionary dict){
	if(dict.find(curr_word.substr(0,2)) != dict.end()){  // i.e. a key already exists for this
		return true; // push the next char to this vector
	}
	return false;
}


bool stem_search(string word, dictionary dict){
	string start = word.substr(0,2);
	if(dict.find(start) != dict.end()){  // i.e. a key already exists for the beginning of this word
		for(vector<string>::iterator itr = dict[start].begin(); itr != dict[start].end(); ++itr){
			string stem = *itr;
			if(stem.size() >= word.size()){ //CUT THE WORD DOWN IF LONG ENOUGH TO CHECK IF SAME STEM
				stem.erase(stem.begin() + word.size(), stem.end());
				if(stem == word){
					return true; // This STEM exists in dictionary
				}
			}
		}
	}
	return false; //If above conditions not satisfied return false
}


bool word_in_dict(dictionary dict, score_words & computer_score, string curr_word){
	if(curr_word.size() == 1){ return true;} //IF SIZE ==1 BECAUSE KEYS OF DICT ARE 2 IGNORE AND CONTINUE
	if( check_key_exists(curr_word, dict) ){ //IF KEY DOESN'T EXIST FALSE

		if( check_word_dict(curr_word, dict) ){
			cout << curr_word << " Is a word" << endl;
			computer_score.insert(curr_word);
			return true; //WANT TO CONTINUE CHECKING FOR LONGER WORDS
		}
		if( stem_search(curr_word, dict) ){
			return true; //STEM EXISTS SEE IF WE CAN MAKE LONGER WORD
		} else {
			return false; //STEM DOES NOT EXIST TRIGGER BACKTRACKING
		}


	} else {
		return false; //KEY DOES NOT EXIST TRIGGER BACKTRACKING
	}
}


void find_word_board(dictionary dict, score_words & computer_score, board game_board, string & curr_word, pointT & pos){
	if(word_in_dict(dict, computer_score, curr_word)){  //---------------------//BASE CASE CHECKING

		for (int col=-1; col<2; col++){ //Iterate through the columns around the current point
			pos.col += col;
			for (int row=-1; row<2; row++){ //Iterate through the rows around the current point
				pos.row += row;
				if(pos.col > -1 && pos.col < game_board.size() && pos.row> -1 && pos.row < game_board.size()) { //NOT OUTSIDE WALL

					string new_char = game_board[pos.row][pos.col];

					if(new_char != "!"){ //NOT ALREADY USED

						game_board[pos.row][pos.col] = "!"; // MAKING CHANGES TO DATA STRUCTS
						curr_word.append(new_char);

						find_word_board(dict, computer_score, game_board, curr_word, pos);

						curr_word = curr_word.substr(0, curr_word.size() - 1); //UNDO !
						game_board[pos.row][pos.col] = new_char; //UNDO !
					}
				}
				pos.row -= row;
			}
			pos.col -= col;
		}
	}
}

void Remove_human_word(score_words & computer_words, score_words & human_words){
//Loop through the human words and delete them from the computer words
	for(score_words::iterator iter=human_words.begin(); iter != human_words.end(); ++iter){
		computer_words.erase(*iter); //Erase the value from the computer word that corresponds to the human word 
	}
}


void Computer_Score(dictionary dict, score_words & computer_score, board game_board, score_words & human_score){
	cout << "Computer will now try to beat you" << endl;
	int index = 0;
	pointT pos;
	//THESE LOOPS CHOOSE THE FIRST CUBE CHAR THEN RECURSIVE FUNCTION CALLED FOR ALL FIRST CHARS
	for(int i=0; i<game_board.size(); i++){
		for(int j=0; j<game_board.size(); j++, index++){

			pos.col = j; // MAKING CHANGES TO DATA STRUCTS
			pos.row = i;
			string temp = game_board[pos.row][pos.col];
			string curr_word = game_board[pos.row][pos.col]; //CHOOSE ONE CUBE TO BE THE START OF WORD
			game_board[pos.row][pos.col] = "!"; //This to make sure don't back track

			find_word_board(dict, computer_score, game_board, curr_word, pos);
			game_board[pos.row][pos.col] = temp; // UNDOING CHANGES TO DATA STRUCTS
		}
	}
	CheckPrint(game_board);
	Remove_human_word(computer_score, human_score);
	Printwords(computer_score);
}


// ---------------------------------------------Comparison of two scores-----------------------------------------------------

int add_score(score_words score){
	int score_int = 0;
	string word;
	for(score_words::iterator iter=score.begin(); iter!=score.end(); iter++){
		word = *iter;
		score_int += word.size();
	}
	return score_int;
}

void compare_score(score_words & computer_words, score_words & human_words){
	cout << "Human Score: " << add_score(human_words) << " Computer Score: " << add_score(computer_words) << endl; 
}


// ---------------------------------------------Main function----------------------------------------------------------------


int main()
{
	// SETUP BOARD AND GAME
	srand (time(NULL)); //This sets the random number generator to a random value
	Welcome();
	GiveInstructions();
	int size = 16;
	board game_board;
	game_board = CreateBoard(size);

	// SETUP DICTIONARY
	string file = "HangmanLexicon.txt";
	dictionary dict;
	open_file(file, dict);

	// HUMAN PLAY
	score_words human_score;
	Human_Score(dict, human_score, game_board);

	// COMPUTER PLAY
	score_words computer_score;
	Computer_Score(dict, computer_score, game_board, human_score);

	//COMPARISON PRINTOUT
	compare_score(computer_score, human_score);

	return 0;
}


