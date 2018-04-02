#pragma once

#include"resources.h"
#include"objects.h"

int loot_potion(player&p)
{
	srand(time(0));
	
	int chance = (rand () % 5);

	c = GREEN;
	setcolor();

	t = LOOT;
	textart();

	c = WHITE;
	setcolor();
	
	switch(chance)
	{
		default:
		{
			cout<<"\nYou found a Health Potion"<<endl;
			
			p.i.hp++;
			
			cout<<"\nNo of Health Potions : "<<p.i.hp<<endl;
		}
		break;

		case 1: case 2:
		{
			cout<<"\nYou found an Ale"<<endl;

			p.i.sp++;

			cout<<"\nNo of Ales : "<<p.i.sp<<endl;			
		}
		break;
	}
}

int display_weaponstats(weapon&w)
{
	if(w.STR > 0 || w.DEX > 0 || w.FAI > 0 || w.INE > 0)
	{
		cout<<" [ ";
	}

	if(w.STR > 0)
	{
		cout<<"STR : ";

		c = GREEN;
		setcolor();

		cout<<"+"<<w.STR;
	}

	c = WHITE;
	setcolor();

	if(w.DEX > 0)
	{
		cout<<" DEX : ";

		c = GREEN;
		setcolor();

		cout<<"+"<<w.DEX;
	}

	c = WHITE;
	setcolor();

	if(w.FAI > 0)
	{
		cout<<" FAITH : ";

		c = GREEN;
		setcolor();

		cout<<"+"<<w.FAI;
	}

	c = WHITE;
	setcolor();

	if(w.INE > 0)
	{
		cout<<" INT : ";

		c = GREEN;
		setcolor();

		cout<<"+"<<w.INE;
	}

	c = WHITE;
	setcolor();

	if(w.STR > 0 || w.DEX > 0 || w.FAI > 0 || w.INE > 0)
	{
		cout<<" ]";
	}
}

int removeplayerstats_weapons(player&p, weapon&own)
{
	p.STR -= own.STR;
	p.DEX -= own.DEX;
	p.FAI -= own.FAI;
	p.INE -= own.INE;
}

int addplayerstats_weapons(player&p)
{
	p.STR += p.w.STR;
	p.DEX += p.w.DEX;
	p.FAI += p.w.FAI;
	p.INE += p.w.INE;
}

int loot_weapon(player&p)
{
	weapon temp, own;
	int choice, weaponslot;

	own = p.w;

	c = GREEN;
	setcolor();

	t = LOOT;
	textart();

	c = WHITE;
	setcolor();
	
	temp = weaponlist(temp,p);
	
	cout<<"\nYou found a "<<temp.name; display_weaponstats(temp);
	cout<<endl;

	cout<<"\nWeapon Damage : ";

	if(temp.damage > p.w.damage)
	{
		c = GREEN;
		setcolor();

		cout<<temp.damage<<endl;
	}

	else
	{
		c = RED;
		setcolor();

		cout<<temp.damage<<endl;
	}

	c = WHITE;
	setcolor();

	cout<<"\nWeapon Weight : ";

	if(temp.weight < p.w.weight)
	{
		c = GREEN;
		setcolor();

		cout<<temp.weight<<endl;
	}

	else
	{
		c = RED;
		setcolor();

		cout<<temp.weight<<endl;
	}

	c = WHITE;
	setcolor();

	cout<<"\nCurrent Weapon Damage : "<<p.w.damage<<endl;
	cout<<"\nCurrent Weapon Weight : "<<p.w.weight<<endl;
	
	cout<<"\nDo you pick up the "<<temp.name<<"?"<<endl;
	cout<<"\n1. Yes"<<endl;
	cout<<"\n2. No"<<endl;
	
	cout<<"\nInput choice : ";
	cin>>choice;

	system("cls");
	
	switch(choice)
	{
		case 1:
		{
			cout<<"\nYou picked up the weapon"<<endl;

			p.w = temp;
			
			if(p.i.weapons < 5)
			{
				cout<<"\nYou store your current weapon in your inventory"<<endl;
				
				weaponslot = p.i.weapons;

				p.i.iw[weaponslot] = own;

				p.i.weapons++;
			}
			
			else
			{
				cout<<"\nYou drop your current weapon"<<endl;
			}

			removeplayerstats_weapons(p,own);

			addplayerstats_weapons(p);
		}
		break;
		
		case 2:
		{
			if(p.i.weapons < 5)
			{
				cout<<"\nYou store the weapon in your inventory"<<endl;

				weaponslot = p.i.weapons;

				p.i.iw[weaponslot] = temp;

				p.i.weapons++;
			}
			
			else
			{
				cout<<"\nYou leave the weapon"<<endl;
			}	
		}
		break;
	}
}

