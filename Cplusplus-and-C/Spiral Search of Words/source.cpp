/*
Baris Batuhan Topal, 24071, CS204 HW1
This homework aims to find some words in a nxn table. All the table characters and words are given in the input.
Program first makes input check and then searchs the words clockwise.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

bool Collect(string dir, int counter, int & xpos, int & ypos, vector<vector<char>> & table, vector<char> & spiral, string word){
// according to the direction the coordinate changes and the character in the new coordinate is taken to the vector spiral
	for(int i = 0; i < counter; i++){
		if(dir == "up") ypos--;
		else if (dir == "down") ypos++;
		else if(dir == "left") xpos--;
		else if (dir == "right") xpos++;
		if (xpos < table[0].size() && xpos >= 0 && ypos < table[0].size() && ypos >= 0) {
			spiral.push_back(table[ypos][xpos]);
		}
		else if (spiral.size() >= word.length()) {
			return true;
		}
		else return false;							// if collecting process ends with reaching the end of the border in table before collecting all necessary words, it returns false.
	}
	return true;
}

bool SpiralWord(string direction, vector<vector<char>> & table, string word, int xpos, int ypos){

	int counter = 1;
	vector<char> spiral;
	bool change = true;				// for example if the first direction is selected as right, the steps for right and down will be same and also for left and up will be the same 
									// before changing the direction. So, the change parameter indicates the passage from first+second directions (in ex. right and down) to third+fourth
									// directions (in ex. left and up)
	bool collectright = true;		// if that parameter returns false at the end, the spiral collecting process ends not right.
	spiral.push_back(table[ypos][xpos]);	// the first matching char is taken to spiral vector.

	while (spiral.size() <= word.length() && collectright == true){

	// according to the first direction to search, the steps are defined and with the int counter the step for each direction before changing it is determined.
		if(direction == "right"){

			if(change){
				collectright = Collect("right", counter, xpos, ypos, table, spiral, word);
				collectright = Collect("down", counter, xpos, ypos, table, spiral, word);
				change = false;
			}

			else{
				collectright = Collect("left", counter, xpos, ypos, table, spiral, word);
				collectright = Collect("up", counter, xpos, ypos, table, spiral, word);
				change = true;
			}
		}

		if(direction == "left"){

			if(!change){
				collectright = Collect("right", counter, xpos, ypos, table, spiral, word);
				collectright = Collect("down", counter, xpos, ypos, table, spiral, word);
				change = true;
			}

			else{
				collectright = Collect("left", counter, xpos, ypos, table, spiral, word);
				collectright = Collect("up", counter, xpos, ypos, table, spiral, word);
				change = false;
			}
		}

		if(direction == "up"){

			if(change){
				collectright = Collect("up", counter, xpos, ypos, table, spiral, word);
				collectright = Collect("right", counter, xpos, ypos, table, spiral, word);
				change = false;
			}

			else{
				collectright = Collect("down", counter, xpos, ypos, table, spiral, word);
				collectright = Collect("left", counter, xpos, ypos, table, spiral, word);
				change = true;
			}
		}

		if(direction == "down"){

			if(change){
				collectright = Collect("down", counter, xpos, ypos, table, spiral, word);
				collectright = Collect("left", counter, xpos, ypos, table, spiral, word);
				change = false;
			}

			else{
				collectright = Collect("up", counter, xpos, ypos, table, spiral, word);
				collectright = Collect("right", counter, xpos, ypos, table, spiral, word);
				change = true;
			}
		}
		counter++;
	}

	if (collectright){		// If the spiral chars are collected right, that vector is compared with the searched word.
		
		for(int i = 0; i < word.length() ; i++){
			if(word[i] != spiral[i])
				return false;			// If they are not the same, returns false.
		}
	}
	else return false;

	return true;
}

void Search(vector<vector<char>> & table, vector<string> & words) {
	// looks at every place in the table and tries to find the letter that is same with the words.

	vector<string> foundwords;

	for (int i = 0; i < table[0].size(); i++) {

		for (int j = 0; j < table[0].size(); j++) {

			for (int p = 0; p < words.size(); p++) {

				bool found = true;
				if (table[i][j] == words[p].at(0)) {

					if (!SpiralWord("right", table, words[p], j, i)) {
						if (!SpiralWord("left", table, words[p], j, i)) {
							if (!SpiralWord("up", table, words[p], j, i)) {
								if (!SpiralWord("down", table, words[p], j, i)) {
									found = false;
								}
							}
						}
					}
				}

				else
					found = false;

				if(found == true){
					foundwords.push_back(words[p]);
					words[p] = " ";
				}
			}
		}
	}

	// According to the size of founded words in the table, the result will be printed.
	if (foundwords.size() == 0) { cout << "No Words are Found."; }
	else if (foundwords.size() == 1) { cout << "1 Word is Found: " << foundwords[0]; }
	else {
		cout << foundwords.size() << " Words are Found: ";
		for (int i = 0; i < foundwords.size(); i++) {
			cout << foundwords[i] << " ";
		}
	}
}

int main() {

	ifstream input;
	string line, filename;			// line is for every line in input file
	int num, size;						// to take numbers in the file

	//filename check
	do {	
		cout << "Enter the name of the file:" << endl;
		cin >> filename;
		input.open(filename.c_str());
		if(input.fail()) { cout << "Could not open the file " << filename << endl; }

	} while (input.fail());
	cin.clear();

	// takes the number of column and rows and checks if it is an integer
	if (input >> size) {
		num = size;
	}
	
	else {
		cout << "Error: Input file is not in correct format!" << endl;
		cin.get();
		cin.ignore();
		return 0;
	}

	vector<vector<char>> table(num);		// table that will built by chars taken from text file
	
	// taking the chars to the table vector and controlling if the file data is true or false
	for (int i = 0; i < num; i++) {
		
		input >> line;
		if (line.length() != num) {
			cout << "Error: Input file is not in correct format!" << endl;
			cin.get();
			cin.ignore();
			return 0;
		}
		else {
			bool charrange = true;
			for (int j = 0; j < num; j++) {
				if (line.at(j) >= 'A' && line.at(j) <= 'Z') { table[i].push_back(line.at(j)); }
				else { charrange = false; }
			}
			if (!charrange) {
				cout << "Error: Input file is not in correct format!" << endl;
				cin.get();
				cin.ignore();
				return 0;
			}
		}
		
	}

	// takes the number of words will be searched and checks if it is an integer
	if (input >> size) {
		num = size;
	}

	else {
		cout << "Error: Input file is not in correct format!" << endl;
		cin.get();
		cin.ignore();
		return 0;
	}
	vector<string> words;					// words to be founded
	// taking the words that will be searched
	for (int i = 0; i < num; i++) {
		// collects the words
		input >> line;
		words.push_back(line);
	}
	
	input.close();
	Search(table, words); // begins to search

	cin.get();
	cin.ignore();
	return 0;
}