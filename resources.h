#pragma once

#include <iostream>
#include<Windows.h>
#include<ctime>
#include<string>
#include<cstdio>
#include<stdlib.h>
#include<fstream>

using namespace std;

enum color {RED, BLUE, GREEN, BLACK, WHITE};
color c;

struct weapon
{
	string name;
	int damage;
	int weight;
};

struct armor 
{
	string name;
	int defense;
	int weight;
};

struct inventory
{
	int hp;
	int money;
	int weapons;
	int armors;
};

struct player
{
	string name;
	
	int wtype;
	int HP;
	int damage;
	int magic;
	int maxHP;
	int wh;
	int luck;
	int stamina;
	int dodge;
	int xp;
	int mana;
	int maxM;
	int spellno;
	int fire;
	int stealth;
	int atype; 
	int no_hp;
	int level;
	bool ability_point;
	
	weapon w;
	inventory i;
	armor a;

	player() //c'est un constructor
	{
		name = "Prisoner";
		wtype = 4; 
		atype = 4;
		HP = 100;
		magic = 5;
		maxHP = 100;
		luck = 2;
		wh = 2;
		dodge = 1;
		damage = 0;
		maxM = 10;
		mana = 10;
		spellno = 0;
		stealth = 1;
		no_hp = 0;
				
		w.name= "Piece of Wood";
		w.damage = 2;
		w.weight = 1;
				
		a.name = "Prisoner Rags";
		a.defense = 2;
		a.weight = 1;

		fire = 0;
		i.hp = 0;
		i.money = 0;
		i.weapons = 0;
		i.armors = 0;
		level = 0;
		ability_point = true;
	}
};

struct enemy
{
	string name;
	int HP;
	int damage;
	int cdamage;
	int dodge;
	int sdodge;
};

int empty();

int line()
{
	empty();
	system("cls");
	return 0;
}

int empty()
{
	cout<<endl;
	system("pause");
	return 0;
}

int liner()
{
	cout<<"\n------------------------------------------------------------------------------------------------------"<<endl;
	return 0;
}

int heal(player&p)
{
	if(p.i.hp>0)
	{
		cout<<"\nYou used a healing potion, and healed up by 300 HP"<<endl;
							
		if(p.HP + 300 < p.maxHP)
		{
			p.HP = p.HP + 300;
			p.i.hp--;
		}
							
		else
		{
			p.HP = p.maxHP;
			p.i.hp--;
		}
	}
						
	else
	{
		cout<<"\nYou're out of potions"<<endl;
	}
	
	cout<<"\nNo of Health Potions : "<<p.i.hp<<endl;
}

int write_data(player&p,string stream)
{
	ofstream savefile(stream);

	//Player Variables
	savefile << p.name << endl;
	savefile << p.w.name << endl;
	savefile << p.a.name << endl;
	savefile << p.wtype << endl; 
	savefile << p.atype << endl;
	savefile << p.HP << endl;
	savefile << p.magic << endl;
	savefile << p.maxHP << endl;
	savefile << p.luck << endl;
	savefile << p.wh << endl;
	savefile << p.dodge << endl;
	savefile << p.damage << endl;
	savefile << p.maxM << endl;
	savefile << p.mana << endl;
	savefile << p.spellno << endl;
	savefile << p.stealth << endl;
	savefile << p.no_hp << endl;
	//Weapon Variables
	savefile << p.w.damage << endl;
	savefile << p.w.weight << endl;
	//Armor Variables
	savefile << p.a.defense << endl;
	savefile << p.a.weight << endl;
	//Inventory Variables
	savefile << p.fire << endl;
	savefile << p.i.hp << endl;
	savefile << p.i.money << endl;
	savefile << p.i.weapons << endl;
	savefile << p.i.armors << endl;
	savefile << p.level << endl;

	savefile.close();
}

int read_data(player&p,string stream)
{
	ifstream savefile(stream);

	//Player Variables
	getline(savefile,p.name); //NAME
	getline(savefile,p.w.name); //NAME
	getline(savefile,p.a.name); //NAME
	savefile >> p.wtype;
	savefile >> p.atype;
	savefile >> p.HP;
	savefile >> p.magic;
	savefile >> p.maxHP;
	savefile >> p.luck;
	savefile >> p.wh;
	savefile >> p.dodge;
	savefile >> p.damage;
	savefile >> p.maxM;
	savefile >> p.mana;
	savefile >> p.spellno;
	savefile >> p.stealth;
	savefile >> p.no_hp;
	//Weapon Variables
	savefile >> p.w.damage;
	savefile >> p.w.weight;
	//Armor Variables
	savefile >> p.a.defense;
	savefile >> p.a.weight;
	//Inventory Variables
	savefile >> p.fire;
	savefile >> p.i.hp;
	savefile >> p.i.money;
	savefile >> p.i.weapons;
	savefile >> p.i.armors;
	savefile >> p.level;
}

int gamesave(player&p,int input)
{
	string stream;
	p.level++;

	switch(input)
	{
		case 1:
		{
			stream = "save1.txt";
		}
		break;

		case 2:
		{
			stream = "save2.txt";
		}
		break;

		case 3:
		{
			stream = "save3.txt";
		}
		break;

		case 4:
		{
			stream = "save4.txt";
		}
		break;

		case 5:
		{
			stream = "save5.txt";
		}
		break;
	}

	write_data(p,stream);
}

int gameload(player&p,int input)
{
	string stream;

	switch(input)
	{
		case 1:
		{
			stream = "save1.txt";
		}
		break;

		case 2:
		{
			stream = "save2.txt";
		}
		break;

		case 3:
		{
			stream = "save3.txt";
		}
		break;

		case 4:
		{
			stream = "save4.txt";
		}
		break;

		case 5:
		{
			stream = "save5.txt";
		}
		break;
	}

	read_data(p,stream);
}

int setcolor()
{
	HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );

	switch(c)
	{
		case RED:
		{
			SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		}
		break;

		case BLUE:
		{
			SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		}
		break;

		case GREEN:
		{
			SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		}
		break;

		case WHITE:
		{
			SetConsoleTextAttribute(h,0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		}
		break;

		case BLACK:
		{
			SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		}
		break;
	}
}
