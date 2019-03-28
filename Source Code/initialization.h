#pragma once

#include"resources.h"
#include"loot.h"

using namespace std;

int race(player&p)
{
	int choice;

correct :

	cout<<"\nWhich race are you?"<<endl;
	cout<<"\n1. Human "<<endl;
	cout<<"\n2. Orc "<<endl;
	cout<<"\n3. Half-Elf"<<endl;
	cout<<"\n4. Half-Orc"<<endl;
	cout<<"\n5. Half-Lizard"<<endl;
	cout<<"\n6. Elf"<<endl;

	cout<<"\nInput choice : ";
	cin>>choice;

	system("cls");

	switch(choice) 
	{
		case 1:
		{
			cout<<"\nYou are a Human"<<endl;
			p.race = "Human";
			p.STR += 1;
			p.VIT += 1;
			p.DEX += 1;
			p.STA += 1;
			
		}
		break;

		case 2:
		{
			cout<<"\nYou are an Orc"<<endl;
			p.race = "Orc";
			p.STR += 3;
			p.VIT += 3;
			p.DEX -= 1;
			p.STA -= 1;
		}
		break;

		case 3:
		{
			cout<<"\nYou are a Half-Elf"<<endl;
			p.race = "Half-Elf";
			p.FAI += 3;
			p.INE += 2;
			p.STR -= 1;			
		}
		break;

		case 4:
		{
			cout<<"\nYou are a Half-Orc"<<endl;
			p.race = "Half-Orc";
			p.DEX += 2;
			p.VIT += 3;
			p.INE -= 1;
		}
		break;

		case 5:
		{
			cout<<"\nYou are a Half-Lizard"<<endl;
			p.race = "Half-Lizard";
			p.DEX += 1;
			p.STA += 3;
		}
		break;

		case 6:
		{
			cout<<"\nYou are an Elf"<<endl;
			p.race = "Elf";
			p.FAI += 3;
			p.INE += 3;
			p.STR -= 1;
			p.VIT -= 1;
		}
		break;

		default:
		{
			cout<<"\nThat isn't a valid choice here"<<endl;

			goto correct;
		}
		break;
	}

	p.setattributes();

	line();

	return 0;
}

