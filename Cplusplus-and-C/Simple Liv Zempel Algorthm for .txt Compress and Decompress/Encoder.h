#ifndef _BST
#define _BST

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#define NO_INT -999999
#define NO_STRING ""

/*------------------------------------
CLASS AND STRUCT DEFINITIONS
------------------------------------*/

struct node
{
	string data;
	int code;
	node * left;
	node * right;

	// CONSTRUCTORS
	node() : data(NO_STRING), code(NO_INT), left(nullptr), right(nullptr) {}

	node(string data, int code, node * left = nullptr, node * right = nullptr) :
		data(data), code(code), left(left), right(right) {}
};

class Encoder
{

public:

	Encoder();
	Encoder(const Encoder &);
	~Encoder();
	node * getHead() const;
	void encode();

private:

	// VALUES
	node * head;
	int size;

	// HELPER FUNCTIONS FOR ENCODE
	void push(string);
	int search(string);

	// HELPER FUNC. FOR ENCODE - IMPORTANT PROCESSES DONE HERE
	void encodeProcess(const string &, string &);

	// READ AND WRITE METHODS TO TEXT FILES
	string FileReader(string);
	bool FileWriter(const string &, string);

	// DESTRUCTOR HELPER
	void clearTree(node *) const;

};

/*-------------------------------------
FUNCTION IMPLEMENTATIONS
-------------------------------------*/

// CONSTRUCTORS, DESTRUCTOR AND IT'S HELPER

Encoder::Encoder() : head(nullptr), size(256) {}

Encoder::Encoder(const Encoder & rhs)
{
	// shallow copy implementation, because deep copy is not needed
	clearTree(head);
	head = rhs.getHead();
}

Encoder::~Encoder()
{
	clearTree(head);
}

void Encoder::clearTree(node * current) const
{
	if( current != nullptr)
	{
		clearTree(current->left);
		clearTree(current->right);
		delete current;
	}
	current = nullptr;
}

// PRIVATE HELPERS FOR ENCODE AND DECODE

void Encoder::encodeProcess(const string & data, string & encodedData)
{
	// the first character is pulled
	string previousData = string(1, data[0]);

	for(unsigned int i = 1; i < data.size(); i++)
	{
		// new string is previous string + the current character i points
		string newData = previousData + string(1, data[i]);
		
		// the string is not in the tree
		if(search(newData) == NO_INT)
		{	
			if(size < 4095) push(newData);
			// if previous string is only a new character
			if(previousData.length() == 1) encodedData += to_string((int) previousData[0]) + " ";
			else encodedData += to_string(search(previousData)) + " ";
			// previous string is updated to the character where i points
			previousData = string(1, data[i]);
			// if there is a last letter left in the string we have to push its code too
			if(i == data.size() - 1) encodedData += to_string((int) previousData[0]);
		}

		// string is in the tree
		else
		{
			previousData = newData;
			// if file ends, the belonging code is pushed to the result string
			if(i == data.size() - 1) encodedData += to_string(search(previousData));	
		}
	}
}

int Encoder::search(string data)
{
	// in binary search tree compares the data inside the nodes and finds the code 
	// related to that data, if there is no code then NO_INT is returned
	node * current = head;

	while(current)
	{
		if(current->data == data) return current->code;
		else if(current->data > data) current = current->left;
		else if(current->data < data) current = current->right;
	}

	return NO_INT;
}

void Encoder::push(string data)
{
	// takes a data and compares every node with its data and moves forward until it finds 
	// a leaf node where it can push the data 
	
	if(head == nullptr)
	{
		head = new node(data, size, nullptr, nullptr);
		size++;
		return;
	}
	
	node * current = head;
	node * prev = current;

	while(current)
	{
		prev = current;
		if(data < current->data) current = current->left;
		else if(data > current->data) current = current->right;
		
	}
	
	current = new node(data, size, nullptr, nullptr);
	if(data < prev->data) prev->left = current;
	else prev->right = current;
	size++;
}

string Encoder::FileReader(string filename)
{
	ifstream input;
	input.open(filename.c_str());

	if(input.fail())		// text file is not found
	{
		cout << "File to encode is not found. Please place the file " <<
			"in the right folder or check the name of that file again." << endl;
	}

	string data = "";
	string tempStr = "";
	while(!input.eof())
	{
		getline(input, tempStr);
		tempStr += "\n";
		data += tempStr;
	}

	data = data.substr(0, data.length()-1);
	input.close();
	return data;
}

bool Encoder::FileWriter(const string & data, string filename)
{
	ofstream out;
	out.open(filename);

	if(!out.is_open())
	{
		cout << filename << " cannot be opened!" << endl;
		return false;
	}

	out << data;
	out.close();
	return true;
}

// ENCODER FUNCTION

void Encoder::encode()
{
	string data = FileReader("compin.txt");
	string encodedData;
	encodeProcess(data, encodedData);

	if(FileWriter(encodedData, "compout.txt"))
		cout << "The file is successfully encoded!" << endl;
}

// GETTER

node * Encoder::getHead() const
{
	return head;
}

#endif