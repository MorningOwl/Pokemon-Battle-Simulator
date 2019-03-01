#include "Pokemon.h"
#include <iostream>

#define next system("pause"); system("cls")

using namespace std;


void Pokemon::initPokemon(ID Name)
{
	switch (Name)
	{
	case BULBASAUR:
		this->p_name = "BULBASAUR";
		this->p_type1 = GRASS;
		this->p_type1Name = "Grass";
		this->p_type2 = POISON;
		this->p_type2Name = "Poison";
		this->p_HP = 19;
		this->p_attack = 8;
		this->p_defense = 8;
		this->p_speed = 8;
		this->p_moveID[1] = GROWL;
		this->p_moveID[2] = TACKLE;
		this->p_moveID[3] = NONE;
		this->p_moveID[4] = NONE;
		break;

	case CHARMANDER:
		this->p_name = "CHARMANDER";
		this->p_type1 = FIRE;
		this->p_type1Name = "Fire";
		this->p_type2 = _;
		this->p_HP = 18;
		this->p_attack = 9;
		this->p_defense = 8;
		this->p_speed = 9;
		this->p_moveID[1] = SCRATCH;
		this->p_moveID[2] = GROWL;
		this->p_moveID[3] = NONE;
		this->p_moveID[4] = NONE;
		break;

	case SQUIRTLE:
		this->p_name = "SQUIRTLE";
		this->p_type1 = WATER;
		this->p_type1Name = "Water";
		this->p_type2 = _;
		this->p_HP = 19;
		this->p_attack = 8;
		this->p_defense = 9;
		this->p_speed = 8;
		this->p_moveID[1] = TACKLE;
		this->p_moveID[2] = TAILWHIP;
		this->p_moveID[3] = NONE;
		this->p_moveID[4] = NONE;
		break;

	case PIDGEY:
		this->p_name = "PIDGEY";
		this->p_type1 = NORMAL;
		this->p_type1Name = "Normal";
		this->p_type2 = FLYING;
		this->p_type2Name = "Flying";
		this->p_HP = 19;
		this->p_attack = 8;
		this->p_defense = 8;
		this->p_speed = 7;
		this->p_moveID[1] = TACKLE;
		this->p_moveID[2] = SANDATTACK;
		this->p_moveID[3] = GUST;
		this->p_moveID[4] = NONE;
		this->p_numMoves = 3;
		break;

	case RATTATA:
		this->p_name = "RATTATA";
		this->p_type1 = NORMAL;
		this->p_type1Name = "Normal";
		this->p_type2 = _;
		this->p_HP = 18;
		this->p_attack = 9;
		this->p_defense = 7;
		this->p_speed = 10;
		this->p_moveID[1] = TACKLE;
		this->p_moveID[2] = TAILWHIP;
		this->p_moveID[3] = NONE;
		this->p_moveID[4] = NONE;
		break;

	case SPEAROW:
		this->p_name = "SPEAROW";
		this->p_type1 = NORMAL;
		this->p_type1Name = "Normal";
		this->p_type2 = FLYING;
		this->p_type2Name = "Flying";
		this->p_HP = 19;
		this->p_attack = 9;
		this->p_defense = 7;
		this->p_speed = 10;
		this->p_moveID[1] = PECK;
		this->p_moveID[2] = GROWL;
		this->p_moveID[3] = NONE;
		this->p_moveID[4] = NONE;
		break;

		case ODDISH:
			this->p_name = "ODDISH";
			this->p_type1 = GRASS;
			this->p_type1Name = "Grass";
			this->p_type2 = POISON;
			this->p_type2Name = "Poison";
			this->p_HP = 19;
			this->p_attack = 9;
			this->p_defense = 9;
			this->p_speed = 7;
			this->p_moveID[1] = ABSORB;
			this->p_moveID[2] = GROWTH;
			this->p_moveID[3] = NONE;
			this->p_moveID[4] = NONE;
			break;
	}

	this->p_ID = Name;
	this->p_HPMax = this->p_HP;
	this->p_attackMax = this->p_attack;
	this->p_attackInitial = this->p_attack;
	this->p_defenseMax = this->p_defense;
	this->p_defenseInitial = this->p_defense;
	this->p_speedMax = this->p_speed;
	this->p_speedInitial = this->p_speed;

	initMoves();
}

