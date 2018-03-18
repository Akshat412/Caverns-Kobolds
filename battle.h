#pragma once

#include"resources.h"
#include"loot.h"

using namespace std;

int attack(player&p,enemy&e)
{
	int choice, landchance, chance, temp, damage_dealt;
	temp = e.HP;
	
	cout<<"\nWhat would you like to do?"<<endl;
	
	switch(p.wtype)
	{
		case 1:
		{
			cout<<"\n1. Critical Attack ";

			c = GREEN;
			setcolor();

			cout<<"(10x Damage)"<<endl;

			c = WHITE;
			setcolor();

			cout<<"\n2. Heavy Attack ";

			c = GREEN;
			setcolor();

			cout<<"(2x Damage)"<<endl;

			c = WHITE;
			setcolor();

			cout<<"\n3. Normal Attack"<<endl;
			
			cout<<"\nInput Choice : ";
			cin>>choice;

			system("cls");
			
			switch(choice)
			{
				case 1:
				{
					cout<<"\nYou used a critical attack"<<endl;
					
					chance = p.w.weight/2 - p.wh + e.sdodge;
					
					landchance = (rand () % chance);
					
					switch(landchance)
					{
						case 0:
						{
							c = GREEN;
							setcolor();

							cout<<"\nYour attack landed"<<endl;
							
							e.HP = e.HP - 10 * (p.w.damage + p.damage);
						}
						break;
						
						default:
						{
							c = RED;
							setcolor();

							cout<<"\nYour attack missed"<<endl;
						}
						break;
					}
				}
				break;
				
				case 2:
				{
					cout<<"\nYou used a heavy attack"<<endl;
					
					chance = p.w.weight/5 + e.sdodge - p.wh;
					
					landchance = (rand () % chance);
					
					switch(landchance)
					{
						case 0:
						{
							c = GREEN;
							setcolor();

							cout<<"\nYour attack landed"<<endl;
							
							e.HP = e.HP - 2 * (p.w.damage + p.damage);
						}
						break;
						
						default:
						{
							c = RED;
							setcolor();

							cout<<"\nYour attack missed"<<endl;
						}
						break;
					}	
				}
				break;
				
				case 3:
				{
					cout<<"\nYou used a normal attack"<<endl;
					
					chance = (30 - (p.w.weight + e.sdodge)) + p.wh;
					
					landchance = (rand () % chance);
					
					switch(landchance)
					{
						default:
						{
							c = GREEN;
							setcolor();

							cout<<"\nYour attack landed"<<endl;
							
							e.HP = e.HP - (p.w.damage + p.damage);
						}
						break;
						
						case 0:
						{
							c = RED;
							setcolor();

							cout<<"\nYour attack missed"<<endl;
						}
						break;
					}	
				}
				break;
			}
		}
		break;
		
		case 2:
		{
			cout<<"\n1. Heavy Attack ";

			c = GREEN;
			setcolor();

			cout<<"(2x Damage)"<<endl;

			c = WHITE;
			setcolor();

			cout<<"\n2. Normal Attack"<<endl;
			cout<<"\n3. Dash Attack ";

			c = GREEN;
			setcolor();

			cout<<"(1/5x Damage, Confirmed Landing)"<<endl;

			c = WHITE;
			setcolor();
			
			cout<<"\nInput Choice : ";
			cin>>choice;

			system("cls");
			
			switch(choice)
			{
				case 1:
				{
					cout<<"\nYou used a heavy attack"<<endl;
					
					chance = p.w.weight/2 - p.wh/10 + e.sdodge;
					
					landchance = (rand () % chance);
					
					switch(landchance)
					{
						case 0:
						{
							c = GREEN;
							setcolor();

							cout<<"\nYour attack landed"<<endl;
							
							e.HP = e.HP - 2 * (p.w.damage + p.damage);
						}
						break;
						
						default:
						{
							c = RED;
							setcolor();

							cout<<"\nYour attack missed"<<endl;
						}
						break;
					}		
				}
				break;
				
				case 2:
				{
					cout<<"\nYou used a normal attack"<<endl;
					
					chance = (30 - p.w.weight) + p.wh - e.sdodge;
					
					landchance = (rand () % chance);
					
					switch(landchance)
					{
						default:
						{
							c = GREEN;
							setcolor();

							cout<<"\nYour attack landed"<<endl;
							
							e.HP = e.HP - (p.w.damage + p.damage);
						}
						break;
						
						case 0:
						{
							c = RED;
							setcolor();

							cout<<"\nYour attack missed"<<endl;
						}
						break;
					}		
				}
				break;
				
				case 3:
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou used a dash attack"<<endl;
					
					e.HP = e.HP - (p.w.damage + p.damage)/5;	
				}
				break;
			}
		}
		break;
		
		case 3:
		{
			cout<<"\n1. Normal Attack"<<endl;
			cout<<"\n2. Dash Attack ";

			c = GREEN;
			setcolor();

			cout<<"(1/5x Damage, Confirmed Landing)"<<endl;

			c = WHITE;
			setcolor();
			
			cout<<"\nInput Choice : ";
			cin>>choice;

			system("cls");
			
			switch(choice)
			{
				case 1:
				{
					cout<<"\nYou used a normal attack"<<endl;
					
					chance = (30 - (p.w.weight + e.sdodge)) + p.wh;
					
					landchance = (rand () % chance);
					
					switch(landchance)
					{
						default:
						{
							c = GREEN;
							setcolor();

							cout<<"\nYour attack landed"<<endl;
							
							e.HP = e.HP - (p.w.damage + p.damage);
						}
						break;
						
						case 0:
						{
							c = RED;
							setcolor();

							cout<<"\nYour attack missed"<<endl;
						}
						break;
					}		
				}
				break;
				
				case 2:
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou used a dash attack"<<endl;
					
					e.HP = e.HP - (p.w.damage + p.damage)/5;	
				}
				break;
			}
		}
		break;
		
		case 4:
		{
			system("cls");
			
			cout<<"\nYou used a normal attack"<<endl;
			
			chance = (25 - (p.w.weight + e.sdodge)) + p.wh;
					
			landchance = (rand () % chance);
					
			switch(landchance)
			{
				default:
				{
					c = GREEN;
					setcolor();

					cout<<"\nYour attack landed"<<endl;
							
					e.HP = e.HP - (p.w.damage + p.damage);
				}
				break;
						
				case 0:
				{
					c = RED;
					setcolor();

					cout<<"\nYour attack missed"<<endl;
				}
				break;
			}	
		}
		break;
	}

	c = WHITE;
	setcolor();
	
	cout<<"\nDamage Dealt : "<<temp - e.HP<<endl;
}

