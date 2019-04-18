#ifndef ai_h
#define ai_h
#include "Party.h"
#include <algorithm>



vector<character*> getWeakestEnemies(party* enemy)
{
	vector<int> health(enemy->getPartyCharacter().size());
	vector<character*> weakestCharacter(enemy->getPartyCharacter().size());
	for (int i = 0; i < enemy->getPartyCharacter().size(); i++)
		health[i] = enemy->getPartyCharacter()[i]->currentHealth;
	sort(health.begin(), health.end());
	for (int i = 0; i < enemy->getPartyCharacter().size(); i++)
		for (int j = 0; j < health.size(); j++)
			if (enemy->getPartyCharacter()[j]->currentHealth == health[i])
				weakestCharacter[i] = enemy->getPartyCharacter()[j];
	return weakestCharacter;
}



void AIattack(character* attackingCharacter, character* targetCharacter)
{
	double hitChance = (rand() % 100) / 100;
	double dodgeChance = targetCharacter->stats[5] / (5 + targetCharacter->stats[5]);
	if (hitChance > dodgeChance)
		targetCharacter->currentHealth -= (1 - targetCharacter->defence)*(attackingCharacter->physicalDamage)*(attackingCharacter->damageMultiplier);
	////cursor move
	cout << attackingCharacter->name << " attacked " << targetCharacter->name << endl;

}



bool AIspell(vector<character*> playerCharacter, vector<character*> weakestCharacter, vector<bool> playerCharacterInBattle, vector<bool> enemyCharacterInBattle, int index)
{
	character* attackingCharacter = playerCharacter[index];
	spell* usedSpell = attackingCharacter->learnedSpells[0];
	int areaOfSpell = usedSpell->getArea();
	int const perIndex = index;

	bool successfulSpell;
	do
	{
		//for spells that require targets
		if (areaOfSpell > 0)
		{
			/////////////vector<int> chooseTarget;
			int count = 0;
			//only damaging spells can target enemies
			if (usedSpell->getEffect() == "Damage")
			{
				////battleGraphics that shows numbers beside the enemy characters
				for (int i = 0; i < areaOfSpell; i++)
				{
					//////////////////chooseTarget.push_back(getch());
					if ((index + i) >= weakestCharacter.size())
						index = -i;
					if (attackingCharacter->useSpell(usedSpell, weakestCharacter[index + i]))
						count++;					//counting the number of successful spells (the change in the character is not yet done)
				}
			}
			//so the rest of the effects are Heal, Damage Buff, and Defence Buff
			else
			{
				////battleGraphics that shows numbers beside the player characters
				for (int i = 0; i < areaOfSpell; i++)
				{
					////////////////chooseTarget.push_back(getch());
					if (attackingCharacter->useSpell(usedSpell, playerCharacter[i]))
						count++;					//same as the count above
				}
			}


			//applying the spell's effect
			//if the spell effects all of the targeted characters, apply changes and return "spells are used"
			if (count == areaOfSpell)
			{
				if (usedSpell->getEffect() == "Damage")
					for (int i = 0; i < areaOfSpell; i++)
					{
						if ((index + i) >= weakestCharacter.size())
							index = -i;									//if the function is looking to target nth character in a vector of (n-1) max character, it will instead target the first character
						character* targetCharacter = weakestCharacter[index + i];
						double hitChance = (rand() % 100) / 100;
						double dodgeChance = targetCharacter->stats[5] / (5 + targetCharacter->stats[5]);
						//only hits if the hit chance * accuracy is greater than dodgeChance
						//but the spell is counted as casted
						if ((hitChance*usedSpell->getAccuracy())>dodgeChance)
							targetCharacter->currentHealth -= (1 - targetCharacter->defence)*(attackingCharacter->damageMultiplier)*(attackingCharacter->magicalDamage)*(usedSpell->getValue());
					}
				else if (usedSpell->getEffect() == "Heal")
					for (int i = 0; i < areaOfSpell; i++)
					{
						character* targetCharacter = playerCharacter[i];
						targetCharacter->currentHealth += usedSpell->getValue();
					}
				else if (usedSpell->getEffect() == "Damage Buff")
					for (int i = 0; i < areaOfSpell; i++)
					{
						character* targetCharacter = playerCharacter[i];
						targetCharacter->damageMultiplier += usedSpell->getValue();
					}
				else
					for (int i = 0; i < areaOfSpell; i++)
					{
						character* targetCharacter = playerCharacter[i];
						targetCharacter->defence += usedSpell->getValue();
					}
				////cursor move
				cout << attackingCharacter->name << " used " << usedSpell->getName();
				return true;
			}
			//if all the spell does not effect all of the characters, go back in the loop and try again or choose a different spell
			else
			{
				successfulSpell = false;
			}
		}



		//for spells that don't require target
		else
		{
			//checking if the character can cast the spell, apply changes to the characters being affected
			if (attackingCharacter->useSpell(usedSpell))
			{
				//the only spells that can effect enemies are damaging spells
				if (usedSpell->getTarget() == "ge")
					for (int i = 0; i < weakestCharacter.size(); i++)
					{
						//effects the character if it's still in battle
						if (enemyCharacterInBattle[i])
						{
							character* targetCharacter = weakestCharacter[i];
							double hitChance = (rand() % 100) / 100;
							double dodgeChance = targetCharacter->stats[5] / (5 + targetCharacter->stats[5]);
							//same as the spell that requires targetting
							if ((hitChance*usedSpell->getAccuracy()) > dodgeChance)
								targetCharacter->currentHealth -= (1 - targetCharacter->defence)*(attackingCharacter->magicalDamage)*(attackingCharacter->damageMultiplier)*(usedSpell->getValue());
						}
					}
				//the other spells have targets = "s" and "ga" with Heal, Damage Buff and Defence Buff, which only apply to allies
				else
					if (usedSpell->getEffect() == "Heal")
						for (int i = 0; i < playerCharacter.size(); i++)
						{
							if (playerCharacterInBattle[i])
							{
								character* targetCharacter = playerCharacter[i];
								targetCharacter->currentHealth += usedSpell->getValue();
							}
						}
					else if (usedSpell->getEffect() == "Damage Buff")
						for (int i = 0; i < playerCharacter.size(); i++)
						{
							if (playerCharacterInBattle[i])
							{
								character* targetCharacter = playerCharacter[i];
								targetCharacter->damageMultiplier += usedSpell->getValue();
							}
						}
					else
						for (int i = 0; i < playerCharacter.size(); i++)
						{
							if (playerCharacterInBattle[i])
							{
								character* targetCharacter = playerCharacter[i];
								targetCharacter->defence += usedSpell->getValue() - (targetCharacter->defence)*(usedSpell->getValue());
							}
						}
				////cursor move
				cout << attackingCharacter->name << " used " << usedSpell->getName() << endl;
				return true;
			}
			else
			{
				successfulSpell = false;
			}
		}
	} while (!successfulSpell);
}




