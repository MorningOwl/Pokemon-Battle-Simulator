#include "Pokemon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


double criticalHit()
{
	srand(time(0));
	int det = (1 + rand() % 10000 <= 625) ? 2 : 1;

	if (det == 2)
	{
		system("pause");
		system("cls");
		cout << "A critical hit!\n\n";
	}

	return det;
}

double random()
{
	srand(time(0));
	double random = 85 + rand() % 16;
	return random / 100;
}

double Pokemon::stab(Type moveType)
{
	return (moveType == this->p_type1 || moveType == this->p_type2) ? 1.5 : 1;
}

double Pokemon::typeDamage(Pokemon &foe, Type moveType)
{
	double det = 0;

	if (foe.p_type1 == GRASS || foe.p_type2 == GRASS)
	{
		if (moveType == FIRE || moveType == FLYING) det = 2;
		else if (moveType == WATER || moveType == GRASS) det = 0.5;
	}


	else if (foe.p_type1 == WATER || foe.p_type2 == WATER)
	{
		if (moveType == GRASS) det = 2;
		else if (moveType == FIRE || moveType == WATER) det = 0.5;
	}


	if (foe.p_type1 == FIRE || foe.p_type2 == FIRE)
	{
		if (moveType == WATER) det = 2;
		else if (moveType == GRASS || moveType == FIRE) det = 0.5;
	}

	else if (foe.p_type1 == FLYING || foe.p_type2 == FLYING)
	{
		if (moveType == GRASS) det = 0.5;
	}

	if (det == 2)
	{
		system("pause");
		system("cls");
		cout << "It's super effective!\n\n";
		return det;
	}

	if (det == 0.5)
	{
		system("pause");
		system("cls");
		cout << "It's not very effective...\n\n";
		return det;
	}

	return 1;
}

double Pokemon::modifier(Pokemon &foe, Type moveType)
{
	return criticalHit() * random() * this->stab(moveType) * this->typeDamage(foe, moveType);
}

double Pokemon::damage(Pokemon &foe, int power, Type moveType)
{
	return ((((2 * this->p_level) / 5 + 2) * power * (this->p_attack / foe.p_defense)) / 50 + 2) * this->modifier(foe, moveType);
}