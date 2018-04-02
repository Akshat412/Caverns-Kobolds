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

			p.STR = 13;
			p.VIT = 13;
			p.DEX = 15;
			p.STA = 13;
			p.FAI = 9;
			p.INE = 8;
			
		}
		break;

		case 2:
		{
			cout<<"\nYou are an Orc"<<endl;
			p.race = "Orc";
			p.STR = 22;
			p.VIT = 21;
			p.DEX = 8;
			p.STA = 7;
			p.FAI = 7;
			p.INE = 5;
			
		}
		break;

		case 3:
		{
			cout<<"\nYou are a Half-Elf"<<endl;
			p.race = "Half-Elf";
			p.STR = 11;
			p.VIT = 17;
			p.DEX = 8;
			p.STA = 6;
			p.FAI = 17;
			p.INE = 11;
			
		}
		break;

		case 4:
		{
			cout<<"\nYou are a Half-Orc"<<endl;
			p.race = "Half-Orc";
			p.STR = 13;
			p.VIT = 18;
			p.DEX = 18;
			p.STA = 9;
			p.FAI = 7;
			p.INE = 5;
			
		}
		break;

		case 5:
		{
			cout<<"\nYou are a Half-Lizard"<<endl;
			p.race = "Half-Lizard";
			p.STR = 14;
			p.VIT = 8;
			p.DEX = 16;
			p.STA = 19;
			p.FAI = 8;
			p.INE = 5;
			
		}
		break;

		case 6:
		{
			cout<<"\nYou are an Elf"<<endl;
			p.race = "Elf";
			p.STR = 4;
			p.VIT = 9;
			p.DEX = 7;
			p.STA = 6;
			p.FAI = 22;
			p.INE = 22;
			
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
}

int playerclass(player&p)
{
	cout<<"\n1. Berserker"<<endl;
	cout<<"\n2. Herald"<<endl;
	cout<<"\n3. Knight"<<endl;
	cout<<"\n4. Rogue"<<endl;
	cout<<"\n5. Pyromancer"<<endl;
	
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
			p.wtype = 1; //Heavy Weapons
			p.atype = 1;//Heavy Armor

			p.STR += 3;
			p.VIT += 5;
			p.STA -= 2;
			p.luck = 2;

			p.no_hp = 8;
			
			p.w.name= "Iron Mace";
			p.w.damage=50;
			p.w.weight = 24;
			p.w.STR += 4;
			
			p.a.name = "Heavy Chainmail Armor";
			p.a.defense = 10;
			p.a.weight = 10;
		}
		break;
		
		case 2:
		{
			cout<<"\nYou chose Class Herald"<<endl;
			p.pclass = "Herald";
			p.wtype = 2; //Medium Weapons
			p.atype = 2; //Medium Armor

			p.VIT += 2;
			p.FAI += 3;
			p.luck = 3;

			p.no_hp = 12;
			
			p.w.name= "Iron Spear";
			p.w.damage=20;
			p.w.weight = 10;
			p.w.STR += 2;
			p.w.FAI += 2;
			
			p.a.name = "Light Iron Armor";
			p.a.defense = 5;
			p.a.weight = 5;
		}
		break;
		
		case 3:
		{
			cout<<"\nYou chose Class Knight"<<endl;
			p.pclass = "Knight";
			p.wtype = 2; //Medium Weapons
			p.atype = 1; //Heavy Armor

			p.VIT += 2;
			p.DEX += 6;
			p.luck = 2;

			p.no_hp = 10;
			
			p.w.name= "Rusty Sword";
			p.w.damage = 30;
			p.w.weight = 15;
			p.w.STR += 2;
			p.w.DEX += 2;
			
			p.a.name = "Heavy Iron Armor";
			p.a.defense = 8;
			p.a.weight = 9;
		}
		break;
		
		case 4:
		{
			cout<<"\nYou chose Class Rogue"<<endl;
			p.pclass = "Rogue";
			p.wtype = 3; //Light Weapons
			p.atype = 3; //Light Armor

			p.DEX += 4;
			p.STA += 5;
			p.VIT -= 1;
			p.luck = 8;

			p.no_hp = 16;
			
			p.w.name= "Rusty Dagger";
			p.w.damage = 10;
			p.w.weight = 2;
			p.w.STR += 1;
			p.w.DEX += 3;
			
			p.a.name = "Leather Clothes";
			p.a.defense = 2;
			p.a.weight = 0;
		}
		break;
		
		case 5:
		{
			cout<<"\nYou choose Class Pyromancer"<<endl;
			p.pclass = "Pyromancer";
			p.wtype = 4; //No Weapons
			p.atype = 4; //No Armor

			p.FAI += 5;
			p.INE += 6;
			p.VIT -= 2;
			p.luck = 3;

			p.no_hp = 6;
			
			p.w.name= "Walking Stick";
			p.w.damage=1;
			p.w.weight = 10;
			p.w.FAI += 2;
			p.w.INE += 2;
			
			p.a.name = "Plain Robes";
			p.a.defense = 1;
			p.a.weight = 0;
		}
		break;
	}

	p.setattributes();

	addplayerstats_weapons(p);

	p.ability_point = 5;
	
	c = WHITE;
	setcolor();

	return choice;
}

