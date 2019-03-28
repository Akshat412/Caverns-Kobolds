#pragma once

#include"resources.h"

using namespace std;

weapon weaponlist(weapon temp, player &p, int x = -999)
{
	srand(time(0));
	int chance;
	
	if(x == -999)
	{
		chance = (rand () % 28) + 1;
	}

	else
	{
		chance = x;
	}
	
	switch(p.level)
	{
		case 3:
		{
			switch(chance)
			{
				case 1:
				{
					temp.name = "Bronze Mace";
					temp.damage = 100;
					temp.weight = 27;
					temp.STR = 5;
					temp.dh = true;
					temp.type = HV_BLUDGE;
				}
				break;

				case 2:
				{
					temp.name = "Bronze Morning Star";
					temp.damage = 125;
					temp.weight = 29;	
					temp.STR = 5;
					temp.dh = true;
					temp.type = HV_BLUDGE;
				}
				break;

				case 3:
				{
					temp.name = "Bronze Longsword";
					temp.damage = 90;
					temp.weight = 22;
					temp.STR = 4;
					temp.DEX = 1;
					temp.dh = true;
					temp.type = HV_SWORD;
				}
				break;

				case 4:
				{
					temp.name = "Bronze Halberd";
					temp.damage = 95;
					temp.weight = 25;
					temp.STR = 4;
					temp.DEX = 1;
					temp.dh = true;
					temp.type = HV_AXE;
				}
				break;

				case 5:
				{
					temp.name = "Bronze Warhammer";
					temp.damage = 110;
					temp.weight = 28;
					temp.STR = 4;
					temp.FAI = 1;
					temp.dh = true;
					temp.type = HV_BLUDGE;
				}
				break;

				case 6:
				{
					temp.name = "Bronze Broadsword";
					temp.damage = 75;
					temp.weight = 16;
					temp.STR = 4;
					temp.DEX = 1;
					temp.dh = true;
					temp.type = HV_SWORD;
				}
				break;

				case 7:
				{
					temp.name = "Bronze Rapier";
					temp.damage = 40;
					temp.weight = 10;
					temp.STR = 2;	
					temp.DEX = 3;
					temp.dh = false;
					temp.type = SWORD;
				}
				break;

				case 8:
				{
					temp.name = "Bronze Lance";
					temp.damage = 50;
					temp.weight = 13;
					temp.STR = 2;
					temp.FAI = 3;
					temp.dh = false;
					temp.type = SPEAR;
				}
				break;

				case 9:
				{
					temp.name = "Bronze Spear";
					temp.damage = 60;
					temp.weight = 14;
					temp.STR = 1;
					temp.FAI = 4;
					temp.dh = false;
					temp.type = SPEAR;
				}
				break;

				case 10:
				{
					temp.name = "Bronze War Axe";
					temp.damage = 35;
					temp.weight = 9;
					temp.STR = 5;
					temp.dh = false;
					temp.type = AXE;
				}
				break;

				case 11:
				{
					temp.name = "Bronze Dagger";
					temp.damage = 10;
					temp.weight = 3;
					temp.DEX = 5;
					temp.dh = false;
					temp.type = DAGGER;
				}
				break;

				case 12:
				{
					temp.name = "Iron Blade";
					temp.damage = 15;
					temp.weight = 8;	
					temp.STR = 1;
					temp.DEX = 4;
					temp.dh = false;
					temp.type = DAGGER;
				}
				break;

				case 13:
				{
					temp.name = "Bronze Blade";
					temp.damage = 25;
					temp.weight = 7;
					temp.STR = 1;
					temp.DEX = 4;
					temp.dh = false;
					temp.type = DAGGER;
				}
				break;

				case 14:
				{
					temp.name = "Bronze Tipped Staff";
					temp.damage = 2;
					temp.weight = 1;
					temp.FAI = 5;
					temp.INE = 5;
					temp.dh = true;
					temp.type = STAFF;
				}
				break;

				case 15:
				{
					temp.name = "Bronze Wizard Blade";
					temp.damage = 20;
					temp.weight = 4;
					temp.FAI = 1;
					temp.INE = 4;
					temp.dh = false;
					temp.type = DAGGER;
				}
				break;

				case 16:
				{
					temp.name = "Copper Maul";
					temp.damage = 110;
					temp.weight = 29;
					temp.STR = 7;
					temp.dh = true;
					temp.type = HV_BLUDGE;
				}
				break;

				case 17:
				{
					temp.name = "Copper Longsword";
					temp.damage = 75;
					temp.weight = 22;
					temp.STR = 4;
					temp.DEX = 3;
					temp.dh = true;
					temp.type = HV_SWORD;
				}
				break;

				case 18:
				{
					temp.name = "Copper Spear";
					temp.damage = 45;
					temp.weight = 14;
					temp.STR = 2;
					temp.FAI = 5;
					temp.dh = false;
					temp.type = SPEAR;
				}
				break;

				default:
				{
					temp.name = "Copper War Axe";
					temp.damage = 25;
					temp.weight = 9;
					temp.STR = 7;
					temp.dh = false;
					temp.type = AXE;
				}
				break;

				case 20:
				{
					temp.name = "Copper Blade";
					temp.damage = 15;
					temp.weight = 7;
					temp.STR = 1;
					temp.DEX = 6;
					temp.dh = false;
					temp.type = DAGGER;
				}
				break;

				case 21:
				{
					temp.name = "Copper Enchanted Sword";
					temp.damage = 30;
					temp.weight = 10;
					temp.FAI = 7;
					temp.dh = false;
					temp.type = SWORD;
				}
				break;

				case 22:
				{
					temp.name = "Copper Claymore";
					temp.damage = 65;
					temp.weight = 20;
					temp.STR = 7;
					temp.dh = true;
					temp.type = SWORD;
				}
				break;

				case 23:
				{
					temp.name = "Copper Hatchet";
					temp.damage = 30;
					temp.weight = 10;
					temp.STR = 5;
					temp.DEX = 2;
					temp.dh = false;
					temp.type = AXE;
				}
				break;

				case 24:
				{
					temp.name = "Copper Tomahawk";
					temp.damage = 40;
					temp.weight = 11;
					temp.STR = 6;
					temp.DEX = 1;
					temp.dh = false;
					temp.type = AXE;
				}
				break;

				case 25:
				{
					temp.name = "Copper Bo";
					temp.damage = 20;
					temp.weight = 5;
					temp.DEX = 7;
					temp.dh = false;
					temp.type = STAFF;
				}
				break;
			}

		}
		break;

		case 6:
		{
			switch(chance)
			{
				case 1:
				{
					temp.name = "Steel Mace";
					temp.damage = 200;
					temp.weight = 26;
					temp.STR = 5;
					temp.dh = true;
					temp.type = HV_BLUDGE;
				}
				break;

				case 2:
				{
					temp.name = "Steel Halberd";
					temp.damage = 175;
					temp.weight = 22;
					temp.STR = 4;
					temp.DEX = 1;
					temp.dh = true;
					temp.type = HV_AXE;
				}
				break;

				case 3:
				{
					temp.name = "Steel Maul";
					temp.damage = 250;
					temp.weight = 29;
					temp.STR = 5;
					temp.dh = true;
					temp.type = HV_BLUDGE;
				}
				break;

				case 4:
				{
					temp.name = "Steel Longsword";
					temp.damage = 150;
					temp.weight = 20;
					temp.STR = 3;
					temp.DEX = 2;
					temp.dh = true;
					temp.type = HV_SWORD;
				}
				break;

				case 5:
				{
					temp.name = "Steel Warhammer";
					temp.damage = 225;
					temp.weight = 28;
					temp.STR = 3;
					temp.FAI = 2;
					temp.dh = true;
					temp.type = HV_BLUDGE;
				}
				break;

				case 6:
				{
					temp.name = "Steel War Axe";
					temp.damage = 70;
					temp.weight = 9;
					temp.STR = 1;
					temp.DEX = 4;
					temp.dh = false;
					temp.type = AXE;
				}
				break;

				case 7:
				{
					temp.name = "Steel Rapier";
					temp.damage = 80;
					temp.weight = 10;
					temp.STR = 1;	
					temp.DEX = 4;
					temp.dh = false;
					temp.type = SWORD;
				}
				break;

				case 8:
				{
					temp.name = "Steel Broadsword";
					temp.damage = 150;
					temp.weight = 20;
					temp.STR = 4;
					temp.DEX = 1;
					temp.dh = true;
					temp.type = HV_SWORD;
				}
				break;

				case 9:
				{
					temp.name = "Steel Spear";
					temp.damage = 125;
					temp.weight = 15;
					temp.STR = 2;
					temp.FAI = 3;
					temp.dh = false;
					temp.type = SPEAR;
				}
				break;

				case 10:
				{
					temp.name = "Steel Lance";
					temp.damage = 100;
					temp.weight = 13;
					temp.STR = 3;
					temp.FAI = 2;
					temp.dh = false;
					temp.type = SPEAR;
				}
				break;

				case 11:
				{
					temp.name = "Steel Dagger";
					temp.damage = 20;
					temp.weight = 3;
					temp.DEX = 5;
					temp.dh = false;
					temp.type = DAGGER;
				}
				break;

				case 12:
				{
					temp.name = "Steel Blade";
					temp.damage = 50;
					temp.weight = 8;
					temp.STR = 1;
					temp.DEX = 4;
					temp.dh = false;
					temp.type = DAGGER;
				}
				break;

				case 13:
				{
					temp.name = "Bronze Blade";
					temp.damage = 25;
					temp.weight = 7;
					temp.STR = 1;
					temp.DEX = 4;
					temp.dh = false;
					temp.type = DAGGER;
				}
				break;

				case 14:
				{
					temp.name = "Steel Tipped Staff";
					temp.damage = 3;
					temp.weight = 2;
					temp.FAI = 5;
					temp.INE = 5;
					temp.dh = true;
					temp.type = STAFF;
				}
				break;

				case 15:
				{
					temp.name = "Steel Wizard Blade";
					temp.damage = 35;
					temp.weight = 4;
					temp.FAI = 1;
					temp.INE = 4;
					temp.dh = false;
					temp.type = DAGGER;
				}
				break;

				case 16:
				{
					temp.name = "Silver Mace";
					temp.damage = 180;
					temp.weight = 27;
					temp.STR = 7;
					temp.dh = true;
					temp.type = HV_BLUDGE;
				}
				break;

				case 17:
				{
					temp.name = "Silver Longsword";
					temp.damage = 140;
					temp.weight = 22;
					temp.STR = 4;
					temp.DEX = 3;
					temp.dh = true;
					temp.type = HV_SWORD;
				}
				break;

				default:
				{
					temp.name = "Silver Spear";
					temp.damage = 90;
					temp.weight = 14;
					temp.STR = 2;
					temp.FAI = 5;
					temp.dh = false;
					temp.type = SPEAR;
				}
				break;

				case 19:
				{
					temp.name = "Silver War Axe";
					temp.damage = 50;
					temp.weight = 9;
					temp.STR = 7;
					temp.dh = false;
					temp.type = AXE;
				}
				break;

				case 20:
				{
					temp.name = "Silver Blade";
					temp.damage = 35;
					temp.weight = 7;
					temp.STR = 1;
					temp.DEX = 6;
					temp.dh = false;
					temp.type = DAGGER;
				}
				break;

				case 21:
				{
					temp.name = "Silver Enchanted Sword";
					temp.damage = 60;
					temp.weight = 10;
					temp.FAI = 7;
					temp.dh = false;
					temp.type = SWORD;
				}
				break;

				case 22:
				{
					temp.name = "Silver Claymore";
					temp.damage = 120;
					temp.weight = 20;
					temp.STR = 7;
					temp.dh = true;
					temp.type = SWORD;
				}
				break;

				case 23:
				{
					temp.name = "Silver Hatchet";
					temp.damage = 60;
					temp.weight = 10;
					temp.STR = 5;
					temp.DEX = 2;
					temp.dh = false;
					temp.type = AXE;
				}
				break;

				case 24:
				{
					temp.name = "Silver Tomahawk";
					temp.damage = 80;
					temp.weight = 11;
					temp.STR = 6;
					temp.DEX = 1;
					temp.dh = false;
					temp.type = AXE;
				}
				break;

				case 25:
				{
					temp.name = "Silver Bo";
					temp.damage = 40;
					temp.weight = 5;
					temp.DEX = 7;
					temp.dh = false;
					temp.type = STAFF;
				}
				break;
			}
		}
		break;
	}

	return temp;
}

