#include "Pokemon.h"
#include <iostream>
#include <cstdlib>

using namespace std;


void Pokemon::changeStat(Pokemon &target, const char* stat, int det)
{
	switch (det)
	{
	case -2:
		if (stat == "attack") target.p_attackLevel -= 2, cout << target.p_name << " 's Attack harshly fell!\n\n";
		else if (stat == "defense") target.p_defenseLevel -= 2, cout << target.p_name << " 's Defense harshly fell!\n\n";
		else if (stat == "spAttack") target.p_attackLevel -= 2, target.p_spAttackLevel -= 2, cout << target.p_name << " 's Attack and Sp. Atk harshly fell!\n\n";
		else if (stat == "spDefense") target.p_defenseLevel -= 2, target.p_spDefenseLevel -= 2, cout << target.p_name << " 's Defense and Sp. Def harshly fell!\n\n";
		else if (stat == "accuracy") target.p_accuracyLevel -= 2, cout << target.p_name << " 's Accuracy harshly fell!\n\n";
		else if (stat == "evasion") target.p_evasionLevel -= 2, cout << target.p_name << " 's Evasiness harshly fell!\n\n";
		break;

	case -1:
		if (stat == "attack") target.p_attackLevel--, cout << target.p_name << " 's Attack fell!\n\n";
		else if (stat == "defense") target.p_defenseLevel--, cout << target.p_name << " 's Defense fell!\n\n";
		else if (stat == "spAttack") target.p_attackLevel--, target.p_spAttackLevel--, cout << target.p_name << " 's Attack and Sp. Atk fell!\n\n";
		else if (stat == "spDefense") target.p_defenseLevel--, target.p_spDefenseLevel--, cout << target.p_name << " 's Defense and Sp. Def fell!\n\n";
		else if (stat == "accuracy") target.p_accuracyLevel--, cout << target.p_name << " 's Accuracy fell!\n\n";
		else if (stat == "evasion") target.p_evasionLevel--, cout << target.p_name << " 's Evasiness fell!\n\n";
		break;

	case 1:
		if (stat == "attack") target.p_attackLevel++, cout << target.p_name << " 's Attack rose!\n\n";
		else if (stat == "defense") target.p_defenseLevel++, cout << target.p_name << " 's Defense rose!\n\n";
		else if (stat == "spAttack") target.p_attackLevel++, target.p_spAttackLevel++, cout << target.p_name << " 's Attack and Sp. Atk rose!\n\n";
		else if (stat == "spDefense") target.p_defenseLevel++, target.p_spDefenseLevel++, cout << target.p_name << " 's Defense and Sp. Def rose!\n\n";
		else if (stat == "accuracy") target.p_accuracyLevel++, cout << target.p_name << " 's Accuracy rose!\n\n";
		else if (stat == "evasion") target.p_evasionLevel++, cout << target.p_name << " 's Evasiness rose!\n\n";
		break;

	case 2:
		if (stat == "attack") target.p_attackLevel += 2, cout << target.p_name << " 's Attack sharply rose!\n\n";
		else if (stat == "defense") target.p_defenseLevel += 2, cout << target.p_name << " 's Defense sharply rose!\n\n";
		else if (stat == "spAttack") target.p_attackLevel += 2, target.p_spAttackLevel += 2, cout << target.p_name << " 's Attack and Sp. Atk sharply rose!\n\n";
		else if (stat == "spDefense") target.p_defenseLevel += 2, target.p_spDefenseLevel += 2, cout << target.p_name << " 's Defense and Sp. Def sharply rose!\n\n";
		else if (stat == "accuracy") target.p_accuracyLevel += 2, cout << target.p_name << " 's Accuracy sharply rose!\n\n";
		else if (stat == "evasion") target.p_evasionLevel += 2, cout << target.p_name << " 's Evasiness sharply rose!\n\n";
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

	if (stat == "spAttack")
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

		switch (target.p_spAttackLevel)
		{
		case -6: target.p_spAttack = 0.25 * target.p_spAttackInitial; break;
		case -5: target.p_spAttack = 0.28 * target.p_spAttackInitial; break;
		case -4: target.p_spAttack = 0.33 * target.p_spAttackInitial; break;
		case -3: target.p_spAttack = 0.40 * target.p_spAttackInitial; break;
		case -2: target.p_spAttack = 0.50 * target.p_spAttackInitial; break;
		case -1: target.p_spAttack = 0.66 * target.p_spAttackInitial; break;
		case 0: target.p_spAttack = target.p_spAttackInitial; break;
		case 1: target.p_spAttack = 1.50 * target.p_spAttackInitial; break;
		case 2: target.p_spAttack = 2.00 * target.p_spAttackInitial; break;
		case 3: target.p_spAttack = 2.50 * target.p_spAttackInitial; break;
		case 4: target.p_spAttack = 3.00 * target.p_spAttackInitial; break;
		case 5: target.p_spAttack = 3.50 * target.p_spAttackInitial; break;
		case 6: target.p_spAttack = 4.00 * target.p_spAttackInitial; break;
		}
	}

	else if (stat == "spDefense")
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

		switch (target.p_spDefenseLevel)
		{
		case -6: target.p_spDefense = 0.25 * target.p_spDefenseInitial; break;
		case -5: target.p_spDefense = 0.28 * target.p_spDefenseInitial; break;
		case -4: target.p_spDefense = 0.33 * target.p_spDefenseInitial; break;
		case -3: target.p_spDefense = 0.40 * target.p_spDefenseInitial; break;
		case -2: target.p_spDefense = 0.50 * target.p_spDefenseInitial; break;
		case -1: target.p_spDefense = 0.66 * target.p_spDefenseInitial; break;
		case 0: target.p_spDefense = target.p_spDefenseInitial; break;
		case 1: target.p_spDefense = 1.50 * target.p_spDefenseInitial; break;
		case 2: target.p_spDefense = 2.00 * target.p_spDefenseInitial; break;
		case 3: target.p_spDefense = 2.50 * target.p_spDefenseInitial; break;
		case 4: target.p_spDefense = 3.00 * target.p_spDefenseInitial; break;
		case 5: target.p_spDefense = 3.50 * target.p_spDefenseInitial; break;
		case 6: target.p_spDefense = 4.00 * target.p_spDefenseInitial; break;
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