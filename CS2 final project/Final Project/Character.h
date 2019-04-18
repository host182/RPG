#ifndef character_h_
#define character_h_
#include <vector>
#include <cmath>
#include "Spell.h"
#include "Item.h"

using std::vector;

class character
{
public:
	string name;
	//order of occupation
	//fighter, mage, rogue, bard
	int occupation[4];
	//order of stats
	//constitution, strength, intelligence, willpower, charisma, alacrity, armor
	int stats[7];
	vector<spell*> learnedSpells;
	vector<item*> itemsInUse;					//these items can only be stat items and maximum number of items = 4
	int maxHealth, currentHealth;
	int maxMana, currentMana;
	int physicalDamage;
	double magicalDamage;
	double damageMultiplier;
	double defence;
	bool isAlly;
	bool isHostile;

	//functions
	character();
	character(string n, int o[], vector<spell*> ls, vector<item*> items, bool ally, bool hostile);
	bool useItem(item* ITEM);
	item* removeItem(int i);
	bool useSpell(spell* SPELL, character* targetCharacter);
	bool useSpell(spell* SPELL);
	void manaRegen();
	void resetCharacter();
	void describeCharacter();
	bool learnSpell(spell* SPELL,int);
	int getCharacterLevel();
	void checkCharacterHealthAndMana();
	bool getAlly();
	void setAlly(bool ally);
	bool getHostile();
	void setHostile(bool hostile);
};

#endif