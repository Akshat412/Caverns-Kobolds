#pragma once

#include <iostream>
#include<Windows.h>
#include<ctime>
#include<string>
#include<cstdio>
#include<stdlib.h>
#include<fstream>
#include"textart.h"

using namespace std;

enum color {RED, BLUE, GREEN, YELLOW, BLACK, WHITE};
color c;

struct weapon
{
	string name;
	int damage;
	int weight;

	int STR, DEX, FAI, INE;

	weapon()
	{
		STR = 0;
		DEX = 0;
		FAI = 0;
		INE = 0;
	}
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
	int sp;
	int money;
	int weapons;
	int armors;
	weapon iw[5];
	armor ia[2];
};

struct player
{
	//Name stuff
	string name,pclass,race;
	//Items
	weapon w;
	inventory i;
	armor a;

	//Basic Stats
	int wtype, atype;
	int HP, maxHP;
	int STR, VIT, DEX, STA, FAI, INE; 
	
	//Deriviative Stats
	int magic;
	int damage;
	int wh;
	int stamina;
	int dodge;
	int mana;
	int maxM;
	int spellno;
	int fire;
	int stealth;

	//General Stats 
	int no_hp;
	int level;
	int ability_point;
	bool ability;
	int xp;
	int luck;

	//Stress Related Stats
	int stress;
	int stress_limit;
	int smDM;
	int smHP;
	int smDEX;
	bool panic_attack;

	int setattributes()
	{
		maxHP = 40 * VIT;
		HP = maxHP;
		damage = 1.5 * STR;
		wh = DEX/2;
		dodge = STA / 3;
		stealth = STA / 3;
		maxM = 40 * INE;
		mana = maxM;
		if(INE/5 - 1 > 0) spellno = INE/5 - 1; else spellno = 0;
		fire = 8 * INE;
		magic = 8 * FAI;

		stress_limit = VIT * 2;
		if(stress * 100 / stress_limit < 50) smDM = 0; else smDM = 50/STR;
		smHP = 30/VIT;
		smDEX = 20/DEX;
	}

	int initialize_inventory()
	{
		for(int f = 0; f < 5; f++)
		{
			i.iw[f].name = "Empty";
		}

		for(int f = 0; f < 2; f++)
		{
			i.ia[f].name = "Empty";
		}
	}

	player() //c'est un constructor
	{
		name = "";
		race = "Human";
		pclass = "Prisoner";
		wtype = 4; 
		atype = 4;
		luck = 3;

		STR = 5;
		VIT = 5;
		DEX = 5;
		STA = 5;
		FAI = 5;
		INE = 5;
		
		setattributes();

		w.name= "Piece of Wood";
		w.damage = 2;
		w.weight = 1;
				
		a.name = "Prisoner Rags";
		a.defense = 2;
		a.weight = 1;

		xp = 0;
		stress = 0;
		no_hp = 0;
		i.hp = 0;
		i.sp = 0;
		i.money = 0;
		i.weapons = 0;
		i.armors = 0;

		initialize_inventory();

		level = 0;

		ability_point = 5;
		ability = false;
	}
};