int playerclass(player&p)
{
	cout<<"\n1. Berserker"<<endl;
	cout<<"\n2. Battlemage"<<endl;
	cout<<"\n3. Herald"<<endl;
	cout<<"\n4. Knight"<<endl;
	cout<<"\n5. Mercenary"<<endl;
	cout<<"\n6. Rogue"<<endl;
	cout<<"\n7. Assassin"<<endl;
	cout<<"\n8. Spell-Sword"<<endl;
	cout<<"\n9. Pyromancer"<<endl;
	cout<<"\n10. Adventurer"<<endl;
	
	int choice;
	
	cout<<"\nInput choice : ";
	cin>>choice;
	
	system("cls");
	
	c = GREEN;
	setcolor();

	switch(choice)
	{
		case 1:
		{
			cout<<"\nYou chose Class Berserker"<<endl;
			p.pclass = "Berserker";

			p.STR += 25;
			p.VIT += 22;
			p.DEX += 7;
			p.STA += 5;
			p.FAI += 6;
			p.INE += 5;
			p.luck = 2;

			p.no_hp = 8;
			
			p.w.name = "Iron Mace";
			p.w.damage = 50;
			p.w.weight = 24;
			p.w.STR += 4;
			p.w.dh = true;
			p.w.type = HV_BLUDGE;
			p.w.material = IRON;
			
			p.a.name = "Heavy Chainmail Armor";
			p.a.defense = 10;
			p.a.weight = 10;
			p.a.VIT += 4;

			p.s.name = "No Shield";
			p.s.defense = 1;
			p.s.weight = 0;
		}
		break;

		case 2:
		{
			cout<<"\nYou chose Class Battlemage"<<endl;
			p.pclass = "Battlemage";

			p.STR += 13;
			p.VIT += 16;
			p.DEX += 8;
			p.STA += 7;
			p.FAI += 10;
			p.INE += 16;
			p.luck = 2;

			p.no_hp = 10;
			
			p.w.name= "Blade of the Magi";
			p.w.damage = 16;
			p.w.weight = 12;
			p.w.FAI += 2;
			p.w.INE += 2;
			p.w.dh = false;
			p.w.type = SWORD;
			p.w.material = IRON;

			p.a.name = "Heavy Iron Armor";
			p.a.defense = 8;
			p.a.weight = 9;
			p.a.VIT += 4;

			p.s.name = "Iron Shield Of The Magi";
			p.s.defense = 6;
			p.s.weight = 3;
			p.s.INE += 4;
		}
		break;
		
		case 3:
		{
			cout<<"\nYou chose Class Herald"<<endl;
			p.pclass = "Herald";

			p.STR += 11;
			p.VIT += 17;
			p.DEX += 8;
			p.STA += 6;
			p.FAI += 17;
			p.INE += 11;
			p.luck = 3;

			p.no_hp = 12;
			
			p.w.name= "Iron Spear";
			p.w.damage = 20;
			p.w.weight = 10;
			p.w.STR += 1;
			p.w.FAI += 3;
			p.w.dh = false;
			p.w.type = SPEAR;
			p.w.material = IRON;
			
			p.a.name = "Light Iron Armor";
			p.a.defense = 5;
			p.a.weight = 5;
			p.a.VIT += 1;
			p.a.FAI += 3;

			p.s.name = "Iron Shield Of The Magi";
			p.s.defense = 6;
			p.s.weight = 3;
			p.s.INE += 4;
		}
		break;
		
		case 4:
		{
			cout<<"\nYou chose Class Knight"<<endl;
			p.pclass = "Knight";

			p.STR += 15;
			p.VIT += 18;
			p.DEX += 18;
			p.STA += 9;
			p.FAI += 6;
			p.INE += 4;
			p.luck = 2;

			p.no_hp = 10;
			
			p.w.name= "Rusty Sword";
			p.w.damage = 30;
			p.w.weight = 15;
			p.w.STR += 2;
			p.w.DEX += 2;
			p.w.dh = false;
			p.w.type = SWORD;
			p.w.material = IRON;
			
			p.a.name = "Heavy Iron Armor";
			p.a.defense = 8;
			p.a.weight = 9;
			p.a.VIT += 4;

			p.s.name = "Heavy Iron Shield";
			p.s.defense = 8;
			p.s.weight = 4;
			p.s.STR += 2;
			p.s.DEX += 2;
		}
		break;

		case 5:
		{
			cout<<"\nYou chose Class Mercenary"<<endl;
			p.pclass = "Mercenary";

			p.STR += 23;
			p.VIT += 12;
			p.DEX += 16;
			p.STA += 11;
			p.FAI += 4;
			p.INE += 4;
			p.luck = 3;

			p.no_hp = 8;
			
			p.w.name= "Iron Sword";
			p.w.damage = 20;
			p.w.weight = 12;
			p.w.DEX += 5;
			p.w.dh = false;
			p.w.type = SWORD;
			p.w.material = IRON;
			
			p.a.name = "Heavy Cloth Armor";
			p.a.defense = 4;
			p.a.weight = 4;
			p.a.STA += 4;
			p.a.VIT += 1;

			p.s.name = "Iron Shield";
			p.s.defense = 6;
			p.s.weight = 3;
			p.s.STR += 2;
			p.s.DEX += 2;
		}
		break;
		
		case 6:
		{
			cout<<"\nYou chose Class Rogue"<<endl;
			p.pclass = "Rogue";

			p.STR += 14;
			p.VIT += 8;
			p.DEX += 16;
			p.STA += 19;
			p.FAI += 8;
			p.INE += 5;
			p.luck = 8;

			p.no_hp = 16;
			
			p.w.name= "Rusty Dagger";
			p.w.damage = 10;
			p.w.weight = 2;
			p.w.STR += 1;
			p.w.DEX += 3;
			p.w.dh = false;
			p.w.type = DAGGER;
			p.w.material = IRON;
			
			p.a.name = "Leather Clothes";
			p.a.defense = 2;
			p.a.weight = 0;
			p.a.STA += 4;

			p.s.name = "Leather Shield";
			p.s.defense = 4;
			p.s.weight = 2;
			p.s.DEX += 4;
		}
		break;

		case 7:
		{
			cout<<"\nYou chose Class Assassin"<<endl;
			p.pclass = "Assassin";

			p.STR += 19;
			p.VIT += 8;
			p.DEX += 12;
			p.STA += 17;
			p.FAI += 7;
			p.INE += 7;
			p.luck = 4;

			p.no_hp = 16;
			
			p.w.name= "Eastern Iron Sword";
			p.w.damage = 18;
			p.w.weight = 11;
			p.w.STR += 1;
			p.w.DEX += 3;
			p.w.dh = false;
			p.w.type = SWORD;
			p.w.material = IRON;
			
			p.a.name = "Leather Clothes";
			p.a.defense = 2;
			p.a.weight = 0;
			p.a.STA += 4;	

			p.s.name = "Leather Shield";
			p.s.defense = 4;
			p.s.weight = 2;
			p.s.DEX += 4;
		}
		break;

		case 8:
		{
			cout<<"\nYou chose Class Spell-Sword"<<endl;
			p.pclass = "Spell-Sword";

			p.STR += 11;
			p.VIT += 6;
			p.DEX += 8;
			p.STA += 18;
			p.FAI += 11;
			p.INE += 16;
			p.luck = 4;

			p.no_hp = 10;
			
			p.w.name= "Iron Wizard Blade";
			p.w.damage = 10;
			p.w.weight = 4;
			p.w.FAI += 1;
			p.w.INE += 4;
			p.w.dh = false;
			p.w.type = DAGGER;
			p.w.material = IRON;
			
			p.a.name = "Leather Clothes";
			p.a.defense = 2;
			p.a.weight = 0;
			p.a.STA += 2;

			p.s.name = "Leather Shield";
			p.s.defense = 4;
			p.s.weight = 2;
			p.s.DEX += 4;
		}
		break;
		
		case 9:
		{
			cout<<"\nYou choose Class Pyromancer"<<endl;
			p.pclass = "Pyromancer";

			p.STR += 4;
			p.VIT += 11;
			p.DEX += 8;
			p.STA += 6;
			p.FAI += 17;
			p.INE += 22;
			p.luck = 3;

			p.no_hp = 6;
			
			p.w.name= "Walking Stick";
			p.w.damage = 1;
			p.w.weight = 2;
			p.w.FAI += 2;
			p.w.INE += 2;
			p.w.dh = true;
			p.w.type = STAFF;
			p.w.material = WOOD;
			
			p.a.name = "Plain Robes";
			p.a.defense = 1;
			p.a.weight = 0;
			p.a.FAI += 2;
			p.a.INE += 2;

			p.s.name = "No Shield";
			p.s.defense = 1;
			p.s.weight = 0;
		}
		break;

		case 10:
		{
			cout<<"\nYou chose Class Adventurer"<<endl;
			p.pclass = "Adventurer";

			p.STR += 13;
			p.VIT += 14;
			p.DEX += 11;
			p.STA += 12;
			p.FAI += 10;
			p.INE += 10;
			p.luck = 2;

			p.no_hp = 16;
			
			p.w.name= "Rusty Iron Sword";
			p.w.damage = 17;
			p.w.weight = 10;
			p.w.STR += 2;
			p.w.DEX += 2;
			p.w.dh = false;
			p.w.type = SWORD;
			p.w.material = IRON;
			
			p.a.name = "Heavy Cloth Armor";
			p.a.defense = 4;
			p.a.weight = 4;
			p.a.STA += 2;

			p.s.name = "Leather Shield";
			p.s.defense = 4;
			p.s.weight = 2;
			p.s.DEX += 4;
		}
		break;
	}

	addplayerstats_weapons(p);
	addplayerstats_armors(p);
	addplayerstats_shields(p);

	p.setattributes();	
	
	c = WHITE;
	setcolor();

	return choice;
}

