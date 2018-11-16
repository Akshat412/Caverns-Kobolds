#pragma once

#include "resources.h"
#include "objects.h"
#include "textart.h"

void loot_potion(player &p)
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
		case 1:
    case 2:
		{
			cout<<"\nYou found an Ale"<<endl;

			p.i.sp++;

			cout<<"\nNo of Ales : "<<p.i.sp<<endl;
		}
		break;

    default:
    {
      cout<<"\nYou found a Health Potion"<<endl;

      p.i.hp++;

      cout<<"\nNo of Health Potions : "<<p.i.hp<<endl;
    }
    break;
	}
}

void display_weaponstats(weapon &w)
{
	cout<<" [ Damage : ";

	c = YELLOW;
	setcolor();

	cout<<w.damage;

	c = WHITE;
	setcolor();

	cout<<" Weight : ";

	c = YELLOW;
	setcolor();

	cout<<w.weight;

	c = WHITE;
	setcolor();

	cout<<" ] ";

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

	if(w.dh == true && w.name != "Empty")
	{
		c = RED;
		setcolor();

		cout<<" [Dual Handed]";
	}

	else if(w.name != "Empty")
	{
		c = GREEN;
		setcolor();

		cout<<" [Single Handed]";
	}

	c = WHITE;
	setcolor();
}

