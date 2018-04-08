#pragma once

#include"resources.h"
#include"loot.h"

using namespace std;

int display_battlestats(player&p, enemy&e)
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

	cout<<"\n"<<e.name<<" Health : ";

	c = GREEN;
	setcolor();

	if(e.HP > 0)
	{
		cout<<e.HP;
	}

	else
	{
		cout<<"0";
	}

	c = WHITE;
	setcolor();

	cout<<" / "<<e.maxHP;

	cout<<endl;
	printH(e.HP, e.maxHP);

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
}

int attack(player&p,enemy&e,string&playerdone,string&playerchance)
{
	int choice, landchance, chance, temp, damage_dealt, stressfac, stress, knock_fac;
	temp = e.HP;
	
	cout<<"\nWhat would you like to do?"<<endl;
	
	cout<<"\n1. Critical Attack ";

	c = GREEN;
	setcolor();

	cout<<"(10x Damage, High Knockback)"<<endl;

	c = WHITE;
	setcolor();

	cout<<"\n2. Heavy Attack ";

	c = GREEN;
	setcolor();

	cout<<"(2x Damage, Low Knockback)"<<endl;

	c = WHITE;
	setcolor();

	cout<<"\n3. Normal Attack"<<endl;
			
	cout<<"\nInput Choice : ";
	cin>>choice;

	system("cls");

	stress = (p.stress/5) + 1;

	stressfac = (rand () % stress);

	display_battlestats(p,e);

	switch(choice)
	{
		case 1:
		{
			playerdone = "CRITICAL ATTACK";

			if(((30 - (p.w.weight + e.sdodge)) + p.wh - stressfac * p.smDEX) > 1) chance = (30 - (p.w.weight + e.sdodge)) + p.wh - stressfac * p.smDEX; else chance = 1;
					
			landchance = (rand () % chance);
					
			switch(landchance)
			{
				default:
				{
					playerchance = "LANDED";
					e.HP = e.HP - 10 * (p.w.damage + p.damage);

					knock_fac = (rand () % 10);

					p.HP -= knock_fac * p.w.weight;
				}
				break;
						
				case 0:
				{
					playerchance = "MISSED";
					p.stress++;
				}
				break;
			}
		}
		break;

		case 2:
		{
			playerdone = "HEAVY ATTACK";

			if(((30 - (p.w.weight + e.sdodge)) + p.wh - stressfac * p.smDEX) > 1) chance = (30 - (p.w.weight + e.sdodge)) + p.wh - stressfac * p.smDEX; else chance = 1;
					
			landchance = (rand () % chance);
					
			switch(landchance)
			{
				default:
				{
					playerchance = "LANDED";
					e.HP = e.HP - 2 * (p.w.damage + p.damage);

					knock_fac = (rand () % 2);

					p.HP -= knock_fac * p.w.weight;
				}
				break;
						
				case 0:
				{
					playerchance = "MISSED";
					p.stress++;
				}
				break;
			}	
		}
		break;

		case 3:
		{
			playerdone = "NORMAL ATTACK";

			if(((30 - (p.w.weight + e.sdodge)) + p.wh - stressfac * p.smDEX) > 1) chance = (30 - (p.w.weight + e.sdodge)) + p.wh - stressfac * p.smDEX; else chance = 1;
					
			landchance = (rand () % chance);
					
			switch(landchance)
			{
				default:
				{
					playerchance = "LANDED";

					if(((p.w.damage + p.damage) - stressfac*p.smDM) > 0) e.HP = e.HP - (p.w.damage + p.damage) + stressfac * p.smDM; else e.HP = e.HP;
				}
				break;
						
				case 0:
				{
					playerchance = "MISSED";
					p.stress++;
				}
				break;
			}	
		}
	}


	c = WHITE;
	setcolor();
}

int ability(player&p,string&playerdone,string&playersuccess)
{
	system("cls");

	int temp_h = p.HP;

	if(p.race == "Orc" || p.race == "Half-Orc")
	{
		if(p.ability_point > 0 && p.ability == false)
		{
			playerdone = "BERSERK";

			playersuccess = "SUCCESSFUL";

			p.STR *= 4;
			p.ability_point --;
			p.ability = true;
		}

		else
		{
			playerdone = "BERSERK";

			playersuccess = "UNSUCCESSFUL";
			p.stress++;
		}
	}

	if(p.race == "Elf" || p.race == "Half-Elf")
	{
		if(p.ability_point > 0 && p.ability == false)
		{
			playerdone = "FAITH MIRACLE";

			playersuccess = "SUCCESSFUL";

			p.FAI *= 3;
			p.ability_point --;
			p.ability = true;
		}

		else
		{
			playerdone = "FAITH MIRACLE";

			playersuccess = "UNSUCCESSFUL";
			p.stress++;
		}	
	}

	if(p.race == "Half-Lizard")
	{
		if(p.ability_point > 0 && p.ability == false)
		{
			playerdone = "SHADOW STEP";

			playersuccess = "SUCCESSFUL";

			p.STA *= 3;
			p.ability_point --;
			p.ability = true;
		}

		else
		{
			playerdone = "SHADOW STEP";

			playersuccess = "UNSUCCESSFUL";
			p.stress++;
		}	
	}

	p.setattributes();

	p.HP = temp_h;

	c = WHITE;
	setcolor();
}