int custom_character(player&p)
{
	int total = 0, choice_STR = 0, choice_VIT = 0, choice_DEX = 0, choice_STA = 0, choice_FAI = 0, choice_INE = 0, choice_weapon = 0, choice_armor = 0; 

	cout<<"\nPlease set your stats";

	c = RED;
	setcolor();

	cout<<" [Keep in mind maximum sum must be 70]"<<endl;

	c = WHITE;
	setcolor();

	do
	{
		total = 0;

		cout<<"\nEnter Strength : ";
		cin>>choice_STR; total += choice_STR; p.STR += choice_STR;

		cout<<"\nEnter Vitality : ";
		cin>>choice_VIT; total += choice_VIT; p.VIT += choice_VIT;

		cout<<"\nEnter Dexterity : ";
		cin>>choice_DEX; total += choice_DEX; p.DEX += choice_DEX;

		cout<<"\nEnter Stamina : ";
		cin>>choice_STA; total += choice_STA; p.STA += choice_STA;

		cout<<"\nEnter Faith : ";
		cin>>choice_FAI; total += choice_FAI; p.FAI += choice_FAI;

		cout<<"\nEnter Intelligence : ";
		cin>>choice_INE; total += choice_INE; p.INE += choice_INE;

		if(total <= 70)
		{
			break;
		}

		else
		{
			c = RED;
			setcolor();

			cout<<"\nThe total is not 70. Try again"<<endl;

			c = WHITE;
			setcolor();
		}

	} while(total != 70);

	cout<<"\nBlacksmith : You should also choose your weapon, armor and shield"<<endl;

	line();

	cout<<"\nChoose your weapon "<<endl;

	weapon temp1, temp2, temp3, temp4, temp5;

	cout<<"\n1. Iron Mace"; 

	temp1.name = "Iron Mace";
	temp1.damage = 50;
	temp1.weight = 24;
	temp1.dh = true;
	temp1.STR += 4;
	temp1.type = HV_BLUDGE;
	temp1.material = IRON;

	display_weaponstats(temp1); cout<<endl;

	cout<<"\n2. Rusty Sword"; 

	temp2.name = "Rusty Sword";
	temp2.damage = 30;
	temp2.weight = 15;
	temp2.dh = false;
	temp2.STR += 2;
	temp2.DEX += 2;
	temp2.type = SWORD;
	temp2.material = IRON;

	display_weaponstats(temp2); cout<<endl;

	cout<<"\n3. Rusty Dagger"; 

	temp3.name = "Rusty Dagger";
	temp3.damage = 10;
	temp3.weight = 2;
	temp3.dh = false;
	temp3.STR += 1;
	temp3.DEX += 3;
	temp3.type = DAGGER;
	temp3.material = IRON;

	display_weaponstats(temp3); cout<<endl;

	cout<<"\n4. Iron Wizard Blade"; 

	temp4.name = "Iron Wizard Blade";
	temp4.damage = 10;
	temp4.weight = 4;
	temp4.dh = false;
	temp4.FAI += 1;
	temp4.INE += 3;
	temp4.type = DAGGER;
	temp4.material = IRON;

	display_weaponstats(temp4); cout<<endl;

	cout<<"\n5. Walking Stick"; 

	temp5.name = "Walking Stick";
	temp5.damage = 1;
	temp5.weight = 2;
	temp5.dh = true;
	temp5.FAI += 2;
	temp5.INE += 2;
	temp5.type = STAFF;
	temp5.material = WOOD;

	display_weaponstats(temp5); cout<<endl;

	cout<<"\nInput choice : ";
	cin>>choice_weapon;

	switch(choice_weapon)
	{
		case 1: if(p.STR >= temp1.weight) p.w = temp1; else p.w = temp4;
		break;

		case 2: if(p.STR >= temp2.weight) p.w = temp2; else p.w = temp4;
		break;

		case 3: if(p.STR >= temp3.weight) p.w = temp3; else p.w = temp4;
		break;

		case 4: if(p.STR >= temp4.weight) p.w = temp4; else p.w = temp4;
		break;

		case 5: if(p.STR >= temp5.weight) p.w = temp5; else p.w = temp4;
		break;
	}

	cout<<"\nYou now weild the "<<p.w.name<<endl;

	line();

	armor atemp1, atemp2, atemp3;

	cout<<"\nChoose your armor "<<endl;

	cout<<"\n1. Iron Heavy Armor";

	atemp1.name = "Heavy Iron Armor";
	atemp1.defense = 8;
	atemp1.weight = 9;
	atemp1.VIT += 4;

	display_armorstats(atemp1); cout<<endl;

	cout<<"\n2. Leather Clothes";

	atemp2.name = "Leather Clothes";
	atemp2.defense = 2;
	atemp2.weight = 0;
	atemp2.STA += 2;

	display_armorstats(atemp2); cout<<endl;

	cout<<"\n3. Plain Robes";

	atemp3.name = "Plain Robes";
	atemp3.defense = 1;
	atemp3.weight = 0;
	atemp3.FAI += 2;
	atemp3.INE += 2;

	display_armorstats(atemp3); cout<<endl;

	cout<<"\nInput choice : ";
	cin>>choice_armor;

	switch(choice_armor)
	{
		case 1: if(p.VIT >= atemp1.weight) p.a = atemp1; else p.a = atemp2;
		break;

		case 2: p.a = atemp2;
		break;

		case 3: p.a = atemp3;
		break;
	}

	cout<<"\nYou wear the "<<p.a.name<<endl;

	cout<<"\nBlacksmith : Alright lad. Yer ready. Good luck."<<endl;

	addplayerstats_weapons(p);
	addplayerstats_armors(p);
	addplayerstats_shields(p);

	p.setattributes();	

	line();

	return 0;
}

