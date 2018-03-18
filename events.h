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
					e.damage = 50;
					e.cdamage = 100;

					dead = battle1(p,e);

					if(dead == 1)
					{
						return dead;
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
							enemyclass1(e);
							
							cout<<"\nA ";

							c = RED;
							setcolor();

							cout<<e.name;
							cout<<" jumped out at you."<<endl;
							
							dead = battle1(p,e);
							
							if(p.HP <= 0)
							{
								dead = 1;
								return dead;
							}
						}
						break;
						
						case 1:
						{
							c = GREEN;
							setcolor();

							cout<<"\nYou found a weapon"<<endl;
							
							loot_weapon1(p);
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
	
	return 0;
	empty();
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
							c = GREEN;
							setcolor();
							
							cout<<"\nYou found a weapon"<<endl;
							
							loot_weapon2(p);
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

int battle_collosus1(player&p,enemy&e)
{
	e.HP = 1000;
	e.damage = 200;
	e.cdamage = 500;
	e.dodge = 5;
	
	cout<<"\nThe first Collosus appeared. It's a Titan"<<endl;
	
	srand(time(0));
	
	int dead=0;
	 
	int damage = p.damage + p.w.damage;
	int dodge = (10 - p.a.weight) + p.dodge + e.dodge;
	int chance = (25 - p.w.weight) + p.wh, choice,c;
	int enemy_landchance,drop_chance,echoice,spellcheck=0,armor_chance, t_damage, t_dodge;

	p.ability_point = true;

	ability_setup(p, t_damage, t_dodge);
	
	while(e.HP)
	{
		//Player choice
		cout<<"\nWhat do you choose?"<<endl;
		cout<<"\n1. Attack enemy"<<endl;
		cout<<"\n2. Use Magic"<<endl;
		cout<<"\n3. Use Healing Potion"<<endl;
		cout<<"\n4. Use Ability"<<endl;
			
		cout<<"\nInput choice : ";
		cin>>choice;
		
		spellcheck = 0;
		
		switch(choice)
		{
			case 1:
			{
				attack(p,e);
			}
			break;
				
			case 2: 
			{
				spellcheck = spell1(p);
			}
			break;
				
			case 3:
			{
				heal(p);
			}
			break;

			case 4:
			{
				ability(p,e);
			}
			break;
		}
			
		//Enemy move
		enemy_attack(p,e,spellcheck);
			
		if(p.HP<=0)
		{
			c = RED;
			setcolor();

			cout<<"\nYou died"<<endl;
			dead=1;
			return dead;
		}
			
		if(e.HP<=0)
		{
			c = GREEN;
			setcolor();

			cout<<"\nThe Titan died"<<endl;
			empty();
			
			dead=0;
			break;
		}
			
		cout<<"\nPlayer Health : "<<p.HP<<endl;
		cout<<"\nEnemy Health : "<<e.HP<<endl;
			
		cout<<"\nPlayer Mana : "<<p.mana<<endl;
	
		line();
	}

	ability_reverse(p,t_damage,t_dodge);
	
	system("cls");
	
	cout<<"\nThe Titan dropped a weapon"<<endl;
	
	switch(p.wtype)
	{
		case 1:
		{
			c = GREEN;
			setcolor();

			cout<<"\nIt dropped a Bronze Halberd"<<endl;

			c = WHITE;
			setcolor();

			cout<<"\nDamage : 150"<<endl;
			cout<<"\nWeight : 27"<<endl;
			cout<<"\nCurrent Weapon Damage : "<<p.w.damage<<endl;
			cout<<"\nCurrent Weapon Weight : "<<p.w.weight<<endl;
					
			cout<<"\nEquip?"<<endl;
			cout<<"\n1. Yes"<<endl;
			cout<<"\n2. No"<<endl;
					
			cout<<"\nInput choice : ";
			cin>>choice;

			system("cls");
					
			switch(choice)
			{
				case 1:
				{
					cout<<"\nYou picked up the weapon"<<endl;
					p.w.name= "Broze Halberd";
					p.w.damage = 150;
					p.w.weight = 27;
							
					if(p.i.weapons < 5)
					{
						cout<<"\nYou store your current weapon to sell"<<endl;
						p.i.weapons++;
					}
							
					else
					{
						cout<<"\nYour inventory is full. You dropped your current weapon"<<endl;
					}
				}
				break;
						
				case 2:
				{
					if(p.i.weapons < 5)
					{
						cout<<"\nYou picked up the weapon to sell"<<endl;
						p.i.weapons++;
					}
							
					else
					{
						cout<<"\nYour inventory is full. You left weapon"<<endl;
					}
				}
				break;
			}
		}
		break;
		
		case 2:
		{
			c = GREEN;
			setcolor();

			cout<<"\nIt dropped a Bronze War Axe"<<endl;

			c = WHITE;
			setcolor();
			
			cout<<"\nDamage : 80"<<endl;
			cout<<"\nWeight : 14"<<endl;
			cout<<"\nCurrent Weapon Damage : "<<p.w.damage<<endl;
			cout<<"\nCurrent Weapon Weight : "<<p.w.weight<<endl;
					
			cout<<"\nEquip?"<<endl;
			cout<<"\n1. Yes"<<endl;
			cout<<"\n2. No"<<endl;
					
			cout<<"\nInput choice : ";
			cin>>choice;

			system("cls");
					
			switch(choice)
			{
				case 1:
				{
					cout<<"\nYou picked up the weapon"<<endl;
					p.w.name= "Broze War Axe";
					p.w.damage = 80;
					p.w.weight = 14;
							
					if(p.i.weapons < 5)
					{
						cout<<"\nYou store your current weapon to sell"<<endl;
						p.i.weapons++;
					}
							
					else
					{
						cout<<"\nYour inventory is full. You dropped your current weapon"<<endl;
					}
				}
				break;
						
				case 2:
				{
					if(p.i.weapons < 5)
					{
						cout<<"\nYou picked up the weapon to sell"<<endl;
						p.i.weapons++;
					}
							
					else
					{
						cout<<"\nYour inventory is full. You left weapon"<<endl;
					}
				}
				break;
			}
		}
		break;
		
		case 3:
		{
			c = GREEN;
			setcolor();

			cout<<"\nIt dropped a Bronze Sabre"<<endl;

			c = WHITE;
			setcolor();
			
			cout<<"\nDamage : 30"<<endl;
			cout<<"\nWeight : 8"<<endl;
			cout<<"\nCurrent Weapon Damage : "<<p.w.damage<<endl;
			cout<<"\nCurrent Weapon Weight : "<<p.w.weight<<endl;
					
			cout<<"\nEquip?"<<endl;
			cout<<"\n1. Yes"<<endl;
			cout<<"\n2. No"<<endl;
					
			cout<<"\nInput choice : ";
			cin>>choice;

			system("cls");
					
			switch(choice)
			{
				case 1:
				{
					cout<<"\nYou picked up the weapon"<<endl;
					p.w.name= "Broze Sabre";
					p.w.damage = 30;
					p.w.weight = 8;
							
					if(p.i.weapons < 5)
					{
						cout<<"\nYou store your current weapon to sell"<<endl;
						p.i.weapons++;
					}
							
					else
					{
						cout<<"\nYour inventory is full. You dropped your current weapon"<<endl;
					}
				}
				break;
						
				case 2:
				{
					if(p.i.weapons < 5)
					{
						cout<<"\nYou picked up the weapon to sell"<<endl;
						p.i.weapons++;
					}
							
					else
					{
						cout<<"\nYour inventory is full. You left weapon"<<endl;
					}
				}
				break;
			}	
		}
		break;
	}
	
	cout<<"\nYou gained XP"<<endl;
	
	p.xp +=500;
	
	cout<<"\nXP : "<<p.xp<<endl;
	
	cout<<"\nThe Titan dropped money"<<endl;
	
	p.i.money += 250;
	
	cout<<"\nMoney : "<<p.i.money<<endl;
	
	line();
	
	return dead;
}

int battle_collosus2(player&p,enemy&e)
{
	e.HP = 1250;
	e.damage = 150;
	e.cdamage = 600;
	e.dodge = 2;
	
	cout<<"\nThe second Collosus appeared. It's a Hydra"<<endl;
	
	srand(time(0));
	
	int dead=0;
	 
	int damage = p.damage + p.w.damage;
	int dodge = (10 - p.a.weight) + p.dodge + e.dodge;
	int chance = (25 - p.w.weight) + p.wh, choice,c;
	int enemy_landchance,drop_chance,echoice,spellcheck=0,armor_chance,t_damage,t_dodge;
	int poison = 50;

	p.ability_point = true;

	ability_setup(p, t_damage, t_dodge);
	
	while(e.HP)
	{
		//Player choice
		cout<<"\nWhat do you choose?"<<endl;
		cout<<"\n1. Attack enemy"<<endl;
		cout<<"\n2. Use Magic"<<endl;
		cout<<"\n3. Use Healing Potion"<<endl;
		cout<<"\n4. Use Ability"<<endl;
			
		cout<<"\nInput choice : ";
		cin>>choice;
		
		spellcheck = 0;
		
		switch(choice)
		{
			case 1:
			{
				attack(p,e);
			}
			break;
				
			case 2: 
			{
				spellcheck = spell1(p);
			}
			break;
				
			case 3:
			{
				heal(p);
			}
			break;

			case 4:
			{
				ability(p,e);
			}
			break;
		}
			
		//Enemy move
		enemy_attack(p,e,spellcheck);
			
		cout<<"\nThe Hydra's poison depletes your HP"<<endl;
		p.HP = p.HP - poison;
		
		if(p.HP<=0)
		{
			cout<<"\nYou died"<<endl;
			dead=1;
			return dead;
		}
			
		if(e.HP<=0)
		{
			cout<<"\nEnemy died"<<endl;
			empty();
			
			dead=0;
			break;
		}
			
		cout<<"\nPlayer Health : "<<p.HP<<endl;
		cout<<"\nEnemy Health : "<<e.HP<<endl;
			
		cout<<"\nPlayer Mana : "<<p.mana<<endl;
	
		line();
	}

	ability_reverse(p,t_damage,t_dodge);
	
	system("cls");
	
	cout<<"\nThe Hydra dropped a weapon"<<endl;
	
	switch(p.wtype)
	{
		case 1:
		{
			c = GREEN;
			setcolor();

			cout<<"\nIt dropped a Steel Great Axe"<<endl;

			c = WHITE;
			setcolor();
			
			cout<<"\nDamage : 325"<<endl;
			cout<<"\nWeight : 27"<<endl;
			cout<<"\nCurrent Weapon Damage : "<<p.w.damage<<endl;
			cout<<"\nCurrent Weapon Weight : "<<p.w.weight<<endl;
					
			cout<<"\nEquip?"<<endl;
			cout<<"\n1. Yes"<<endl;
			cout<<"\n2. No"<<endl;
					
			cout<<"\nInput choice : ";
			cin>>choice;

			system("cls");
					
			switch(choice)
			{
				case 1:
				{
					cout<<"\nYou picked up the weapon"<<endl;
					p.w.name= "Steel Great Axe";
					p.w.damage = 325;
					p.w.weight = 27;
							
					if(p.i.weapons < 5)
					{
						cout<<"\nYou store your current weapon to sell"<<endl;
						p.i.weapons++;
					}
							
					else
					{
						cout<<"\nYour inventory is full. You dropped your current weapon"<<endl;
					}
				}
				break;
						
				case 2:
				{
					if(p.i.weapons < 5)
					{
						cout<<"\nYou picked up the weapon to sell"<<endl;
						p.i.weapons++;
					}
							
					else
					{
						cout<<"\nYour inventory is full. You left weapon"<<endl;
					}
				}
				break;
			}
		}
		break;
		
		case 2:
		{
			c = GREEN;
			setcolor();

			cout<<"\nIt dropped a Steel Cutlass"<<endl;

			c = WHITE;
			setcolor();
			
			cout<<"\nDamage : 160"<<endl;
			cout<<"\nWeight : 12"<<endl;
			cout<<"\nCurrent Weapon Damage : "<<p.w.damage<<endl;
			cout<<"\nCurrent Weapon Weight : "<<p.w.weight<<endl;
					
			cout<<"\nEquip?"<<endl;
			cout<<"\n1. Yes"<<endl;
			cout<<"\n2. No"<<endl;
					
			cout<<"\nInput choice : ";
			cin>>choice;

			system("cls");
					
			switch(choice)
			{
				case 1:
				{
					cout<<"\nYou picked up the weapon"<<endl;
					p.w.name= "Steel Cutlass";
					p.w.damage = 160;
					p.w.weight = 12;
							
					if(p.i.weapons < 5)
					{
						cout<<"\nYou store your current weapon to sell"<<endl;
						p.i.weapons++;
					}
							
					else
					{
						cout<<"\nYour inventory is full. You dropped your current weapon"<<endl;
					}
				}
				break;
						
				case 2:
				{
					if(p.i.weapons < 5)
					{
						cout<<"\nYou picked up the weapon to sell"<<endl;
						p.i.weapons++;
					}
							
					else
					{
						cout<<"\nYour inventory is full. You left weapon"<<endl;
					}
				}
				break;
			}
		}
		break;
		
		case 3:
		{
			c = GREEN;
			setcolor();

			cout<<"\nIt dropped an Steel Maine-Gauche"<<endl;

			c = WHITE;
			setcolor();
			
			cout<<"\nDamage : 70"<<endl;
			cout<<"\nWeight : 7"<<endl;
			cout<<"\nCurrent Weapon Damage : "<<p.w.damage<<endl;
			cout<<"\nCurrent Weapon Weight : "<<p.w.weight<<endl;
					
			cout<<"\nEquip?"<<endl;
			cout<<"\n1. Yes"<<endl;
			cout<<"\n2. No"<<endl;
					
			cout<<"\nInput choice : ";
			cin>>choice;

			system("cls");
					
			switch(choice)
			{
				case 1:
				{
					cout<<"\nYou picked up the weapon"<<endl;
					p.w.name= "Steel Maine-Gauche";
					p.w.damage = 70;
					p.w.weight = 7;
							
					if(p.i.weapons < 5)
					{
						cout<<"\nYou store your current weapon to sell"<<endl;
						p.i.weapons++;
					}
							
					else
					{
						cout<<"\nYour inventory is full. You dropped your current weapon"<<endl;
					}
				}
				break;
						
				case 2:
				{
					if(p.i.weapons < 5)
					{
						cout<<"\nYou picked up the weapon to sell"<<endl;
						p.i.weapons++;
					}
							
					else
					{
						cout<<"\nYour inventory is full. You left weapon"<<endl;
					}
				}
				break;
			}	
		}
		break;
	}
	
	cout<<"\nYou gained XP"<<endl;
	
	p.xp +=500;
	
	cout<<"\nXP : "<<p.xp<<endl;
	
	cout<<"\nThe enemy dropped money"<<endl;
	
	p.i.money += 250;
	
	cout<<"\nMoney : "<<p.i.money<<endl;
	
	line();
	
	return dead;
}
