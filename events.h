#pragma once

#include "resources.h"
#include"loot.h"

int random_event1(player&p,enemy&e)
{
	srand(time(0));
	
	int chance = (rand () % p.luck);
	int dead = 0,choice,cchance;
	
	switch(chance)
	{
		case 0:
		{
			c = RED;
			setcolor();

			cout<<"\nYou walked into a bear trap, decreasing your HP by 200"<<endl;
			
			p.HP = p.HP - 200;

			cout<<"\nYour stress increased by 5"<<endl;
			p.stress += 5;

			c = WHITE;
			setcolor();
			
			if(p.HP <= 0)
			{
				dead = 1;
				return dead;
			}
		}
		break;
		
		case 1:
		{
			cout<<"\nYou come across a troll cave. Investigate?"<<endl;
			cout<<"\n1. Yes"<<endl;
			cout<<"\n2. No"<<endl;
			cout<<"\nInput choice : ";
			cin>>choice;

			switch(choice)
			{
				case 1:
				{
					cout<<"\nA ";

					c = RED;
					setcolor();

					cout<<"troll";

					c = WHITE;
					setcolor();

					cout<<" rushes toward you"<<endl;

					line();

					e.name = "Troll";
					e.HP = 500;
					e.maxHP = e.HP;
					e.damage = 50;
					e.cdamage = 100;

					dead = battle(p,e);

					if(dead == 1)
					{
						return dead;
					}

					if(dead == 5)
					{
						cout<<"\nYou flee from the troll cave"<<endl;
						return 0;
					}

					cout<<"\nYou spot a chest guarded by the troll. On opening it you find";

					c = GREEN;
					setcolor();

					cout<<" 500 coins"<<endl;

					c = WHITE;
					setcolor();

					p.i.money += 500;
				}
			}
		}
		break;

		default: 
		{
			cout<<"\nYou found a coffin. Investigate?"<<endl;
			cout<<"\n1. Yes"<<endl;
			cout<<"\n2. No"<<endl;
			cout<<"\nInput choice : ";
			cin>>choice;
			
			system("cls");
			
			switch(choice)
			{
				case 1:
				{
					cchance = (rand () % 3);
					
					switch(cchance)
					{
						case 0:
						{
							enemyclass(p,e);
							
							cout<<"\nA ";

							c = RED;
							setcolor();

							cout<<e.name;

							c = WHITE;
							setcolor();

							cout<<" jumped out at you."<<endl;
							
							dead = battle(p,e);
							
							if(p.HP <= 0)
							{
								dead = 1;
								return dead;
							}
						}
						break;
						
						case 1:
						{
							loot_weapon(p);
						}
						break;

						case 2:
						{
							c = GREEN;
							setcolor();

							cout<<"\nYou found 100 coins"<<endl;
							p.i.money += 100;
						}
						break;
					}
				}
			}
		}
		break;
	}

	empty();

	return 0;
}

int random_event2(player&p,enemy&e)
{
	srand(time(0));
	
	int chance = (rand () % p.luck);
	int dead = 0,choice,cchance;
	
	switch(chance)
	{
		case 0:
		{
			c = RED;
			setcolor();

			cout<<"\nYou walked over a poisonous crab, decreasing your HP by 400"<<endl;
			
			p.HP = p.HP - 400;

			cout<<"\nYour stress increased by 7"<<endl;
			p.stress += 7;

			c = WHITE;
			setcolor();
			
			if(p.HP <= 0)
			{
				dead = 1;
				return dead;
			}
		}
		break;
		
		default: 
		{
			cout<<"\nYou found a pot. Investigate?"<<endl;
			cout<<"\n1. Yes"<<endl;
			cout<<"\n2. No"<<endl;
			cout<<"\nInput choice : ";
			cin>>choice;
			
			system("cls");
			
			switch(choice)
			{
				case 1:
				{
					cchance = (rand () % 2);
					
					switch(cchance)
					{
						case 0:
						{
							c = GREEN;
							setcolor();

							cout<<"\nYou found 50 coins"<<endl;
						}
						break;
						
						default:
						{
							
							loot_weapon(p);
						}
						break;
					}
				}
			}

			c = WHITE;
			setcolor();
		}
		break;
	}

	return 0;
}

int random_event(player&p,enemy&e)
{
	switch(p.level)
	{
		case 2:
		{
			random_event1(p,e);
		}
		break;

		case 3:
		{
			random_event2(p,e);
		}
		break;
	}
}

int battle_collosus1(player&p,enemy&e)
{
	e.HP = 1000;
	e.maxHP = e.HP;
	e.damage = 200;
	e.cdamage = 500;
	e.dodge = 5;
	
	cout<<"\nThe first Collosus appeared. It's a Titan"<<endl;
	
	srand(time(0));
	
	int dead=0;
	 
	dead = battle(p,e);

	if(dead == 1)
	{
		return 1;
	}
}

int battle_collosus2(player&p,enemy&e)
{
	e.HP = 1250;
	e.maxHP = e.HP;
	e.damage = 150;
	e.cdamage = 600;
	e.dodge = 2;
	
	cout<<"\nThe second Collosus appeared. It's a Hydra"<<endl;
	
	srand(time(0));
	
	int dead=0;
	 
	dead = battle(p,e);

	if(dead == 1)
	{
		return 1;
	}
}