int enemyclass1(enemy&e)
{
	srand(time(0));
	
	int echoice = (rand () % 8);
	
	e.dodge = 0;
	e.sdodge = 0;
	
	switch(echoice)
	{
		case 0:
		{
			e.name = "Kobold";
			e.HP = 600;
			e.damage = 40;
			e.cdamage = 120;

			e.nattack = "CLAW ATTACK";
			e.cattack = "FANGED FURY";

			e.type = BEAST;
		}
		break;
		
		case 1:
		{
			e.name = "Zombie Lizard";
			e.HP = 1000;
			e.damage = 20;
			e.cdamage = 75;

			e.nattack = "LICK";
			e.cattack = "CROOKED CLAW";

			e.type = UNHOLY;
		}
		break;
		
		case 2:
		{
			e.name = "Feral Rabbit";
			e.HP = 200;
			e.damage = 50;
			e.cdamage = 500;
			e.sdodge = 1;

			e.nattack = "BITE";
			e.cattack = "FERAL FRENZY";

			e.type = BEAST;
		}
		break;
		
		case 3:
		{
			e.name = "Skeleton";
			e.HP = 400;
			e.damage = 125;
			e.cdamage = 200;

			e.nattack = "HUMERUS STRIKE";
			e.cattack = "SKELETAL SLAM";

			e.type = UNHOLY;
		}
		break;

		case 4:
		{
			e.name = "Goblin";
			e.HP = 700;
			e.damage = 30;
			e.cdamage = 120;

			e.nattack = "STRIKE OF GREED";
			e.cattack = "COINBAG CRUSH";

			e.type = BEAST;
		}
		break;

		case 5:
		{
			e.name = "Undead Miner";
			e.HP = 500;
			e.damage = 150;
			e.cdamage = 200;

			e.nattack = "PICKAXE SLAM";
			e.cattack = "CAVEDIGGER'S CRUSH";

			e.type = UNHOLY;
		}
		break;

		case 6:
		{
			e.name = "Cave Dwarf";
			e.HP = 400;
			e.damage = 60;
			e.cdamage = 180;

			e.nattack = "DWARVEN PUSH";
			e.cattack = "DUERGAR DAMAGE";

			e.type = BEAST;
		}
		break;

		case 7:
		{
			e.name = "Headless Guard";
			e.HP = 650;
			e.damage = 80;
			e.cdamage = 200;

			e.nattack = "BRUTAL REND";
			e.cattack = "HEADLESS HIT";

			e.type = UNHOLY;
		}
	}

	e.maxHP = e.HP;
	
	return 0;
}

