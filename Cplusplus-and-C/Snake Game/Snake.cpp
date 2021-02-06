#include <iostream>
#include <string>
#include "Snake.h"
#include "randgen.h"
#include <conio.h>
#include <vector>
using namespace std;

Snake::Snake() 
{
	x = 11, y = 11;
	gameover = false;
	tail = 0;
	RandGen r;
	frx = r.RandInt(1,22);
	fry = r.RandInt(1,22);
	for ( int b = 0; b < 120; b++) {
		tailX[b] = 0;
		tailY[b] = 0;
	}
}

void Snake::First() {
	tailX[0] = x;
	tailY[0] = y;
}

void Snake::Move() {

	for ( int a = 0; a < tail; a++ ) {

		temp1 = tailX[a+1];
		temp2 = tailY[a+1];
		if ( a == 0 ) {
			tailX[a+1] = tailX[a];
			tailY[a+1] = tailY[a];
		}
		else {
			tailX[a+1] = temp3;
			tailY[a+1] = temp4;
		}
		temp3 = temp1;
		temp4 = temp2;
	}
	tailX[0] = x;
	tailY[0] = y;
}

void Snake::Fruit(){

	RandGen r;
	int a, b;
	
	do{
		a = r.RandInt(1,22);
		b = r.RandInt(1,22);
	} while (map[a][b] != " ");

	lfx = frx;
	lfy = fry;
	frx = a;
	fry = b;
	map[frx][fry] = "X";
}

void Snake::Conditions(){

	if ( x == 22 ) 
		x = 1;
	else if ( x == 0 )
		x = 21;
	if ( y == 0 )
		y = 21;
	else if ( y == 22 )
		y = 1;

	if ( x == frx && y == fry ) {
		tail++;
		Fruit();
		static int a = 0;
		if (a == 0)
			First();

	}
	else if ( map[x][y] == "o" )
		gameover = true;
}

int Snake::Score(){
	return tail;
}

void Snake::Draw() {

	system("cls");
	for(int i = 0; i < 23; i++) {
		
		for( int j = 0; j < 23; j++) {
			
			if((i == 0 || i == 22))
				map[i][j] = "-";
			
			else if((j == 0 || j == 22))
				map[i][j] = "|";
			
			else
				map[i][j] = " ";	
		}		
	}

	if ( tail > 0 && ( lfx != x || lfy != y) )
		map[temp1][temp2] = " ";
	else if ( lfx == x || lfy == y ) {
		lfx = 0;
		lfy = 0;
	}
	
	for ( int a = 0; a < tail; a++ )
		map[tailX[a+1]][tailY[a+1]] = "o";
	
	map[x][y] = "O";
	map[frx][fry] = "X";

	for(int i = 0; i < 23; i++) {	
		for( int j = 0; j < 23; j++)
			cout << map[i][j];
		cout << endl;
	}
	cout << "Your score is: " << tail << endl;
}

bool Snake::End()
{
	return gameover;
}

void Snake::Input()
{
	if (_kbhit())
    {
		switch (_getch())
        {
        case 'a':
            dir = UP;
            break;
        case 'd':
            dir = DOWN;
            break;
        case 'w':
			dir = LEFT;
            break;
        case 's':
            dir = RIGHT;
            break;
		case 'p':
			gameover = true;
            break;
        }
    }
}

void Snake::TurnTrue() {
	gameover = false;
}

void Snake::Direction()
{
	switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
}