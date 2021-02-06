#ifndef _DECODER
#define _DECODER

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#define UNINITIALIZED ""
#define NO_INT -999999

/*-------------------------------------------------------
CLASS DECLERATION
-------------------------------------------------------*/

class Decoder{

public:
	
	Decoder();
	~Decoder();
	void decode();

private:

	string decodedStrings[4096];
	int locToPush;	// tracks the location/code to push the next string

	string FileReader(string);
	bool FileWriter(const string &, string);

	void decodeProcess(const string &, string &);

	void pushArr(string &, int);
	void pushArr(string &);
};

/*-------------------------------------------------------
CLASS METHODS
-------------------------------------------------------*/

// CONSTRUCTOR - 0 TO 255 INITIALIZED AND OTHERS ARE GIVEN UNINITIALIZED STRING
Decoder::Decoder()
{
	for(unsigned int i = 0; i < 256; i++)
	{
		decodedStrings[i] = string(1, (char) i);
	}
	
	for(unsigned int i = 256; i < 4096; i++)
	{
		decodedStrings[i] = UNINITIALIZED;
	}

	locToPush = 256;
}	  

Decoder::~Decoder(){}	// EMPTY DESTRUCTOR -> NO HEAP STORAGE USED

// FILE READING AND WTITING PROCESSES

string Decoder::FileReader(string filename)
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
		data += tempStr;
	}
	

	input.close();
	return data;
}

bool Decoder::FileWriter(const string & data, string filename)
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

// DECODE PUBLIC METHOD
void Decoder::decode()
{
	// data from reader func is pulled
	string data = FileReader("compout.txt");
	string decodedData;
	// process functipn for decode is calles
	decodeProcess(data, decodedData);
	
	// the string that holds the resul is written
	if(FileWriter(decodedData, "decompout.txt"))
		cout << "The encoded file is successfully decoded!" << endl;
}

// DECUDE HELPER PRIVATE FUNCTION
void Decoder::decodeProcess(const string & data, string & decodedData)
{
	istringstream input(data);
	string precededString;
	int encodedNum;
	input >> encodedNum;

	// first character is pulled from string and pushed to the result string
	decodedData += decodedStrings[encodedNum];
	//previous string is initialized with the first taken code string
	precededString = decodedStrings[encodedNum];

	while(input >> encodedNum)
	{
		// Only takes a new character 
		if(encodedNum < 256)
		{
			// taken code's string is found from the array and placed to the result string
			decodedData += decodedStrings[encodedNum];
			
			if(locToPush < 4095)
			{
				// the previous string and the current coded string is added for pushing to tree
				string StringToPush = precededString + decodedStrings[encodedNum];
				// the first empty encode number is found and the string is pushed
				pushArr(StringToPush);
			}
			// preceded string is updated
			precededString = decodedStrings[encodedNum];
			continue;
		}
		
		string codeString = decodedStrings[encodedNum];

		// a new encode number is found
		if(codeString == UNINITIALIZED)
		{

			// the code of that number is cracked with adding previous string and its first character
			codeString = precededString + string(1, precededString[0]);
			// this new string is pushed to the array and added to the result string
			pushArr(codeString, encodedNum);
			decodedData += codeString;
			// preceded string is updated
			precededString = codeString;
		}

		// a string previously pushed to the array is found
		else 
		{
			decodedData += codeString;
			
			if(locToPush < 4095)
			{
				// the previous string and the current coded string is added for pushing to array
				string StringToPush = precededString + string(1, codeString[0]);
			
				// the first empty encode number is found and the StringToPush is pushed
				pushArr(StringToPush);

				// preceded string is updated
				precededString = codeString;
			}
		}

		
	}
}

// THESE ARE PUSH FUNCTIONS WHICH FINDS THE EMPTY PLACE AND ADDS THE RELATED STRING TO THAT ARRAY LOCATION
void Decoder::pushArr(string & codeString)
{
	// increases the paramete locToPush until it finds an empty place or reaches to 4095
	while(decodedStrings[locToPush] != UNINITIALIZED && locToPush < 4095) locToPush++;
	if(decodedStrings[locToPush] == UNINITIALIZED) decodedStrings[locToPush] = codeString;
}

void Decoder::pushArr(string & codeString, int code)
{
	// pushes the string to the given place
	decodedStrings[code] = codeString;
}

#endif