armor armorlist(armor temp,player&p)
{
	srand(time(0));

	int chance;
	
	chance = (rand () % 10) + 1;

	switch(p.level)
	{
		case 3:
		{
			switch(chance)
			{
				case 1:
				{
					temp.name = "Bronze Heavy Armor";
					temp.defense = 30;
					temp.weight = 10;
					temp.VIT = 5;
				}
				break;

				case 2:
				{
					temp.name = "Bronze Warrior Armor";
					temp.defense = 25;
					temp.weight = 9;
					temp.VIT = 5;
				}
				break;

				case 3:
				{
					temp.name = "Bronze Plate Armor";
					temp.defense = 20;
					temp.weight = 8;
					temp.VIT = 4;
					temp.STA = 1;
				}
				break;

				default:
				{
					temp.name = "Bronze Paladin Armor";
					temp.defense = 30;
					temp.weight = 10;
					temp.FAI = 2;
					temp.INE = 3;
				}
				break;

				case 5:
				{
					temp.name = "Bronze Light Armor";
					temp.defense = 10;
					temp.weight = 5;
					temp.VIT = 3;
					temp.STA = 2;
				}
				break;

				case 6:
				{
					temp.name = "Bronze Compound Armor";
					temp.defense = 15;
					temp.weight = 6;
					temp.VIT = 4;
					temp.STA = 1;
				}
				break;

				case 7:
				{
					temp.name = "Bronze Stealth Armor";
					temp.defense = 7;
					temp.weight = 3;
					temp.VIT = 2;
					temp.STA = 3;
				}
				break;

				case 8:
				{
					temp.name = "Leather Stealth Armor";
					temp.defense = 5;
					temp.weight = 1;
					temp.STA = 5;
				}
				break;

				case 9:
				{
					temp.name = "Leather Compound Armor";
					temp.defense = 6;
					temp.weight = 2;
					temp.VIT = 1;
					temp.STA = 4;
				}
				break;

				case 10:
				{
					temp.name = "Mage Robes";
					temp.defense = 1;
					temp.weight = 0;
					temp.FAI = 5;
					temp.INE = 5;
				}
			}
		}
		break;

		case 6:
		{
			switch(chance)
			{
				case 1:
				{
					temp.name = "Steel Heavy Armor";
					temp.defense = 60;
					temp.weight = 10;
					temp.VIT = 5;
				}
				break;

				case 2:
				{
					temp.name = "Steel Warrior Armor";
					temp.defense = 50;
					temp.weight = 9;
					temp.VIT = 5;
				}
				break;

				case 3:
				{
					temp.name = "Steel Plate Armor";
					temp.defense = 40;
					temp.weight = 8;
					temp.VIT = 1;
				}
				break;

				case 4:
				{
					temp.name = "Steel Paladin Armor";
					temp.defense = 60;
					temp.weight = 10;
					temp.FAI = 2;
					temp.INE = 3;
				}
				break;

				case 5:
				{
					temp.name = "Steel Light Armor";
					temp.defense = 20;
					temp.weight = 5;
					temp.VIT = 3;
					temp.FAI = 2;
				}
				break;

				default:
				{
					temp.name = "Steel Compound Armor";
					temp.defense = 25;
					temp.weight = 6;
					temp.VIT = 4;
					temp.STA = 1;
				}
				break;

				case 7:
				{
					temp.name = "Steel Stealth Armor";
					temp.defense = 14;
					temp.weight = 4;
					temp.VIT = 2;
					temp.STA = 3;
				}
				break;

				case 8:
				{
					temp.name = "Fortified Leather Armor";
					temp.defense = 10;
					temp.weight = 1;
					temp.STA = 5;
				}
				break;

				case 9:
				{
					temp.name = "Pyromancy Robes";
					temp.defense = 2;
					temp.weight = 0;
					temp.INE = 10;
				}
				break;

				case 10:
				{
					temp.name = "Elite Mage Robes";
					temp.defense = 2;
					temp.weight = 0;
					temp.FAI = 5;
					temp.INE = 5;
				}
			}
		}
		break;
	}

	return temp;
}