int enemyclass2(enemy&e)
{
	srand(time(0));
	
	int echoice = (rand () % 9);
	
	e.dodge = 0;
	e.sdodge = 0;
	
	switch(echoice)
	{
		case 0:
		{
			e.name = "Undead Pirate";
			e.HP = 1000;
			e.damage = 100;
			e.cdamage = 500;

			e.nattack = "BRUTAL REND";
			e.cattack = "SCIMITAR STRIKE";

			e.type = UNHOLY;
		}
		break;
		
		case 1:
		{
			e.name = "Giant Crab";
			e.HP = 2000;
			e.damage = 75;
			e.cdamage = 200;
			
			e.nattack = "BODY SLAM";
			e.cattack = "CRUSTACEAN CLAW";

			e.type = BEAST;
		}
		break;
		
		case 2:
		{
			e.name = "Vulture";
			e.HP = 300;
			e.damage = 200;
			e.cdamage = 1500;
			e.sdodge = 1;

			e.nattack = "BITE";
			e.cattack = "FLYING FURY";

			e.type = BEAST;
		}
		break;
		
		default:
		{
			e.name = "Undead Viking";
			e.HP = 800;
			e.damage = 300;
			e.cdamage = 400;

			e.nattack = "BRUTAL REND";
			e.cattack = "MARITIME MAYHEM";

			e.type = UNHOLY;
		}
		break;

		case 4:
		{
			e.name = "Pelagic Knight";
			e.HP = 900;
			e.damage = 250;
			e.cdamage = 500;

			e.nattack = "SWORD OF THE SEA";
			e.cattack = "SEAFLOOR SLASH";

			e.type = UNHOLY;
		}
		break;

		case 5:
		{
			e.name = "Ancient Mariner";
			e.HP = 1200;
			e.damage = 250;
			e.cdamage = 400;

			e.nattack = "CLAW ATTACK";
			e.cattack = "ALBATROSS ATTACK";

			e.type = UNHOLY;
		}
		break;

		case 6:
		{
			e.name = "Pelagic Ranger";
			e.HP = 700;
			e.damage = 100;
			e.cdamage = 400;

			e.nattack = "BRUTAL SLASH";
			e.cattack = "SEAFLOOR SLASH";

			e.type = BEAST;
		}
		break;

		case 7:
		{
			e.name = "Sea Cucumber";
			e.HP = 200;
			e.damage = 500;
			e.cdamage = 750;

			e.nattack = "BRUTAL ATTACK";
			e.cattack = "SEAFLOOR SLAM";

			e.type = BEAST;
		}
		break;
	}

	e.maxHP = e.HP;
	
	return 0;
}

int enemyclass(player&p,enemy&e)
{
	switch(p.level)
	{
		case 3:
		{
			enemyclass1(e);
		}
		break;

		case 6:
		{
			enemyclass2(e);
		}
		break;
	}

	return 0;
}