int ability(player&p,enemy&e)
{
	system("cls");
	
	switch(p.wtype)
	{
		case 1:
		{
			if(p.ability_point = true)
			{
				c = GREEN;
				setcolor();

				cout<<"\nYou used Berserk"<<endl;
				cout<<"\nYour weapon damage increased 2x for the rest of the battle"<<endl;

				p.w.damage *= 2;
				p.ability_point = false;
			}

			else
			{
				c = RED;
				setcolor();

				cout<<"\nNo ability points left"<<endl;
			}
		}
		break;

		case 2:
		{
			if(p.ability_point = true)
			{
				c = GREEN;
				setcolor();

				cout<<"\nYou used Celestial Strike"<<endl;
				cout<<"\nYou used a 2x damage attack on the enemy"<<endl;

				e.HP -= 2*(p.w.damage + p.damage);
				p.ability_point = false;
			}

			else
			{
				c = RED;
				setcolor();

				cout<<"\nNo ability points left"<<endl;
			}	
		}
		break;

		case 3:
		{
			if(p.ability_point = true)
			{
				c = GREEN;
				setcolor();

				cout<<"\nYou used Shadow Step"<<endl;
				cout<<"\nYour dodge increased by 10 for the rest of the battle"<<endl;

				p.dodge += 10;
				p.ability_point = false;
			}

			else
			{
				c = RED;
				setcolor();

				cout<<"\nNo ability points left"<<endl;
			}	
		}
		break;

		case 4:
		{
			c = RED;
			setcolor();

			cout<<"\nYour weapon doesn't have an ability"<<endl;
		}
		break;
	}

	c = WHITE;
	setcolor();
}

