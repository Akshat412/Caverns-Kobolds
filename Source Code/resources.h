#pragma once

//libwinpthread-1.dll
//libgcc_s_dw2-1.dll
//libstdc++-6.dll

#include<iostream>
#include<Windows.h>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include"textart.h"

using namespace std;

enum color {RED, BLUE, GREEN, YELLOW, BLACK, WHITE};
color c;

enum wtype {HV_BLUDGE = 0, HV_AXE = 1, HV_SWORD = 2, SWORD = 3, SPEAR = 4, AXE = 5, DAGGER = 6, STAFF = 7, HANDS = 8};

enum object_material {WOOD = 0, IRON = 1, BRONZE = 2, COPPER = 3, STEEL = 4, SILVER = 5};

enum enemytype {BEAST, UNHOLY};

int input, temp_wtype, temp_wmat;

int abs(int x, int y)
{
	if(x - y >= 0)
	{
		return x - y;
	}

	else
	{
		return y - x;
	}

	return 0;
}

struct shield
{
	string name;
	int defense;
	int weight;

	int STR, DEX, FAI, INE;

	shield()
	{
		defense = 1;
		weight = 0;

		STR = 0;
		DEX = 0;
		FAI = 0;
		INE = 0;
	}
};

struct weapon
{
	string name;
	int damage;
	int weight;

	int STR, DEX, FAI, INE;

	bool dh;

	wtype type;

	string c_attack, n_attack, r_attack, s_attack;

	object_material material;

	weapon()
	{
		damage = 0;
		weight = 1;

		STR = 0;
		DEX = 0;
		FAI = 0;
		INE = 0;

		dh = false;
	}
};

struct armor 
{
	string name;
	int defense;
	int weight;

	int VIT, STA, FAI, INE;


	armor()
	{
		defense = 0;
		weight = 1;

		VIT = 0;
		STA = 0;
		FAI = 0;
		INE = 0;
	}
};

struct inventory
{
	int hp;
	int sp;
	int money;
	int weapons;
	int armors;
	int torches;
	weapon iw[5];
	armor ia[2];
	shield is;
};

struct player
{
	//Name stuff
	string name, pclass, race;
	string playerdone, playerchance, playersuccess;
	int playerdoes;
	int damage_taken;
	int armor_defence;
	bool wolf_slayer;
	
	//Items
	weapon w;
	inventory i;
	armor a;
	shield s;

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
	int riposte;

	//General Stats
	int pos; 
	int no_hp;
	int level;
	int ability_point;
	bool ability;
	bool wability;
	bool crit;
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
		damage = 2 * STR;
		if(DEX >= 3) wh = DEX / 3; else wh = 1;
		if(STA >= 5) dodge = STA / 5; else dodge = 1;
		stealth = (STA / 5) + 1;
		maxM = 50 * INE;
		mana = maxM;
		if(INE/5 - 1 > 0) spellno = INE/5 - 1; else spellno = 0;
		fire = 6 * INE;
		magic = 20 * FAI;

		stress_limit = VIT * 2;

		if(level >= 1)
		{
			smDM = 100/STR;
			smHP = 100/VIT; 
			smDEX = 20/DEX; 
		}

