#include "Pokemon.h"
#include <iostream>
#include <string>

using namespace std;


void Pokemon::logMove(const char* move, int num, bool nextLine)
{
	string space = "";
	
	for (int i = strlen(move); i <= 11; i++)
		space += " ";

	cout << num << "." << this->p_moveName[num] << " (" << this->p_movePP[num] << "/" << this->p_movePPMax[num] << ")" << space;
	if (nextLine) cout << "\n"; else cout << "\t";
}

void Pokemon::logName()
{
	string space = "";

	for (int i = strlen(this->p_name); i < 17; i++)
		space += " ";

	cout << this->p_name << space << this->p_HP << "/" << this->p_HPMax << endl;
}