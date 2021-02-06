/*
* Baris Batuhan Topal, 24071
* This program takes a database information about some words and their related document numbers. These values are pushed in some linked lists
* in a sorted way and after that for the given number of words, the related documents including all are printed.
*/

#include <sstream>
#include <fstream>
#include "Linkedlist.h"

//HELPER FUNCTIONS FOR THE LINKEDLIST CLASS

int findMax(vector<int> numArray)
{
	int max = INT_MIN;

	for(unsigned int i = 0; i < numArray.size(); i++)
	{
		if(max < numArray[i]) max = numArray[i];
	}

	return max;
}

/*
* Normally I aimed to sort the word without case sensitivity. Because uppercase or lowercase
* it is still the same word. However TA told that it is not necessary. So I commented that part

string ToLower(string word)
{
	string result;
	for(int i = 0; i < word.length(); i++)
	{
		result += tolower(word[i]);
	}

	return result;
}

*/

// HELPER FUNCTIONS FOR THE MAIN PROCESS

void SearchProcess(string searchString, Linkedlist<node1> & wordsHolder)
{
	istringstream in(searchString);
		string word;
		int num;

		in >> num;
		vector<string> wordsToSearch;
		while(in >> word)
		{
			// for every word in the search string, they are collected into a string vector
			wordsToSearch.push_back(word);
		}

		// every word in the vector is searched in the Linkedlist and the common doc no are returned
		vector<int> docNumsAllWordsIncluded = wordsHolder.searchListForWords(wordsToSearch);
		cout <<	"The following documents have the words:" << endl;

		string result;

		// put result into the right format
		for(unsigned int i = 0; i < wordsToSearch.size(); i++)
		{
			result +=  wordsToSearch[i] + " ";
		}

		result += to_string(docNumsAllWordsIncluded.size()) + " ";

		for(unsigned int i = 0; i <docNumsAllWordsIncluded.size(); i++)
		{
			result +=  to_string(docNumsAllWordsIncluded[i]) + " ";
		}

		cout << result << endl << endl;
}

bool DatabaseReader(Linkedlist<node1> & wordsHolder)
{
	ifstream input;
	string filename = "docdb.txt";		// name of the text file

	input.open(filename.c_str());

	if(input.fail())		// text file is not found
	{
		cout << "'docdb.txt' is not found. Please place the file in the right folder." << endl;
		return false;
	}

	while(!input.eof())
	{
		string line;
		getline(input, line);	// taking the input line by line
		int space = line.find(' ');
		string word = line.substr(0, space);	// left part of the line consdering space is the word
		int docNum = stoi(line.substr(space+1));	// right part of the line consdering space is the document no
		wordsHolder.addElementsToListSorted(word, docNum);	// word's lower version is added to list
	}

	return true;
}

// MAIN PROCESS

int main()
{

	Linkedlist<node1> wordsHolder;
	bool successful = DatabaseReader(wordsHolder);
	if(!successful) return 0;		// Text file is not read correctly!

	//Linkedlist<node1> copy = wordsHolder;

	string searchString;

	cout << "Database is imported, please enter your search string." << endl;
	cout << "If you write '0', it will exit!" << endl << endl;
	cout << "Search String: ";

	getline(cin, searchString, '\n');

	while(searchString != "0")
	{
		// every time a search string is taken until it is '0'
		SearchProcess(searchString, wordsHolder);
		cout << "Search String: ";
		getline(cin, searchString, '\n');
	}

	if(searchString == "0") cout << "Exitting from the program." << endl;

	return 0;
}