int ability_setup(player&p,player&temp)
{
	if(p.race == "Orc" || p.race == "Half-Orc")
	{
		temp.STR = p.STR;
	}

	if(p.race == "Elf" || p.race == "Half-Elf")
	{
		temp.FAI = p.FAI;
	}

	if(p.race == "Half-Lizard")
	{
		temp.STA = p.STA;
	}

	p.ability = false;
}

int ability_reverse(player&p,player&temp)
{
	int temp_h = p.HP;

	if(p.race == "Orc" || p.race == "Half-Orc")
	{
		p.STR = temp.STR;
	}

	if(p.race == "Elf" || p.race == "Half-Elf")
	{
		p.FAI = temp.FAI;
	}

	if(p.race == "Half-Lizard")
	{
		p.STA = temp.STA;
	}	

	p.setattributes();

	p.HP = temp_h;
	p.ability = false;
}

int spell1(player&p,string&playerdone,string&playersuccess)
{
	int spellchoice, check = 0; 
	
	int m_heal = 100;
	int m_cleanse = 150;
	int m_stun = 500;
	int m_confuse = 750;
	int m_fireball = 150;
	int m_firestorm = 1000;
	
	switch(p.spellno)
	{
		case 0:
		{
			playerdone  = "NO MAGIC";	
			playersuccess = "UNSUCCESSFUL";
		}
		break;
		
		case 1:
		{
			cout<<"\nWhich spell would you like?"<<endl;
			cout<<"\n1. Heal : "<<m_heal<<" Mana"<<endl;
			cout<<"\n2. Cleanse Aura : "<<m_cleanse<<" Mana"<<endl;
							
			cout<<"\nInput Choice : ";
			cin>>spellchoice;

			system("cls");
							
			switch(spellchoice)
			{
				case 1:
				{
					playerdone = "HEAL";

					if(p.mana>=m_heal)
					{
						playersuccess = "SUCCESSFUL";

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
						playersuccess = "UNSUCCESSFUL";
						p.stress++;	
					}
				}
				break;

				case 2:
				{
					playerdone = "CLEANSE AURA";

					if(p.mana >= m_cleanse)
					{
						playersuccess = "SUCCESSFUL";

						if(p.stress - 10 > 0)
						{
							p.stress -= 10;
							p.mana = p.mana - m_cleanse;
						}
						
						else
						{
							p.stress = 0;
							p.mana = p.mana - m_cleanse;
						}
					}
					
					else
					{
						playersuccess = "UNSUCCESSFUL";
					}
				}
			}
		}
		break;
						
		case 2:
		{
			cout<<"\nWhich spell would you like?"<<endl;
			cout<<"\n1. Heal : "<<m_heal<<" Mana"<<endl;
			cout<<"\n2. Stun : "<<m_stun<<" Mana"<<endl;
			cout<<"\n3. Cleanse Aura : "<<m_cleanse<<" Mana"<<endl;
			
			cout<<"\nInput Choice : ";
			cin>>spellchoice;

			system("cls");
			
			switch(spellchoice)
			{
				case 1:
				{
					playerdone = "HEAL";

					if(p.mana>=m_heal)
					{
						playersuccess = "SUCCESSFUL";

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
						playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 2:
				{
					playerdone = "STUN";

					if(p.mana >= m_stun)
					{
						playersuccess = "SUCCESSFUL";
						check = 1;
						p.mana = p.mana - m_stun;
					}
					
					else
					{
						playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;

				case 3:
				{
					playerdone = "CLEANSE AURA";

					if(p.mana >= m_cleanse)
					{
						playersuccess = "SUCCESSFUL";

						if(p.stress - 10 > 0)
						{
							p.stress -= 10;
							p.mana = p.mana - m_cleanse;
						}
						
						else
						{
							p.stress = 0;
							p.mana = p.mana - m_cleanse;
						}
					}
					
					else
					{
						playersuccess = "UNSUCCESSFUL";
					}
				}
			}
		}
		break;
		
		case 3:
		{
			cout<<"\nWhich spell would you like?"<<endl;
			cout<<"\n1. Heal : "<<m_heal<<" Mana"<<endl;
			cout<<"\n2. Stun : "<<m_stun<<" Mana"<<endl;
			cout<<"\n3. Confuse : "<<m_confuse<<" Mana"<<endl;
			cout<<"\n4. Cleanse Aura : "<<m_cleanse<<" Mana"<<endl;
			
			cout<<"\nInput Choice : ";
			cin>>spellchoice;

			system("cls");
			
			switch(spellchoice)
			{
				case 1:
				{
					playerdone = "HEAL";

					if(p.mana>=m_heal)
					{
						playersuccess = "SUCCESSFUL";

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
						playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 2:
				{
					playerdone = "STUN";

					if(p.mana >=m_stun)
					{
						playersuccess = "SUCCESSFUL";
						check = 1;
						p.mana = p.mana - m_stun;	
					}
					
					else
					{
						playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 3:
				{
					playerdone = "CONFUSE";

					if(p.mana >= m_confuse)
					{
						playersuccess = "SUCCESSFUL";

						check = 2;
						p.mana = p.mana - m_confuse;	
					}
					
					else
					{
						playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 4:
				{
					playerdone = "CLEANSE AURA";

					if(p.mana >= m_cleanse)
					{
						playersuccess = "SUCCESSFUL";

						if(p.stress - 10 > 0)
						{
							p.stress -= 10;
							p.mana = p.mana - m_cleanse;
						}
						
						else
						{
							p.stress = 0;
							p.mana = p.mana - m_cleanse;
						}
					}
					
					else
					{
						playersuccess = "UNSUCCESSFUL";
					}
				}
			}
			break;
		}
		
		case 4:
		{
			cout<<"\nWhich spell would you like?"<<endl;
			cout<<"\n1. Heal : "<<m_heal<<" Mana"<<endl;
			cout<<"\n2. Confuse : "<<m_confuse<<" Mana"<<endl;
			cout<<"\n3. Fireball : "<<m_fireball<<" Mana"<<endl;
			cout<<"\n4. Cleanse Aura : "<<m_cleanse<<" Mana"<<endl;
			cout<<"\n5. Mana Increase by 100"<<endl;
			
			cout<<"\nInput Choice : ";
			cin>>spellchoice;

			system("cls");
			
			switch(spellchoice)
			{
				case 1:
				{
					playerdone = "HEAL";

					if(p.mana >= m_heal)
					{
						playersuccess = "SUCCESSFUL";

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
						playersuccess = "UNSUCCESSFUL";	
						p.stress++;
					}
				}
				break;
				
				case 2:
				{
					playerdone = "CONFUSE";

					if(p.mana >= m_confuse)
					{
						playersuccess = "SUCCESSFUL";
						check = 2;
						p.mana = p.mana - m_confuse;	
					}
					
					else
					{
						playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 3:
				{
					playerdone = "FIREBALL";

					if(p.mana >= m_fireball)
					{
						playersuccess = "SUCCESSFUL";

						check = 3;
						p.mana = p.mana - m_fireball;	
					}
					
					else
					{
						playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;

				case 4:
				{
					playerdone = "CLEANSE AURA";

					if(p.mana >= m_cleanse)
					{
						playersuccess = "SUCCESSFUL";

						if(p.stress - 10 > 0)
						{
							p.stress -= 10;
							p.mana = p.mana - m_cleanse;
						}
						
						else
						{
							p.stress = 0;
							p.mana = p.mana - m_cleanse;
						}
					}
					
					else
					{
						playersuccess = "UNSUCCESSFUL";
					}
				}
				
				case 5:
				{
					playerdone = "MANA BOOST";

					playersuccess = "SUCCESSFUL";

					if(p.mana + 100<p.maxM) p.mana = p.mana + 100; else p.mana = p.maxM;
				}
				break;
			}	
		}
		break;
		
		default:
		{
			cout<<"\nWhich spell would you like?"<<endl;
			cout<<"\n1. Heal : "<<m_heal<<" Mana"<<endl;
			cout<<"\n2. Confuse : "<<m_confuse<<" Mana"<<endl;
			cout<<"\n3. Fireball : "<<m_fireball<<" Mana"<<endl;
			cout<<"\n4. Fire Storm : "<<m_firestorm<<" Mana"<<endl;
			cout<<"\n5. Cleanse Aura : "<<m_cleanse<<" Mana"<<endl;
			cout<<"\n6. Mana Increase by 100"<<endl;
			
			cout<<"\nInput Choice : ";
			cin>>spellchoice;

			system("cls");
			
			switch(spellchoice)
			{
				case 1:
				{
					playerdone = "HEAL";

					if(p.mana>=m_heal)
					{
						playersuccess = "SUCCESSFUL";

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
						playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 2:
				{
					playerdone = "CONFUSE";

					if(p.mana >= m_confuse)
					{
						playersuccess = "SUCCESSFUL";
						check = 2;
						p.mana = p.mana - m_confuse;	
					}
					
					else
					{
						playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 3:
				{
					playerdone = "FIREBALL";

					if(p.mana >= m_fireball)
					{
						playersuccess = "SUCCESSFUL";

						check = 3;
						p.mana = p.mana - m_fireball;	
					}
					
					else
					{
						playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 4:
				{
					playerdone = "FIRE STORM";

					if(p.mana >= m_firestorm)
					{
						playersuccess = "SUCCESSFUL";
						check = 4;
						p.mana = p.mana - m_firestorm;
					}
					
					else
					{
						playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;

				case 5:
				{
					playerdone = "CLEANSE AURA";

					if(p.mana >= m_cleanse)
					{
						playersuccess = "SUCCESSFUL";

						if(p.stress - 10 > 0)
						{
							p.stress -= 10;
							p.mana = p.mana - m_cleanse;
						}
						
						else
						{
							p.stress = 0;
							p.mana = p.mana - m_cleanse;
						}
					}
					
					else
					{
						playersuccess = "UNSUCCESSFUL";
					}
				}
				
				case 6:
				{
					playerdone = "MANA BOOST";

					playersuccess = "SUCCESSFUL";

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

int enemy_attack(player&p, enemy&e, int check, string&enemydoes)
{
	int echoice, enemy_landchance, armor_chance, self_dodge, AA, stressfac, stress, A = p.a.defense - 5, low = 5;
	
	self_dodge = (10 - p.a.weight) + p.dodge;

	stress = (p.stress/5) + 1;

	stressfac = (rand () % stress);

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
							armor_chance = (rand () % p.a.defense);
							
							if(armor_chance < e.cdamage)
							{
								p.HP = p.HP - e.cdamage + armor_chance - stressfac * p.smHP;

								enemydoes = "Enemy used CRITICAL ATTACK and it LANDED";
								p.stress+=3;
							}
								
							else
							{
								enemydoes = "Your armor defends you completely against the enemy";	
							}
						}
						break;
				
						default :
						{
							armor_chance = (rand () % p.a.defense);
								
							if(armor_chance < e.damage)
							{
								p.HP = p.HP - e.damage + armor_chance - stressfac * p.smHP;

								enemydoes = "Enemy used NORMAL ATTACK and it LANDED";
								p.stress++;
							}
								
							else
							{
								enemydoes = "Your armor defends you completely against the enemy";	
							}
						}
						break;
					}
				}
				break;
			
				default:
				{
					enemydoes = "You dodge the enemy's attack";
				}
				break;
			}
		}
		break;
				
		case 1:
		{
			enemydoes = "Enemy is STUNNED, and loses 10 percent attack damage";
				
			e.damage = 9/10 * e.damage;
		}
		break;
				
		case 2:
		{
			enemydoes = "Enemy is CONFUSED, and hits itself";
			
			e.HP = e.HP - e.damage;
		}
		break;
			
		case 3:
		{
			e.HP = e.HP - p.fire;
				
			switch(enemy_landchance)
			{
				case 0: case 1:
				{
					switch(echoice)
					{
						case 0:
						{ 
							enemydoes = "Enemy is hit by the FIREBALL, and uses CRITICAL ATTACK";

							p.HP = p.HP - e.cdamage - stressfac * p.smHP;

							
							p.stress += 3;
						}
						break;
				
						default :
						{
							enemydoes = "Enemy is hit by the FIREBALL, and uses NORMAL ATTACK";

							p.HP = p.HP - e.damage - stressfac * p.smHP; 

							p.stress++;;
						}
						break;
					}
				}
				break;
			
				default:
				{
					enemydoes = "Enemy is hit by the FIREBALL, and you dodge it's attack";
				}
				break;
			}
		}
		break;
			
		case 4:
		{		
			enemydoes = "Enemy is trapped in the FIRE STORM";

			e.HP = e.HP - 500;
		}
		break;
	}	

	c = WHITE;
	setcolor();
}

int panicattack_setup(player&p, player&temp)
{
	temp.STR = p.STR;
	temp.VIT = p.VIT;
	temp.DEX = p.DEX;
	temp.STA = p.STA;
	temp.FAI = p.FAI;
}

int panicattack(player&p)
{
	if(p.stress >= p.stress_limit)
	{
		c = RED;
		setcolor();

		system("cls");
		cout<<"\nYour stress has reached its max, and you have a panic attack. All of your stats drop down to 5"<<endl;

		p.STR = 5;
		p.VIT = 5;
		p.DEX = 5;
		p.STA = 5;
		p.FAI = 5;

		p.setattributes();

		p.stress = 0;
	}

	c = WHITE;
	setcolor();
}

int panicattack_reverse(player&p, player&temp)
{
	int temp_h;

	temp_h = p.HP;

	p.STR = temp.STR;
	p.VIT = temp.VIT;
	p.DEX = temp.DEX;
	p.STA = temp.STA;
	p.FAI = temp.FAI;

	p.setattributes();

	p.HP = temp_h;
}

int output_battle(player&p,string&playerdone,string&playerchance,string&enemydoes,int playerdoes)
{
	switch(playerdoes)
	{
		case 1:
		{
			cout<<"\nYou used "<<playerdone<<" and it ";

			if(playerchance == "LANDED")
			{
				c = GREEN;
				setcolor();
			}

			else
			{
				c = RED;
				setcolor();
			}

			cout<<playerchance<<endl;

			c = WHITE;
			setcolor();
		}
		break;

		case 2:
		{
			cout<<"\nYou used "<<playerdone<<" and it was ";

			if(playerchance == "SUCCESSFUL")
			{
				c = GREEN;
				setcolor();
			}

			else
			{
				c = RED;
				setcolor();
			}

			cout<<playerchance<<endl;

			c = WHITE;
			setcolor();
		}
		break;

		case 3:
		{
			cout<<"\nYou used a health potion"<<endl;

			cout<<"\nNo of Health Potions : "<<p.i.hp<<endl;
		}
		break;

		case 4:
		{
			cout<<"\nYou used "<<playerdone<<" and it was ";

			if(playerchance == "SUCCESSFUL")
			{
				c = GREEN;
				setcolor();
			}

			else
			{
				c = RED;
				setcolor();
			}

			cout<<playerchance<<endl;

			c = WHITE;
			setcolor();
		}
		break;

		case 6:
		{
			if(playerchance == "SUCCESSFUL")
			{
				cout<<"\nYou climb upon the Titan, and so you can attack it better. Your attack increases by 25"<<endl;	
			}

			else
			{
				cout<<"\nYou attempt to climb the Titan fails, and the Titan throws you off, damaging you by 50"<<endl;
			}
		}
		break;
	}

	cout<<"\n"<<enemydoes<<endl;
}

int battle(player&p,enemy&e)
{
	srand(time(0));
	
	int dead=0;
	
	int drop_chance, check=0, choice, flee_chance, playerdoes;
	player temp_ability, temp_panic;

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
		cout<<"\n5. Flee"<<endl;
			
		cout<<"\nInput choice : ";
		cin>>choice;
		
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
				flee_chance = (rand () % p.stealth);
				
				switch(flee_chance)
				{
					case 0:
					{
						cout<<"\nYour fleeing attempt failed"<<endl;
					}
					break;

					default:
					{
						cout<<"\nYou were able to trick the enemy and flee"<<endl;
						ability_reverse(p,temp_ability);

						return 5;
					}
					break;
				}
			}
		}

		playerdoes = choice;

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
			empty();
			
			dead=0;
			break;
		}

		panicattack(p);

		line();
	}

	ability_reverse(p,temp_ability);
	panicattack_reverse(p, temp_panic);
	
	system("cls");
	
	drop_chance = (rand() % 5);
	
	switch(drop_chance)
	{
		default: 
		{
			loot_weapon(p);
			empty();
		}
		break;
		
		case 1:
		{
			loot_armor(p);
			empty();
		}
		break;
		
		case 2:
		{
			loot_potion(p);
			empty();
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

int stealth_attack(player&p,enemy&e)
{
	srand(time(0));
	int choice, drop_chance, stealth;

	if((p.stealth - p.w.weight/5 - p.a.weight/2) > 0) stealth = p.stealth - p.w.weight/5 - p.a.weight/2; else stealth = 1;
	
	int chance = (rand () % stealth);
	
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
					e.HP = e.HP - (15 * p.w.damage);

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

		c = WHITE;
		setcolor();
	
		drop_chance = (rand() % 6);
	
		switch(drop_chance)
		{
			case 0: 
			{
				loot_weapon(p);
			}
			break;
		
			case 1:
			{
				loot_armor(p);
			}
			break;
			
			default:
			{
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