void AIbattle(party* player, party* enemy,vector<bool> playerCharacterInBattle,vector<bool> enemyCharacterInBattle)
{
	vector<character*> playerCharacter = player->getPartyCharacter();
	vector<character*> enemyCharacter = enemy->getPartyCharacter();

	vector<vector<bool> > movePriority;
	vector<bool> aPriority(2); aPriority[0] = 1, aPriority[1] = 0;
	vector<bool> sPriority(2); sPriority[0] = 0, sPriority[1] = 1;

	vector<character*> weakestPlayerCharacter = getWeakestEnemies(player);

	for (int i = 0; i < enemyCharacter.size(); i++)
	{
		if (!enemyCharacterInBattle[i])
			break;
		int attackDamage = (enemyCharacter[i]->physicalDamage)*(enemyCharacter[i]->damageMultiplier);
		spell* potentialSpell = enemyCharacter[i]->learnedSpells[0];
		int spellDamage = 0;
		if(potentialSpell->getEffect()=="Damage")
			spellDamage=potentialSpell->getValue()*potentialSpell->getAccuracy()*enemyCharacter[i]->damageMultiplier*enemyCharacter[i]->magicalDamage;
		if (potentialSpell->getEffect() != "Damage")
		{
			if (attackDamage >= spellDamage)
				movePriority.push_back(aPriority);
			else
				movePriority.push_back(sPriority);
		}
		if (movePriority[i][0])
			AIattack(enemyCharacter[i], weakestPlayerCharacter[i]);
		else
			if(!AIspell(enemyCharacter, weakestPlayerCharacter, enemyCharacterInBattle, playerCharacterInBattle, i))
				AIattack(enemyCharacter[i], weakestPlayerCharacter[i]);
	}
}



#endif