int enemyclass1(enemy&e)
{
	srand(time(0));
	
	int echoice = (rand () % 4);
	
	e.dodge = 0;
	e.sdodge = 0;
	
	switch(echoice)
	{
		case 0:
		{
			e.name = "Kobold";
			e.HP = 200;
			e.damage = 40;
			e.cdamage = 120;
			
		}
		break;
		
		case 1:
		{
			e.name = "Zombie Lizard";
			e.HP = 500;
			e.damage = 10;
			e.cdamage = 75;
		}
		break;
		
		case 2:
		{
			e.name = "Feral Rabbit";
			e.HP = 75;
			e.damage = 50;
			e.cdamage = 500;
			e.sdodge = 1;
		}
		break;
		
		case 3:
		{
			e.name = "Skeleton";
			e.HP = 150;
			e.damage = 125;
			e.cdamage = 200;
		}
		break;
	}

	e.maxHP = e.HP;
	
	return 0;
}

int enemyclass2(enemy&e)
{
	srand(time(0));
	
	int echoice = (rand () % 4);
	
	e.dodge = 0;
	e.sdodge = 0;
	
	switch(echoice)
	{
		case 0:
		{
			e.name = "Undead Pirate";
			e.HP = 500;
			e.damage = 200;
			e.cdamage = 500;
		}
		break;
		
		case 1:
		{
			e.name = "Giant Crab";
			e.HP = 1000;
			e.damage = 75;
			e.cdamage = 200;
			
		}
		break;
		
		case 2:
		{
			e.name = "Vulture";
			e.HP = 200;
			e.damage = 200;
			e.cdamage = 1500;
			e.sdodge = 1;
		}
		break;
		
		case 3:
		{
			e.name = "Undead Viking";
			e.HP = 300;
			e.damage = 500;
			e.cdamage = 750;
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
		case 2:
		{
			enemyclass1(e);
		}
		break;

		case 3:
		{
			enemyclass2(e);
		}
		break;
	}
}

int levelup(player&p)
{
	int choice;
	
	int xp_STR, xp_VIT, xp_DEX, xp_STA, xp_FAI;

	xp_STR = p.STR * 25;
	xp_VIT = p.VIT * 25;
	xp_DEX = p.DEX * 25;
	xp_STA = p.STA * 25;
	xp_FAI = p.FAI * 25;
	
	cout<<"\nWhat would you like to level up?"<<endl;
	cout<<"\n1. Strength +1 : "<<xp_STR<<endl;
	cout<<"\n2. Vitality +1 : "<<xp_VIT<<endl;
	cout<<"\n3. Dexterity +1 : "<<xp_DEX<<endl;
	cout<<"\n4. Stamina +1 : "<<xp_STA<<endl;
	cout<<"\n5. Faith +1 : "<<xp_FAI<<endl;
	cout<<"\n6. Exit"<<endl;
	
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
				cout<<"\nXP too low"<<endl;
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
				cout<<"\nXP too low"<<endl;
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
				cout<<"\nXP too low"<<endl;
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
				cout<<"\nXP too low"<<endl;
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
				cout<<"\nXP too low"<<endl;
			}
		}
		break;

		case 6:
		{
			return 0;
		}
		break;
	}

	p.setattributes();

	c = WHITE;
	setcolor();
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
	cout<<"\nMana : "; printM(p.mana,p.maxM);
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
	cout<<endl;

	cout<<"\nVitality : "<<p.VIT<<endl;

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
	cout<<endl;

	cout<<"\nStamina : "<<p.STA<<endl;

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
	cout<<endl;

	cout<<"\nXP : "<<p.xp<<endl;

	line();

	c = GREEN;
	setcolor();
	
	cout<<"\nPlayer Items"<<endl;
	cout<<endl;

	c = WHITE;
	setcolor();
	
	cout<<"\nWeapon : "<<p.w.name<<endl;
	cout<<"\nArmor : "<<p.a.name<<endl;
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
		cout<<"\n1. Improve Weapon (Improves Damage by 25) : 300 Coins"<<endl;
		cout<<"\n2. Streamline Weapon (Decreases weight by 1) : 100 Coins"<<endl;
		cout<<"\n3. Improve Armor (Improves Defence by 25) : 300 Coins"<<endl;
		cout<<"\n4. Buy Healing Potions (5) : 300 Coins"<<endl;
		cout<<"\n5. Buy Lucky Charm (Luck increases by 5) : 100 Coins"<<endl;
		cout<<"\n6. Exit"<<endl;
		
		cout<<"\nMoney : "<<p.i.money<<endl;
		
		cout<<"\nInput choice : ";

		int choice;
		cin>>choice;
		
		switch(choice)
		{
			case 1:
			{
				if(p.i.money >= 300)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou improved your weapon damage by 25"<<endl;
					p.w.damage += 25;
					p.i.money -= 300;
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
				if(p.i.money >= 100)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou reduced your weapon weight by 1"<<endl;

					if(p.w.weight > 0) p.w.weight -= 1; else p.w.weight = 0;
					p.i.money -= 100;
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
				if(p.i.money >= 300)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou improved your armor defence by 25"<<endl;
					p.a.defense += 25;
					p.i.money -= 300;
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
				if(p.i.money >= 300)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou bought 5 Healing Potions"<<endl;
					p.i.hp += 5;
					p.i.money -= 300;
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
				if(p.i.money >= 100)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou bought a Lucky Charm"<<endl;
					p.luck += 5;
					p.i.money -= 100;
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

				cout<<"\n1. You have five stats that determine your attributes : Strength, Vitality, Dexterity, Stamina, and Faith"<<endl;
				cout<<"\n2. Strength controls the damage you do"<<endl;
				cout<<"\n3. Vitality controls your health"<<endl;
				cout<<"\n4. Dexterity controls your weapon handling"<<endl;
				cout<<"\n5. Stamina controls your dodging as well as stealth abilities"<<endl;
				cout<<"\n6. Faith controls your magic based abilities, including mana"<<endl;

				empty();
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
			}
			break;
			
			case 3:
			{
				cout<<"\nDungeons"<<endl;

				cout<<endl;

				cout<<"\n1. Dungeons are the main areas of the game, containing enemies and loot"<<endl;
				cout<<"\n2. Each dungeon has a Collosi at the end of it, with the Titan 15 chunks into the dungeon, and the Hydra 20 chunks in"<<endl;
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

		system("cls");
	}
}
