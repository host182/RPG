#include "Party.h"

party::party(vector<vector<item*> >i, vector<character*> p)
{
	partyItems = i;
	partyCharacter = p;
}

//have to check if the item being used is stat item or not before calling this function
//since stat items cannot be used in battle
bool party::consumeItem(item* ITEM, character* ch)
{
	bool used = ch->useItem(ITEM);
	if (used)
		cout << "Used " << ITEM->name << " on " << ch->name << endl;
	else
		cout << "Professor Oak : 'There's a time and place for everything'\n";
	partyItems[0] = emptyItems;
	return used;
}

void party::dropItem(int i,int j, int number)
{
	item* ITEM = partyItems[i][j];
	partyItems[i - number].push_back(ITEM);
	partyItems[i].erase(partyItems[i].begin() + j);
	partyItems[0] = emptyItems;
}

bool party::grabItems(item* ITEM)
{
	//maximum number of items is 9
	int itemCount = 0;
	for (int i = 0; i < partyItems.size(); i++)
		itemCount += partyItems[i].size();
	if (itemCount >= 9)
		return false;
	for (int i = 0; i < partyItems.size(); i++)
		for (int j = 0; j < partyItems[i].size(); j++)
			if (partyItems[i][j] == ITEM)
			{
				partyItems[i + 1].push_back(partyItems[i][j]);
				partyItems[i].erase(partyItems[i].begin() + j);
				return true;
			}
	partyItems[1].push_back(ITEM);
	return true;
}


//adding some characters to the party
bool party::addCharacter(character* c)
{
	if (partyCharacter.size() < 6)
	{
		partyCharacter.push_back(c);
		return true;
	}
	return false;
}

void party::removeCharacter(character* c)
{
	int itr;
	for (int i = 0; i < 6; i++)
		if (c == partyCharacter[i])
			itr = i;
	cout << "Are you sure you want to remove this character from your party? (y/n) : "; char y;
	cin >> y;
	if (y == 'y')
		partyCharacter.erase(partyCharacter.begin() + itr);
}

vector<vector<item*> > party::getItem() { return partyItems; }

vector<character*> party::getPartyCharacter() { return partyCharacter; }

vector<item*> party::dropItemsAfterDeath()
{
	vector<item*> temp;
	int iSize = partyItems.size();
	for (int i = 1; i < iSize; i++)
	{
		int jSize = partyItems[i].size();
		for (int j = 0; j < jSize; j++)
			temp.push_back(partyItems[i][j]);
	}
	return temp;
}