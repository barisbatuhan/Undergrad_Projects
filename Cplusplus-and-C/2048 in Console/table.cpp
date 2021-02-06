#include "table.h"
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int score = 0;

bool table::win() {	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (mytab[i][j] == "4096")  return true;
		}
	}
	return false;
}

bool table::lose() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (mytab[i][j] == "    ")  return false;
		}
	}
	return true;
}

string change(string str) {
	if (str == "  2 ") {
		score += 2;
		return "  4 ";
	}
	else if (str == "  4 ") {
		score += 4;
		return "  8 ";
	}
	else if (str == "  8 ") {
		score += 8;
		return " 16 ";
	}
	else if (str == " 16 ") {
		score += 16; 
		return " 32 ";
	}
	else if (str == " 32 ") {
		score += 32;
		return " 64 ";
	}
	else if (str == " 64 ") {
		score += 64;
		return " 128";
	}
	else if (str == " 128") {
		score += 128;
		return " 256";
	}
	else if (str == " 256") {
		score += 256;
		return " 512";
	}
	else if (str == " 512") {
		score += 512;
		return "1024";
	}
	else if (str == "1024") {
		score += 1024;
		return "2048";
	}
	else if (str == "2048") {
		score += 2048;
		return "4096";
	}
	else {
		return "0000";
	}
}

void table::random() {
	int times = 0;
	while (times < 1) {
		int i = rand() % 4;
		int j = rand() % 4;
		int num = rand() % 2;
		if (mytab[i][j] == "    ") {
			if (num == 0) mytab[i][j] = "  2 ";
			else mytab[i][j] = "  4 ";
			times++;
		}
	}
}

table::table() {
		
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mytab[i][j] = "    ";
		}
	}
	random();
	random();
}

void table::Draw() {

	if (!win()) {
		
		system("cls");
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 21; j++) {

				if (i % 2 == 0) {
					if (j == 20) cout << "-" << endl;
					else cout << "-";
				}
				else if (j % 5 == 0) {
					if (j == 20) cout << "|" << endl;
					else cout << "|";
				}
				else {
					cout << mytab[(int)i / 2][(int)(j - 1) / 5];
					j += 3;
				}
			}
		}

		if (!lose()) {
			cout << endl;
			cout << "Your score is: " << score << endl;
		}
		else {
			cout << endl;
			cout << "No more moves are left :(" << endl << "Your score is: " << score << endl;
		}	
	}

	else {
		cout << endl;
		cout << "Congratulations, you reached 4096!!! Your score is: " << score << endl;
	}
}

void table::Down() {
	
	for (int j = 0; j < 4; j++) {
		if (mytab[0][j] != "    " || mytab[1][j] != "    " || mytab[2][j] != "    " || mytab[3][j] != "    ") {
			bool moved = false;
			do {
				moved = false;
				for (int i = 2; i >= 0; i--) {
					if (mytab[i][j] != "    " && mytab[i + 1][j] == "    ") {
						mytab[i + 1][j] = mytab[i][j];
						mytab[i][j] = "    ";
						moved = true;
					}
					else if (mytab[i][j] == mytab[i + 1][j] && mytab[i][j] != "    ") {
						mytab[i + 1][j] = change(mytab[i][j]);
						mytab[i][j] = "    ";
					}
				}
			} while (moved);
		}
	}
}

void table::Up() {
	
	for (int j = 0; j < 4; j++) {
		if (mytab[0][j] != "    " || mytab[1][j] != "    " || mytab[2][j] != "    " || mytab[3][j] != "    ") {
			bool moved = false;
			do {
				moved = false;
				for (int i = 0; i < 3; i++) {
					if (mytab[i][j] == "    " && mytab[i + 1][j] != "    ") {
						mytab[i][j] = mytab[i+1][j];
						mytab[i+1][j] = "    ";
						moved = true;
					}
					else if (mytab[i][j] == mytab[i + 1][j] && mytab[i][j] != "    ") {
						mytab[i][j] = change(mytab[i+1][j]);
						mytab[i+1][j] = "    ";
					}
				}
			} while (moved);
		}
	}
}

void table::Left() {
	for (int i = 0; i < 4; i++) {
		if (mytab[i][0] != "    " || mytab[i][1] != "    " || mytab[i][2] != "    " || mytab[i][3] != "    ") {
			bool moved = false;
			do {
				moved = false;
				for (int j = 0; j < 3; j++) {
					if (mytab[i][j] == "    " && mytab[i][j+1] != "    ") {
						mytab[i][j] = mytab[i][j+1];
						mytab[i][j+1] = "    ";
						moved = true;
					}
					else if (mytab[i][j] == mytab[i][j+1] && mytab[i][j+1] != "    ") {
						mytab[i][j] = change(mytab[i][j+1]);
						mytab[i][j+1] = "    ";
					}
				}
			} while (moved);
		}
	}
}

void table::Right() {
	
	for (int i = 0; i < 4; i++) {
		if (mytab[i][0] != "    " || mytab[i][1] != "    " || mytab[i][2] != "    " || mytab[i][3] != "    ") {
			bool moved = false;
			do {
				moved = false;
				for (int j = 2; j >= 0; j--) {
					if (mytab[i][j] != "    " && mytab[i][j + 1] == "    ") {
						mytab[i][j+1] = mytab[i][j];
						mytab[i][j] = "    ";
						moved = true;
					}
					else if (mytab[i][j] == mytab[i][j + 1] && mytab[i][j + 1] != "    ") {
						mytab[i][j+1] = change(mytab[i][j]);
						mytab[i][j] = "    ";
					}
				}
			} while (moved);
		}
	}
}

void table::Input() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			Left();
			random();
			Draw();
			break;
		case 'd':
			Right();
			random();
			Draw();
			break;
		case 'w':
			Up();
			random();
			Draw();
			break;
		case 's':
			Down();
			random();
			Draw();
			break;
		default:
			break;
		}
	}
}