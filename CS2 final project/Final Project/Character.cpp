#include "Character.h"

//I only set this constructor because the compiler wanted one
character::character() {}

character::character(string n, int o[], vector<spell*> ls, vector<item*> items, bool ally, bool hostile)
{
	name = n, learnedSpells = ls, itemsInUse = items;
	for (int i = 0; i < 4; i++)
		occupation[i] = o[i];
	for (int i = 0; i < 7; i++)
	{
		stats[i] = 1;
		for (int j = 0; j < items.size(); j++)
			stats[i] += items[j]->getItemStat()[i];
	}
	maxHealth = currentHealth = stats[0] * 10 + 40;
	maxMana = stats[2] * 20 + 20;
	currentMana = 0;
	physicalDamage = 20 + stats[1] * 5;
	magicalDamage = stats[3] / (5 + stats[3]);
	damageMultiplier = 1;
	defence = (1 - exp(-0.1*stats[6])) / (1 + exp(-0.1*stats[6]));
	isAlly = ally, isHostile = hostile;
}


bool character::useItem(item* ITEM)
{
		string EFFECT = ITEM->getEffect();
		if (EFFECT == "Health")
			currentHealth += ITEM->getValue();
		else if (EFFECT == "Mana")
			currentMana += ITEM->getValue();
		else if (EFFECT == "Damage")
			damageMultiplier += ITEM->getValue();
		else if (EFFECT == "Defence")
			defence = (1-ITEM->getValue())*defence;
		//for the following part of code to work, the player must not be able to use stat items during the fight
		else if (EFFECT == "")
		{
			if (itemsInUse.size() < 4)
			{
				itemsInUse.push_back(ITEM);
				for (int i = 0; i < 7; i++)
					stats[i] += ITEM->getItemStat()[i];
				maxHealth = stats[0] * 10 + 40;
				maxMana = stats[2] * 20 + 20;
				physicalDamage = stats[1] * 5 + 20;
				magicalDamage = 1 + (stats[3] / (5 + stats[3]));
				defence += (1 - exp(-0.1*stats[6])) / (1 + exp(-0.1*stats[6]));
				return true;
			}
			return false;
		}
		return true;
}

item* character::removeItem(int i)
{
	item* removedItem = itemsInUse[i];
	itemsInUse.erase(itemsInUse.begin() + i);
	return removedItem;
}

bool character::useSpell(spell* SPELL, character* targetCharacter)
{
	if (SPELL->useSpell(targetCharacter->getAlly()))
	{
		if (SPELL->getMana() <= currentMana)
		{
			string EFFECT = SPELL->getEffect();
			if (EFFECT == "Heal")
				targetCharacter->currentHealth += SPELL->getValue();
			else if (EFFECT == "Damage")
				targetCharacter->currentHealth -= SPELL->getValue();
			else if (EFFECT == "Buff Damage")
				targetCharacter->damageMultiplier += SPELL->getValue();
			else if (EFFECT == "Buff Defence")
				targetCharacter->defence += SPELL->getValue() - targetCharacter->defence*SPELL->getValue();
			return true;
		}
		else
			cout << "Not enough mana" << endl;
	}
	return false;
}


bool character::useSpell(spell * SPELL)
{
	if (SPELL->getMana() <= currentMana)
		return true;
	return false;
}


//have to call this function after every turn in battle
void character::manaRegen() { currentMana += maxMana*0.25; }


//use this function after the battle
void character::resetCharacter()
{
	maxHealth = currentHealth = stats[0] * 10 + 40;
	maxMana = stats[2] * 20 + 20;
	currentMana = 0;
	physicalDamage = 20 + stats[1] * 5;
	magicalDamage = 1 + (stats[3] / (5 + stats[3]));
	damageMultiplier = 1;
	defence = (1 - exp(-0.1*stats[6])) / (1 + exp(-0.1*stats[6]));
}

void character::describeCharacter()
{
	cout << name << endl << "Physical Damage : " << physicalDamage << endl << "Magical Damage : " << magicalDamage 
		<< endl << "Damage Multiplier : " << damageMultiplier << endl << "Defense : " << defence << endl;
}

bool character::learnSpell(spell* SPELL,int spellType)
{
	if (SPELL->getSpellLevel() <= occupation[spellType])
		{
			learnedSpells.push_back(SPELL);
			return true;
		}
	return false;
}

int character::getCharacterLevel()
{
	int level = 0;
	for (int i = 0; i < 4; i++)
		level += occupation[i];
	return level;
}

void character::checkCharacterHealthAndMana()
{
	if (currentHealth > maxHealth)
		currentHealth = maxHealth;
	else if (currentHealth < 0)
		currentHealth = 0;
	if (currentMana > maxMana)
		currentMana = maxMana;
}

bool character::getAlly() { return isAlly; }

void character::setAlly(bool ally) { isAlly = ally; }

bool character::getHostile() { return isHostile; }

void character::setHostile(bool hostile) { isHostile = hostile; }
