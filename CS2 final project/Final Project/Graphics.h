#ifndef graphics_h
#define graphics_h
#include <Windows.h>
#include "CreateLocations.h"

///////////create 'x to go back' - DONE
///////////also have to make a function that ensures that the character input from getch() are valid for the calculation - DONE

void mainMenu()
{

}

bool checkInput(char &input, int vectorSize)
{
	if (input == 'x')
		return false;
	reInter:
	if ((input < 49) || (input > vectorSize + 48))
	{
		input = getch();
		goto reInter;
	}
	return true;
}

void battleGraphics(party* player, party* enemy)
{
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "Player Party\t\t\t\t\t\t\t\t\t\t\t\t\Enemy Party" << endl;
		for (int i = 0; i < 6; i++)
		{
			if (i < player->getPartyCharacter().size())
			{
				cout << player->getPartyCharacter()[i]->name << "\t\t\t\t\t\t\t\t\t\t\t";
			}
			if (i < enemy->getPartyCharacter().size())
			{
				cout << enemy->getPartyCharacter()[i]->name << endl;
			}

			if (i < player->getPartyCharacter().size())
			{
				cout << "Health : " << "(" << player->getPartyCharacter()[i]->currentHealth << "/" << player->getPartyCharacter()[i]->maxHealth << ")"<< "\t\t\t\t\t\t\t\t\t\t\t";
			}
			if (i < enemy->getPartyCharacter().size())
			{
				cout << "Health : " << "(" << enemy->getPartyCharacter()[i]->currentHealth << "/" << enemy->getPartyCharacter()[i]->maxHealth << ")" << endl;
			}
			
			if (i < player->getPartyCharacter().size())
			{
				cout << "Mana : " << "(" << player->getPartyCharacter()[i]->currentMana << "/" << player->getPartyCharacter()[i]->maxMana << ")" << "\t\t\t\t\t\t\t\t\t\t\t";
			}
			if (i < enemy->getPartyCharacter().size())
			{
				cout << "Mana : " << "(" << enemy->getPartyCharacter()[i]->currentMana << "/" << enemy->getPartyCharacter()[i]->maxMana << ")" << endl;
			}

		}
		cout << "-------------------------------------------------------------------------------------------" << endl;
}

void showMap()
{

}

void partyScreen(party* player)
{
	int partySize = player->getPartyCharacter().size();
	for (int i = 0; i < partySize; i++)
		cout << player->getPartyCharacter()[i]->name << endl <<
		"Health : " << "(" << player->getPartyCharacter()[i]->currentHealth << "/" << player->getPartyCharacter()[i]->maxHealth << ")" << endl <<
		"Mana : " << "(" << player->getPartyCharacter()[i]->currentMana << "/" << player->getPartyCharacter()[i]->maxMana << ")" << endl;
}

