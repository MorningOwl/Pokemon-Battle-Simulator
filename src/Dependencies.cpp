#include "Dependencies.h"
#include <iostream>
#include <string>

#define next system("pause"); system("cls")

using namespace std;


//Log Functions
void logMove(Pokemon pkmn, const char* move, int num, bool nextLine)
{
	string space = "";
	
	for (int i = strlen(move); i <= 11; i++)
		space += " ";

	cout << num << "." << pkmn.p_move[num].m_name << " (" << pkmn.p_move[num].m_PP << "/" << pkmn.p_move[num].m_PPMax << ")" << space;
	if (nextLine) cout << "\n"; else cout << "\t";
}

void logName(Pokemon pkmn)
{
	string space = "";

	for (int i = strlen(pkmn.p_name); i < 17; i++)
		space += " ";

	cout << pkmn.p_name << space << pkmn.p_HP << "/" << pkmn.p_HPMax << endl;
}

void logMoveInfo(Pokemon pkmn, Move move)
{
	string space = "";
	int longest = 0;

	for (int i = 1; i <= pkmn.p_numMoves; i++)
		if (strlen(pkmn.p_move[i].m_name) > longest)
			longest = strlen(pkmn.p_move[i].m_name);

	for (int i = strlen(move.m_name); i < longest; i++)
		space += " ";

	cout << move.m_name << ": " << space;

	switch (move.m_ID)
	{
		case TACKLE:
			cout << "A physical attack in which the user charges and slams into the target\n        " << space << "with its whole body.\n\n";
			break;

		case GROWL:
			cout << "The user growls in an endearing way, making the opposing Pokemon less\n       " << space << "wary. This lowers their Attack stat.\n\n";
			break;

		case SCRATCH:
			cout << "Hard, pointed, sharp claws rake the target to inflict damage.\n\n";
			break;

		case TAILWHIP:
			cout << "The user wags its tail cutely, making the opposing Pokemon less wary\n           " << space << "and lowering their Defense stat.\n\n";
			break;

		case SANDATTACK:
			cout << "Sand is hurled in the target's face, reducing the target's accuracy.\n\n";
			break;

		case GUST:
			cout << "A gust of wind is whipped up by wings and launched at the target to\n      " << space << "inflict damage.\n\n";
			break;

		case PECK:
			cout << "The target is jabbed with a sharply pointed beak or horn.\n\n";
			break;

		case ABSORB:
			cout << "A nutrient-draining attack. The user's HP is restored by half the\n        " << space << "damage taken by the target.\n\n";
			break;

		case GROWTH:
			cout << "The user's body grows all at once, raising the Attack and Special\n        " << space << "Attack stats.\n\n";
			break;
	}
}


//Operator Overloads
void Pokemon::operator=(Pokemon pkmn)
{
	this->p_name = pkmn.p_name;
	this->p_ID = pkmn.p_ID;
	this->p_type1 = pkmn.p_type1;
	this->p_type2 = pkmn.p_type2;
	this->p_type1Name = pkmn.p_type1Name;
	this->p_type2Name = pkmn.p_type2Name;
	this->p_level = pkmn.p_level;
	this->p_numMoves = pkmn.p_numMoves;

	for (int i = 1; i < 5; i++)
	{
		this->p_move[i].m_ID = pkmn.p_move[i].m_ID;
		this->p_move[i].m_name = pkmn.p_move[i].m_name;
		this->p_move[i].m_type = pkmn.p_move[i].m_type;
		this->p_move[i].m_effect = pkmn.p_move[i].m_effect;
		this->p_move[i].m_PP = pkmn.p_move[i].m_PP;
		this->p_move[i].m_PPMax = pkmn.p_move[i].m_PPMax;
	}

	this->p_HP = pkmn.p_HP;
	this->p_HPMax = pkmn.p_HPMax;
	this->p_attack = pkmn.p_attack;
	this->p_attackMax = pkmn.p_attackMax;
	this->p_attackInitial = pkmn.p_attackInitial;
	this->p_defense = pkmn.p_defense;
	this->p_defenseMax = pkmn.p_defenseMax;
	this->p_defenseInitial = pkmn.p_defenseInitial;
	this->p_spAttack = pkmn.p_spAttack;
	this->p_spAttackMax = pkmn.p_spAttackMax;
	this->p_spAttackInitial = pkmn.p_spAttackInitial;
	this->p_spDefense = pkmn.p_spDefense;
	this->p_spDefenseMax = pkmn.p_spDefenseMax;
	this->p_spDefenseInitial = pkmn.p_spDefenseInitial;
	this->p_speed = pkmn.p_speed;
	this->p_speedMax = pkmn.p_speedMax;
	this->p_speedInitial = pkmn.p_speedInitial;

	this->p_accuracy = pkmn.p_accuracy;
	this->p_evasion = pkmn.p_evasion;

	this->p_attackLevel = pkmn.p_attackLevel;
	this->p_defenseLevel = pkmn.p_defenseLevel;
	this->p_spAttackLevel = pkmn.p_spAttackLevel;
	this->p_spDefenseLevel = pkmn.p_spDefenseLevel;
	this->p_accuracyLevel = pkmn.p_accuracyLevel;
	this->p_evasionLevel = pkmn.p_evasionLevel;
}