void Pokemon::initMoves()
{
	for (int i = 1; i < 5; i++)
		switch (this->p_moveID[i])
		{
			case TACKLE:
				this->p_moveName[i] = "Tackle";
				this->p_moveType[i] = NORMAL;
				this->p_moveEffect[i] = PHYSICAL;
				this->p_movePP[i] = 35;
				break;

			case GROWL:
				this->p_moveName[i] = "Growl";
				this->p_moveType[i] = NORMAL;
				this->p_moveEffect[i] = STATUS;
				this->p_movePP[i] = 40;
				break;

			case SCRATCH:
				this->p_moveName[i] = "Scratch";
				this->p_moveType[i] = NORMAL;
				this->p_moveEffect[i] = PHYSICAL;
				this->p_movePP[i] = 35;
				break;

			case TAILWHIP:
				this->p_moveName[i] = "Tail Whip";
				this->p_moveType[i] = NORMAL;
				this->p_moveEffect[i] = STATUS;
				this->p_movePP[i] = 35;
				break;

			case SANDATTACK:
				this->p_moveName[i] = "Sand Attack";
				this->p_moveType[i] = GROUND;
				this->p_moveEffect[i] = STATUS;
				this->p_movePP[i] = 15;
				break;

			case GUST:
				this->p_moveName[i] = "Gust";
				this->p_moveType[i] = FLYING;
				this->p_moveEffect[i] = PHYSICAL;
				this->p_movePP[i] = 35;
				break;

			case PECK:
				this->p_moveName[i] = "Peck";
				this->p_moveType[i] = FLYING;
				this->p_moveEffect[i] = PHYSICAL;
				this->p_movePP[i] = 35;
				break;

			case ABSORB:
				this->p_moveName[i] = "Absorb";
				this->p_moveType[i] = GRASS;
				this->p_moveEffect[i] = PHYSICAL;
				this->p_movePP[i] = 25;
				break;
			
			case GROWTH:
				this->p_moveName[i] = "Growth";
				this->p_moveType[i] = NORMAL;
				this->p_moveEffect[i] = STATUS;
				this->p_movePP[i] = 40;
				break;
		}

	for (int i = 1; i <= this->p_numMoves; i++)
		this->p_movePPMax[i] = this->p_movePP[i];
}

void Pokemon::move1(Pokemon &pkmn, Pokemon &foe)
{
	if (this->p_movePP[1] <= 0)
	{
		cout << "That move can no longer be used!\n\n";
		next;
		return;
	}

	switch (this->p_moveID[1])
	{
		case TACKLE: this->tackle(foe); break;
		case GROWL: this->growl(foe); break;
		case SCRATCH: this->scratch(foe); break;
		case TAILWHIP: this->tailWhip(foe); break;
		case SANDATTACK: this->sandAttack(foe); break;
		case GUST: this->gust(foe); break;
		case PECK: this->peck(foe); break;
		case ABSORB: this->absorb(foe); break;
		case GROWTH: this->growth(pkmn); break;
	}

	this->p_movePP[1]--;
}

void Pokemon::move2(Pokemon &pkmn, Pokemon &foe)
{
	if (this->p_movePP[2] <= 0)
	{
		cout << "That move can no longer be used!\n\n";
		next;
		return;
	}

	switch (this->p_moveID[2])
	{
		case TACKLE: this->tackle(foe); break;
		case GROWL: this->growl(foe); break;
		case SCRATCH: this->scratch(foe); break;
		case TAILWHIP: this->tailWhip(foe); break;
		case SANDATTACK: this->sandAttack(foe); break;
		case GUST: this->gust(foe); break;
		case PECK: this->peck(foe); break;
		case ABSORB: this->absorb(foe); break;
		case GROWTH: this->growth(pkmn); break;
	}

	this->p_movePP[2]--;
}

void Pokemon::move3(Pokemon &pkmn, Pokemon &foe)
{
	if (this->p_movePP[3] <= 0)
	{
		cout << "That move can no longer be used!\n\n";
		next;
		return;
	}

	switch (this->p_moveID[3])
	{
		case TACKLE: this->tackle(foe); break;
		case GROWL: this->growl(foe); break;
		case SCRATCH: this->scratch(foe); break;
		case TAILWHIP: this->tailWhip(foe); break;
		case SANDATTACK: this->sandAttack(foe); break;
		case GUST: this->gust(foe); break;
		case PECK: this->peck(foe); break;
		case ABSORB: this->absorb(foe); break;
		case GROWTH: this->growth(pkmn); break;
	}

	this->p_movePP[3]--;
}

void Pokemon::move4(Pokemon &pkmn, Pokemon &foe)
{
	if (this->p_movePP[4] <= 0)
	{
		cout << "That move can no longer be used!\n\n";
		next;
		return;
	}

	switch (this->p_moveID[4])
	{
		case TACKLE: this->tackle(foe); break;
		case GROWL: this->growl(foe); break;
		case SCRATCH: this->scratch(foe); break;
		case TAILWHIP: this->tailWhip(foe); break;
		case SANDATTACK: this->sandAttack(foe); break;
		case GUST: this->gust(foe); break;
		case PECK: this->peck(foe); break;
		case ABSORB: this->absorb(foe); break;
		case GROWTH: this->growth(pkmn); break;
	}

	this->p_movePP[4]--;
}