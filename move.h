#pragma once

#include"resources.h"
#include"battle.h"
#include"initialization.h"
#include"loot.h"
#include"events.h"

using namespace std;

int move(player&p,enemy&e)
{
	srand(time(0));
	
	int pos=0,monster_chance,loot_chance,dead=0,random_chance;
	
	p.stamina = 5;
	
	int l = 12 - p.luck;
	
	int choice,cchoice;
	
	while(pos<15)
	{
		cout<<"\nWhat do you choose"<<endl;
		
		cout<<"\n1. Move forward"<<endl;
		cout<<"\n2. Rest"<<endl;
		cout<<"\n3. Level Up"<<endl;
		cout<<"\n4. Stats"<<endl;
		cout<<"\n5. Inventory"<<endl;
		
		cout<<"\nInput choice : ";
		cin>>choice;
		
		system("cls");
		
		switch(choice)
		{
			case 1:
			{
				if(p.stamina>0)
				{
					cout<<"\nYou moved forward"<<endl;
					pos++;
					p.stamina--;
				
					enemyclass(p,e);
				
					cout<<"\nCurrent Position : "<<pos<<endl;
				
					monster_chance = (rand () % p.luck);
					loot_chance = (rand () % l);
				
					switch(monster_chance)
					{
						case 0:
						{
							cout<<"\nYou spotted a ";

							c = RED;
							setcolor();

							cout<<e.name<<endl;

							c = WHITE;
							setcolor();
							
							stealth_attack(p,e);
							
							if(e.HP > 0)
							{
								dead = battle(p,e);	
							}
							
							if(dead==1)
							{
								return dead;
							}
						}
						break;
					
						default:
						{
							cout<<"\nNo enemies appeared"<<endl;
							
							random_chance = (rand () % 7);
							
							switch(random_chance)
							{
								case 0:
								{
									dead = random_event(p,e);
								}
								break;
							}
							
							if(dead==1)
							{
								return dead;
							}
						}
						break;
					}
					
					switch(loot_chance)
					{
						case 0:
						{
							loot_potion(p);
						}
						break;
						
						default:
						{
							cout<<"\nYou didn't find any loot on the ground"<<endl;
						}
						break;
					}
					
					empty();
				}
				else
				{
					c = RED;
					setcolor();

					cout<<"\nYour stamina is too low to move"<<endl;
					empty();

					c = WHITE;
					setcolor();
				}
			}
			break;
			
			case 2:
			{
				cout<<"\nYou chose to rest"<<endl;
				
				cout<<"\nCurrent position : "<<pos<<endl;
				
				cout<<"\nYour stamina increased"<<endl;
				p.stamina = 5;
				
				cout<<"\nYour mana increased to it's max"<<endl;
				
				p.mana = p.maxM;

				empty();
			}
			break;
			
			case 3:
			{
				levelup(p);
				empty();
			}
			break;
			
			case 4:
			{
				logging(p);
				empty();
			}
			break;

			case 5:
			{
				inventory(p);
				empty();
			}
			break;
		}
		
		system("cls");
		c = WHITE;
		setcolor();
	}

	return dead;
}