int levelup(player&p)
{
	int choice;
	
	int xp_STR, xp_VIT, xp_DEX, xp_STA, xp_FAI, xp_INE;

	xp_STR = 100;
	xp_VIT = 100;
	xp_DEX = 100;
	xp_STA = 100;
	xp_FAI = 100;
	xp_INE = 100;

	c = WHITE;
	setcolor();

	while(true)
	{
		c = WHITE;
		setcolor();

		cout<<"\nWhat would you like to level up?"<<endl;
		cout<<"\n1. Strength +1 : "<<xp_STR<<endl;
		cout<<"\n2. Vitality +1 : "<<xp_VIT<<endl;
		cout<<"\n3. Dexterity +1 : "<<xp_DEX<<endl;
		cout<<"\n4. Stamina +1 : "<<xp_STA<<endl;
		cout<<"\n5. Faith +1 : "<<xp_FAI<<endl;
		cout<<"\n6. Intelligence +1 : "<<xp_FAI<<endl;
		cout<<"\n7. Exit"<<endl;
		
		cout<<"\nXP : "<<p.xp<<endl;
		
		cout<<"\nInput choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1 :
			{
				if(p.xp >= xp_STR)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYour Strength increased by 1"<<endl;
					p.STR++;
					p.xp -= xp_STR;
				}

				else
				{
					c = RED;
					setcolor();	

					cout<<"\nXP too low"<<endl;

					c = WHITE;
					setcolor();
				}
			}
			break;

			case 2:
			{
				if(p.xp >= xp_VIT)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYour Vitality increased by 1"<<endl;
					p.VIT++;
					p.xp -= xp_VIT;
				}

				else
				{
					c = RED;
					setcolor();	

					cout<<"\nXP too low"<<endl;

					c = WHITE;
					setcolor();
				}
			}
			break;

			case 3:
			{
				if(p.xp >= xp_DEX)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYour Dexterity increased by 1"<<endl;
					p.DEX++;
					p.xp -= xp_DEX;
				}

				else
				{
					c = RED;
					setcolor();	

					cout<<"\nXP too low"<<endl;

					c = WHITE;
					setcolor();
				}
			}
			break;

			case 4:
			{
				if(p.xp >= xp_STA)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYour Stamina increased by 1"<<endl;
					p.STA++;
					p.xp -= xp_STA;
				}

				else
				{
					c = RED;
					setcolor();	

					cout<<"\nXP too low"<<endl;

					c = WHITE;
					setcolor();
				}
			}
			break;

			case 5:
			{
				if(p.xp >= xp_FAI)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYour Faith increased by 1"<<endl;
					p.FAI++;
					p.xp -= xp_FAI;
				}

				else
				{
					c = RED;
					setcolor();	

					cout<<"\nXP too low"<<endl;

					c = WHITE;
					setcolor();
				}
			}
			break;

			case 6:
			{
				if(p.xp >= xp_INE)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYour Intelligence increased by 1"<<endl;
					p.INE++;
					p.xp -= xp_INE;
				}

				else
				{
					c = RED;
					setcolor();	

					cout<<"\nXP too low"<<endl;

					c = WHITE;
					setcolor();
				}
			}
			break;

			default:
			{
				return 0;
			}
			break;
		}

		line();
	}

	p.setattributes();

	c = WHITE;
	setcolor();

	return 0;
}

int log_raws(player&p)
{
	cout<<"\nDamage : "<<p.damage<<endl;
	cout<<"\nMax HP : "<<p.maxHP<<endl;
	cout<<"\nWeapon Handling : "<<p.wh<<endl;
	cout<<"\nDodge : "<<p.dodge<<endl;
	cout<<"\nStealth : "<<p.stealth<<endl;
	cout<<"\nMagic : "<<p.magic<<endl;
	cout<<"\nMax Mana : "<<p.maxM<<endl;
	cout<<"\nSpell Level : "<<p.spellno<<endl;
	cout<<"\nFire : "<<p.fire<<endl;

	return 0;
}