		return 0;
	}

	int initialize_inventory()
	{
		for(int f = 0; f < 5; f++)
		{
			i.iw[f].name = "Empty";
			i.iw[f].damage = 0;
			i.iw[f].weight = 0;
			i.iw[f].STR = i.iw[f].DEX = i.iw[f].FAI = i.iw[f].INE = 0;

			i.iw[f].dh = false;
		}

		for(int f = 0; f < 2; f++)
		{
			i.ia[f].name = "Empty";
			i.ia[f].defense = 0;
			i.ia[f].weight = 0;
			i.ia[f].VIT = i.ia[f].STA = i.ia[f].FAI = i.ia[f].INE = 0;
		}

		i.is.name = "No Shield";

		return 0;
	}

	player() 
	{
		name = "Default Character";
		race = "Human";
		pclass = "Prisoner";
		wtype = 4; 
		atype = 4;
		luck = 3;

		damage_taken = 0;

		STR = 5;
		VIT = 5;
		DEX = 5;
		STA = 5;
		FAI = 5;
		INE = 5;
		
		setattributes();

		w.name= "Piece of Wood";
		w.damage = 3;
		w.weight = 1;
		w.type = HV_BLUDGE;
		w.dh = true;
		w.material = WOOD;
				
		a.name = "Prisoner Rags";
		a.defense = 2;
		a.weight = 1;

		s.name = "Iron Sheet";
		s.defense = 1;
		s.weight = 1;

		xp = 0;
		riposte = 0;
		pos = 0;
		stress = 0;
		no_hp = 0;
		i.torches = 0;
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
	string nattack;
	string cattack;
	string enemydoes;
	int enemychance;
	int damage_taken;
	int HP;
	int maxHP;
	int damage;
	int cdamage;
	int dodge;
	int sdodge;

	int stunned;
	int bleeding;
	int poisoned;

	enemytype type;
	bool boss;

	enemy()
	{
		stunned = 0;
		bleeding = 0;
		poisoned = 0;

		damage_taken = 0;

		boss = false;
	}
};

int removeplayerstats_weapons(player&p, weapon&own)
{
	p.STR -= own.STR;
	p.DEX -= own.DEX;
	p.FAI -= own.FAI;
	p.INE -= own.INE;

	return 0;
}

int addplayerstats_weapons(player&p)
{
	int HP = p.HP, stress = p.stress, mana = p.mana;

	p.STR += p.w.STR;
	p.DEX += p.w.DEX;
	p.FAI += p.w.FAI;
	p.INE += p.w.INE;

	p.setattributes();

	if(HP <= p.maxHP) p.HP = HP;
	if(stress <= p.stress_limit) p.stress = stress;
	if(mana <= p.maxM) p.mana = mana;

	return 0;
}

int removeplayerstats_armors(player&p, armor&own)
{
	p.VIT -= own.VIT;
	p.STA -= own.STA;
	p.FAI -= own.FAI;
	p.INE -= own.INE;

	return 0;
}

int addplayerstats_armors(player&p)
{
	int HP = p.HP, stress = p.stress, mana = p.mana;

	p.VIT += p.a.VIT;
	p.STA += p.a.STA;
	p.FAI += p.a.FAI;
	p.INE += p.a.INE;

	p.setattributes();

	if(HP <= p.maxHP) p.HP = HP;
	if(stress <= p.stress_limit) p.stress = stress;
	if(mana <= p.maxM) p.mana = mana;

	return 0;
}

int removeplayerstats_shields(player&p, shield&own)
{
	p.STR -= own.STR;
	p.DEX -= own.DEX;
	p.FAI -= own.FAI;
	p.INE -= own.INE;

	return 0;
}

int addplayerstats_shields(player&p)
{
	int HP = p.HP, stress = p.stress, mana = p.mana;

	p.STR += p.s.STR;
	p.DEX += p.s.DEX;
	p.FAI += p.s.FAI;
	p.INE += p.s.INE;

	p.setattributes();

	if(HP <= p.maxHP) p.HP = HP;
	if(stress <= p.stress_limit) p.stress = stress;
	if(mana <= p.maxM) p.mana = mana;

	return 0;
}

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

