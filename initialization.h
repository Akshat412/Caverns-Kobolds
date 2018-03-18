#pragma once

#include"resources.h"

using namespace std;

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
	
	p.fire = 0;
	p.i.hp = 0;
	p.i.money = 0;
	p.i.weapons = 0;
	p.i.armors = 0;
	
	c = GREEN;
	setcolor();

	switch(choice)
	{
		case 1:
		{
			cout<<"\nYou chose Class Berserker"<<endl;
			p.wtype = 1; //Heavy Weapons
			p.atype = 1;//Heavy Armor
			p.HP = 1000;
			p.magic = 15;
			p.maxHP = 1000;
			p.luck = 2;
			p.wh = 3;
			p.dodge = 1;
			p.damage = 0;
			p.maxM = 100;
			p.mana = 10;
			p.spellno = 0;
			p.stealth = 1;
			p.no_hp = 8;
			
			p.w.name= "Iron Mace";
			p.w.damage=50;
			p.w.weight = 24;
			
			p.a.name = "Heavy Chainmail Armor";
			p.a.defense = 10;
			p.a.weight = 10;
		}
		break;
		
		case 2:
		{
			cout<<"\nYou chose Class Herald"<<endl;
			p.wtype = 2; //Medium Weapons
			p.atype = 2; //Medium Armor
			p.HP= 300 ;
			p.magic = 50;
			p.maxHP = 500;
			p.luck = 4;
			p.wh = 5;
			p.dodge = 2;
			p.damage = 0;
			p.maxM = 500;
			p.mana = 500;
			p.spellno = 1;
			p.stealth = 1;
			p.no_hp = 12;
			
			p.w.name= "Iron Spear";
			p.w.damage=20;
			p.w.weight = 10;
			
			p.a.name = "Light Iron Armor";
			p.a.defense = 5;
			p.a.weight = 5;
		}
		break;
		
		case 3:
		{
			cout<<"\nYou chose Class Knight"<<endl;
			p.wtype = 2; //Medium Weapons
			p.atype = 1; //Heavy Armor
			p.HP = 750;
			p.magic = 5;
			p.maxHP = 750;
			p.luck = 3;
			p.wh = 50;
			p.dodge = 4;
			p.damage = 0;
			p.maxM = 200;
			p.mana = 100;
			p.spellno = 0;
			p.stealth = 1;
			p.no_hp = 10;
			
			p.w.name= "Rusty Sword";
			p.w.damage = 30;
			p.w.weight = 15;
			
			p.a.name = "Heavy Iron Armor";
			p.a.defense = 8;
			p.a.weight = 9;
		}
		break;
		
		case 4:
		{
			cout<<"\nYou chose Class Rogue"<<endl;
			p.wtype = 3; //Light Weapons
			p.atype = 3; //Light Armor
			p.HP = 100;
			p.magic = 5;
			p.maxHP = 250;
			p.luck = 10;
			p.wh = 20;
			p.dodge = 5;
			p.damage = 0;
			p.maxM = 200;
			p.mana = 100;
			p.spellno = 0;
			p.stealth = 10;
			p.no_hp = 16;
			
			p.w.name= "Rusty Dagger";
			p.w.damage = 10;
			p.w.weight = 2;
			
			p.a.name = "Leather Clothes";
			p.a.defense = 2;
			p.a.weight = 0;
		}
		break;
		
		case 5:
		{
			cout<<"\nYou choose Class Pyromancer"<<endl;
			p.wtype = 4; //No Weapons
			p.atype = 4; //No Armor
			p.HP = 100;
			p.magic = 100;
			p.maxHP = 250;
			p.luck = 2;
			p.wh = 1;
			p.dodge = 0;
			p.damage = 0;
			p.maxM = 1500;
			p.mana = 1500;
			p.spellno = 4;
			p.fire = 100;
			p.stealth = 1;
			p.no_hp = 6;
			
			p.w.name= "Walking Stick";
			p.w.damage=1;
			p.w.weight = 10;
			
			p.a.name = "Plain Robes";
			p.a.defense = 1;
			p.a.weight = 0;
		}
		break;
	}
	
	c = WHITE;
	setcolor();

	p.xp = 0;

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
			e.damage = 25;
			e.cdamage = 100;
			
		}
		break;
		
		case 1:
		{
			e.name = "Zombie Lizard";
			e.HP = 500;
			e.damage = 5;
			e.cdamage = 50;
		}
		break;
		
		case 2:
		{
			e.name = "Feral Rabbit";
			e.HP = 25;
			e.damage = 20;
			e.cdamage = 500;
			e.sdodge = 1;
		}
		break;
		
		case 3:
		{
			e.name = "Skeleton";
			e.HP = 100;
			e.damage = 100;
			e.cdamage = 150;
		}
		break;
	}
	
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
			e.damage = 100;
			e.cdamage = 250;
		}
		break;
		
		case 1:
		{
			e.name = "Giant Crab";
			e.HP = 1000;
			e.damage = 30;
			e.cdamage = 60;
			
		}
		break;
		
		case 2:
		{
			e.name = "Vulture";
			e.HP = 150;
			e.damage = 25;
			e.cdamage = 600;
			e.sdodge = 1;
		}
		break;
		
		case 3:
		{
			e.name = "Undead Viking";
			e.HP = 250;
			e.damage = 300;
			e.cdamage = 500;
		}
		break;
	}
	
	return 0;
}

