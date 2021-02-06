#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// int findMax(vector<int> numArray)
// {
// 	int max = -999999;
//
// 	for(unsigned int i = 0; i < numArray.size(); i++)
// 	{
// 		if(max < numArray[i]) max = numArray[i];
// 	}
//
// 	return max;
// }


// I use structs in each other and thus, I give prototypes of them first
struct node1;
struct node2;
template <class Type>
class Linkedlist;

// For the List of Words
struct node1
{
	string word;
	char type;	// whether it is node2 or node1
	node1 * next;
	Linkedlist<node2> * docList;

	node1(){type = '1';}

	node1(string word, node1 * next)
		: word(word), next(next) {type = '1';}
};


// For the List of Document Numbers
struct node2
{
	int docNo;
	char type;	// whether it is node2 or node1
	node2 * next;
	node2(){type = '2';}

	node2(int docNo, node2 * next)
		: docNo(docNo), next(next) {type = '2';}
};

// one template for both 2 types of the node lists
template <class Type>
class Linkedlist
{

public:

	Linkedlist();
	Linkedlist(const Linkedlist<Type> &);
	~Linkedlist();

	Type * getHead() const;
	void setHead(Type *);

	// searchs in the Linkedlist for the documents that include all the written words
	vector<int> searchListForWords(const vector<string> &);
	// pushes wors and doc numbers to the Linkedlist
	void addElementsToListSorted(string, int);

private:

	// adds the word to linked list
	Linkedlist<node2> * AddWordToSortedList(string);
	// adds the doc no to linkedlist
	void AddDocNoToSortedList(Linkedlist<node2> *, int);
	Type * head;
};

/*
* CLASS FUNCTIONS
* ............................................
*/


// CONSTRUCTORS - DESTRUCTORS
template <class Type>
Linkedlist<Type>::Linkedlist()
{
	head = nullptr;
}


template <class Type>
Linkedlist<Type>::Linkedlist(const Linkedlist<Type> & list)
{
	// for this homework, shallow copy is more useful. Thus, I implemented that
	head = list.getHead();
}

template <class Type>
Linkedlist<Type>::~Linkedlist() // destructor
{
	while (head->next != nullptr)
	{
		Type * temp = head->next;

		if(head->type == '1')
		{
			node2 * tempInside = (*(head->docList)).getHead();
			while(tempInside->next != nullptr)
			{
				node2 * nextInside = tempInside->next;
				delete tempInside;
				tempInside = nextInside;
			}
			delete tempInside;
		}

		delete head;
		head = temp;

	}

	node2 * tempInside = (*(head->docList)).getHead();
	while(tempInside->next != nullptr)
	{
		node2 * nextInside = tempInside->next;
		delete tempInside;
		tempInside = nextInside;
	}

	delete tempInside;
	delete head;
}

// METHODS FOR THE PROCESS OF INSERTING AND SEARCHING

template <class Type>
vector<int> Linkedlist<Type>::searchListForWords(const vector<string> & searchWords)
{
	vector<int> docsIncludeWords;

	// to check if we search in an empty database or on the node2 linkedlist
	if(head == nullptr || head->type == '2') return docsIncludeWords;

	vector<node2 *> wordNodes;
	// Holds every header of Linkedlist<node2> that are element of the node1
	// which have the same word parameters with the searched words.

	node1 * temp = head;
	int totalWordsSize = searchWords.size();  // holds the # of total searched words

	while(temp != nullptr)
	{
		for(unsigned int i = 0; i < searchWords.size(); i++)
		{
			if(temp->word == searchWords[i]) // checks if the words searched and stored the same
			{
				// above mentoned headers are filled in the vector here
				wordNodes.push_back((*(temp->docList)).getHead());
				totalWordsSize--;  // for every found word the # decreases
			}
		}

		temp = temp->next;
	}

	if(totalWordsSize != 0)
	{
		// checks if all the searched words are located in the Linkedlist
		return docsIncludeWords;
	}

	else
	{
		bool allNullptr = false;
		while(!allNullptr)
		{
			// runs until every node2* in the wordnodes becomes nullptr

			vector<int> docNumsForCurrentNodes;
			// collects every doc no that wordNode pointers point to
			for(unsigned int i = 0; i < wordNodes.size(); i++)
			{
				allNullptr = true;
				if(wordNodes[i] != nullptr)
				{
					docNumsForCurrentNodes.push_back(wordNodes[i]->docNo);
					// checks if all the node2* are nullpointers
					allNullptr = false;
				}

			}

			int maxNumInCurrentNodes = findMax(docNumsForCurrentNodes);
			int NodesIncludingSameDocs = 0;

			for(unsigned int i = 0; i < wordNodes.size(); i++)
			{
				// if a pointer points to null, then there can be no other match
				if(wordNodes[i] == nullptr) return docsIncludeWords;
				else if(wordNodes[i]->docNo < maxNumInCurrentNodes) wordNodes[i] = wordNodes[i]->next;
				else if(wordNodes[i]->docNo == maxNumInCurrentNodes) NodesIncludingSameDocs++;
			}

			if(NodesIncludingSameDocs == wordNodes.size())
			{
				// if all the pointers point to the same number, this number is pushed to docsIncludeWords
				docsIncludeWords.push_back(maxNumInCurrentNodes);
				for(unsigned int i = 0; i < wordNodes.size(); i++)
				{
					wordNodes[i] = wordNodes[i]->next;
				}
			}

		}
	}

	return docsIncludeWords;
}

