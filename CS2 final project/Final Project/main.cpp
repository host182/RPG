#include "Battle.h"

//////////////change the position of death
//////////////organize the creation of player character, party, etc

party enemy1 = e1();
party enemy2 = e2();
party enemy3 = e3();
party enemy4 = e4();
party enemy5 = e5();
party enemy6 = e6();
party enemy7 = e7();
party enemy8 = e8();
party enemy9 = e9();
party* enemies[9] = { &enemy1,&enemy2,&enemy3,&enemy4,&enemy5,&enemy6,&enemy7,&enemy8,&enemy9 };


location location1 = PV();
location location2 = OM();
location location3 = BMF();
location location4 = RF();
location location5 = SB();
location location6 = EE();
location location7 = MOBB();
location location8 = CCM();
location location9 = W();
location* Locations[9] = { &location1,&location2,&location3,&location4,&location5,&location6,&location7,&location8,&location9 };


int main()
{
	do {
		cout << "Enter your name: ";
		string name;
		cin >> name;

		char playerOccupation; int o[4] = { 0,0,0,0 };
		cout << "You have an occupation to choose:" << endl
			<< "1. Fighter" << endl << "2. Mage" << endl << "3. Rogue" << endl << "4. Bard" << endl;
		playerOccupation = getch();
		o[playerOccupation - 49] = 1;

		//items of the party characters
		vector<item* >playerItems(1, &Dragon_Balls);

		character* player = new character(name, o, noSpells, playerItems, true, false);
		vector<character*> partyCharacters(1, player);

		//party items
		vector<vector<item*> >partyItems(2);
		partyItems[1].push_back(&Dragon_Balls);

		//making the party of player
		party *playerParty = new party(partyItems, partyCharacters);

		//location of the player
		location *currentLocation = new location;
		*currentLocation = location1;

		if (playerChoice(currentLocation, playerParty))				//true means the player has moved to a different location
		{
			party* enemyParty = currentLocation->getGuardians();
			if (!enemyParty->getPartyCharacter().empty())
				if (!startBattle(playerParty, enemyParty))
					goto death;
			currentLocation->iWasHere();
			int itemDropSize = currentLocation->getGuardians()->dropItemsAfterDeath().size();
			if (itemDropSize > 0)
			{
				cout << "The enemy dropped some items.\n";
				for(int i=0;i<itemDropSize;i++)
			}
			collectLocationItems(currentLocation, playerParty);
		}
		death:
	} while (true);
	return 0;
}