struct enemy
{
	string name;
	int HP;
	int maxHP;
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

int heal(player&p)
{
	if(p.i.hp > 0)
	{
		cout<<"\nYou used a healing potion, and healed up by 400 HP"<<endl;
							
		if(p.HP + 400 < p.maxHP)
		{
			p.HP = p.HP + 400;
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

int s_heal(player&p)
{
	if(p.i.sp > 0)
	{
		cout<<"\nYou used an ale, and decreased your stress by 10"<<endl;
							
		if(p.stress - 10 > 0)
		{
			p.stress -= 10;
			p.i.sp--;
		}
							
		else
		{
			p.stress = 0;
			p.i.sp--;
		}
	}
						
	else
	{
		cout<<"\nYou're out of ales"<<endl;
	}
	
	cout<<"\nNo of Ales : "<<p.i.sp<<endl;
}

int write_data(player&p,string stream)
{
	ofstream savefile(stream);

	//Player Variables
	savefile << p.name << endl;
	savefile << p.race << endl;
	savefile << p.pclass << endl;
	savefile << p.w.name << endl;
	savefile << p.a.name << endl;
	
	savefile << p.STR << endl;
	savefile << p.VIT << endl;
	savefile << p.DEX << endl;
	savefile << p.STA << endl;
	savefile << p.FAI << endl;
	savefile << p.INE << endl;

	//Weapon Variables
	savefile << p.wtype << endl;
	savefile << p.w.damage << endl;
	savefile << p.w.weight << endl;
	savefile << p.w.STR << " " << p.w.DEX << " " << p.w.FAI << " " << p.w.INE << endl;
	//Armor Variables
	savefile << p.atype << endl;
	savefile << p.a.defense << endl;
	savefile << p.a.weight << endl;
	//Inventory Variables
	savefile << p.luck << endl;
	savefile << p.stress << endl;
	savefile << p.no_hp << endl;
	savefile << p.i.hp << endl;
	savefile << p.i.sp << endl;
	savefile << p.i.money << endl;
	savefile << p.i.weapons << endl;
	savefile << p.i.armors << endl;
	savefile << p.xp << endl;
	savefile << p.level << endl;

	savefile.close();
}

int read_data(player&p,string stream)
{
	ifstream savefile(stream);

	//Player Variables
	getline(savefile,p.name); 
	getline(savefile,p.race);
	getline(savefile,p.pclass);
	getline(savefile,p.w.name); 
	getline(savefile,p.a.name);
	 
	savefile >> p.STR;
	savefile >> p.VIT;
	savefile >> p.DEX;
	savefile >> p.STA;
	savefile >> p.FAI;
	savefile >> p.INE;
	
	//Weapon Variables
	savefile >> p.wtype;
	savefile >> p.w.damage;
	savefile >> p.w.weight;
	savefile >> p.w.STR >> p.w.DEX >> p.w.FAI >> p.w.INE;
	//Armor Variables
	savefile >> p.atype;
	savefile >> p.a.defense;
	savefile >> p.a.weight;
	//Inventory Variables
	savefile >> p.luck;
	savefile >> p.stress;
	savefile >> p.no_hp;
	savefile >> p.i.hp;
	savefile >> p.i.sp;
	savefile >> p.i.money;
	savefile >> p.i.weapons;
	savefile >> p.i.armors;
	savefile >> p.xp;
	savefile >> p.level;
}

int setcolor()
{
	HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );

	switch(c)
	{
		case RED:
		{
			SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
		}
		break;

		case BLUE:
		{
			SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY );
		}
		break;

		case GREEN:
		{
			SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		break;

		case YELLOW:
		{
			SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		}
		break;

		case BLACK:
		{
			SetConsoleTextAttribute(h,0);
		}
		break;

		case WHITE:
		{
			SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		break;
	}
}

int gamesave(player&p,int input)
{
	string stream;
	p.level++;

	switch(input)
	{
		case 1:
		{
			stream = "Savefiles/save1.txt";
		}
		break;

		case 2:
		{
			stream = "Savefiles/save2.txt";
		}
		break;

		case 3:
		{
			stream = "Savefiles/save3.txt";
		}
		break;

		case 4:
		{
			stream = "Savefiles/save4.txt";
		}
		break;

		case 5:
		{
			stream = "Savefiles/save5.txt";
		}
		break;
	}

	write_data(p,stream);

	c = GREEN;
	setcolor();

	cout<<"\nGame has been saved"<<endl;

	c = WHITE;
	setcolor();
}

int gameload(player&p,int input)
{
	string stream;

	switch(input)
	{
		case 1:
		{
			stream = "Savefiles/save1.txt";
		}
		break;

		case 2:
		{
			stream = "Savefiles/save2.txt";
		}
		break;

		case 3:
		{
			stream = "Savefiles/save3.txt";
		}
		break;

		case 4:
		{
			stream = "Savefiles/save4.txt";
		}
		break;

		case 5:
		{
			stream = "Savefiles/save5.txt";
		}
		break;
	}

	read_data(p,stream);

	p.setattributes();

	p.ability_point = 5;
}

int printH(int HP, int maxHP)
{
	int x = ((HP * 50) / maxHP);

	for(int i = 0; i < 52; i++)
	{
		if(i == 0)
		{
			cout<<"[";
		}

		else if(i == 51)
		{
			cout<<"]"<<endl;
		}

		else
		{
			if(x > 0)
			{
				c = GREEN;
				setcolor();

				cout<<";";
				x--;
			}

			else
			{
				cout<<" ";
			}
		}

		c = WHITE;
		setcolor();
	}
}

int printM(int mana, int maxM)
{
	int x = ((mana * 30) / maxM) + 1;

	for(int i = 0; i < 32; i++)
	{
		if(i == 0)
		{
			cout<<"[";
		}

		else if(i == 31)
		{
			cout<<"]"<<endl;
		}

		else
		{
			if(x > 0)
			{
				c = BLUE;
				setcolor();

				cout<<":";
				x--;
			}

			else
			{
				cout<<" ";
			}
		}

		c = WHITE;
		setcolor();
	}
}

int printA(int abi, int fac)
{
	int x = ((abi * 5) / fac) + 1;

	for(int i = 0; i < 7; i++)
	{
		if(i == 0)
		{
			cout<<"[";
		}

		else if(i == 6)
		{
			cout<<"]"<<endl;
		}

		else
		{
			if(x > 0)
			{
				c = YELLOW;
				setcolor();

				cout<<">";
				x--;
			}

			else
			{
				cout<<" ";
			}
		}

		c = WHITE;
		setcolor();
	}
}

int printS(int abi, int fac)
{
	int x = ((abi * 10) / fac) + 1;

	for(int i = 0; i < 12; i++)
	{
		if(i == 0)
		{
			cout<<"[";
		}

		else if(i == 11)
		{
			cout<<"]"<<endl;
		}

		else
		{
			if(x > 0)
			{
				c = RED;
				setcolor();

				cout<<">";
				x--;
			}

			else
			{
				cout<<" ";
			}
		}

		c = WHITE;
		setcolor();
	}
}