shield shieldlist(shield temp,player&p)
{
	srand(time(0));

	int chance;

	chance = (rand () % 5) + 1;

	switch(p.level)
	{
		case 3:
		{
			switch(chance)
			{
				case 1:
				{
					temp.name = "Heavy Bronze Shield";
					temp.defense = 20;
					temp.weight = 4;
					temp.STR += 5;
				}
				break;

				case 2:
				{
					temp.name = "Bronze Shield of the Magi";
					temp.defense = 13;
					temp.weight = 3;
					temp.FAI += 2;
					temp.INE += 3;
				}
				break;

				case 3:
				{
					temp.name = "Bronze Shield";
					temp.defense = 13;
					temp.weight = 3;
					temp.STR += 3;
					temp.DEX += 2;
				}
				break;

				case 4:
				{
					temp.name = "Fortified Leather Shield";
					temp.defense = 8;
					temp.weight = 2;
					temp.DEX += 5;
				}
				break;

				case 5:
				{
					temp.name = "Intelligence Talisman";
					temp.defense = 2;
					temp.weight = 1;
					temp.INE += 10;
				}
				break;
			}
		}
		break;

		case 6:
		{
			switch(chance)
			{
				case 1:
				{
					temp.name = "Heavy Steel Shield";
					temp.defense = 40;
					temp.weight = 4;
					temp.STR += 5;
				}
				break;

				case 2:
				{
					temp.name = "Steel Shield of the Magi";
					temp.defense = 25;
					temp.weight = 3;
					temp.FAI += 2;
					temp.INE += 3;
				}
				break;

				case 3:
				{
					temp.name = "Steel Shield";
					temp.defense = 26;
					temp.weight = 3;
					temp.STR += 3;
					temp.DEX += 2;
				}
				break;

				case 4:
				{
					temp.name = "Compound Leather Shield";
					temp.defense = 16;
					temp.weight = 2;
					temp.DEX += 5;
				}
				break;

				case 5:
				{
					temp.name = "Warlock Talisman";
					temp.defense = 2;
					temp.weight = 1;
					temp.INE += 15;
				}
				break;
			}
		}
	}

	return temp;
}