int write_data(player&p,string stream)
{
	ofstream savefile(stream);

	//Player Variables
	savefile << p.name << endl;
	savefile << p.race << endl;
	savefile << p.pclass << endl;
	savefile << p.w.name << endl;
	savefile << p.a.name << endl;
	savefile << p.s.name << endl;

	for(int f = 0; f < 5; f++)
	{
		savefile << p.i.iw[f].name << endl;
	}

	for(int f = 0; f < 2; f++)
	{
		savefile << p.i.ia[f].name << endl;
	}

	savefile << p.i.is.name << endl;

	for(int f = 0; f < 5; f++)
	{
		savefile << p.i.iw[f].damage << endl;
		savefile << p.i.iw[f].weight << endl;
		savefile << p.i.iw[f].STR << " " << p.i.iw[f].DEX << " " << p.i.iw[f].FAI << " " << p.i.iw[f].INE << endl;
	}

	for(int f = 0; f < 2; f++)
	{
		savefile << p.i.ia[f].defense << endl;
		savefile << p.i.ia[f].weight << endl;
		savefile << p.i.ia[f].VIT << " " << p.i.ia[f].STA << " " << p.i.ia[f].FAI << " " << p.i.ia[f].INE << endl;
	}

	savefile << p.i.is.defense << endl;
	savefile << p.i.is.weight << endl;
	savefile << p.i.is.STR << " " << p.i.is.DEX << " " << p.i.is.FAI << " " << p.i.is.INE << endl;
	
	savefile << p.STR << endl;
	savefile << p.VIT << endl;
	savefile << p.DEX << endl;
	savefile << p.STA << endl;
	savefile << p.FAI << endl;
	savefile << p.INE << endl;
	//Weapon Variables
	savefile << p.w.damage << endl;
	savefile << p.w.weight << endl;
	savefile << p.w.STR << " " << p.w.DEX << " " << p.w.FAI << " " << p.w.INE << endl;
	savefile << p.w.dh << endl;

	switch(p.w.type)
	{
		case 0: temp_wtype = 0;
		break;

		case 1: temp_wtype = 1;
		break;

		case 2: temp_wtype = 2;
		break;

		case 3: temp_wtype = 3;
		break;

		case 4: temp_wtype = 4;
		break;

		case 5: temp_wtype = 5;
		break;

		case 6: temp_wtype = 6;
		break;

		case 7: temp_wtype = 7;
		break;

		case 8: temp_wtype = 8;
		break;
	}

	savefile << temp_wtype << endl;

	savefile << temp_wmat << endl;

	//Armor Variables
	savefile << p.a.defense << endl;
	savefile << p.a.weight << endl;
	savefile << p.a.VIT << " " << p.a.STA << " " << p.a.FAI << " " << p.a.INE << endl;

	//Shield Variables
	savefile << p.s.defense << endl;
	savefile << p.s.weight << endl;
	savefile << p.s.STR << " " << p.s.DEX << " " << p.s.FAI << " " << p.s.INE << endl;

	//Inventory Variables
	savefile << p.pos << endl;
	savefile << p.luck << endl;
	savefile << p.no_hp << endl;
	savefile << p.ability_point << endl;
	savefile << p.i.torches << endl;
	savefile << p.i.hp << endl;
	savefile << p.i.sp << endl;
	savefile << p.i.money << endl;
	savefile << p.i.weapons << endl;
	savefile << p.i.armors << endl;
	savefile << p.xp << endl;
	savefile << p.level << endl;

	savefile.close();

	return 0;
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
	getline(savefile,p.s.name);

	for(int f = 0; f < 5; f++)
	{
		getline(savefile,p.i.iw[f].name);
	}

	for(int f = 0; f < 2; f++)
	{
		getline(savefile,p.i.ia[f].name);
	}

	getline(savefile,p.i.is.name);

	for(int f = 0; f < 5; f++)
	{
		savefile >> p.i.iw[f].damage;
		savefile >> p.i.iw[f].weight;
		savefile >> p.i.iw[f].STR >> p.i.iw[f].DEX >> p.i.iw[f].FAI >> p.i.iw[f].INE;
	}

	for(int f = 0; f < 2; f++)
	{
		savefile >> p.i.ia[f].defense;
		savefile >> p.i.ia[f].weight;
		savefile >> p.i.ia[f].VIT >> p.i.ia[f].STA >> p.i.ia[f].FAI >> p.i.ia[f].INE;
	}

	savefile >> p.i.is.defense;
	savefile >> p.i.is.weight;
	savefile >> p.i.is.STR >> p.i.is.DEX >> p.i.is.FAI >> p.i.is.INE;

	savefile >> p.STR;
	savefile >> p.VIT;
	savefile >> p.DEX;
	savefile >> p.STA;
	savefile >> p.FAI;
	savefile >> p.INE;
	//Weapon Variables
	savefile >> p.w.damage;
	savefile >> p.w.weight;
	savefile >> p.w.STR >> p.w.DEX >> p.w.FAI >> p.w.INE;
	savefile >> p.w.dh;
	savefile >> temp_wtype;
	
	switch(temp_wtype)
	{
		case 0: p.w.type = HV_BLUDGE;
		break;

		case 1: p.w.type = HV_AXE;
		break;

		case 2: p.w.type = HV_SWORD;
		break;

		case 3: p.w.type = SWORD;
		break;

		case 4: p.w.type = SPEAR;
		break;

		case 5: p.w.type = AXE;
		break;

		case 6: p.w.type = DAGGER;
		break;

		case 7: p.w.type = STAFF;
		break;

		case 8: p.w.type = HANDS;
	}

	savefile >> temp_wmat;

	//Armor Variables
	savefile >> p.a.defense;
	savefile >> p.a.weight;
	savefile >> p.a.VIT >> p.a.STA >> p.a.FAI >> p.a.INE;

	//Shield Variables
	savefile >> p.s.defense;
	savefile >> p.s.weight;
	savefile >> p.s.STR >> p.s.DEX >> p.s.FAI >> p.s.INE;

	//Inventory Variables
	savefile >> p.pos;
	savefile >> p.luck;
	savefile >> p.no_hp;
	savefile >> p.ability_point;
	savefile >> p.i.torches;
	savefile >> p.i.hp;
	savefile >> p.i.sp;
	savefile >> p.i.money;
	savefile >> p.i.weapons;
	savefile >> p.i.armors;
	savefile >> p.xp;
	savefile >> p.level;

	return 0;
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

	return 0;
}

