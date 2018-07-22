#pragma once

#include "resources.h"
#include"loot.h"

int random_shop(player&p)
{
	int choice;

	cout<<"\nYou come across a Skeleton Merchant"<<endl;

	cout<<"\nSkeleton Merchant : No need to be afraid. I'm not going to attack you. I infact have some wares you may find useful"<<endl;

	cout<<"\n1. Buy Healing Potions (5) : 1000 Coins "<<endl;
	cout<<"\n2. Buy Ales (5) : 750 Coins"<<endl;
	cout<<"\nInput choice : ";
	cin>>choice;

	switch(choice)
	{
		case 1:
		{
			if(p.i.money >= 1000)
			{
				cout<<"\nYou buy ";

				c = GREEN;
				setcolor();

				cout<<"5 Healing Potions "<<endl;

				c = WHITE;
				setcolor();

				p.i.money -= 1000;
				p.i.hp += 5;
			}

			else
			{
				c = RED;
				setcolor();

				cout<<"\nMoney too low"<<endl;

				c = WHITE;
				setcolor();
			}
		}
		break;

		case 2:
		{
			if(p.i.money >= 750)
			{
				cout<<"\nYou buy ";

				c = GREEN;
				setcolor();

				cout<<"5 Ales"<<endl;

				c = WHITE;
				setcolor();

				p.i.money -= 750;
				p.i.sp += 5;
			}

			else
			{
				c = RED;
				setcolor();

				cout<<"\nMoney too low"<<endl;

				c = WHITE;
				setcolor();
			}
		}
	}
}