template <class Type>
void Linkedlist<Type>::addElementsToListSorted(string word, int docNo)
{
	if(head == nullptr || head->type == '1')
	{
		// node2 linkedlist cannot insert the word, thus only node1 has the access
		// to the inside of the if statement
		Linkedlist<node2> * temp = AddWordToSortedList(word);
		AddDocNoToSortedList(temp, docNo);
	}

	else return;

}

// GETTERS AND SETTERS FOR THE HEAD NODE
template <class Type>
Type * Linkedlist<Type>::getHead() const
{
	return head;
}

template <class Type>
void Linkedlist<Type>::setHead(Type * node)
{
	head = node;
}


// HELPER PRIVATE FUNCTIONS FOR THE CLASS PROCESSES
template <class Type>
Linkedlist<node2> * Linkedlist<Type>::AddWordToSortedList(string newWord)
{
	// inserts the word and for the node1, in which the word is inserted
	// the linkedlist<node2> pointer is returned to insert the doc no by another function
	node1 * temp = head;

	// Control for the head of the Linkedlist<node1>

	if(temp == nullptr)
	{
		node1 * temp2 = new node1(newWord, nullptr);
		temp2->docList = new Linkedlist<node2>;
		head = temp2;
		return (temp2->docList);

	}

	else if(temp->word > newWord)
	{
		// if the new word is alphabetically before the word of head
		node1 * temp2 = new node1(newWord, head);
		temp2->docList = new Linkedlist<node2>;
		head = temp2;
		return (temp2->docList);
	}

	else if(temp->word == newWord)
	{
		// if the new word is alphabetically same with the word of head
		return (temp->docList);
	}

	else
	{
		// control for the further elements in the Linkedlist<node1>
		while(temp->next != nullptr)
		{
			if(temp->next->word < newWord)
			{
				temp = temp->next;
			}

			else break;
		}

		if(temp->next == nullptr && (temp->word < newWord))
		{
			// if the word is alphabetically in the last order
			node1 * temp2 = new node1(newWord, nullptr);
			temp2->docList = new Linkedlist<node2>;
			temp->next = temp2;
			return (temp2->docList);
		}

		else if(temp->next->word == newWord)
		{
			// if the word is already in the list
			return (temp->next->docList);
		}

		else
		{
			// the only remaining option is if the word is between 2
			// Linkedlist<node1> words
			node1 * temp2 = new node1(newWord, temp->next);
			temp2->docList = new Linkedlist<node2>;
			temp->next = temp2;
			return (temp2->docList);
		}
	}
}

template <class Type>
void Linkedlist<Type>::AddDocNoToSortedList(Linkedlist<node2> * insideList, int docNo)
{
	node2 * headInside = (*insideList).getHead();

	if(headInside == nullptr)
	{
		// if the document number list is empty
		// we have to initialize the head of the document linked list
		(*insideList).setHead(new node2(docNo, nullptr));
	}

	else if(headInside->docNo > docNo)
	{
		// if this doc number is the least one in the list
		node2 * temp = new node2(docNo, headInside);
		(*insideList).setHead(temp);
	}

	else
	{
		node2 * insideTemp = headInside;
		while(insideTemp->next != nullptr && insideTemp->next->docNo < docNo)
		{
			insideTemp = insideTemp->next;
		}

		if(insideTemp->next == nullptr)
		{
			// if the doc number is the greatest in the list
			node2 * temp = new node2(docNo, nullptr);
			insideTemp->next = temp;
		}

		else if(insideTemp->next->docNo == docNo)
		{
			// if the number is already in the list
			return;
		}

		else
		{
			// if the number is between 2 linkedlist nodes
			node2 * temp = new node2(docNo, insideTemp->next);
			insideTemp->next = temp;
		}
	}
}

#endif
