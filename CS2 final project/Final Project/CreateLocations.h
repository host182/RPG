#ifndef createlocation_H
#define createlocation_H
#include "CreateCharacters.h"
#include "location.h"
#include "CreateParties.h"

location PV() {
	// location 1
	vector<int > escapes1(3);
	escapes1[0] = 2;
	escapes1[1] = 3;
	escapes1[2] = 4;
	vector<character* > Ally1(1, &Grummle);
	vector<item*> Item1(1, &strength_booster);
	location Prymoor_Village("Prymoor Village", 1, Ally1, Item1, &enemy1, escapes1, 1);
	return Prymoor_Village;
}

location OM() {
	// location 2 
	vector<int > escapes2(2);
	escapes2[0] = 2;
	escapes2[1] = 5;
	vector<character* > Ally2(1, &Blue_Knight);
	vector<item*> Item2(1, &blue_potion);
	location Orton_Marsh("Orton Marsh", 2, Ally2, Item2, &enemy2, escapes2, 0);
	return Orton_Marsh;
}

location BMF() {// location 3
	vector<int > escapes3(3);
	escapes3[0] = 1;
	escapes3[1] = 5;
	escapes3[2] = 4;
	vector<character* > Ally3(1, &Jinyu);
	vector<item*> Item3(1, &strength_booster);
	location Black_Mill_Farm("Black Mill Farm", 3, Ally3, Item3, &enemy3, escapes3, 0);
	return Black_Mill_Farm;
}

location RF() {
	//location 4
	vector<int > escapes4(2);
	escapes4[0] = 1;
	escapes4[1] = 5;
	vector<character* > Ally4(1, &Trogg);
	vector<item*> Item4(1, &red_potion);
	location Rosemarble_Forest("Rosemarble Forest", 4, Ally4, Item4, &enemy4, escapes4, 0);
	return Rosemarble_Forest;
}
	
location SB() {//location 5
	vector<int > escapes5(5);
	escapes5[0] = 2;
	escapes5[1] = 3;
	escapes5[2] = 4;
	escapes5[3] = 7;
	escapes5[4] = 6;
	vector<character* > Ally5(1, &Your_Mother);
	vector<item*> Item5(1, &Voice_changer);
	location Starry_Borrow("Starry Borrow", 5, Ally5, Item5, &enemy5, escapes5, 0);
	return Starry_Borrow;
}

location EE() {
	//location 6
	vector<int > escapes6(2);
	escapes6[0] = 9;
	escapes6[1] = 5;
	vector<character* > Ally6(1, &Sayaadi);
	vector<item*> Item6(1, &Sneaky_Mask);
	location East_Elf("East Elf", 6, Ally6, Item6, &enemy6, escapes6, 0);
	return East_Elf;
}

location MOBB() {
	//location 7
	vector<int > escapes7(3);
	escapes7[0] = 2;
	escapes7[1] = 3;
	escapes7[2] = 4;
	vector<character* > Ally7(1, &Mulan);
	vector<item*> Item7(1, &strength_booster);
	location Mines_of_ByBarrow("Mines of ByBarrow", 7, Ally7, Item7, &enemy7, escapes7, 0);
	return Mines_of_ByBarrow;
}

location CCM() {
	//location 8 
	vector<int > escapes8(2);
	escapes8[0] = 7;
	escapes8[1] = 9;
	vector<character* > Ally8(1, &Mogu);
	vector<item*> Item8(1, &defence_booster);
	location ColdCliff_Mountains("ColdCliff Mountains", 8, Ally8, Item8, &enemy8, escapes8, 0);
	return ColdCliff_Mountains;
}

location W() {
	//location 9 
	vector<int > escapes9(2);
	escapes9[0] = 7;
	escapes9[1] = 6;
	vector<character* > Ally9(1, &Murloc);
	vector<item*> Item9(1, &strength_booster);
	location Whitworth("Whitworth", 9, Ally9, Item9, &enemy9, escapes9, 0);
	return Whitworth;
}

#endif