bool playerChoice(location* currentLocation,party* player)
{

	output1:														//output
	cout << "1. Party\n2. Bag Items\n3. Grab items from the ground\n4. Go to...\n";
	char choice = getch();
	/////////////////////////////////////
	//choice is Party
	if (choice == 49)
	{

		output2:															//output
		////cursor move
		partyScreen(player);
		////cursor move
		cout << "1. Spells\n2. Items\n";
		char spellOrItemChoice = getch();
		if (!checkInput(spellOrItemChoice, 2))
			goto output1;

		//choice = spell
		if (spellOrItemChoice == 49)
		{

			output3:																//output
			////cursor move
			cout << "Choose the character" << endl;
			char characterChoice = getch();
			if (!checkInput(characterChoice, player->getPartyCharacter().size()))
				goto output2;
			character* chosenCharacter = player->getPartyCharacter()[characterChoice - 49];
			int characterSpellSize = chosenCharacter->learnedSpells.size();
			
			do {

				output4:																	//output
				////cursor move
				for (int i = 0; i < characterSpellSize; i++)
					cout << i + 1 << ". " << chosenCharacter->learnedSpells[i]->getName() << endl;
				if (characterSpellSize < 4)
					cout << characterSpellSize + 1 << ". Add a spell" << endl;
				char spellChoice = getch();
				if (!checkInput(spellChoice, characterSpellSize))
					goto output3;

				output5:																	//output
				////cursor move
				//if the chosen spell is not "Add a spell", display what is happening, else it's not needed
				if (spellChoice != characterSpellSize + 49)
					cout << "What type of spell will you replace it with?\n";

				cout << "1. Fighter Spells\t\t\t\t\t\t\t\t\t2. Mage Spells\n3. Rogue Spells\t\t\t\t\t\t\t\t\t4. Bard Spells\n";
				char spellTypeChoice = getch();
				if (!checkInput(spellTypeChoice, 4))
					goto output4;
				
				spell** chosenSpellType = allSpells[spellTypeChoice - 49];
				//finding the size of the array
				int spellSize = sizeof(chosenSpellType) / sizeof(*chosenSpellType);

				output6:																	//output
				////cursor move
				for (int i = 0; i < spellSize; i++)
				cout << i + 1 << ". " << chosenSpellType[i]->getName() << endl;
				char addSpellChoice = getch();
				//if the user enters a no-meaning input, make him input again
				if (!checkInput(addSpellChoice, spellSize))
					goto output5;
				if (chosenCharacter->learnSpell(chosenSpellType[addSpellChoice - 49], addSpellChoice - 49))
				{
					if (spellChoice != characterSpellSize + 49)
					{
						cout << chosenCharacter->name << " has forgotten " << chosenCharacter->learnedSpells[addSpellChoice - 49]->getName();
						chosenCharacter->learnedSpells.erase(chosenCharacter->learnedSpells.begin() + addSpellChoice - 49);
					}
					cout << chosenCharacter->name << " learned " << chosenSpellType[addSpellChoice - 49] << endl;
				}
				else
					cout << chosenCharacter->name << " does not have enough occupation levels" << endl;
				
			} while (true);
		}

		//choice = items
		if (spellOrItemChoice == 50)
		{

		output3_1:																	//output
			////cursor move
			cout << "Choose the character" << endl;
			char characterChoice = getch();
			if (!checkInput(characterChoice, player->getPartyCharacter().size()))
				goto output2;
			character* chosenCharacter = player->getPartyCharacter()[characterChoice - 49];
			int characterItemSize = chosenCharacter->itemsInUse.size();

			do {
			output4_1:																	//output
				////cursor move
				for (int i = 0; i < characterItemSize; i++)
					cout << i + 1 << ". " << chosenCharacter->itemsInUse[i]->name << endl;
				if (characterItemSize < 4)
					cout << characterItemSize + 1 << ". Add an item\n";
				char itemChoice = getch();
				if (!checkInput(itemChoice, characterItemSize))
					goto output3_1;
				item** removedItem = new item*;
				//*removedItem = chosenCharacter->itemsInUse[itemChoice - 49];
				//chosenCharacter->removeItem(itemChoice - 49);

				vector<vector<item*> >ITEMS = player->getItem();
				int itemSize = ITEMS.size();

				//displayed items
			output5_1:																		//output
				int count = 0;
				vector < item*>* reorganizedItems = new vector<item*>;
				////cursor move
				for (int i = 1; i < itemSize; i++)
				{
					int size = ITEMS[i].size();
					for (int j = 0; j < size; j++)
					{
						reorganizedItems->push_back(ITEMS[i][j]);
						cout << count << ". " << (*reorganizedItems)[count]->name << "\t\t\t\t\t\t\t\t\t" << i << endl;
						count++;
					}
				}

				char replaceItemChoice = getch();
				if (!checkInput(replaceItemChoice, itemSize))
				{
					delete reorganizedItems;
					goto output5_1;
				}

				item* chosenItem = (*reorganizedItems)[replaceItemChoice - 49];
				if (chosenItem->getEffect() != "")
					cout << "Consumables can't be used at this moment\n";
				else
				{
					player->grabItems(chosenCharacter->removeItem(replaceItemChoice - 49));
					chosenCharacter->useItem(chosenItem);
				}
			} while (true);
		}
	}
	//////////////////////////////////////
	//choice is Items
	else if (choice == 50)
	{
		do {
			int itemSize = player->getItem().size();
		output2_2:
			int count = 0;
			vector<item*>* displayingItem = new vector<item*>;
			//ignoring the first vector as it has no elements
			for (int i = 1; i < itemSize; i++)
			{
				int size = player->getItem()[i].size();
				for (int j = 0; j < size; j++)
				{
					displayingItem->push_back(player->getItem()[i][j]);
					cout << count + 1 << ". " << (*displayingItem)[count]->name << "\t\t\t\t\t\t\t\t" << i << endl;
					count++;
				}
			}
			char itemChoice = getch();
			if (!checkInput(itemChoice, displayingItem->size()))
				goto output1;
			item* chosenItem = (*displayingItem)[itemChoice - 49];
			int chosenI = 0, chosenJ = 0, cumulative = 0;
			for (int i = 1; i < itemSize; i++)
			{
				int size = player->getItem()[i].size();
				cumulative += size;
				if (cumulative >= itemChoice - 48)
				{
					chosenI = i;
					chosenJ = cumulative - itemChoice - 1;
				}
			}

		output3_2:															//output
			////cursor move
			cout << "1 - " << chosenI << "\nHow many items to drop: ";
			char itemDropNumber = getch();
			if (!checkInput(itemDropNumber, chosenI))
				goto output2_2;
			player->dropItem(chosenI, chosenJ, itemDropNumber - 48);
		} while (true);
	}
	/////////////////////////////////////
	//choice is Grab items from the ground
	else if (choice == 51)
	{
		collectLocationItems(currentLocation, player);
	}
	/////////////////////////////////////
	//choice is go to...
	else if (choice == 52)
	{
		int numberOfEscapes = currentLocation->getEscapes().size();
		output2_3:													//output
		////cursor move
		for (int i = 0; i < numberOfEscapes; i++)
			cout << i + 1 << ". " << Locations[currentLocation->getEscapes()[i]] << endl;
		char escapeChoice = getch();
		if (!checkInput(escapeChoice, numberOfEscapes))
			goto output1;
		int escapeLocation = currentLocation->getEscapes()[escapeChoice - 49];
		currentLocation = Locations[escapeLocation - 1];
		return true;
	}

}

void collectLocationItems(location* currentLocation, party* player)
{
	vector<item*>* locationItems = &currentLocation->getLocationItems();
	if (currentLocation->getVisits())
	{
		int size = locationItems->size();
		if (size == 0)
			cout << "No items on the ground\n";
	output1:
		for (int i = 0; i < size; i++)
			cout << i + 1 << ". " << (*locationItems)[i]->name << endl;
		do {
			char grabItemChoice = getch();
			if (!checkInput(grabItemChoice, size))
				break;
			item* chosenItem = (*locationItems)[grabItemChoice - 49];
			if (player->grabItems(chosenItem))
			{
				cout << "You grabbed " << chosenItem->name << endl;
				(*locationItems).erase((*locationItems).begin() + grabItemChoice - 49);
			}
			else
			{
				cout << "Your bag is full\n";
				break;
			}
		} while (!locationItems->empty());
	}
}

#endif