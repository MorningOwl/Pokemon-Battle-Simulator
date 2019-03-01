#include "Pokemon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define next system("pause"); system("cls")

using namespace std;


void Pokemon::tackle(Pokemon &foe)
{
	srand(time(0));
	int prob = 100 * this->p_accuracy / foe.p_evasion;

	cout << this->p_name << " used Tackle!\n\n";

	if (1 + rand() % 100 <= prob)
		foe.p_HP -= damage(foe, 40, NORMAL);

	else
	{
		next;
		cout << this->p_name << " 's attack missed!\n\n";
	}

	next;
}

void Pokemon::scratch(Pokemon &foe)
{
	srand(time(0));
	int prob = 100 * this->p_accuracy / foe.p_evasion;


	cout << this->p_name << " used Scratch!\n\n";

	if (1 + rand() % 100 <= prob)
		foe.p_HP -= damage(foe, 40, NORMAL);

	else
	{
		next;
		cout << this->p_name << " 's attack missed!\n\n";
	}

	next;
}

void Pokemon::growl(Pokemon &foe)
{
	srand(time(0));
	int prob = 100 * this->p_accuracy / foe.p_evasion;

	cout << this->p_name << " used Growl!\n\n";
	next;

	if (1 + rand() % 100 <= prob)
		changeStat(foe, "attack", -1);

	else
	{
		cout << this->p_name << " 's attack missed!\n\n";
		next;
	}
}

void Pokemon::tailWhip(Pokemon &foe)
{
	srand(time(0));
	int prob = 100 * this->p_accuracy / foe.p_evasion;

	cout << this->p_name << " used Tail Whip!\n\n";
	next;

	if (1 + rand() % 100 <= prob)
		changeStat(foe, "defense", -1);

	else
	{
		cout << this->p_name << " 's attack missed!\n\n";
		next;
	}
}

void Pokemon::sandAttack(Pokemon &foe)
{
	srand(time(0));
	int prob = 100 * this->p_accuracy / foe.p_evasion;

	cout << this->p_name << " used Sand Attack!\n\n";
	next;

	if (1 + rand() % 100 <= prob)
		changeStat(foe, "accuracy", -1);

	else
	{
		cout << this->p_name << " 's attack missed!\n\n";
		next;
	}
}

void Pokemon::gust(Pokemon &foe)
{
	srand(time(0));
	int prob = 100 * this->p_accuracy / foe.p_evasion;

	cout << this->p_name << " used Gust!\n\n";

	if (1 + rand() % 100 <= prob)
		foe.p_HP -= damage(foe, 40, FLYING);

	else
	{
		next;
		cout << this->p_name << " 's attack missed!\n\n";
	}

	next;
}

void Pokemon::peck(Pokemon &foe)
{
	srand(time(0));
	int prob = 100 * this->p_accuracy / foe.p_evasion;

	cout << this->p_name << " used Peck!\n\n";

	if (1 + rand() % 100 <= prob)
		foe.p_HP -= damage(foe, 35, FLYING);

	else
	{
		next;
		cout << this->p_name << " 's attack missed!\n\n";
	}

	next;
}

void Pokemon::absorb(Pokemon &foe)
{
	srand(time(0));
	int prob = 100 * this->p_accuracy / foe.p_evasion;

	cout << this->p_name << " used Absorb!\n\n";

	if (1 + rand() % 100 <= prob)
	{
		int temp = damage(foe, 20, GRASS);
		foe.p_HP -= temp;

		if (this->p_HP < p_HPMax - temp)
			this->p_HP += temp / 2;

		else
			this->p_HP = this->p_HPMax;

		next;
		cout << foe.p_name << " had it's energy drained!\n\n";
	}

	else
	{
		next;
		cout << this->p_name << " 's attack missed!\n\n";
	}

	next;
}

void Pokemon::growth(Pokemon &pkmn)
{
	srand(time(0));

	cout << this->p_name << " used Growth!\n\n";
	next;

	changeStat(pkmn, "attack", 1);
}