#ifndef createitems_h
#define createitems_h

// consumables 
consumable red_potion("Red Potion", "a Potion that gives you a little bit of health", "Health", 40.0);
consumable blue_potion("Blue Potion", "a Potion that gives you a little bit of mana", "Mana", 25.0);
consumable strength_booster("Strength Booster", "A mysterious mixture that is said to have been given by the Gods. It boots your strength", "Damage", 1.0);
consumable defence_booster("Defence Booster", "Made by the mysterious women from the northern islands. It boosts your defence", "Defence", 1.0);

//stat items 
// Dragon Balls 
int a[7] = { 1,1,1,1,1,1,1 };
statItem Dragon_Balls("Dragon Balls", "Powerful weapon from another dimension.", a);
// Slimy Armor
int b[7] = { 0,0,0,0,0,0,2 };
statItem Slimy_Armor("Slimy Armor", "Armor not the best but gets the job done.", b);
// Gloves of Bashing
int c[7] = { 1,3,0,0,0,0,0 };
statItem Gloves_of_bashing("Gloves of Bashing", "Protects your hands.", c);
//Sneaky Mask 
int d[7] = { 0,0,0,0,4,0,0 };
statItem Sneaky_Mask("Sneaky Mask", "A mask that pretty much lets you get away with anything.", d);
//Staff of Infection 
int e[7] = { 0,0,2,2,0,0,0 };
statItem Staff_of_Infection("Staff of Infection", "Like a staph infection, but a little different.", e);
// Voice Changer
int f[7] = { 0,0,0,0,0,4,0 };
statItem Voice_changer("Voice Changer", "Gives you the Voice of a Siren.", f);
//Helm of Helms
int g[7] = { 1,0,2,0,1,0,2 };
statItem Helm_of_Helms("Helm of Helms", "a mystical Helm that gives mystical Powers.", g);

#endif