int loot_armor(player&p)
{
	armor temp, own;
	int choice, armorslot;

	own = p.a;

	c = GREEN;
	setcolor();

	t = LOOT;
	textart();

	c = WHITE;
	setcolor();
	
	temp = armorlist(temp,p);
	
	cout<<"\nYou found "<<temp.name<<endl;

	cout<<"\nArmor Defence : ";

	if(temp.defense > p.a.defense)
	{
		c = GREEN;
		setcolor();

		cout<<temp.defense<<endl;
	}

	else
	{
		c = RED;
		setcolor();

		cout<<temp.defense<<endl;
	}

	c = WHITE;
	setcolor();

	cout<<"\nArmor Weight : ";

	if(temp.weight < p.a.weight)
	{
		c = GREEN;
		setcolor();

		cout<<temp.weight<<endl;
	}

	else
	{
		c = RED;
		setcolor();

		cout<<temp.weight<<endl;
	}

	c = WHITE;
	setcolor();

	cout<<"\nCurrent Armor Defence : "<<p.a.defense<<endl;
	cout<<"\nCurrent Weapon Weight : "<<p.a.weight<<endl;

	cout<<"\nDo you pick up the "<<temp.name<<"?"<<endl;
	cout<<"\n1. Yes"<<endl;
	cout<<"\n2. No"<<endl;
	
	cout<<"\nInput choice : ";
	cin>>choice;

	system("cls");
	
	switch(choice)
	{
		case 1:
		{
			cout<<"\nYou picked up the armor"<<endl;
			
			p.a = temp;
			
			if(p.i.armors < 2)
			{
				cout<<"\nYou store your current armor in your inventory"<<endl;

				armorslot = p.i.armors;

				p.i.ia[armorslot] = own;

				p.i.armors++;
			}
			
			else
			{
				cout<<"\nYou drop your current armor"<<endl;
			}
		}
		break;
		
		case 2:
		{
			if(p.i.armors < 2)
			{
				cout<<"\nYou store the armor in your inventory"<<endl;

				armorslot = p.i.armors;

				p.i.ia[armorslot] = temp;

				p.i.armors++;
			}
			
			else
			{
				cout<<"\nYou leave the armor"<<endl;
			}	
		}
		break;
	}
}

int inventory(player&p)
{
	int choice, wchoice, weaponslot, armorslot;
	weapon wown;
	armor aown;

	wown = p.w;
	aown = p.a;

	cout<<"\nWhich items would you like to use?"<<endl;

	cout<<"\n1. Weapons"<<endl;
	cout<<"\n2. Armors"<<endl;
	cout<<"\n3. Healing Potions"<<endl;
	cout<<"\n4. Ales"<<endl;

	cout<<"\nInput choice : ";
	cin>>choice;

	switch(choice)
	{
		case 1:
		{
			cout<<"\nWhich weapon would you like to use?"<<endl;

			for(int i = 0; i < 5; i++)
			{
				cout<<"\nSlot "<<i + 1<<" : "<<p.i.iw[i].name; display_weaponstats(p.i.iw[i]);
				cout<<endl;
			}

			cout<<"\nWhich weapon would you like to equip?"<<endl;

			cout<<"\nInput choice : ";
			cin>>wchoice;

			switch(wchoice)
			{
				case 1: case 2: case 3: case 4: case 5:
				{
					weaponslot  = wchoice - 1;

					p.w = p.i.iw[weaponslot];

					p.i.iw[weaponslot] = wown;
				}
				break;

				default:
				{
					cout<<"\nYou do not change your current weapon"<<endl;

					return 0;
				}
				break;
			}
		}
		break;

		case 2:
		{
			cout<<"\nWhich armor would you like to use?"<<endl;

			for(int i = 0; i < 2; i++)
			{
				cout<<"\nSlot "<<i + 1<<" : "<<p.i.ia[i].name<<endl;
			}	

			cout<<"\nWhich armor would you like to equip?"<<endl;

			cout<<"\nInput choice : ";
			cin>>wchoice;

			switch(wchoice)
			{
				case 1: case 2: 
				{
					armorslot  = wchoice - 1;

					p.a = p.i.ia[armorslot];

					p.i.ia[armorslot] = aown;
				}
				break;

				default:
				{
					cout<<"\nYou do not change your current armor"<<endl;

					return 0;
				}
				break;
			}
		}
		break;

		case 3:
		{
			cout<<"\nYou have "<<p.i.hp<<" health potions"<<endl; 
			cout<<"\nDo you use a health potion?"<<endl;
			cout<<"\n1. Yes"<<endl;
			cout<<"\n2. No"<<endl;

			cout<<"\nInput choice : ";
			cin>>wchoice;

			switch(wchoice)
			{
				case 1:
				{
					heal(p);
				}
				break;

				default:
				{
					cout<<"\nYou do not use a health potion"<<endl;
				}
				break;
			}
		}
		break;

		case 4:
		{
			cout<<"\nYou have "<<p.i.sp<<" ales"<<endl; 
			cout<<"\nDo you use an ale?"<<endl;
			cout<<"\n1. Yes"<<endl;
			cout<<"\n2. No"<<endl;

			cout<<"\nInput choice : ";
			cin>>wchoice;

			switch(wchoice)
			{
				case 1:
				{
					s_heal(p);
				}
				break;

				default:
				{
					cout<<"\nYou do not use an ale"<<endl;
				}
				break;
			}	
		}
	}
}



