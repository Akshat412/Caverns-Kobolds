#pragma once

#include"resources.h"
#include"objects.h"

int loot_potion(player&p)
{
	srand(time(0));
	
	int chance = (rand () % 5);
	
	switch(chance)
	{
		case 0: case 1: case 2: 
		{
			cout<<"\nYou found a Health Potion."<<endl;
			
			p.i.hp++;
			
			cout<<"\nNo of Health Potions : "<<p.i.hp<<endl;
		}
		break;
		
		case 3:
		{
			cout<<"\nYou found a book on Healing Magic. You learnt to cast a better healing spell"<<endl;
			
			p.magic = p.magic + 50;
			
			cout<<"\nHealing : "<<p.magic<<endl;
		}
		break;
		
		case 4:
		{
			cout<<"\nYou found a Max Health Potion. Your max health increased."<<endl;
			
			p.maxHP = p.maxHP + 100;
			
			cout<<"\nMax Health : "<<p.maxHP<<endl;
		}
		break;
	}
}

int loot_weapon1(player&p)
{
	weapon temp;
	int choice;
	
	temp = weaponlist_1(temp,p);
	
	cout<<"\nYou found a "<<temp.name<<endl;

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
			p.w.name = temp.name;
			p.w.damage = temp.damage;
			p.w.weight = temp.weight;
			
			if(p.i.weapons < 5)
			{
				cout<<"\nYou store your current weapon in your inventory"<<endl;
				p.i.weapons++;
			}
			
			else
			{
				cout<<"\nYou drop your current weapon"<<endl;
			}
		}
		break;
		
		case 2:
		{
			if(p.i.weapons < 5)
			{
				cout<<"\nYou store the weapon in your inventory"<<endl;
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

int loot_weapon2(player&p)
{
	weapon temp;
	int choice;
	
	temp = weaponlist_2(temp,p);

	cout<<"\nYou found a "<<temp.name<<endl;
	
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
			p.w.name = temp.name;
			p.w.damage = temp.damage;
			p.w.weight = temp.weight;
			
			if(p.i.weapons < 5)
			{
				cout<<"\nYou store your current weapon in your inventory"<<endl;
				p.i.weapons++;
			}
			
			else
			{
				cout<<"\nYou drop your current weapon"<<endl;
			}
		}
		break;
		
		case 2:
		{
			if(p.i.weapons < 5)
			{
				cout<<"\nYou store the weapon in your inventory"<<endl;
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

int loot_armor1(player&p)
{
	armor temp;
	int choice;
	
	temp = armorlist_1(temp,p);
	
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
			p.a.name = temp.name;
			p.a.defense = temp.defense;
			p.a.weight = temp.weight;
			
			if(p.i.armors < 2)
			{
				cout<<"\nYou store your current armor in your inventory"<<endl;
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

int loot_armor2(player&p)
{
	armor temp;
	int choice;
	
	temp = armorlist_2(temp,p);
	
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
			p.a.name = temp.name;
			p.a.defense = temp.defense;
			p.a.weight = temp.weight;
			
			if(p.i.armors < 2)
			{
				cout<<"\nYou store your current armor in your inventory"<<endl;
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