int random_event1(player&p,enemy&e)
{
	srand(time(0));
	
	int chance = (rand () % 10);
	int dead = 0,choice,cchance;
	
	switch(chance)
	{
		case 0:
		{
			int trap_fac, trap_guess, diff;

			cout<<"\nYou come across a bear trap, and you must disarm it to move forward"<<endl;
			cout<<"\nGuess a number between 0 and 9 : ";

			trap_fac = (rand () % 10);

			cin>>trap_guess;

			diff = abs(trap_fac, trap_guess);

			if(diff > 2)
			{
				c = RED;
				setcolor();

				t = TRAP;
				textart();

				cout<<"\nYou are unable to disarm the trap. Your hand is jammed into the bear trap"<<endl;
				
				p.HP = p.HP - 200;

				cout<<"\nYour stress increased by 5"<<endl;
				p.stress += 5;
				
				if(p.HP <= 0)
				{
					dead = 1;
					return dead;
				}	
			}

			else
			{
				c = GREEN;
				setcolor();

				t = TRAP;
				textart();

				cout<<"\nYou successfully disarm the trap"<<endl;
			}

			c = WHITE;
			setcolor();
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

					cout<<"Troll";

					c = WHITE;
					setcolor();

					cout<<" rushes toward you"<<endl;

					line();

					e.name = "Troll";
					e.HP = 1250;
					e.maxHP = e.HP;
					e.damage = 100;
					e.cdamage = 200;
					e.cattack = "TROLL TAKEDOWN";
					e.nattack = "RAMPAGE";
					e.type = BEAST;

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
				break;

				case 2:
				{
					cout<<"\nYou ignore the cave and move forth"<<endl;
				}
			}
		}
		break;

		case 2:
		{
			cout<<"\nYou come across a set of bronze armor lying on the floor, with a small opening in the helmet"<<endl;
			cout<<"\nThere is a ruby next to it. What do you do?"<<endl;
			cout<<"\n1. Put Ruby in the opening"<<endl;
			cout<<"\n2. Ignore and move on"<<endl;
			cout<<"\nInput choice : ";
			cin>>choice;

			switch(choice)
			{
				case 1:
				{
					cout<<"\nThe bronze armor suddenly becomes an";

					c = RED;
					setcolor();

					cout<<" Automoton";

					c = WHITE;
					setcolor();

					cout<<", and rushes towards you"<<endl;

					line();

					e.name = "Bronze Automoton";
					e.HP = 1450;
					e.maxHP = e.HP;
					e.damage = 200;
					e.cdamage = 250;
					e.cattack = "AUTOMOTON ASSAULT";
					e.nattack = "BRONZE CLAW";
					e.type = UNHOLY;

					dead = battle(p,e);

					if(dead == 1)
					{
						return dead;
					}

					if(dead == 5)
					{
						cout<<"\nYou flee from the automoton"<<endl;
						return 0;
					}

					cout<<"\nRemoving the backplate of the automoton reveals";

					c = GREEN;
					setcolor();

					cout<<" 5 Ales";

					c = WHITE;
					setcolor();

					cout<<" stashed inside"<<endl;

					p.i.sp += 5;
				}
				break;

				case 2:
				{
					cout<<"\nYou ignore the armor and move onward"<<endl;
				}
				break;
			}
		}
		break;

		default: 
		{
			cout<<"\nYou find a coffin. Investigate?"<<endl;
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
			
			cout<<"\nYou find a strange pool"<<endl;
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

					if(poison_check > 1)
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

		case 4:
		{
			int trap_fac, trap_guess, diff;

			cout<<"\nYou come across a wire trap on the ground. You must disarm it to move onward"<<endl;
			cout<<"\nGuess a number between 0 and 9 : ";

			trap_fac = (rand () % 10);

			cin>>trap_guess;

			diff = abs(trap_fac, trap_guess);

			if(diff > 3)
			{
				c = RED;
				setcolor();

				cout<<"\nYou are unable to disarm the trap. Heavy boulders fall on you from the ceiling of the Caverns"<<endl;
				
				p.HP = p.HP - 400;

				cout<<"\nYour stress increased by 5"<<endl;
				p.stress += 5;
				
				if(p.HP <= 0)
				{
					dead = 1;
					return dead;
				}	
			}

			else
			{
				c = GREEN;
				setcolor();

				cout<<"\nYou successfully disarm the trap"<<endl;
			}

			c = WHITE;
			setcolor();
		}
		break;

		case 5:
		{
			int trap_check;
			
			cout<<"\nYou find a handle sticking out of the wall"<<endl;
			cout<<"\nWhat do you do?"<<endl;

			cout<<"\n1. Pull Handle"<<endl;
			cout<<"\n2. Ignore"<<endl;

			cout<<"\nInput choice : ";
			cin>>choice;

			switch(choice)
			{
				case 1:
				{
					trap_check = (rand () % p.luck);

					if(trap_check > 1)
					{
						c = GREEN;
						setcolor();

						cout<<"\nYou pull the handle, and it turns out to be a weapon"<<endl;

						line();

						loot_weapon(p);
					}

					else
					{
						c = RED;
						setcolor();

						cout<<"\nPulling the handle causes stones from the walls to dislodge, and they fall on you"<<endl;

						p.HP = p.HP - 300;

						cout<<"\nYour stress increased by 5"<<endl;

						p.stress += 5;
						
						if(p.HP <= 0)
						{
							dead = 1;
							return dead;
						}	
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

		case 6:
		{
			random_shop(p);
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
	
	int chance = (rand () % 10);
	int dead = 0,choice,cchance;
	
	switch(chance)
	{
		case 0:
		{
			int trap_fac, trap_guess, diff;

			cout<<"\nYou come across a bear trap, and you must disarm it to move forward"<<endl;
			cout<<"\nGuess a number between 0 and 9 : ";

			trap_fac = (rand () % 10);

			cin>>trap_guess;

			diff = abs(trap_fac, trap_guess);

			if(diff > 2)
			{
				c = RED;
				setcolor();

				t = TRAP;
				textart();

				cout<<"\nYou are unable to disarm the trap. Your hand is jammed into the bear trap"<<endl;
				
				p.HP = p.HP - 200;

				cout<<"\nYour stress increased by 5"<<endl;
				p.stress += 5;
				
				if(p.HP <= 0)
				{
					dead = 1;
					return dead;
				}	
			}

			else
			{
				c = GREEN;
				setcolor();

				t = TRAP;
				textart();

				cout<<"\nYou successfully disarm the trap"<<endl;
			}

			c = WHITE;
			setcolor();
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

		case 1:
		{
			int trap_fac, trap_guess, diff;

			cout<<"\nYou come across a wire trap on the ground. You must disarm it to move onward"<<endl;
			cout<<"\nGuess a number between 0 and 9 : ";

			trap_fac = (rand () % 10);

			cin>>trap_guess;

			diff = abs(trap_fac, trap_guess);

			if(diff > 3)
			{
				c = RED;
				setcolor();

				cout<<"\nYou are unable to disarm the trap. Heavy boulders fall on you from the ceiling of the Caverns"<<endl;
				
				p.HP = p.HP - 400;

				cout<<"\nYour stress increased by 5"<<endl;
				p.stress += 5;
				
				if(p.HP <= 0)
				{
					dead = 1;
					return dead;
				}	
			}

			else
			{
				c = GREEN;
				setcolor();

				cout<<"\nYou successfully disarm the trap"<<endl;
			}

			c = WHITE;
			setcolor();
		}
		break;

		case 2:
		{
			cout<<"\nYou come across a small opening in the wall. Investigate?"<<endl;

			cout<<"\n1. Yes"<<endl;
			cout<<"\n2. No"<<endl;
			cout<<"\nInput choice : ";

			cin>>choice;

			switch(choice)
			{
				case 1:
				{
					cout<<"\nAn ";

					c = RED;
					setcolor();

					cout<<"Armored Rat";

					c = WHITE;
					setcolor();

					cout<<" rushes toward you"<<endl;

					line();

					e.name = "Armored Rat";
					e.HP = 600;
					e.maxHP = e.HP;
					e.damage = 300;
					e.cdamage = 600;
					e.cattack = "RODENT RAMPAGE";
					e.nattack = "FRENZY";
					e.type = BEAST;

					dead = battle(p,e);

					if(dead == 1)
					{
						return dead;
					}

					if(dead == 5)
					{
						cout<<"\nYou flee from the opening"<<endl;
						return 0;
					}

					cout<<"\nYou discover that the Rat was guarding";

					c = GREEN;
					setcolor();

					cout<<" 5 Healing Potions"<<endl;

					c = WHITE;
					setcolor();

					p.i.hp += 5;
				}
				break;

				case 2:
				{
					cout<<"\nYou continue on"<<endl;
				}
				break;
			}
		}
		break;

		case 3:
		{
			int poison_check;
			
			cout<<"\nYou find a strange pool"<<endl;
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

					if(poison_check > 1)
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

		case 4:
		{
			cout<<"\nYou come across the statue of a potato"<<endl;
			cout<<"\nWhat do you do?"<<endl;

			cout<<"\n1. Sacrifice 1000 Gold for blessings"<<endl;
			cout<<"\n2. Ignore and continue"<<endl;
			cout<<"\nInput choice : ";

			cin>>choice;

			switch(choice)
			{
				case 1:
				{
					if(p.i.money >= 1000)
					{
						cout<<"\nYou sacrifice 1000 Gold to the statue"<<endl;
						cout<<"\nYour stress becomes 0, and your health increases to its max"<<endl;

						p.stress = 0;
						p.HP = p.maxHP;
						p.i.money -= 1000;
					}

					else
					{
						cout<<"\nYou do not have enough money to sacrifice"<<endl;
					}
				}
				break;
			}
		}
		break;
	}

	return 0;
}

int random_event(player&p,enemy&e)
{
	switch(p.level)
	{
		case 3:
		{
			random_event1(p,e);
		}
		break;

		case 6:
		{
			random_event2(p,e);
		}
		break;
	}
}

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
	
	cout<<"\nThe first Collosus appeared. It's a Titan"<<endl;

	cout<<"\nSeeing the Titan increases your stress by 7"<<endl;
	p.stress += 7;

	empty();
	
	srand(time(0));
	
	int dead=0;
	
	int drop_chance, check=0, choice, flee_chance, climb_check, no_climbs = 4, shield_effect, choice_ability;
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

			case 5:
			{
				p.playerdoes = 6;

				climb_check = (rand () % p.STA);

				if(climb_check > 15 && no_climbs > 0)
				{
					p.playerchance = "SUCCESSFUL";

					p.damage += 25;
					no_climbs--;
				}

				else
				{
					p.playerchance = "UNSUCCESSFUL";

					p.HP -= 200;
				}
			}
		}

		//Enemy move
		enemy_attack(p,e,check,shield_effect);

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
		cout<<"\n5. Stun The Hydra (Takes 1 Torch)"<<endl;
			
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

			case 5:
			{
				p.playerdoes = 7;

				if(p.i.torches >= 0)
				{
					playerchance = "SUCCESSFUL";

					p.i.torches--;

					e.stunned += 5;
				}

				else
				{
					playerchance = "UNSUCCESSFUL";
				}
			}
			break;
		}

		//Enemy move
		enemy_attack(p,e,check,shield_effect);

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