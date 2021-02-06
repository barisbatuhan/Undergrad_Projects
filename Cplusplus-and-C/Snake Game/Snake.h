#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Snake {

public:

	Snake();
	void Input();
	void Move();
	bool End();
	void Draw();
	void Direction();
	void Fruit();
	void Conditions();
	void First();
	void TurnTrue();
	int Score();

private:

	int x, y;
	bool gameover;
	string map[23][23];
	enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
	eDirecton dir;
	int tail;
	int tailX[121];
	int tailY[121];
	int frx, fry;
	int lfx, lfy;
	int temp1, temp2, temp3, temp4;
};