int ability_setup(player&p,int&t_damage,int&t_dodge)
{
	switch(p.wtype)
	{
		case 1:
		{
			t_damage = p.w.damage;
		}
		break;

		case 3:
		{
			t_dodge = p.dodge;
		}
		break;
	}
}

int ability_reverse(player&p,int t_damage,int t_dodge)
{
	switch(p.wtype)
	{
		case 1:
		{
			p.w.damage = t_damage;
		}
		break;

		case 3:
		{
			p.dodge = t_dodge;
		}
		break;
	}
}

int spell1(player&p)
{
	int spellchoice, check = 0; 
	
	int m_heal = 100;
	int m_stun = 500;
	int m_confuse = 750;
	int m_fireball = 200;
	int m_firestorm = 1000;
	
	switch(p.spellno)
	{
		case 0:
		{
			cout<<"\nYou don't have enough training in magic to use spells"<<endl;
			check = 0;
		}
		break;
		
		case 1:
		{
			cout<<"\nWhich spell would you like?"<<endl;
			cout<<"\n1. Heal : "<<m_heal<<" Mana"<<endl;
							
			cout<<"\nInput Choice : ";
			cin>>spellchoice;

			system("cls");
							
			switch(spellchoice)
			{
				case 1:
				{
					if(p.mana>=m_heal)
					{
						c = GREEN;
						setcolor();

						cout<<"\nYour health increased by "<<p.magic<<endl;
						if(p.HP + p.magic < p.maxHP)
						{
							p.HP = p.HP + p.magic;
							p.mana = p.mana - m_heal;
						}
						
						else
						{
							p.HP = p.maxHP;
							p.mana = p.mana - m_heal;
						}
					}
					
					else
					{
						c = RED;
						setcolor();

						cout<<"\nMana too low"<<endl;
					}
				}
				break;
			}
		}
		break;
						
		case 2:
		{
			cout<<"\nWhich spell would you like?"<<endl;
			cout<<"\n1. Heal : "<<m_heal<<" Mana"<<endl;
			cout<<"\n2. Stun : "<<m_stun<<" Mana"<<endl;
			
			cout<<"\nInput Choice : ";
			cin>>spellchoice;

			system("cls");
			
			switch(spellchoice)
			{
				case 1:
				{
					if(p.mana>=m_heal)
					{
						c = GREEN;
						setcolor();

						cout<<"\nYour health increased by "<<p.magic<<endl;
						if(p.HP + p.magic < p.maxHP)
						{
							p.HP = p.HP + p.magic;
							p.mana = p.mana - m_heal;
						}
						
						else
						{
							p.HP = p.maxHP;
							p.mana = p.mana - m_heal;
						}
					}
					
					else
					{
						c = RED;
						setcolor();

						cout<<"\nMana too low"<<endl;
					}
				}
				break;
				
				case 2:
				{
					if(p.mana >= m_stun)
					{
						c = GREEN;
						setcolor();

						cout<<"\nYou stunned the enemy for this move"<<endl;
						check = 1;
						p.mana = p.mana - m_stun;
					}
					
					else
					{
						c = RED;
						setcolor();

						cout<<"\nMana too low"<<endl;
					}
				}
				break;
			}
		}
		break;
		
		case 3:
		{
			cout<<"\nWhich spell would you like?"<<endl;
			cout<<"\n1. Heal : "<<m_heal<<" Mana"<<endl;
			cout<<"\n2. Stun : "<<m_stun<<" Mana"<<endl;
			cout<<"\n3. Confuse : "<<m_confuse<<" Mana"<<endl;
			
			cout<<"\nInput Choice : ";
			cin>>spellchoice;

			system("cls");
			
			switch(spellchoice)
			{
				case 1:
				{
					if(p.mana>=m_heal)
					{
						c = GREEN;
						setcolor();

						cout<<"\nYour health increased by "<<p.magic<<endl;
						if(p.HP + p.magic < p.maxHP)
						{
							p.HP = p.HP + p.magic;
							p.mana = p.mana - m_heal;
						}
						
						else
						{
							p.HP = p.maxHP;
							p.mana = p.mana - m_heal;
						}
					}
					
					else
					{
						c = RED;
						setcolor();

						cout<<"\nMana too low"<<endl;
					}
				}
				break;
				
				case 2:
				{
					if(p.mana >=m_stun)
					{
						c = GREEN;
						setcolor();
							
						cout<<"\nYou used Stun"<<endl;
						check = 1;
						p.mana = p.mana - m_stun;	
					}
					
					else
					{
						c = RED;
						setcolor();

						cout<<"\nMana too low"<<endl;
					}
				}
				break;
				
				case 3:
				{
					if(p.mana >= m_confuse)
					{
						c = GREEN;
						setcolor();

						cout<<"\nYou used Confuse"<<endl;
						check = 2;
						p.mana = p.mana - m_confuse;	
					}
					
					else
					{
						c = RED;
						setcolor();

						cout<<"\nMana too low"<<endl;
					}
				}
				break;
				
				
			}
			break;
		}
		
		case 4:
		{
			cout<<"\nWhich spell would you like?"<<endl;
			cout<<"\n1. Heal : "<<m_heal<<" Mana"<<endl;
			cout<<"\n2. Confuse : "<<m_confuse<<" Mana"<<endl;
			cout<<"\n3. Fireball : "<<m_fireball<<" Mana"<<endl;
			cout<<"\n4. Mana Increase by 100"<<endl;
			
			cout<<"\nInput Choice : ";
			cin>>spellchoice;

			system("cls");
			
			switch(spellchoice)
			{
				case 1:
				{
					if(p.mana >= m_heal)
					{
						c = GREEN;
						setcolor();

						cout<<"\nYour health increased by "<<p.magic<<endl;
						if(p.HP + p.magic < p.maxHP)
						{
							p.HP = p.HP + p.magic;
							p.mana = p.mana - m_heal;
						}
						
						else
						{
							p.HP = p.maxHP;
							p.mana = p.mana - m_heal;
						}
					}
					
					else
					{
						c = RED;
						setcolor();

						cout<<"\nMana too low"<<endl;
					}
				}
				break;
				
				case 2:
				{
					if(p.mana >= m_confuse)
					{
						c = GREEN;
						setcolor();

						cout<<"\nYou used Confuse"<<endl;
						check = 2;
						p.mana = p.mana - m_confuse;	
					}
					
					else
					{
						c = RED;
						setcolor();

						cout<<"\nMana too low"<<endl;
					}
				}
				break;
				
				case 3:
				{
					if(p.mana >= m_fireball)
					{
						c = GREEN;
						setcolor();

						cout<<"\nYou used Fireball"<<endl;
						check = 3;
						p.mana = p.mana - m_fireball;	
					}
					
					else
					{
						c = RED;
						setcolor();

						cout<<"\nMana too low"<<endl;
					}
				}
				break;
				
				case 4:
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou increased your mana by 100"<<endl;
					if(p.mana + 100<p.maxM) p.mana = p.mana + 100; else p.mana = p.maxM;
				}
				break;
			}	
		}
		break;
		
		case 5:
		{
			cout<<"\nWhich spell would you like?"<<endl;
			cout<<"\n1. Heal : "<<m_heal<<" Mana"<<endl;
			cout<<"\n2. Confuse : "<<m_confuse<<" Mana"<<endl;
			cout<<"\n3. Fireball : "<<m_fireball<<" Mana"<<endl;
			cout<<"\n4. Fire Storm : "<<m_firestorm<<" Mana"<<endl;
			cout<<"\n5. Mana Increase by 100"<<endl;
			
			cout<<"\nInput Choice : ";
			cin>>spellchoice;

			system("cls");
			
			switch(spellchoice)
			{
				case 1:
				{
					if(p.mana >= m_heal)
					{
						c = GREEN;
						setcolor();

						cout<<"\nYour health increased by "<<p.magic<<endl;
						if(p.HP + p.magic < p.maxHP)
						{
							p.HP = p.HP + p.magic;
							p.mana = p.mana - m_heal;
						}
						
						else
						{
							p.HP = p.maxHP;
							p.mana = p.mana - m_heal;
						}
					}
					
					else
					{
						c = RED;
						setcolor();

						cout<<"\nMana too low"<<endl;
					}
				}
				break;
				
				case 2:
				{
					if(p.mana >= m_confuse)
					{
						c = GREEN;
						setcolor();

						cout<<"\nYou used Confuse"<<endl;
						check = 2;
						p.mana = p.mana - m_confuse;	
					}
					
					else
					{
						c = RED;
						setcolor();

						cout<<"\nMana too low"<<endl;
					}
				}
				break;
				
				case 3:
				{
					if(p.mana >= m_fireball)
					{
						c = GREEN;
						setcolor();

						cout<<"\nYou used Fireball"<<endl;
						check = 3;
						p.mana = p.mana - m_fireball;	
					}
					
					else
					{
						c = RED;
						setcolor();

						cout<<"\nMana too low"<<endl;
					}
				}
				break;
				
				case 4:
				{
					if(p.mana >= m_firestorm)
					{
						c = GREEN;
						setcolor();

						cout<<"\nYou used Fire Storm"<<endl;
						check = 4;
						p.mana = p.mana - m_firestorm;
					}
					
					else
					{
						c = RED;
						setcolor();

						cout<<"\nMana too low"<<endl;
					}
				}
				break;
				
				case 5:
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou increased your mana by 100"<<endl;
					if(p.mana + 100<p.maxM) p.mana = p.mana + 100; else p.mana = p.maxM;
				}
				break;
			}	
		}
	}

	c = WHITE;
	setcolor();
	
	return check;
}