int heal(player&p)
{
	int faith_factor = p.FAI/5;

	int heal = ((10 + faith_factor) * 400)/10;

	if(p.i.hp > 0)
	{
		cout<<"\nYou used a healing potion, and healed up by ";

		c = GREEN;
		setcolor();

		cout<<heal;

		c = WHITE;
		setcolor();

		cout<<" HP"<<endl;
							
		if(p.HP + heal < p.maxHP)
		{
			p.HP = p.HP + heal;
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

	return 0;
}

int s_heal(player&p)
{
	int faith_factor = p.FAI/5;

	int stress_heal = 10 + faith_factor;

	if(p.i.sp > 0)
	{
		cout<<"\nYou used an ale, and decreased your stress by ";

		c = GREEN;
		setcolor();

		cout<<stress_heal<<endl;

		c = WHITE;
		setcolor();
							
		if(p.stress - stress_heal > 0)
		{
			p.stress -= stress_heal;
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

	return 0;
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

	return 0;
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

	return 0;
}

int printH(int HP, int maxHP)
{
	int bar_size = 50;

	int x = ((HP * bar_size) / maxHP);

	for(int i = 0; i < bar_size + 2; i++)
	{
		if(i == 0)
		{
			cout<<"[";
		}

		else if(i == bar_size + 1)
		{
			cout<<"]"<<endl;
		}

		else
		{
			if(x > 0)
			{
				c = GREEN;
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

	return 0;
}

int printM(int mana, int maxM)
{
	int bar_size = 50;

	int x = ((mana * bar_size) / maxM) + 1;

	for(int i = 0; i < bar_size + 2; i++)
	{
		if(i == 0)
		{
			cout<<"[";
		}

		else if(i == bar_size + 1)
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

	return 0;
}

int printA(int abi, int fac)
{
	int x = ((abi * 5) / fac);

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

	return 0;
}

int printS(int abi, int fac)
{
	int bar_size = 30;

	int x = ((abi * bar_size) / fac) + 1;

	for(int i = 0; i < bar_size + 2; i++)
	{
		if(i == 0)
		{
			cout<<"[";
		}

		else if(i == bar_size + 1)
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

	return 0;
}

int printRAGE(int rage, int r = 5)
{
	int x = rage;

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

	return 0;
}