int levelup1(player&p)
{
	int choice;
	
	int xp_d, xp_m, xp_wh, xp_magi;
	
	xp_d = (p.damage + 1) * 10;
	xp_m = p.mana;
	xp_wh = p.wh * 50;
	xp_magi = (p.spellno + 1) * 50;
	
	cout<<"\nWhat would you like to level up?"<<endl;
	cout<<"\n1. Damage +15 : "<<xp_d<<endl;
	cout<<"\n2. Max Mana +50 : "<<xp_m<<endl;
	cout<<"\n3. Weapon Handling +1 : "<<xp_wh<<endl;
	cout<<"\n4. Magic Level : "<<xp_magi<<endl;
	
	cout<<"\nXP : "<<p.xp<<endl;
	
	cout<<"\nInput choice : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1: //Damage 
		{
			if(p.xp>=xp_d)
			{
				c = GREEN;
				setcolor();

				cout<<"\nYour damage increased by 15"<<endl;
				p.damage = p.damage + 15;
				p.xp = p.xp - xp_d;
				
				cout<<"\nDamage : "<<p.damage<<endl;
				cout<<"\nXP : "<<p.xp<<endl;
			}
			
			else
			{
				c = RED;
				setcolor();

				cout<<"\nYour XP is too low to level up"<<endl;
				
				cout<<"\nDamage : "<<p.damage<<endl;
				cout<<"\nXP : "<<p.xp<<endl;
			}
		}
		break;
		
		case 2: //Mana 
		{
			if(p.xp>=xp_m)
			{
				c = GREEN;
				setcolor();

				cout<<"\nYour max mana increased by 50"<<endl;
				p.maxM = p.maxM + 50;
				p.xp = p.xp - xp_m;
				
				cout<<"\nMax Mana : "<<p.maxM<<endl;
				cout<<"\nXP : "<<p.xp<<endl;
			}
			
			else
			{
				c = RED;
				setcolor();

				cout<<"\nYour XP is too low to level up"<<endl;
				
				cout<<"\nMax Mana : "<<p.maxM<<endl;
				cout<<"\nXP : "<<p.xp<<endl;
			}
		}
		break;
		
		case 3: //Weapon Handling
		{
			if(p.xp>=xp_wh)
			{
				c = GREEN;
				setcolor();

				cout<<"\nYour weapon handling increased by 1"<<endl;
				p.wh = p.wh + 1;
				p.xp = p.xp - xp_wh;
				
				cout<<"\nWeapon Handling : "<<p.wh<<endl;
				cout<<"\nXP : "<<p.xp<<endl;
			}
			
			else
			{
				c = RED;
				setcolor();

				cout<<"\nYour XP is too low to level up"<<endl;
				
				cout<<"\nWeapon Handling : "<<p.wh<<endl;
				cout<<"\nXP : "<<p.xp<<endl;
			}
		}
		break;
		
		case 4:
		{
			
			switch(p.spellno)
			{
				case 0: case 1: case 2:
				{
					if(p.xp>=xp_magi)
					{
						c = GREEN;
						setcolor();

						cout<<"\nYour magic level increased by 1"<<endl;
						p.spellno++;
						p.xp = p.xp - xp_magi;
						
						cout<<"\nMagic Level : "<<p.spellno<<endl;
						cout<<"\nXP : "<<p.xp<<endl;
					}
					
					else
					{
						c = RED;
						setcolor();

						cout<<"\nYour XP is too low to level up"<<endl;
						
						cout<<"\nMagic Level : "<<p.spellno<<endl;
						cout<<"\nXP : "<<p.xp<<endl;
					}
				}
				break;
				
				case 3:
				{
					c = RED;
					setcolor();

					cout<<"\nYour magic level is maximum for your class"<<endl;
				}
				break;
				
				case 4:
				{
					if(p.xp>=xp_magi)
					{
						c = GREEN;
						setcolor();

						cout<<"\nYour magic level increased by 1"<<endl;
						p.spellno++;
						p.xp = p.xp - xp_magi;
						
						cout<<"\nMagic Level : "<<p.spellno<<endl;
						cout<<"\nXP : "<<p.xp<<endl;
					}
					
					else
					{
						c = RED;
						setcolor();

						cout<<"\nYour XP is too low to level up"<<endl;
						
						cout<<"\nMagic Level : "<<p.spellno<<endl;
						cout<<"\nXP : "<<p.xp<<endl;
					}
				}
				break;
				
				case 5:
				{
					c = RED;
					setcolor();

					cout<<"\nYour magic level is maximum"<<endl;
				}
				break;
			}
		}
	}

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
	cout<<"\nHealth : "<<p.HP<<endl;
	cout<<"\nMax Health : "<<p.maxHP<<endl;
	cout<<"\nDamage : "<<p.damage<<endl;
	cout<<"\nMana : "<<p.mana<<endl;
	cout<<"\nMax Mana : "<<p.maxM<<endl;
	cout<<"\nMagic Level : "<<p.spellno<<endl;
	cout<<"\nHealing Spell Power : "<<p.magic<<endl;
	cout<<"\nFireball Damage : "<<p.fire<<endl;
	cout<<"\nWeapon Handling : "<<p.wh<<endl;
	cout<<"\nLuck : "<<p.luck<<endl;
	cout<<"\nDodge : "<<p.dodge<<endl;
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
	cout<<"\nArmor : "<<1-p.i.armors<<endl;//
	
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
		
		cout<<"\n1. Dungeon Crawling"<<endl;
		cout<<"\n2. The Collosi"<<endl;
		cout<<"\n3. Weapons and Armor"<<endl;
		cout<<"\n4. Exit"<<endl;
		
		cout<<"\nInput choice : ";
		cin>>choice;
		
		system("cls");
		
		switch(choice)
		{
			case 1:
			{
				cout<<"\nDungeon Crawling:"<<endl;

				liner();
				
				cout<<"\n1. You can take healing potions while resting as well as during combat, but you may only heal when in combat."<<endl;
				cout<<"\n2. A high Luck will help you find more items on the ground and encounter a lesser amount of enemies."<<endl;
				cout<<"\n3. Pots and other objects you find may contain weapons inside them....or enemies."<<endl;
				cout<<"\n4. You have a chance of sneaking up on non Collosi enemies."<<endl;
				empty();
			}
			break;
			
			case 2:
			{
				cout<<"\nThe Collosi"<<endl;
				
				liner();
				
				cout<<"\n1. The Titan : A giant Titan, which has very high health, but a low chance of landing attacks. Conserve Health Potions and get ready for a long battle."<<endl;
				cout<<"\n2. The Hydra : A large snake-like creature, with low health, but does poison damage every turn. High damage weapons are ideal, as the shorter the battle, the better."<<endl;
				empty();
			}
			break;
			
			case 3:
			{
				cout<<"\nWeapons and Armor"<<endl;
				
				liner();
				
				cout<<"\n1. The higher the weapon damage, the higher damage it will do."<<endl;
				cout<<"\n2. The lighter the weapon, the higher chance you have of landing attacks."<<endl;
				cout<<"\n3. Weapons can be found as drops from enemies, and from coffins etc. all around a dungeon."<<endl;
				cout<<"\n4. You get a random value between 0 and your armor defence as your defence for an attack."<<endl;
				cout<<"\n5. The lighter your armor, the higher chance you have of dodging enemy attacks."<<endl;
				cout<<"\n6. Armor can be found as drops from enemies."<<endl;
				empty();
			}
			break;
			
			case 4:
			{
				return 0;
			}
			break;
		}

		system("cls");
	}
}