void loot_weapon(player &p)
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

	cout<<"\nCurrent Weapon : "<<p.w.name; display_weaponstats(p.w);
	cout<<endl;

	if(p.STR - p.w.STR >= temp.weight)
	{
		cout<<"\nDo you pick up the "<<temp.name<<"?"<<endl;
		cout<<"\n1. Yes"<<endl;
		cout<<"\n2. No"<<endl;

		cout<<"\nInput choice : ";
		cin>>choice;

		clear();

		switch(choice)
		{
			case 1:
			{
				cout<<"\nYou picked up the weapon"<<endl;

				p.w = temp;

				if(p.w.dh == true && p.s.name != "No Shield")
				{
					cout<<"\nYou are no longer able to hold a shield, so you store yours in your inventory"<<endl;

					p.i.is = p.s;

					p.s.name = "No Shield";
				}

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

	else
	{
		c = RED;
		setcolor();

		cout<<"\nYour Strength is too low to pick up this weapon"<<endl;
	}

	c = WHITE;
	setcolor();
}

void display_armorstats(armor &a)
{
	cout<<" [ Defence : ";

	c = YELLOW;
	setcolor();

	cout<<a.defense;

	c = WHITE;
	setcolor();

	cout<<" Weight : ";

	c = YELLOW;
	setcolor();

	cout<<a.weight;

	c = WHITE;
	setcolor();

	cout<<" ] ";

	if(a.VIT > 0 || a.STA > 0 || a.FAI > 0 || a.INE > 0)
	{
		cout<<" [ ";
	}

	if(a.VIT > 0)
	{
		cout<<"VIT : ";

		c = GREEN;
		setcolor();

		cout<<"+"<<a.VIT;
	}

	c = WHITE;
	setcolor();

	if(a.STA > 0)
	{
		cout<<" STA : ";

		c = GREEN;
		setcolor();

		cout<<"+"<<a.STA;
	}

	c = WHITE;
	setcolor();

	if(a.FAI > 0)
	{
		cout<<" FAITH : ";

		c = GREEN;
		setcolor();

		cout<<"+"<<a.FAI;
	}

	c = WHITE;
	setcolor();

	if(a.INE > 0)
	{
		cout<<" INT : ";

		c = GREEN;
		setcolor();

		cout<<"+"<<a.INE;
	}

	c = WHITE;
	setcolor();

	if(a.VIT > 0 || a.STA > 0 || a.FAI > 0 || a.INE > 0)
	{
		cout<<" ]";
	}
}

void loot_armor(player &p)
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

	cout<<"\nYou found "<<temp.name; display_armorstats(temp);
	cout<<endl;

	cout<<"\nCurrent Armor : "<<p.a.name; display_armorstats(p.a);
	cout<<endl;

	if((p.VIT - p.a.VIT) / 2 >= temp.weight)
	{
		cout<<"\nDo you pick up the "<<temp.name<<"?"<<endl;
		cout<<"\n1. Yes"<<endl;
		cout<<"\n2. No"<<endl;

		cout<<"\nInput choice : ";
		cin>>choice;

		clear();

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

				removeplayerstats_armors(p,own);

				addplayerstats_armors(p);
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

	else
	{
		c = RED;
		setcolor();

		cout<<"\nYour Vitality is too low to pick up this weapon"<<endl;
	}

	c = WHITE;
	setcolor();
}

void display_shieldstats(shield &w)
{
	cout<<" [ Defence : ";

	c = YELLOW;
	setcolor();

	cout<<w.defense;

	c = WHITE;
	setcolor();

	cout<<" Weight : ";

	c = YELLOW;
	setcolor();

	cout<<w.weight;

	c = WHITE;
	setcolor();

	cout<<" ] ";

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

void loot_shield(player &p)
{
	shield temp, own;
	int choice;

	own = p.s;

	c = GREEN;
	setcolor();

	t = LOOT;
	textart();

	c = WHITE;
	setcolor();

	temp = shieldlist(temp,p);

	cout<<"\nYou found a "<<temp.name; display_shieldstats(temp);
	cout<<endl;

	cout<<"\nCurrent Shield : "<<p.s.name; display_shieldstats(p.s);
	cout<<endl;

	if((p.STR - p.s.STR)/3 >= temp.weight && p.w.dh == false)
	{
		cout<<"\nDo you pick up the "<<temp.name<<"?"<<endl;
		cout<<"\n1. Yes"<<endl;
		cout<<"\n2. No"<<endl;

		cout<<"\nInput choice : ";
		cin>>choice;

		clear();

		switch(choice)
		{
			case 1:
			{
				cout<<"\nYou picked up the shield"<<endl;

				p.s = temp;

				cout<<"\nYou dropped your current shield"<<endl;

				removeplayerstats_shields(p,own);

				addplayerstats_shields(p);
			}
			break;

			case 2:
			{
				cout<<"\nYou left the shield and moved on"<<endl;
			}
			break;
		}
	}

	else if(p.w.dh == true)
	{
		c = RED;
		setcolor();

		cout<<"\nYou cannot use a shield as you have a dual handed weapon. You store the shield in your inventory"<<endl;

		c = WHITE;
		setcolor();

		p.i.is = temp;
	}

	else
	{
		c = RED;
		setcolor();

		cout<<"\nYour Strength is too low to pick up this shield"<<endl;
	}

	c = WHITE;
	setcolor();
}

void inventory(player &p)
{
	int choice, wchoice, weaponslot, armorslot;
	weapon wown;
	armor aown;
	shield empty;

	wown = p.w;
	aown = p.a;

	cout<<"\nWhich items would you like to use?"<<endl;

	cout<<"\n1. Weapons"<<endl;
	cout<<"\n2. Armors"<<endl;
	cout<<"\n3. Equip Shield"<<endl;
	cout<<"\n4. Healing Potions"<<endl;
	cout<<"\n5. Ales"<<endl;

	cout<<"\nInput choice : ";
	cin>>choice;

	switch(choice)
	{
		case 1:
		{
			cout<<"\nWhich weapon would you like to use [Enter 10x the choice to throw away the weapon]?"<<endl;

			for(int i = 0; i < 5; i++)
			{
				cout<<"\nSlot "<<i + 1<<" : "<<p.i.iw[i].name; display_weaponstats(p.i.iw[i]);
				cout<<endl;
			}

			cout<<"\nWhich weapon would you like to chose?"<<endl;

			cout<<"\nInput choice : ";
			cin >> wchoice;

			switch(wchoice)
			{
				case 1:
        case 2:
        case 3:
        case 4:
        case 5:
				{
					weaponslot  = wchoice - 1;

					p.w = p.i.iw[weaponslot];

					p.i.iw[weaponslot] = wown;

					removeplayerstats_weapons(p,wown);
					addplayerstats_weapons(p);

					cout<<"\nYou draw the "<<p.w.name<<endl;

					if(p.w.dh == true)
					{
						p.s = empty;
					}

					if(p.w.name == "Empty")
					{
						p.w.name = "Iron Gloves";
						p.w.damage = 5;
						p.w.weight = 1;
						p.w.dh = false;
						p.w.type = HANDS;
						p.w.material = IRON;
					}
				}
				break;

				case 10:
        case 20:
        case 30:
        case 40:
        case 50:
				{
					weaponslot  = (wchoice/10)- 1;

					cout<<"\nYou throw away the "<<p.i.iw[weaponslot].name<<endl;

					p.i.iw[weaponslot].name = "Empty";
					p.i.iw[weaponslot].damage = 0;
					p.i.iw[weaponslot].weight = 1;
					p.i.iw[weaponslot].STR = p.i.iw[weaponslot].DEX = p.i.iw[weaponslot].FAI = p.i.iw[weaponslot].INE = 0;
					p.i.iw[weaponslot].dh = false;

					p.i.weapons--;
				}

				default:
					cout<<"\nYou do not change your current weapon"<<endl;
          return;
			}
		}
		break;

		case 2:
		{
			cout<<"\nWhich armor would you like to use?"<<endl;

			for(int i = 0; i < 2; i++)
			{
				cout<<"\nSlot "<<i + 1<<" : "<<p.i.ia[i].name; display_armorstats(p.i.ia[i]);
				cout<<endl;
			}

			cout<<"\nWhich armor would you like to equip [Enter 10x the choice to throw away the armor]?"<<endl;

			cout<<"\nInput choice : ";
			cin>>wchoice;

			switch(wchoice)
			{
				case 1:
        case 2:
				{
					armorslot  = wchoice - 1;

					p.a = p.i.ia[armorslot];

					p.i.ia[armorslot] = aown;

					removeplayerstats_armors(p,aown);
					addplayerstats_armors(p);

					cout<<"\nYou wear the "<<p.a.name<<endl;
				}
				break;

				case 10:
        case 20:
        case 30:
        case 40:
        case 50:
				{
					armorslot  = (wchoice/10)- 1;

					cout<<"\nYou throw away the "<<p.i.ia[armorslot].name<<endl;

					p.i.ia[armorslot].name = "Empty";
					p.i.ia[armorslot].defense = 0;
					p.i.ia[armorslot].weight = 1;
					p.i.ia[armorslot].VIT = p.i.ia[armorslot].STA = p.i.ia[armorslot].FAI = p.i.ia[armorslot].INE = 0;

					p.i.armors--;
				}

				default:
					cout<<"\nYou do not change your current armor"<<endl;
          return;
			}
		}
		break;

		case 3:
		{
			if(p.w.dh == false)
			{
				if(p.i.is.name == "No Shield" && p.s.name == "No Shield")
				{
					c = RED;
					setcolor();

					cout<<"\nYou don't have a shield to equip"<<endl;

					c = WHITE;
					setcolor();
				}

				else if(p.i.is.name == "No Shield" && p.s.name != "No Shield")
				{
					c = RED;
					setcolor();

					cout<<"\nYou already have a shield equipped"<<endl;

					c = WHITE;
					setcolor();
				}

				else if(p.i.is.name != "No Shield" && p.s.name == "No Shield")
				{
					p.s = p.i.is;
					p.i.is.name = "No Shield";
				}
			}

			else
			{
				c = RED;
				setcolor();

				cout<<"\nYou cannot equip a shield as you have a dual-handed weapon equipped"<<endl;

				c = WHITE;
				setcolor();
			}
		}
		break;

		case 4:
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

		case 5:
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
		break;

		default:
		{
			//
		}
		break;
	}
}
