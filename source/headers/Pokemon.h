#pragma once
#include <string>

enum GameMode { MENU, CLASSIC, MULTIPLAYER, ENDLESS, CAMPAIGN };
enum PID { BULBASAUR, CHARMANDER, SQUIRTLE, PIDGEY, RATTATA, SPEAROW, ODDISH, GEODUDE, PIKACHU, BIDOOF };
enum Type { _, NORMAL, GRASS, FIRE, WATER, POISON, FLYING, GROUND, ROCK, ELECTRIC };
enum MID { NONE, TACKLE, GROWL, SCRATCH, TAILWHIP, SANDATTACK, GUST, PECK, ABSORB, GROWTH, DEFENSECURL, THUNDERSHOCK };
enum I_ID { EMPTY, POTION, ETHER, XATTACK, XDEFENSE, POKEBALL };
enum Effect { PHYSICAL, SPECIAL, STATUS, DAMAGE };
enum Ability { STATIC };


class Move
{
public:
	MID m_ID = NONE;
	Effect m_effect;
	Effect m_cat = STATUS;
	Type m_type;
	const char* m_name;
	int m_PP, m_PPMax;
};


class Item
{
public:
	I_ID i_ID = EMPTY;
	const char* i_name;
	int i_num;

	void operator=(Item item);
};


class Pokemon
{
public:
	//Definitive Stats
	const char* p_name;
	PID p_ID;
	Type p_type1, p_type2;
	Ability p_ability1, p_ability2;
	const char* p_type1Name;
	const char* p_type2Name;
	int p_level = 5;

	int p_numMoves = 2;
	Move p_move[5];

	//Variable Stats
	int p_HP, p_HPMax;
	int p_attack, p_attackMax, p_attackInitial;
	int p_defense, p_defenseMax, p_defenseInitial;
	int p_spAttack, p_spAttackMax, p_spAttackInitial;
	int p_spDefense, p_spDefenseMax, p_spDefenseInitial;
	int p_speed, p_speedMax, p_speedInitial;

	double p_accuracy = 1;
	double p_evasion = 1;

	int p_attackLevel = 0;
	int p_defenseLevel = 0;
	int p_spAttackLevel = 0;
	int p_spDefenseLevel = 0;
	int p_accuracyLevel = 0;
	int p_evasionLevel = 0;

	//Status Effects
	bool isParalized = false;
	int paralysis_count = 0;

	//Initialization
	void initPokemon(PID Name);
	void initMoves();

	//Moves
	void tackle(Pokemon &foe);
	void growl(Pokemon &foe);
	void scratch(Pokemon &foe);
	void tailWhip(Pokemon &foe);
	void sandAttack(Pokemon &foe);
	void gust(Pokemon &foe);
	void peck(Pokemon &foe);
	void absorb(Pokemon &foe);
	void growth(Pokemon &pkmn);
	void defenseCurl(Pokemon &pkmn);
	void thunderShock(Pokemon &foe);

	void move(int moveNum, Pokemon &pkmn, Pokemon &foe);

	//Dependencies
	void changeStat(Pokemon &target, const char* stat, int det);

	double stab(Type moveType);
	double typeDamage(Pokemon &foe, Type moveType);
	double modifier(Pokemon &foe, Type moveType);
	double damage(Pokemon &foe, int power, Type moveType, Effect moveEffect);

	void operator=(Pokemon pkmn);		//Update these whenever updating 
	bool operator==(Pokemon pkmn);		//Pokemon attributes

	void refresh();
};


class Player
{
public:
	int y, x;
	Item bag[6];
	Pokemon pkmn, Pkmn[7];

	int numPkmn = 1;
	int numItems = 4;
	bool battleEnd = false;

	bool potions, ethers;
	bool xAttacks, xDefenses;
	bool pokeBalls;

	bool potion();
	bool ether();
	bool XAttack();
	bool XDefense();
	bool pokeBall(Pokemon &foe);

	Player(int y, int  x) :x(x), y(y) {};
	void initPlayer(GameMode mode);
	void logItemInfo(Item item);
	bool item(int itemNum, Pokemon &foe);
};


/*
	~~~ADDING NEW POKEMON~~~
	-Add name to ID enum
	-Add stats to initPokemon()
	-Add option to selection screen
	*Ensure type effectiveness is accounted for


	~~~ADDING NEW MOVES~~~
	-Add name to Move enum
	-Add function to Moves.cpp
	-Add stats to initMoves()
	-Add name to move function
	-Add info to logMoveInfo()
*/