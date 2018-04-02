#pragma once

using namespace std;

weapon weaponlist(weapon temp,player&p)
{
	srand(time(0));
	int chance;
	
	chance = (rand () % 5) + 1;

	switch(p.level)
	{
		case 2:
		{
			switch(p.wtype)
			{
				case 1:
				{
					switch(chance)
					{
						case 1:
						{
							temp.name = "Bronze Mace";
							temp.damage = 100;
							temp.weight = 27;
							temp.STR = 2;
						}
						break;
						
						case 2:
						{
							temp.name = "Bronze Morning Star";
							temp.damage = 125;
							temp.weight = 29;	
							temp.STR = 4;
						}
						break;
						
						case 3:
						{
							temp.name = "Bronze Longsword";
							temp.damage = 90;
							temp.weight = 22;
							temp.STR = 1;
							temp.DEX = 2;
						}
						break;

						case 4:
						{
							temp.name = "Bronze Halberd";
							temp.damage = 95;
							temp.weight = 25;
							temp.STR = 1;
							temp.FAI = 1;
						}
						break;

						case 5:
						{
							temp.name = "Bronze Warhammer";
							temp.damage = 110;
							temp.weight = 28;
							temp.STR = 3;
						}
						break;
					}
				}
				break;
				
				case 2:
				{
					switch(chance)
					{
						case 1:
						{
							temp.name = "Bronze Broadsword";
							temp.damage = 75;
							temp.weight = 16;
							temp.STR = 2;
						}
						break;
						
						case 2:
						{
							temp.name = "Bronze Rapier";
							temp.damage = 40;
							temp.weight = 10;	
							temp.DEX = 4;
						}
						break;
						
						case 3:
						{
							temp.name = "Bronze Lance";
							temp.damage = 50;
							temp.weight = 13;
							temp.STR = 1;
							temp.FAI = 2;
						}
						break;

						case 4:
						{
							temp.name = "Bronze Spear";
							temp.weight = 60;
							temp.weight = 14;
							temp.FAI = 3;
						}
						break;

						case 5:
						{
							temp.name = "Bronze War Axe";
							temp.damage = 35;
							temp.weight = 9;
							temp.STR = 4;
							temp.DEX = 2;
						}
						break;
					}
				}
				break;
				
				case 3:
				{
					switch(chance)
					{
						case 1:
						{
							temp.name = "Bronze Dagger";
							temp.damage = 10;
							temp.weight = 3;
							temp.DEX = 2;
						}
						break;
						
						default:
						{
							temp.name = "Iron Blade";
							temp.damage = 15;
							temp.weight = 8;	
							temp.STR = 1;
						}
						break;
						
						case 3:
						{
							temp.name = "Bronze Blade";
							temp.damage = 25;
							temp.weight = 7;
							temp.STR = 1;
						}
						break;
					}
				}
				break;
				
				case 4:
				{
					temp.name = "Bronze Tipped Staff";
					temp.damage = 2;
					temp.weight = 10;
					temp.FAI = 5;
					temp.INE = 5;
				}
				break;
			}
		}
		break;

		case 3 :
		{
			switch(p.wtype)
			{
				case 1:
				{
					switch(chance)
					{
						case 1:
						{
							temp.name = "Steel Mace";
							temp.damage = 200;
							temp.weight = 26;
							temp.STR = 2;
						}
						break;
						
						case 2:
						{
							temp.name = "Steel Halberd";
							temp.damage = 175;
							temp.weight = 22;
							temp.STR = 1;
							temp.FAI = 1;	
						}
						break;
						
						case 3:
						{
							temp.name = "Steel Maul";
							temp.damage = 250;
							temp.weight = 29;
							temp.STR = 4;
						}
						break;

						case 4:
						{
							temp.name = "Steel Longsword";
							temp.damage = 150;
							temp.weight = 20;
							temp.STR = 1;
							temp.DEX = 2;
						}
						break;

						case 5:
						{
							temp.name = "Steel Warhammer";
							temp.damage = 225;
							temp.weight = 28;
							temp.STR = 3;
						}
						break;
					}
				}
				break;
				
				case 2:
				{
					switch(chance)
					{
						case 1:
						{
							temp.name = "Steel War Axe";
							temp.damage = 70;
							temp.weight = 9;
							temp.STR = 4;
							temp.DEX = 2;
						}
						break;
						
						case 2:
						{
							temp.name = "Steel Rapier";
							temp.damage = 80;
							temp.weight = 10;	
							temp.DEX = 4;
						}
						break;
						
						case 3:
						{
							temp.name = "Steel Spear";
							temp.damage = 125;
							temp.weight = 15;
							temp.FAI = 3;
						}
						break;

						case 4:
						{
							temp.name = "Steel Broadsword";
							temp.damage = 150;
							temp.weight = 20;
							temp.STR = 3;
						}
						break;

						case 5:
						{
							temp.name = "Steel Lance";
							temp.damage = 100;
							temp.weight = 13;
							temp.STR = 1;
							temp.FAI = 2;
						}
						break;
					}
				}
				break;
				
				case 3:
				{
					switch(chance)
					{
						case 1:
						{
							temp.name = "Steel Dagger";
							temp.damage = 20;
							temp.weight = 3;
							temp.DEX = 2;
						}
						break;
						
						default:
						{
							temp.name = "Steel Blade";
							temp.damage = 50;
							temp.weight = 8;
							temp.STR = 1;	
						}
						break;
						
						case 3:
						{
							temp.name = "Bronze Blade";
							temp.damage = 25;
							temp.weight = 7;
							temp.STR = 1;
						}
						break;
					}
				}
				break;
				
				case 4:
				{
					temp.name = "Steel Tipped Staff";
					temp.damage = 3;
					temp.weight = 10;
					temp.FAI = 5;
					temp.INE = 5;
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
	
	chance = (rand () % 3) + 1;

	switch(p.level)
	{
		case 2 :
		{
			switch(p.atype)
			{
				case 1:
				{
					switch(chance)
					{
						case 1:
						{
							temp.name = "Bronze Heavy Armor";
							temp.defense = 30;
							temp.weight = 10;
						}
						break;
						
						case 2:
						{
							temp.name = "Bronze Warrior Armor";
							temp.defense = 25;
							temp.weight = 9;
						}
						break;
						
						case 3:
						{
							temp.name = "Bronze Plate Armor";
							temp.defense = 20;
							temp.weight = 8;
						}
						break;
					}
				}
				break;
				
				case 2:
				{
					switch(chance)
					{
						case 1:
						{
							temp.name = "Bronze Light Armor";
							temp.defense = 10;
							temp.weight = 5;
						}
						break;
						
						case 2:
						{
							temp.name = "Bronze Compound Armor";
							temp.defense = 15;
							temp.weight = 6;
						}
						break;
						
						case 3:
						{
							temp.name = "Bronze Stealth Armor";
							temp.defense = 7;
							temp.weight = 3;
						}
						break;
					}	
				}
				break;
				
				case 3:
				{
					temp.name = "Leather Stealth Armor";
					temp.defense = 5;
					temp.weight = 1;
				}
				break;
				
				case 4:
				{
					temp.name = "Mage Robes";
					temp.defense = 5;
					temp.weight = 0;
				}
				break;
			}
		}
		break;

		case 3 :
		{
			switch(p.atype)
			{
				case 1:
				{
					switch(chance)
					{
						case 1:
						{
							temp.name = "Steel Heavy Armor";
							temp.defense = 60;
							temp.weight = 10;
						}
						break;
						
						case 2:
						{
							temp.name = "Steel Warrior Armor";
							temp.defense = 50;
							temp.weight = 9;
						}
						break;
						
						case 3:
						{
							temp.name = "Steel Plate Armor";
							temp.defense = 40;
							temp.weight = 8;
						}
						break;
					}
				}
				break;
				
				case 2:
				{
					switch(chance)
					{
						case 1:
						{
							temp.name = "Steel Light Armor";
							temp.defense = 20;
							temp.weight = 5;
						}
						break;
						
						case 2:
						{
							temp.name = "Steel Compound Armor";
							temp.defense = 25;
							temp.weight = 6;
						}
						break;
						
						case 3:
						{
							temp.name = "Steel Stealth Armor";
							temp.defense = 14;
							temp.weight = 4;
						}
						break;
					}
				}
				break;
				
				case 3:
				{
					temp.name = "Fortified Leather Armor";
					temp.defense = 10;
					temp.weight = 1;
				}
				break;
				
				case 4:
				{
					temp.name = "Elite Mage Robes";
					temp.defense = 10;
					temp.weight = 0;
				}
				break;
			}
		}
		break;
	}

	return temp;
}
