#pragma once

#include "resources.h"
#include"loot.h"

int battle_collosus1(player&p,enemy&e)
{
	e.name = "Titan";
	e.HP = 2000;
	e.maxHP = e.HP;
	e.damage = 200;
	e.cdamage = 500;
	e.dodge = 5;
	e.cattack = "COLLOSAL CRUSH";
	e.nattack = "BRUTAL REND";
	e.type = UNHOLY;
	e.boss = true;
	
	cout<<"\nThe first Collosus appeared. It's a Titan"<<endl;

	cout<<"\nSeeing the Titan increases your stress by 7"<<endl;
	p.stress += 7;

	empty();
	
	srand(time(0));
	
	int dead=0;
	
	int drop_chance, check = 0, choice, flee_chance, climb_check, shield_effect, choice_ability, turn = 0;
	player temp_ability, temp_panic, temp_damage;

	bool climbed = false;

	ability_setup(p,temp_ability);
	panicattack_setup(p,temp_panic);

	c = RED;
	setcolor();

	t = BATTLE;
	textart();

	c = WHITE;
	setcolor();
	
	while(e.HP)
	{
		turn++;

		display_battlestats(p,e);

		int temp = turn % 5;
		cout << endl;
		cout << "Titan Rage : "; printRAGE(temp, 5);

		//Player choice
		cout<<"\nWhat do you choose?"<<endl;
		cout<<"\n1. Attack enemy"<<endl;
		cout<<"\n2. Use Magic"<<endl;
		cout<<"\n3. Use Healing Potion"<<endl;
		cout<<"\n4. Use Ability "<<endl;

		if(!climbed) cout<<"\n5. Climb up the Titan"<<endl;
		else cout<<"\n5. Climb down the Titan"<<endl;
			
		cout<<"\nInput choice : ";
		cin>>choice;

		p.playerdoes = choice;
		
		check = 0;

		int temp_health = e.HP;
		
		switch(choice)
		{
			case 1:
			{
				attack(p,e);
			}
			break;
				
			case 2: 
			{
				check = spell1(p,e);
			}
			break;
				
			case 3:
			{
				heal(p);
			}
			break;

			case 4:
			{
				cout<<"\nWhich ability do you use?"<<endl;
				cout<<"\n1. Racial Ability"<<endl;
				cout<<"\n2. Weapon Ability"<<endl;
				cout<<"\nInput choice : ";
				cin>>choice_ability;

				switch(choice_ability)
				{
					case 1:
					{
						ability(p);
					}
					break;

					case 2:
					{
						weapon_ability(p,e);
					}
					break;

					default : //Nothing
					break;
				}
			}
			break;

			case 5:
			{
				climb_check = (rand () % p.STA);

				if(climbed)
				{
					p.playerdoes = 7;
					climbed = false;
					p.damage -= 50;
				}

				else if(climb_check > 15)
				{
					p.playerdoes = 6;
					p.playerchance = "SUCCESSFUL";
					p.damage += 50;
					climbed = true;
				}

				else
				{
					p.playerdoes = 6;
					p.playerchance = "UNSUCCESSFUL";
					p.HP -= 500;
				}
			}
		}

		int random = (rand () % 10);

		if(turn % 5 == 0 && (e.stunned <= 0 && e.bleeding <= 0 && e.poisoned <= 0))
		{
			e.enemydoes = "bm11";

			p.HP -= e.cdamage * 5;

			p.damage_taken = e.cdamage * 5;
		} 

		else if(e.HP < e.HP/2 && random == 0)
		{
			e.enemydoes = "bm12";

			e.HP = temp_health;
		}

		else enemy_attack(p, e, shield_effect);

		system("cls");

		display_battlestats(p,e);
		output_battle(p, e, check, shield_effect);
		panicattack(p);
			
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

		line();
	}

	ability_reverse(p,temp_ability);
	panicattack_reverse(p, temp_panic);

	c = WHITE;
	setcolor();

	e.stunned = 0;
	e.bleeding = 0;
	e.poisoned = 0;

	return 0;
}

int battle_collosus2(player&p,enemy&e)
{
	e.name = "Hydra";
	e.HP = 2500;
	e.maxHP = e.HP;
	e.damage = 400;
	e.cdamage = 1000;
	e.dodge = 5;
	e.cattack = "SERPENT STRIKE";
	e.nattack = "SNAKE BITE";
	e.type = BEAST;
	e.boss = true;
	
	cout<<"\nThe second Collosus appeared. It's a Hydra"<<endl;

	cout<<"\nSeeing the Titan increases your stress by 10"<<endl;
	p.stress += 10;

	empty();
	
	srand(time(0));
	
	int dead=0;
	
	int drop_chance, check=0, choice, flee_chance, playerdoes, climb_check, no_climbs = 4, shield_effect, choice_ability;
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
	int enemychance;
	
	while(e.HP)
	{
		display_battlestats(p,e);

		//Player choice
		cout<<"\nWhat do you choose?"<<endl;
		cout<<"\n1. Attack enemy"<<endl;
		cout<<"\n2. Use Magic"<<endl;
		cout<<"\n3. Use Healing Potion"<<endl;
		cout<<"\n4. Use Ability "<<endl;
			
		cout<<"\nInput choice : ";
		cin>>choice;

		p.playerdoes = choice;
		
		check = 0;
		
		switch(choice)
		{
			case 1:
			{
				attack(p,e);
			}
			break;
				
			case 2: 
			{
				check = spell1(p,e);
			}
			break;
				
			case 3:
			{
				heal(p);
			}
			break;

			case 4:
			{
				cout<<"\nWhich ability do you use?"<<endl;
				cout<<"\n1. Racial Ability"<<endl;
				cout<<"\n2. Weapon Ability"<<endl;
				cout<<"\nInput choice : ";
				cin>>choice_ability;

				switch(choice_ability)
				{
					case 1:
					{
						ability(p);
					}
					break;

					case 2:
					{
						weapon_ability(p,e);
					}
					break;

					default : //Nothing
					break;
				}
			}
			break;
		}

		//Enemy move
		enemy_attack(p, e, shield_effect);

		system("cls");

		display_battlestats(p,e);

		output_battle(p, e, check, shield_effect);

		panicattack(p);
			
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

		line();
	}

	ability_reverse(p,temp_ability);
	panicattack_reverse(p, temp_panic);

	c = WHITE;
	setcolor();

	e.stunned = 0;
	e.bleeding = 0;
	e.poisoned = 0;

	return 0;
}