bool Pokemon::operator==(Pokemon pkmn)
{
	if (!(this->p_name == pkmn.p_name && this->p_ID == pkmn.p_ID && this->p_type1 == pkmn.p_type1 && this->p_type2 == pkmn.p_type2 &&
		this->p_type1Name == pkmn.p_type1Name && this->p_type2Name == pkmn.p_type2Name && this->p_level == pkmn.p_level && this->p_numMoves == pkmn.p_numMoves))
		return false;

	for (int i = 1; i < 5; i++)
	{
		if (!(this->p_move[i].m_ID == pkmn.p_move[i].m_ID && this->p_move[i].m_name == pkmn.p_move[i].m_name &&
			this->p_move[i].m_type == pkmn.p_move[i].m_type && this->p_move[i].m_effect == pkmn.p_move[i].m_effect &&
			this->p_move[i].m_PP == pkmn.p_move[i].m_PP && this->p_move[i].m_PPMax == pkmn.p_move[i].m_PPMax))
			return false;
	}

	if (!(this->p_HP == pkmn.p_HP && this->p_HPMax == pkmn.p_HPMax)) return false;
	if (!(this->p_attack == pkmn.p_attack && this->p_attackMax == pkmn.p_attackMax && this->p_attackInitial == pkmn.p_attackInitial)) return false;
	if (!(this->p_defense == pkmn.p_defense && this->p_defenseMax == pkmn.p_defenseMax && this->p_defenseInitial == pkmn.p_defenseInitial)) return false;
	if (!(this->p_spAttack == pkmn.p_spAttack && this->p_spAttackMax == pkmn.p_spAttackMax && this->p_spAttackInitial == pkmn.p_spAttackInitial)) return false;
	if (!(this->p_spDefense == pkmn.p_spDefense && this->p_spDefenseMax == pkmn.p_spDefenseMax && this->p_spDefenseInitial == pkmn.p_spDefenseInitial)) return false;
	if (!(this->p_speed == pkmn.p_speed && this->p_speedMax == pkmn.p_speedMax && this->p_speedInitial == pkmn.p_speedInitial)) return false;

	if (!(this->p_accuracy == pkmn.p_accuracy && this->p_evasion == pkmn.p_evasion)) return false;

	if (!(this->p_attackLevel == pkmn.p_attackLevel && this->p_defenseLevel == pkmn.p_defenseLevel)) return false;
	if (!(this->p_accuracyLevel == pkmn.p_accuracyLevel && this->p_evasionLevel == pkmn.p_evasionLevel)) return false;

	return true;
}


//Campaign Functions
void Pokemon::refresh()
{
	this->p_HP = this->p_HPMax;
	this->p_attack = this->p_attackMax;
	this->p_defense = this->p_defenseMax;
	this->p_spAttack = this->p_spAttackMax;
	this->p_spDefense = this->p_spDefenseMax;
	this->p_speed = this->p_speedMax;
	this->p_accuracy = 1;
	this->p_evasion = 1;
	this->p_attackLevel = 0;
	this->p_defenseLevel = 0;
	this->p_spAttackLevel = 0;
	this->p_spDefenseLevel = 0;
	this->p_accuracyLevel = 0;
	this->p_evasionLevel = 0;
}