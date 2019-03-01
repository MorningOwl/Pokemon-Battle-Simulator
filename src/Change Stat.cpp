#include "Pokemon.h"
#include <iostream>
#include <cstdlib>

using namespace std;


void Pokemon::changeStat(Pokemon &target, const char* stat, int det)
{
	switch (det)
	{
		case -2:
			if (stat == "attack") target.p_attackLevel -= 2, cout << target.p_name << " 's attack harshly fell!\n\n";
			else if (stat == "defense") target.p_defenseLevel -= 2, cout << target.p_name << " 's defense harshly fell!\n\n";
			else if (stat == "accuracy") target.p_accuracyLevel -= 2, cout << target.p_name << " 's accuracy harshly fell!\n\n";
			else if (stat == "evasion") target.p_evasionLevel -= 2, cout << target.p_name << " 's evasiness harshly fell!\n\n";
			break;

		case -1:
			if (stat == "attack") target.p_attackLevel--, cout << target.p_name << " 's attack fell!\n\n";
			else if (stat == "defense") target.p_defenseLevel--, cout << target.p_name << " 's defense fell!\n\n";
			else if (stat == "accuracy") target.p_accuracyLevel--, cout << target.p_name << " 's accuracy fell!\n\n";
			else if (stat == "evasion") target.p_evasionLevel--, cout << target.p_name << " 's evasiness fell!\n\n";
			break;

		case 1:
			if (stat == "attack") target.p_attackLevel++, cout << target.p_name << " 's attack rose!\n\n";
			else if (stat == "defense") target.p_defenseLevel++, cout << target.p_name << " 's defense rose!\n\n";
			else if (stat == "accuracy") target.p_accuracyLevel++, cout << target.p_name << " 's accuracy rose!\n\n";
			else if (stat == "evasion") target.p_evasionLevel++, cout << target.p_name << " 's evasiness rose!\n\n";
			break;

		case 2:
			if (stat == "attack") target.p_attackLevel += 2, cout << target.p_name << " 's attack sharply rose!\n\n";
			else if (stat == "defense") target.p_defenseLevel += 2, cout << target.p_name << " 's defense sharply rose!\n\n";
			else if (stat == "accuracy") target.p_accuracyLevel += 2, cout << target.p_name << " 's accuracy sharply rose!\n\n";
			else if (stat == "evasion") target.p_evasionLevel += 2, cout << target.p_name << " 's evasiness sharply rose!\n\n";
			break;
	}

	system("pause");
	system("cls");

	if (stat == "attack")
	{
		switch (target.p_attackLevel)
		{
			case -6: target.p_attack = 0.25 * target.p_attackInitial; break;
			case -5: target.p_attack = 0.28 * target.p_attackInitial; break;
			case -4: target.p_attack = 0.33 * target.p_attackInitial; break;
			case -3: target.p_attack = 0.40 * target.p_attackInitial; break;
			case -2: target.p_attack = 0.50 * target.p_attackInitial; break;
			case -1: target.p_attack = 0.66 * target.p_attackInitial; break;
			case 0: target.p_attack = target.p_attackInitial; break;
			case 1: target.p_attack = 1.50 * target.p_attackInitial; break;
			case 2: target.p_attack = 2.00 * target.p_attackInitial; break;
			case 3: target.p_attack = 2.50 * target.p_attackInitial; break;
			case 4: target.p_attack = 3.00 * target.p_attackInitial; break;
			case 5: target.p_attack = 3.50 * target.p_attackInitial; break;
			case 6: target.p_attack = 4.00 * target.p_attackInitial; break;
		}
	}

	else if (stat == "defense")
	{
		switch (target.p_defenseLevel)
		{
			case -6: target.p_defense = 0.25 * target.p_defenseInitial; break;
			case -5: target.p_defense = 0.28 * target.p_defenseInitial; break;
			case -4: target.p_defense = 0.33 * target.p_defenseInitial; break;
			case -3: target.p_defense = 0.40 * target.p_defenseInitial; break;
			case -2: target.p_defense = 0.50 * target.p_defenseInitial; break;
			case -1: target.p_defense = 0.66 * target.p_defenseInitial; break;
			case 0: target.p_defense = target.p_defenseInitial; break;
			case 1: target.p_defense = 1.50 * target.p_defenseInitial; break;
			case 2: target.p_defense = 2.00 * target.p_defenseInitial; break;
			case 3: target.p_defense = 2.50 * target.p_defenseInitial; break;
			case 4: target.p_defense = 3.00 * target.p_defenseInitial; break;
			case 5: target.p_defense = 3.50 * target.p_defenseInitial; break;
			case 6: target.p_defense = 4.00 * target.p_defenseInitial; break;
		}
	}

	else if (stat == "accuracy")
	{
		switch (target.p_accuracyLevel)
		{
			case -6: target.p_accuracy = 0.33; break;
			case -5: target.p_accuracy = 0.36; break;
			case -4: target.p_accuracy = 0.43; break;
			case -3: target.p_accuracy = 0.50; break;
			case -2: target.p_accuracy = 0.60; break;
			case -1: target.p_accuracy = 0.75; break;
			case 0: target.p_accuracy = 1; break;
			case 1: target.p_accuracy = 1.33; break;
			case 2: target.p_accuracy = 1.36; break;
			case 3: target.p_accuracy = 2.00; break;
			case 4: target.p_accuracy = 2.33; break;
			case 5: target.p_accuracy = 2.36; break;
			case 6: target.p_accuracy = 3.00; break;
		}
	}

	else if (stat == "evasion")
	{
		switch (target.p_evasionLevel)
		{
			case -6: target.p_evasion = 0.33; break;
			case -5: target.p_evasion = 0.36; break;
			case -4: target.p_evasion = 0.43; break;
			case -3: target.p_evasion = 0.50; break;
			case -2: target.p_evasion = 0.60; break;
			case -1: target.p_evasion = 0.75; break;
			case 0: target.p_evasion = 1; break;
			case 1: target.p_evasion = 1.33; break;
			case 2: target.p_evasion = 1.36; break;
			case 3: target.p_evasion = 2.00; break;
			case 4: target.p_evasion = 2.33; break;
			case 5: target.p_evasion = 2.36; break;
			case 6: target.p_evasion = 3.00; break;
		}
	}
}