int logging(player&p)
{
	c = GREEN;
	setcolor();

	cout<<"\nPlayer Info"<<endl;
	cout<<endl;

	c = WHITE;
	setcolor();
	
	cout<<"\nName : "<<p.name<<endl;
	cout<<"\nPlaystyle : "<<p.race<<" "<<p.pclass<<endl;

	cout<<"\nHealth : "; printH(p.HP,p.maxHP);
	cout<<"\nMana : "; printM(p.mana, p.maxM);
	cout<<"\nAbility : "; printA(p.ability_point, 5); 
	cout<<"\nStress : "; printS(p.stress, p.stress_limit);

	cout<<"\nStrength : "<<p.STR;

	if(p.w.STR > 0)
	{
		cout<<" [ +";

		c = GREEN;
		setcolor();

		cout<<p.w.STR;

		c = WHITE;
		setcolor();

		cout<<" ]";
	}

	if(p.s.STR > 0)
	{
		cout<<" [ +";

		c = GREEN;
		setcolor();

		cout<<p.s.STR;

		c = WHITE;
		setcolor();

		cout<<" ]";
	}
	cout<<endl;

	cout<<"\nVitality : "<<p.VIT;

	if(p.a.VIT > 0)
	{
		cout<<" [ +";

		c = GREEN;
		setcolor();

		cout<<p.a.VIT;

		c = WHITE;
		setcolor();

		cout<<" ]";
	}
	cout<<endl;

	cout<<"\nDexterity : "<<p.DEX;

	if(p.w.DEX > 0)
	{
		cout<<" [ +";

		c = GREEN;
		setcolor();

		cout<<p.w.DEX;

		c = WHITE;
		setcolor();
		
		cout<<" ]";
	}

	if(p.s.DEX > 0)
	{
		cout<<" [ +";

		c = GREEN;
		setcolor();

		cout<<p.s.DEX;

		c = WHITE;
		setcolor();
		
		cout<<" ]";
	}
	cout<<endl;

	cout<<"\nStamina : "<<p.STA;

	if(p.a.STA > 0)
	{
		cout<<" [ +";

		c = GREEN;
		setcolor();

		cout<<p.a.STA;

		c = WHITE;
		setcolor();

		cout<<" ]";
	}
	cout<<endl;

	cout<<"\nFaith : "<<p.FAI;

	if(p.w.FAI > 0)
	{
		cout<<" [ +";

		c = GREEN;
		setcolor();

		cout<<p.w.FAI;

		c = WHITE;
		setcolor();
		
		cout<<" ]";
	}

	if(p.a.FAI > 0)
	{
		cout<<" [ +";

		c = GREEN;
		setcolor();

		cout<<p.a.FAI;

		c = WHITE;
		setcolor();
		
		cout<<" ]";
	}

	if(p.s.FAI > 0)
	{
		cout<<" [ +";

		c = GREEN;
		setcolor();

		cout<<p.s.FAI;

		c = WHITE;
		setcolor();
		
		cout<<" ]";
	}
	cout<<endl;

	cout<<"\nIntelligence : "<<p.INE;

	if(p.w.INE > 0)
	{
		cout<<" [ +";

		c = GREEN;
		setcolor();

		cout<<p.w.INE;

		c = WHITE;
		setcolor();
		
		cout<<" ]";
	}

	if(p.a.INE > 0)
	{
		cout<<" [ +";

		c = GREEN;
		setcolor();

		cout<<p.a.INE;

		c = WHITE;
		setcolor();
		
		cout<<" ]";
	}

	if(p.s.INE > 0)
	{
		cout<<" [ +";

		c = GREEN;
		setcolor();

		cout<<p.s.INE;

		c = WHITE;
		setcolor();
		
		cout<<" ]";
	}
	cout<<endl;

	cout<<"\nXP : "<<p.xp<<endl;

	line();

	c = GREEN;
	setcolor();
	
	cout<<"\nPlayer Items"<<endl;
	cout<<endl;

	c = WHITE;
	setcolor();
	
	cout<<"\nWeapon : "<<p.w.name; display_weaponstats(p.w); cout<<endl;
	cout<<"\nArmor : "<<p.a.name; display_armorstats(p.a); cout<<endl;
	cout<<"\nShield : "<<p.s.name; if(p.w.dh == false) {display_shieldstats(p.s);} cout<<endl;
	cout<<"\nNo of Healing Potions : "<<p.i.hp<<endl;
	cout<<"\nMoney : "<<p.i.money<<endl;
	cout<<endl;
	
	cout<<"\nFree Space in Inventory : "<<endl;
	cout<<"\nWeapons : "<<5-p.i.weapons<<endl;
	cout<<"\nArmor : "<<2-p.i.armors<<endl;
	
	return 0;
}

