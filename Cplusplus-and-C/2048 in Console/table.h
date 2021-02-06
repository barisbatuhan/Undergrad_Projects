#include <iostream>
#include <vector>
using namespace std;

class table {

public:
	table();
	void Draw();
	void Input();

private:
	void random();
	void Down();
	void Up();
	void Left();
	void Right();
	bool win();
	bool lose();
	string mytab[4][4];

};
