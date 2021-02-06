#include "Snake.h"
#include "randgen.h"
#include <conio.h>
#include <vector>

int main() 
{
	bool playagain = true;
	int highest = 0;
	do {
		Snake s1;
		playagain = true;

		while(!s1.End()) 
		{
			s1.Input();
			s1.Direction();
			s1.Conditions();
			s1.Move();
			s1.Draw();
			if (highest < s1.Score()) highest = s1.Score();
			cout << "Highest score is: " << highest << endl;
			if(s1.End()) {
				cout << "If you want to play again please press y, to contine press p, to end press n:";
				string a;
				cin >> a;
				if ( a=="y") playagain = false;
				else if ( a=="n") ;
				else if ( a=="p") s1.TurnTrue();
			}
		}
	}while(!playagain);
	return 0;
}