int enemy_attack(player&p, enemy&e, int check)
{
	int echoice, enemy_landchance, armor_chance, self_dodge,AA , A = p.a.defense - 5, low = 5;
	
	self_dodge = (10 - p.a.weight) + p.dodge;

	echoice = (rand () % 10);
			
	enemy_landchance = (rand () % self_dodge);
			
	switch(check)
	{
		case 0:
		{
			switch(enemy_landchance)
			{
				case 0: case 1:
				{
					switch(echoice)
					{
						case 0:
						{
							AA = rand () % A;
							armor_chance = AA + low;
							
							if(armor_chance < e.cdamage)
							{
								p.HP = p.HP - e.cdamage + armor_chance;

								c = RED;
								setcolor();

								cout<<"\nEnemy used critical attack"<<endl;

								c = GREEN;
								setcolor();

								cout<<"\nYour armor defended you by "<<armor_chance<<endl;
							}
								
							else
							{
								c = GREEN;
								setcolor();

								cout<<"\nYour armor defended you completely"<<endl;
							}
						}
						break;
				
						default :
						{
							armor_chance = rand () % p.a.defense;
								
							if(armor_chance < e.damage)
							{
								p.HP = p.HP - e.damage + armor_chance;

								c = RED;
								setcolor();

								cout<<"\nEnemy used normal attack"<<endl;

								c = GREEN;
								setcolor();

								cout<<"\nYour armor defended you by "<<armor_chance<<endl;
							}
								
							else
							{
								c = GREEN;
								setcolor();

								cout<<"\nYour armor defended you completely against the attack"<<endl;
							}
						}
						break;
					}
				}
				break;
			
				default:
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou dodged the enemy's attack"<<endl;
				}
				break;
			}
		}
		break;
				
		case 1:
		{
			cout<<"\nEnemy was stunned for the move"<<endl;	
			cout<<"\nEnemy's attack dropped by 10%"<<endl;
				
			e.damage = 9/10 * e.damage;
		}
		break;
				
		case 2:
		{
			cout<<"\nEnemy was confused for this move"<<endl;
			e.HP = e.HP - e.damage;
		}
		break;
			
		case 3:
		{
			cout<<"\nEnemy was hit by the fireball"<<endl;
			e.HP = e.HP - p.fire;
				
			switch(enemy_landchance)
			{
				case 0: case 1:
				{
					switch(echoice)
					{
						case 0:
						{ 
							p.HP=p.HP-e.cdamage;

							c = RED;
							setcolor();

							cout<<"\nEnemy used critical attack"<<endl;
						}
						break;
				
						default :
						{
							c = RED;
							setcolor();

							p.HP=p.HP-e.damage; cout<<"\nEnemy used normal attack"<<endl;
						}
						break;
					}
				}
				break;
			
				default:
				{
					c = GREEN;
					setcolor();

					cout<<"\nYou dodged the enemy's attack"<<endl;
				}
				break;
			}
		}
		break;
			
		case 4:
		{
			c = GREEN;
			setcolor();

			cout<<"\nEnemy was trapped in the fire storm"<<endl;
					
			e.HP = e.HP - 500;
		}
		break;
	}	

	c = WHITE;
	setcolor();
}

