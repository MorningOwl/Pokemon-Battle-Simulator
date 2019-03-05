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
	double det = 1;

	if (foe.p_type1 == GRASS || foe.p_type2 == GRASS)
	{
		if (moveType == FIRE || moveType == FLYING) det = 2;
		else if (moveType == GRASS || moveType == WATER || moveType == ELECTRIC) det = 0.5;
		else if (moveType == GROUND)
		{
			if (foe.p_type1 == POISON || foe.p_type2 == POISON) det = 1;
			else det = 2;
		}
	}


	else if (foe.p_type1 == WATER || foe.p_type2 == WATER)
	{
		if (moveType == GRASS || moveType == ELECTRIC) det = 2;
		else if (moveType == WATER || moveType == FIRE) det = 0.5;
	}


	else if (foe.p_type1 == FIRE || foe.p_type2 == FIRE)
	{
		if (moveType == WATER || moveType == GROUND) det = 2;
		else if (moveType == FIRE || moveType == GRASS) det = 0.5;
	}

	else if (foe.p_type1 == FLYING || foe.p_type2 == FLYING)
	{
		if (moveType == ELECTRIC) det = 2;
		else if (moveType == FLYING || moveType == GRASS) det = 0.5;
		else if (moveType == GROUND) det = 0;
	}

	else if (foe.p_type1 == ROCK || foe.p_type2 == ROCK)
	{
		if (moveType == WATER || moveType == GRASS || moveType == GROUND) det = 2;
		else if (moveType == ROCK || moveType == NORMAL || moveType == ELECTRIC) det = 0.5;
	}

	else if (foe.p_type1 == ELECTRIC || foe.p_type2 == ELECTRIC)
	{
		if (moveType == GROUND) det = 2;
		else if (moveType == ELECTRIC || moveType == FLYING) det = 0.5;
	}

	else if (foe.p_type1 == GROUND || foe.p_type2 == GROUND)
	{
		if (moveType == WATER || moveType == GRASS) det = 2;
		else if (moveType == ROCK) det = 0.5;
		else if (moveType == ELECTRIC) det = 0;
	}

	if (det == 2)
	{
		system("pause");
		system("cls");
		cout << "It's super effective!\n\n";
	}

	else if (det == 0.5)
	{
		system("pause");
		system("cls");
		cout << "It's not very effective...\n\n";
	}

	else if (det == 0)
	{
		system("pause");
		system("cls");
		cout << "It doesn't affect " << foe.p_name << "!\n\n";
	}

	return det;
}

double Pokemon::modifier(Pokemon &foe, Type moveType)
{
	return random() * this->stab(moveType) * this->typeDamage(foe, moveType);
}

double Pokemon::damage(Pokemon &foe, int power, Type moveType, Effect moveEffect)
{
	int atk, def;
	if (moveEffect == PHYSICAL)
		atk = this->p_attack, def = foe.p_defense;
	else if (moveEffect == SPECIAL)
		atk = this->p_spAttack, def = foe.p_spDefense;

	return ((((2 * this->p_level) / 5 + 2) * power * (atk / def)) / 50 + 2) * this->modifier(foe, moveType);
}