int shop(player&p)
{
	srand(time(0));
	
	int check = 1;
	
	while(check == 1)
	{
		cout<<"\nBlacksmith : Welcome back lad. How may I help?"<<endl;
		cout<<"\nWhat would you like to buy?"<<endl;
		cout<<"\n1. Improve Weapon (Improves Damage by 25 percent) : 500 Coins"<<endl;
		cout<<"\n2. Streamline Weapon (Decreases weight by 1) : 250 Coins"<<endl;
		cout<<"\n3. Improve Armor (Improves Defence by 25 percent) : 500 Coins"<<endl;
		cout<<"\n4. Buy Healing Potions (5) : 500 Coins"<<endl;
		cout<<"\n5. Buy Lucky Charm (Luck increases by 2) : 250 Coins"<<endl;
		cout<<"\n6. Exit"<<endl;
		
		cout<<"\nMoney : "<<p.i.money<<endl;
		
		cout<<"\nInput choice : ";

		int choice;
		cin>>choice;
		
		switch(choice)
		{
			case 1:
			{
				if(p.i.money >= 500)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou improved your weapon damage by 25 percent"<<endl;
					p.w.damage = (p.w.damage * 125)/100;
					p.i.money -= 500;
				}
						
				else
				{
					c = RED;
					setcolor();

					cout<<"\nMoney too low"<<endl;
				}		
			}
			break;
			
			case 2:
			{
				if(p.i.money >= 250)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou reduced your weapon weight by 1"<<endl;

					if(p.w.weight > 0) p.w.weight -= 1; else p.w.weight = 0;
					p.i.money -= 500;
				}
						
				else
				{
					c = RED;
					setcolor();

					cout<<"\nMoney too low"<<endl;
				}	
			}
			break;
			
			case 3:
			{
				if(p.i.money >= 500)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou improved your armor defence by 25 percent"<<endl;
					p.a.defense = (p.a.defense*125)/100;
					p.i.money -= 500;
				}
						
				else
				{
					c = RED;
					setcolor();

					cout<<"\nMoney too low"<<endl;
				}	
			}
			break;
			
			case 4:
			{
				if(p.i.money >= 500)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou bought 5 Healing Potions"<<endl;
					p.i.hp += 5;
					p.i.money -= 500;
				}
						
				else
				{
					c = RED;
					setcolor();

					cout<<"\nMoney too low"<<endl;
				}		
			}
			break;
			
			case 5:
			{
				if(p.i.money >= 250)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou bought a Lucky Charm"<<endl;
					p.luck += 5;
					p.i.money -= 250;
				}
						
				else
				{
					c = RED;
					setcolor();

					cout<<"\nMoney too low"<<endl;
				}	
			}
			break;
			
			case 6:
			{
				line();
				check = 0;
				return 0;
			}
			break;
		}
		
		line();

		
		c = WHITE;
		setcolor();
	}

	return 0;
}

int library()
{
	int choice,check = 1;
	
	cout<<"\nYou come to the library"<<endl;
	
	while(check == 1)
	{
		cout<<"\nWhich manuscript would you like to read?"<<endl;
		
		cout<<"\n1. The Attributes"<<endl;
		cout<<"\n2. Weapons and Armor"<<endl;
		cout<<"\n3. Dungeons"<<endl;
		cout<<"\n4. Stress and Stress Management"<<endl;
		cout<<"\n5. Exit"<<endl;
		
		cout<<"\nInput choice : ";
		cin>>choice;
		
		system("cls");
		
		switch(choice)
		{
			case 1:
			{
				cout<<"\nThe Attributes"<<endl;

				cout<<endl;

				cout<<"\n1. You have six stats that determine your attributes : Strength, Vitality, Dexterity, Stamina, Faith, and Intelligence"<<endl;
				cout<<"\n2. Strength controls the damage you do"<<endl;
				cout<<"\n3. Vitality controls your health"<<endl;
				cout<<"\n4. Dexterity controls your weapon handling"<<endl;
				cout<<"\n5. Stamina controls your dodging as well as stealth abilities"<<endl;
				cout<<"\n6. Faith controls your healing magic abilities"<<endl;
				cout<<"\n7. Intelligence controls your general magical abilities, as well as combat magic"<<endl;
			}
			break;
			
			case 2:
			{
				cout<<"\nWeapons and Armor"<<endl;

				cout<<endl;

				cout<<"\n1. You find weapons and armors as random loot around dungeons"<<endl;
				cout<<"\n2. The heavier a weapon, the lesser accurate it would be"<<endl;
				cout<<"\n3. The heavier an armor, the lesser likely you are to dodge an enemy's attack"<<endl;
				cout<<"\n4. You can hold upto 5 weapons and 2 armors in your inventory, and can switch between weapons freely"<<endl;
				cout<<"\n5. Weapons, armors, and shields also hold stats, which get added to your own stats, effectively giving you stat boosts depending on the weapon you hold"<<endl;					
			}
			break;
			
			case 3:
			{
				cout<<"\nDungeons"<<endl;

				cout<<endl;

				cout<<"\n1. Dungeons are the main areas of the game, containing enemies and loot"<<endl;
				cout<<"\n2. Each dungeon has a Collosi at the end of it, after 20 chunks"<<endl;
				cout<<"\n3. Dungeons also have random events such as finding pots, traps, and mini-bosses"<<endl;	
			}
			break;

			case 4:
			{
				cout<<"\nStress and Stress Management"<<endl;

				cout<<endl;

				cout<<"\n1. Stress gets incremented as various events happen during the dungeon"<<endl;
				cout<<"\n2. Stress can affect combat heavily, and if you reach your stress limit, a panic attack occurs and all your stats go down to 5"<<endl;
				cout<<"\n3. Stress can be removed by drinking ales[-5 stress] and healing potions[-1 stress]"<<endl;
			}
			
			case 5:
			{
				return 0;
			}
			break;
		}

		line();
	}

	return 0;
}
