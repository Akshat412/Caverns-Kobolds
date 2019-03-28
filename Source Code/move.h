#pragma once

#include"resources.h"
#include"battle.h"
#include"initialization.h"
#include"loot.h"
#include"events.h"

using namespace std;

int move(player&p,enemy&e)
{
	system("cls");
	
	srand(time(0));
	
	int monster_chance,loot_chance,dead=0,random_chance;
	
	p.stamina = 5;
	
	int l = 12 - p.luck;
	
	int choice,cchoice;
	
	while(p.pos < 20)
	{
		cout<<"\nPlayer Health : ";

		c = GREEN;
		setcolor();

		if(p.HP > 0)
		{
			cout<<p.HP;
		}

		else
		{
			cout<<"0";
		}

		c = WHITE;
		setcolor();

		cout<<" / "<<p.maxHP;

		cout<<endl;
		printH(p.HP, p.maxHP);

		cout<<"\nPlayer Mana : ";

		c = GREEN;
		setcolor();

		cout<<p.mana;

		c = WHITE;
		setcolor();

		cout<<" / "<<p.maxM;

		cout<<endl;
		printM(p.mana, p.maxM);

		cout<<"\nPlayer Stress : "; printS(p.stress, p.stress_limit);

		if(p.pos < 2)
		{
			cout<<"\nWhat do you choose"<<endl;
		
			cout<<"\n1. Move forward"<<endl;
			cout<<"\n2. Rest";

			c = GREEN;
			setcolor();

			cout<<" [Increases Mana]"<<endl;

			c = WHITE;
			setcolor();

			cout<<"\n3. Level Up"<<endl;
			cout<<"\n4. Stats"<<endl;
			cout<<"\n5. Inventory";

			c = GREEN;
			setcolor();

			cout<<" [Access weapons, armors, and potions]"<<endl;

			c = WHITE;
			setcolor();

			cout<<"\n6. Create Bonfire";

			c = GREEN;
			setcolor();

			cout<<" [Saves Game]"<<endl;

			c = WHITE;
			setcolor();
		}

		else
		{
			cout<<"\nWhat do you choose"<<endl;
		
			cout<<"\n1. Move forward"<<endl;
			cout<<"\n2. Rest"<<endl;
			cout<<"\n3. Level Up"<<endl;
			cout<<"\n4. Stats"<<endl;
			cout<<"\n5. Inventory"<<endl;
			cout<<"\n6. Create Bonfire"<<endl;
		}
		
		cout<<"\nInput choice : ";
		cin>>choice;
		
		system("cls");
		
		switch(choice)
		{
			case 1:
			{
				if(p.stamina>0)
				{
					cout<<"\nPlayer Health : ";

					c = GREEN;
					setcolor();

					if(p.HP > 0)
					{
						cout<<p.HP;
					}

					else
					{
						cout<<"0";
					}

					c = WHITE;
					setcolor();

					cout<<" / "<<p.maxHP;

					cout<<endl;
					printH(p.HP, p.maxHP);

					cout<<"\nPlayer Mana : ";

					c = GREEN;
					setcolor();

					cout<<p.mana;

					c = WHITE;
					setcolor();

					cout<<" / "<<p.maxM;

					cout<<endl;
					printM(p.mana, p.maxM);

					cout<<"\nPlayer Stress : "; printS(p.stress, p.stress_limit);

					cout<<"\nYou moved forward"<<endl;
					p.pos++;
					p.stamina--;
				
					enemyclass(p,e);
				
					cout<<"\nCurrent Position : "<<p.pos<<endl;
				
					monster_chance = (rand () % p.luck);

					if(p.pos > 18)
					{
						monster_chance = 10;
						loot_chance = 0;
					}

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
							
							random_chance = (rand () % 10);
							
							switch(random_chance)
							{
								default:
								{
									dead = random_event(p,e);
								}
								break;

								case 0: case 1: case 2: case 3:
								{
									//Nothing Happens
									break;
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
							empty();
						}
						break;
						
						default:
						{
							cout<<"\nYou didn't find any loot on the ground"<<endl;
							empty();
						}
						break;
					}
				}
				else
				{
					cout<<"\nPlayer Health : ";

					c = GREEN;
					setcolor();

					if(p.HP > 0)
					{
						cout<<p.HP;
					}

					else
					{
						cout<<"0";
					}

					c = WHITE;
					setcolor();

					cout<<" / "<<p.maxHP;

					cout<<endl;
					printH(p.HP, p.maxHP);

					cout<<"\nPlayer Mana : ";

					c = GREEN;
					setcolor();

					cout<<p.mana;

					c = WHITE;
					setcolor();

					cout<<" / "<<p.maxM;

					cout<<endl;
					printM(p.mana, p.maxM);

					cout<<"\nPlayer Stress : "; printS(p.stress, p.stress_limit);

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
				p.mana = p.maxM;

				cout<<"\nPlayer Health : ";

				c = GREEN;
				setcolor();

				if(p.HP > 0)
				{
					cout<<p.HP;
				}

				else
				{
					cout<<"0";
				}

				c = WHITE;
				setcolor();

				cout<<" / "<<p.maxHP;

				cout<<endl;
				printH(p.HP, p.maxHP);

				cout<<"\nPlayer Mana : ";

				c = GREEN;
				setcolor();

				cout<<p.mana;

				c = WHITE;
				setcolor();

				cout<<" / "<<p.maxM;

				cout<<endl;
				printM(p.mana, p.maxM);

				cout<<"\nPlayer Stress : "; printS(p.stress, p.stress_limit);
				
				cout<<"\nYou chose to rest"<<endl;
				
				cout<<"\nCurrent position : "<<p.pos<<endl;
				
				cout<<"\nYour stamina increased"<<endl;
				p.stamina = 5;
				
				cout<<"\nYour mana increased to it's max"<<endl;

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

			case 6:
			{
				cout<<"\nPlayer Health : ";

				c = GREEN;
				setcolor();

				if(p.HP > 0)
				{
					cout<<p.HP;
				}

				else
				{
					cout<<"0";
				}

				c = WHITE;
				setcolor();

				cout<<" / "<<p.maxHP;

				cout<<endl;
				printH(p.HP, p.maxHP);

				cout<<"\nPlayer Mana : ";

				c = GREEN;
				setcolor();

				cout<<p.mana;

				c = WHITE;
				setcolor();

				cout<<" / "<<p.maxM;

				cout<<endl;
				printM(p.mana, p.maxM);

				cout<<"\nPlayer Stress : "; printS(p.stress, p.stress_limit);

				if(p.i.torches > 0)
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou make a bonfire, and rest there"<<endl;

					p.level--;
					p.i.torches--;
					
					gamesave(p,input);

					return 5;
				}

				else
				{
					c = RED;
					setcolor();

					cout<<"\nYou don't have any torches left to make a bonfire"<<endl;
				}
			}
			break;

			case 420:
			{
				log_raws(p);
				empty();
			}

			default:
			{
				//Nothing
			}
			break;
		}
		
		system("cls");
		c = WHITE;
		setcolor();
	}

	return dead;
}
