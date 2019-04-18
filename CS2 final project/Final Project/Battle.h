#ifndef battle_h
#define battle_h
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "Graphics.h"
#include "Party.h"
#include "AI.h"

/////////////have to work on the graphics and state if an attack missed

bool beforeAttack(character* attackingCharacter,party* enemy,vector<bool> enemyCharacterInBattle) {
	char chooseTarget;
	do 
	{
		////cursor move
		cout << "Choose a target" << endl;
		chooseTarget = getch();
		if (!enemyCharacterInBattle[chooseTarget - 49])
			////cursor move
			cout << "This character is exausted and out of battle" << endl;
	} while (!enemyCharacterInBattle[chooseTarget - 49]);
	character* targetCharacter = enemy->getPartyCharacter()[chooseTarget - 49];
	double hitChance = (rand() % 100) / 100;
	double dodgeChance = targetCharacter->stats[5] / (5 + targetCharacter->stats[5]);
	if (hitChance > dodgeChance)
		targetCharacter->currentHealth -= (1 - targetCharacter->defence)*(attackingCharacter->physicalDamage)*(attackingCharacter->damageMultiplier);
	////cursor move
	cout << attackingCharacter->name << " attacked " << targetCharacter->name << endl;
	return true;
}



bool beforSpell(character* attackingCharacter, party* player, party* enemy,vector<bool> playerCharacterInBattle, vector<bool> enemyCharacterInBattle) {
	vector<spell*> availableSpells = attackingCharacter->learnedSpells;
	////cursor move
	for (int i = 0; i < availableSpells.size(); i++)
	{
		cout << i << ". " << availableSpells[i]->getName();
		if (i % 2 == 0)
			cout << "\t\t\t\t\t\t\t";
		else
			cout << endl;
	}
	bool successfulSpell;
	do
	{
		char chooseSpell;
		//can go back if the player presses 'x'
		if (chooseSpell == 'x')
			return false;
		chooseSpell = getch();
		////cursor move
		spell* usedSpell = availableSpells[chooseSpell - 49];
		int areaOfSpell = usedSpell->getArea();


		//for spells that require targets
		if (areaOfSpell > 0)
		{
			vector<char> chooseTarget;
			int count = 0;
			////cursor move
			cout << "Choose " << areaOfSpell << " target" << endl;
			//only damaging spells can target enemies
			if (usedSpell->getEffect() == "Damage")
			{
				////battleGraphics that shows numbers beside the enemy characters
				for (int i = 0; i < areaOfSpell; i++)
				{
					chooseTarget.push_back(getch());
					if (attackingCharacter->useSpell(usedSpell, enemy->getPartyCharacter()[chooseTarget[i] - 49]))
						count++;					//counting the number of successful spells (the change in the character is not yet done)
				}
			}
			//so the rest of the effects are Heal, Damage Buff, and Defence Buff
			else
			{
				////battleGraphics that shows numbers beside the player characters
				for (int i = 0; i < areaOfSpell; i++)
				{
					chooseTarget.push_back(getch());
					if (attackingCharacter->useSpell(usedSpell, player->getPartyCharacter()[chooseTarget[i] - 49]))
						count++;					//same as the count above
				}
			}


			//applying the spell's effect
			//if the spell effects all of the targeted characters, apply changes and return "spells are used"
			if (count == areaOfSpell)
			{
				if(usedSpell->getEffect()=="Damage")
					for (int i = 0; i < areaOfSpell; i++)
					{
						character* targetCharacter = enemy->getPartyCharacter()[chooseTarget[i] - 49];
						double hitChance = (rand() % 100)/100;
						double dodgeChance = targetCharacter->stats[5] / (5 + targetCharacter->stats[5]);
						//only hits if the hit chance * accuracy is greater than dodgeChance
						//but the spell is counted as casted
						if ((hitChance*usedSpell->getAccuracy())>dodgeChance)
							targetCharacter->currentHealth -= (1 - targetCharacter->defence)*(attackingCharacter->damageMultiplier)*(attackingCharacter->magicalDamage)*(usedSpell->getValue());
					}
				else if (usedSpell->getEffect() == "Heal")
					for (int i = 0; i < areaOfSpell; i++)
					{
						
						character* targetCharacter = player->getPartyCharacter()[chooseTarget[i] - 49];
						targetCharacter->currentHealth += usedSpell->getValue();
					}
				else if (usedSpell->getEffect() == "Damage Buff")
					for (int i = 0; i < areaOfSpell; i++)
					{
						
						character* targetCharacter = player->getPartyCharacter()[chooseTarget[i] - 49];
						targetCharacter->damageMultiplier += usedSpell->getValue();
					}
				else
					for (int i = 0; i < areaOfSpell; i++)
					{
						
						character* targetCharacter = player->getPartyCharacter()[chooseTarget[i] - 49];
						targetCharacter->defence += usedSpell->getValue();
					}
				////cursor move
				cout << attackingCharacter->name << " used " << usedSpell->getName() << endl;
				return true;
			}
			//if all the spell does not effect all of the characters, go back in the loop and try again or choose a different spell
			else
			{
				////cursor move
				cout << "Failed";
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
					for (int i = 0; i < enemy->getPartyCharacter().size(); i++)
					{
						//effects the character if it's still in battle
						if (enemyCharacterInBattle[i])
						{
							character* targetCharacter = enemy->getPartyCharacter()[i];
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
						for (int i = 0; i < player->getPartyCharacter().size(); i++)
						{
							if (playerCharacterInBattle[i])
							{
								character* targetCharacter = player->getPartyCharacter()[i];
								targetCharacter->currentHealth += usedSpell->getValue();
							}
						}
					else if(usedSpell->getEffect()=="Damage Buff")
						for (int i = 0; i < player->getPartyCharacter().size(); i++)
						{
							if (playerCharacterInBattle[i])
							{
								character* targetCharacter = player->getPartyCharacter()[i];
								targetCharacter->damageMultiplier += usedSpell->getValue();
							}
						}
					else
						for (int i = 0; i < player->getPartyCharacter().size(); i++)
						{
							if (playerCharacterInBattle[i])
							{
								character* targetCharacter = player->getPartyCharacter()[i];
								targetCharacter->defence += usedSpell->getValue() - (targetCharacter->defence)*(usedSpell->getValue());
							}
						}
				////cursor move
				cout << attackingCharacter->name << " used " << usedSpell->getName() << endl;
				return true;
			}
			else
			{
				////cursor move
				cout << "Failed";
				successfulSpell = false;
			}
		}
	} while (!successfulSpell);
}


bool beforeItem(character* attackingCharacter,party* player)
{
	vector<vector<item*> >ITEMS = player->getItem();
	////cursor move
	for (int i = 1; i < ITEMS.size(); i++)
		for (int j = 0; j < ITEMS[i].size(); j++)
			cout << i*ITEMS[i-1].size()+j+1 << ". " << ITEMS[i][j]->name << "\t\t\t\t" << i << endl;
	char chooseItem;
	chooseItem = getch();
	if (chooseItem == 'x')
		return false;
	int number = 0;
	item* usedItem;
	for (int i = 1; i < ITEMS.size(); i++)
		if ((chooseItem - 48) <= number + ITEMS[i].size())			//check if chooseItem-48 is correct---------if incorrect,
			usedItem = ITEMS[i][chooseItem - 49 - number];			//correct graphics -> playerChoice -> party -> items
	if (usedItem->getEffect() != "")
		return attackingCharacter->useItem(usedItem);
	else
		return false;
}



bool startBattle(party* player, party* enemy)
{
	srand(time(0));
	char chooseCharacter, response;
	int playerPartySize = player->getPartyCharacter().size();
	int enemyPartySize = enemy->getPartyCharacter().size();
	
	bool battleP = true, battleE = true;
	vector<bool> playerCharacterInBattle(playerPartySize, 1);
	vector<bool> enemyCharacterInBattle(enemyPartySize, 1);


	do {
		int conditionToEndTurn = 0;
		vector<bool> playerCharacterInTurn(playerPartySize, 1);
		vector<bool> enemyCharacterInTurn(enemyPartySize, 1);

		battleGraphics(player, enemy);
		//player's turn
		do
		{
			////cursor move
			cout << "Choose a character" << endl;
			chooseCharacter = getch();			
			character* usedCharacter = player->getPartyCharacter()[chooseCharacter - 49];
			if (!playerCharacterInTurn[chooseCharacter - 49])
			{
				////cursor move 
				cout << usedCharacter->name << " has already made it's move" << endl;
				break;
			}
			if (!playerCharacterInBattle[chooseCharacter - 49])
			{
				////cursor move
				cout << usedCharacter->name << " is exhausted" << endl;
				break;
			}

			//The active character is player->partyCharacter[chooseCharacter-49]
			bool proceed;
			do 
			{
			////cursor move
				cout << "1. Attack\t\t\t\t\t\t\t2. Spells\n3. Items\t\t\t\t\t\t\t4. Change character" << endl;
			response = getch();
				if (response == '1')
					proceed = beforeAttack(usedCharacter, enemy,enemyCharacterInBattle);
				if (response == '2')
					proceed = beforSpell(usedCharacter, player, enemy,playerCharacterInBattle,enemyCharacterInBattle);
				if (response == '3')
					proceed = beforeItem(usedCharacter, player);
				else
					proceed = false;
				//If an action is taken, the character cannot make move again
				playerCharacterInTurn[chooseCharacter] = proceed;
			} while (!proceed);
			
			for (int i = 0; i < playerPartySize; i++)
				player->getPartyCharacter()[i]->checkCharacterHealthAndMana();

			for (int i = 0; i < playerPartySize; i++)
				conditionToEndTurn += playerCharacterInBattle[i] + playerCharacterInTurn[i];
		} while (conditionToEndTurn != playerPartySize);


		//calculating if a character is still in battle
		for (int i = 0; i < enemyPartySize; i++)
			if (!(enemy->getPartyCharacter()[i]->currentHealth > 0))
			{
				cout << enemy->getPartyCharacter()[i]->name << " has fainted" << endl;
				enemyCharacterInBattle[i] = false;
			}

		//seeing if there are any enemmies left
		for (int i = 0; i < enemyPartySize; i++)
			battleE += enemyCharacterInBattle[i];
		//if there are none, return true (player won)
		if (!battleE)
			return true;

		///////////////////////////////
		//enemy's turn
		do 
		{
			AIbattle(player, enemy, playerCharacterInBattle, enemyCharacterInBattle);
		} while (true);
		//////////////////////////////////

		for (int i = 0; i < enemyPartySize; i++)
			enemy->getPartyCharacter()[i]->checkCharacterHealthAndMana();

		//calculating if a player character is still in battle
		for (int i = 0; i < player->getPartyCharacter().size(); i++)
			if (!(player->getPartyCharacter()[i]->currentHealth > 0))
			{
				cout << player->getPartyCharacter()[i]->name << " has fainted" << endl;
				playerCharacterInBattle[i] = false;
			}

		//if there are any player characters left
		for (int i = 0; i < playerCharacterInBattle.size(); i++)
			battleP += playerCharacterInBattle[i];
		//if there are no player characters left, the player lost
		if (!battleP)
			return false;

	} while (battleP && battleE);
}


#endif