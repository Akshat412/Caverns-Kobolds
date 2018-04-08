#pragma once

#include "resources.h"
#include"loot.h"

int random_event1(player&p,enemy&e)
{
	srand(time(0));
	
	int chance = (rand () % 10);
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

							line();
							
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

		case 3:
		{
			int poison_check;
			cout<<"\nYou found a strange pool"<<endl;
			cout<<"\nWhat do you do?"<<endl;

			cout<<"\n1. Drink from the pool"<<endl;
			cout<<"\n2. Ignore"<<endl;

			cout<<"\nInput choice : ";
			cin>>choice;

			switch(choice)
			{
				case 1:
				{
					poison_check = (rand () % p.luck);

					if(poison_check > 3)
					{
						c = GREEN;
						setcolor();

						cout<<"\nThe pool heals your HP to its max"<<endl;

						p.HP = p.maxHP;
					}

					else
					{
						c = RED;
						setcolor();

						cout<<"\nThe pool was poisonous; drinking it has damaged you by 10 percent of your HP"<<endl;

						p.HP -= p.HP/10;
					}
				}
				break;

				default:
				{
					cout<<"\nYou continue on"<<endl;
				}
				break;
			}
		}
		break;
	}

	c = WHITE;
	setcolor();

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

	cout<<"\nSeeing the Titan increases your stress by 7"<<endl;
	p.stress += 7;

	empty();
	
	srand(time(0));
	
	int dead=0;
	
	int drop_chance, check=0, choice, flee_chance, playerdoes, climb_check, no_climbs = 4;
	player temp_ability, temp_panic;
	int temp_damage;

	ability_setup(p,temp_ability);
	panicattack_setup(p,temp_panic);

	c = RED;
	setcolor();

	t = BATTLE;
	textart();

	c = WHITE;
	setcolor();

	string playerdone, playerchance, enemydoes;
	
	while(e.HP)
	{
		display_battlestats(p,e);

		//Player choice
		cout<<"\nWhat do you choose?"<<endl;
		cout<<"\n1. Attack enemy"<<endl;
		cout<<"\n2. Use Magic"<<endl;
		cout<<"\n3. Use Healing Potion"<<endl;
		cout<<"\n4. Use Ability "<<endl;
		cout<<"\n5. Climb up the Titan"<<endl;
			
		cout<<"\nInput choice : ";
		cin>>choice;

		playerdoes = choice;
		
		check = 0;
		
		switch(choice)
		{
			case 1:
			{
				attack(p,e,playerdone,playerchance);
			}
			break;
				
			case 2: 
			{
				check = spell1(p,playerdone,playerchance);
			}
			break;
				
			case 3:
			{
				heal(p);
			}
			break;

			case 4:
			{
				ability(p,playerdone,playerchance);
			}
			break;

			case 5:
			{
				playerdoes = 6;

				climb_check = (rand () % p.STA);

				if(climb_check > 15 && no_climbs > 0)
				{
					playerchance = "SUCCESSFUL";

					p.damage += 25;
					no_climbs--;
				}

				else
				{
					playerchance = "UNSUCCESSFUL";

					p.HP -= 50;
				}
			}
		}

		//Enemy move
		enemy_attack(p,e,check,enemydoes);

		system("cls");

		display_battlestats(p,e);

		output_battle(p,playerdone, playerchance, enemydoes, playerdoes);
			
		if(p.HP<=0)
		{
			c = RED;
			setcolor();

			cout<<"\nYou died"<<endl;
			dead = 1;
			return dead;
		}
			
		if(e.HP<=0)
		{
			c = GREEN;
			setcolor();

			cout<<"\nEnemy died"<<endl;
			line();
			
			dead=0;
			break;
		}

		panicattack(p);

		line();
	}

	ability_reverse(p,temp_ability);
	panicattack_reverse(p, temp_panic);

	c = WHITE;
	setcolor();

	return 0;
}

int battle_collosus2(player&p,enemy&e)
{
	e.HP = 1250;
	e.maxHP = e.HP;
	e.damage = 150;
	e.cdamage = 600;
	e.dodge = 2;
	
	cout<<"\nThe second Collosus appeared. It's a Hydra"<<endl;

	empty();
	
	srand(time(0));
	
	int dead=0;
	 
	dead = battle(p,e);

	if(dead == 1)
	{
		return 1;
	}
}