int battle1(player&p,enemy&e)
{
	srand(time(0));
	
	int dead=0;
	
	int enemy_landchance,drop_chance,echoice,check=0,armor_chance,choice,self_dodge;
	int t_damage, t_dodge;

	p.ability_point = true;

	ability_setup(p,t_damage,t_dodge);

	self_dodge = (10 - p.a.weight) + p.dodge;
	
	while(e.HP)
	{
		//Player choice
		cout<<"\nWhat do you choose?"<<endl;
		cout<<"\n1. Attack enemy"<<endl;
		cout<<"\n2. Use Magic"<<endl;
		cout<<"\n3. Use Healing Potion"<<endl;
		cout<<"\n4. Use Ability "<<endl;
			
		cout<<"\nInput choice : ";
		cin>>choice;
		
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
				check = spell1(p);
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
		enemy_attack(p,e,check);
			
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

	c = GREEN;
	setcolor();

	cout<<"\nEnemy dropped loot"<<endl;

	c = WHITE;
	setcolor();
	
	drop_chance = (rand() % 4);
	
	switch(drop_chance)
	{
		case 0: 
		{
			cout<<"\nEnemy dropped a weapon"<<endl;
			loot_weapon1(p);
		}
		break;
		
		case 1:
		{
			cout<<"\nEnemy dropped some armor"<<endl;
			loot_armor1(p);
		}
		break;
		
		default:
		{
			cout<<"\nEnemy dropped a potion"<<endl;
			loot_potion(p);
		}
		break;
	}
	
	cout<<"\nYou gained XP"<<endl;
	
	p.xp +=50;
	
	cout<<"\nXP : "<<p.xp<<endl;
	
	cout<<"\nThe enemy dropped money"<<endl;
	
	p.i.money += 50;
	
	cout<<"\nMoney : "<<p.i.money<<endl;
	
	line();
	
	return dead;
}

int battle2(player&p,enemy&e)
{
	srand(time(0));
	
	int dead=0;

	int enemy_landchance,drop_chance,echoice,check=0,armor_chance,choice,self_dodge;
	int t_damage,t_dodge;

	p.ability_point = true;

	ability_setup(p,t_damage,t_dodge);
	
	self_dodge = (10 - p.a.weight) + p.dodge;
	
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
				check = spell1(p);
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
		enemy_attack(p,e,check);
			
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

	c = GREEN;
	setcolor();
	
	cout<<"\nEnemy dropped loot"<<endl;

	c = WHITE;
	setcolor();
	
	drop_chance = (rand() % 4);
	
	switch(drop_chance)
	{
		case 0: 
		{
			cout<<"\nEnemy dropped a weapon"<<endl;
			loot_weapon2(p);
		}
		break;
		
		case 1:
		{
			cout<<"\nEnemy dropped some armor"<<endl;
			loot_armor2(p);
		}
		break;
		
		default:
		{
			cout<<"\nEnemy dropped a potion"<<endl;
			loot_potion(p);
		}
		break;
	}
	
	cout<<"\nYou gained XP"<<endl;
	
	p.xp += 100;
	
	cout<<"\nXP : "<<p.xp<<endl;
	
	cout<<"\nThe enemy dropped money"<<endl;
	
	p.i.money += 100;
	
	cout<<"\nMoney : "<<p.i.money<<endl;
	
	line();
	
	return dead;
	
}

int stealth_attack1(player&p,enemy&e)
{
	srand(time(0));
	int choice, drop_chance; 
	
	int chance = (rand () % p.stealth);
	
	switch(chance)
	{
		case 0: 
		{
			c = RED;
			setcolor();

			cout<<"\nThe enemy noticed you"<<endl;
		}
		break;
		
		default: 
		{
			c = GREEN;
			setcolor();

			cout<<"\nThe enemy didn't notice you"<<endl;

			c = WHITE;
			setcolor();
			
			cout<<"\nUse stealth attack?"<<endl;
			cout<<"\n1. Yes"<<endl;
			cout<<"\n2. No"<<endl;
			
			cout<<"\nInput choice : ";
			
			cin>>choice;
			switch(choice)
			{
				case 1:
				{	
					c = GREEN;
					setcolor();

					cout<<"\nYou used a stealth attack on the enemy"<<endl;
					e.HP = e.HP - (10 * p.w.damage);

					c = WHITE;
					setcolor();
					
					if(e.HP <= 0)
					{
						cout<<"\nEnemy Health : 0"<<endl;
					}
					
					else
					{
						cout<<"\nEnemy Health : "<<e.HP<<endl;
					}
				}
				break;
			}

			empty();
		}
	}
	
	if(e.HP <= 0)
	{
		system("cls");

		c = GREEN;
		setcolor();
		
		cout<<"\nEnemy died"<<endl;
		
		cout<<"\nEnemy dropped loot"<<endl;

		c = WHITE;
		setcolor();
	
		drop_chance = (rand() % 6);
	
		switch(drop_chance)
		{
			case 0: 
			{
				cout<<"\nEnemy dropped a weapon"<<endl;
				loot_weapon1(p);
			}
			break;
		
			case 1:
			{
				cout<<"\nEnemy dropped some armor"<<endl;
				loot_armor1(p);
			}
			break;
			
			case 2:
			{
				cout<<"\nEnemy dropped a potion"<<endl;
				loot_armor1(p);
			}
			break;
		}
	
		cout<<"\nYou gained XP"<<endl;
	
		p.xp +=50;
	
		cout<<"\nXP : "<<p.xp<<endl;
	
		cout<<"\nThe enemy dropped money"<<endl;
	
		p.i.money += 50;
	
		cout<<"\nMoney : "<<p.i.money<<endl;
	
		return 0;
	}

	c = RED;
	setcolor();
	
	cout<<"\nThe enemy charges at you"<<endl;

	c = WHITE;
	setcolor();

	line();
	
	return 0;
}

int stealth_attack2(player&p,enemy&e)
{
	srand(time(0));
	int choice, drop_chance; 
	
	int chance = (rand () % p.stealth);
	
	switch(chance)
	{
		case 0: 
		{
			c = RED;
			setcolor();

			cout<<"\nThe enemy noticed you"<<endl;
		}
		break;
		
		default: 
		{
			c = GREEN;
			setcolor();

			cout<<"\nThe enemy didn't notice you"<<endl;
			
			cout<<"\nUse stealth attack?"<<endl;
			cout<<"\n1. Yes"<<endl;
			cout<<"\n2. No"<<endl;
			
			cout<<"\nInput choice : ";
			
			cin>>choice;
			switch(choice)
			{
				case 1:
				{	
					c = GREEN;
					setcolor();

					cout<<"\nYou used a stealth attack on the enemy"<<endl;
					e.HP = e.HP - (10*p.w.damage);
					
					if(e.HP <= 0)
					{
						cout<<"\nEnemy Health : 0"<<endl;
					}
					
					else
					{
						cout<<"\nEnemy Health : "<<e.HP<<endl;
					}
				}
				break;
			}

			empty();
		}
	}
	
	if(e.HP <= 0)
	{
		system("cls");

		c = GREEN;
		setcolor();
		
		cout<<"\nEnemy died"<<endl;
		
		cout<<"\nEnemy dropped loot"<<endl;
	
		c = WHITE;
		setcolor();

		drop_chance = (rand() % 6);
	
		switch(drop_chance)
		{
			case 0: 
			{
				cout<<"\nEnemy dropped a weapon"<<endl;
				loot_weapon2(p);
			}
			break;
		
			case 1:
			{
				cout<<"\nEnemy dropped some armor"<<endl;
				loot_armor2(p);
			}
			break;
			
			case 2:
			{
				cout<<"\nEnemy dropped a potion"<<endl;
				loot_potion(p);
			}
			break;
		}
	
		cout<<"\nYou gained XP"<<endl;
	
		p.xp +=50;
	
		cout<<"\nXP : "<<p.xp<<endl;
	
		cout<<"\nThe enemy dropped money"<<endl;
	
		p.i.money += 50;
	
		cout<<"\nMoney : "<<p.i.money<<endl;
	
		return 0;
	}
	
	c = RED;
	setcolor();

	cout<<"\nThe enemy charges at you"<<endl;

	c = WHITE;
	setcolor();
	
	line();
	
	return 0;
}
