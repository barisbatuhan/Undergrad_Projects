#include <iostream>
#include <string>
#include <vector>
#include "table.h"
using namespace std;

int main() {

	table x;
	x.Draw();
	while (true) {
		x.Input();
	}
	
	cin.get();
	cin.ignore();
	return 0;
}