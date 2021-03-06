#pragma once

#include"resources.h"
#include"loot.h"
#include"MA.h"

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

	return 0;
}

int attack_names(player&p)
{
	switch(p.w.type)
	{
		case HV_BLUDGE:
		{
			p.w.c_attack = "BLUDGEON";
			p.w.n_attack = "CRUSH";
			p.w.s_attack = "STUNNING BLOW";
			p.w.r_attack = "RETRIBUTION";
		}
		break;

		case HV_AXE: case AXE:
		{
			p.w.c_attack = "WICKED HACK";
			p.w.n_attack = "BREAKING STRIKE";
			p.w.s_attack = "BLEEDING SWIPE";
			p.w.r_attack = "RIPOSTE SWING";
		}
		break;

		case HV_SWORD: case SWORD:
		{
			p.w.c_attack = "SMITE";
			p.w.n_attack = "SWORD SWIPE";
			p.w.s_attack = "BLEEDING SWING";
			p.w.r_attack = "COUNTER";
		}
		break;

		case SPEAR:
		{
			p.w.c_attack = "LUNGE";
			p.w.n_attack = "SPEAR STRIKE";
			p.w.s_attack = "BLEEDING THROW";
			p.w.r_attack = "COUNTER-LUNGE";
		}
		break;

		case DAGGER:
		{
			p.w.c_attack = "DAGGER DASH";
			p.w.n_attack = "STAB";
			p.w.s_attack = "POISONOUS DAGGER";
			p.w.r_attack = "COUNTER DASH";
		}
		break;

		case STAFF:
		{
			p.w.c_attack = "STRIKE";
			p.w.n_attack = "PATIENT HIT";
			p.w.s_attack = "STUNNING BLOW";
			p.w.r_attack = "MEDITATED STRIKE";
		}
		break;

		case HANDS:
		{
			p.w.c_attack = "FOCUS PUNCH";
			p.w.n_attack = "JAB";
			p.w.s_attack = "STUNNING UPPERCUT";
			p.w.r_attack = "MEDITATED PUNCH";
		}
		break;
	}

	return 0;
}

int assign_crit(player&p)
{
	int crit = 0;

	if(p.DEX >= 50)
	{
		crit = 6;
	}

	else if(p.DEX >= 40)
	{
		crit = 8;
	}

	else if(p.DEX >= 30)
	{
		crit = 10;
	}

	else if(p.DEX >= 20)
	{
		crit = 12;
	}

	else if(p.DEX >= 10)
	{
		crit = 14;
	}

	else 
	{
		crit = 16;
	}

	return crit;
}

int attack(player&p,enemy&e)
{
	int choice, landchance, chance, temp, stressfac, stress, knock_fac, crit_chance, crit, crit_mod, damage = 0;

	int e_temphealth = e.HP;

	attack_names(p);
	
	cout<<"\nWhat would you like to do?"<<endl;
	
	cout<<"\n1. "<<p.w.c_attack;

	c = GREEN;
	setcolor();

	cout<<"(2x Damage, High Knockback, High Stress Add)"<<endl;

	c = WHITE;
	setcolor();

	cout<<"\n2. "<<p.w.n_attack<<endl;

	cout<<"\n3. "<<p.w.s_attack;

	c = GREEN;
	setcolor();

	cout<<"(1/10x Damage, Causes Enemey Status Effect)"<<endl;

	c = WHITE;
	setcolor();
			
	cout<<"\n4. "<<p.w.r_attack;

	c = GREEN;
	setcolor();

	cout<<"(1/10x Damage, Activates Riposte For 2 Turns)"<<endl;

	c = WHITE;
	setcolor();

	cout<<"\nInput Choice : ";
	cin>>choice;

	system("cls");

	if(p.level > 0)
	{
		stress = (p.stress/5) + 1;

		stressfac = (rand () % stress);

	}

	else stressfac = 0;

	crit = assign_crit(p);

	crit_chance = (rand () % crit);

	display_battlestats(p,e);

	if(crit_chance == 0)
	{
		crit_mod = 2;
		p.crit = true;
	}

	else
	{
		crit_mod = 1;
		p.crit = false;
	}

	if((crit_mod * (p.w.damage + p.damage) - stressfac * p.smDM) > 0) damage = crit_mod * (p.w.damage + p.damage) - stressfac * p.smDM / 2; else damage = 0;

	if(((30 - p.w.weight)/2 + p.wh - stressfac * p.smDEX) > 0) chance = (30 - p.w.weight)/2 + p.wh - stressfac * p.smDEX / 2; else chance = 1;

	switch(choice)
	{
		case 1:
		{	
			p.playerdone = p.w.c_attack;
					
			landchance = (rand () % chance);
					
			switch(landchance)
			{
				default:
				{
					p.playerchance = "LANDED";

					e.HP -= damage * 2;

					knock_fac = (rand () % 30);

					p.HP -= (knock_fac * p.w.weight)/p.wh;

					p.stress += 4;
				}
				break;
						
				case 0:
				{
					p.playerchance = "MISSED";
					p.stress++;
				}
				break;
			}
		}
		break;

		case 2:
		{
			p.playerdone = p.w.n_attack;
					
			landchance = (rand () % chance);
					
			switch(landchance)
			{
				default:
				{
					p.playerchance = "LANDED";

					e.HP -= damage;
				}
				break;
						
				case 0:
				{
					p.playerchance = "MISSED";
					p.stress++;
				}
				break;
			}	
		}
		break;

		case 3:
		{
			p.playerdone = p.w.s_attack;

			int effect_chance;
					
			landchance = (rand () % chance);
					
			switch(landchance)
			{
				default:
				{
					p.playerchance = "LANDED";

					e.HP -= damage/10;

					switch(p.w.type)
					{
						case HV_BLUDGE: case STAFF:
						{	
							e.stunned = 2;
						}
						break;

						case HV_AXE: case HV_SWORD: case SWORD: case AXE: case SPEAR:
						{
							e.bleeding = 2;				
						}
						break;

						case DAGGER:
						{
							e.poisoned = 2;
						}
						break;
					}
				}
				break;
						
				case 0:
				{
					p.playerchance = "MISSED";
					p.stress++;
				}
				break;
			}	
		}
		break;

		case 4:
		{
			p.playerdone = p.w.r_attack;
					
			landchance = (rand () % chance);
					
			switch(landchance)
			{
				default:
				{
					p.playerchance = "LANDED";

					e.HP -= damage/10;

					p.riposte = 3;
				}
				break;
						
				case 0:
				{
					p.playerchance = "MISSED";
					p.stress++;
				}
				break;
			}	
		}
		break;
	}

	e.damage_taken = e_temphealth - e.HP;

	c = WHITE;
	setcolor();

	return 0;
}

int counterattack(player&p)
{
	srand(time(0));

	int shield_fac = (rand () % p.s.defense);

	if(p.w.dh == false && p.s.name != "No Shield" && p.s.name != "Intelligence Talisman" && p.s.name != "Warlock Talisman")
	{
		if(shield_fac >= (9*p.s.defense)/10)//90 Percent
		{
			return 5;
		}

		else if(shield_fac >= (8*p.s.defense)/10)//80 Percent
		{
			return 4;
		}

		else if(shield_fac >= (7*p.s.defense)/10)//70 Percent
		{
			return 4;
		}

		else if(shield_fac >= (6*p.s.defense)/10)//60 Percent
		{
			return 3;
		}

		else if(shield_fac >= (5*p.s.defense)/10)//50 Percent
		{
			return 3;
		}

		else if(shield_fac >= (4*p.s.defense)/10)//40 Percent
		{
			return 2;
		}

		else if(shield_fac >= (3*p.s.defense)/10)//30 Percent
		{
			return 2;
		}

		else if(shield_fac >= (2*p.s.defense)/10)//20 Percent
		{
			return 1;
		}

		else if(shield_fac >= (1*p.s.defense)/10)//10 Percent
		{
			return 1;
		}

		else //0 Percent
		{
			return 0;
		}
	}

	else
	{
		return 0;
	}
}

int enemy_attack(player&p, enemy&e, int&shield_effect)
{
	srand(time(0));

	int echoice, enemy_landchance, self_dodge, stressfac, stress, shield_defense, p_temphealth = p.HP, temp_health = e.HP;	

	self_dodge = (10 - p.a.weight)/7 + p.dodge + (30 - p.w.weight)/25 + (4 - p.s.weight)/3;

	stress = (p.stress/5) + 1;

	stressfac = (rand () % stress);

	echoice = (rand () % 14);
			
	enemy_landchance = (rand () % self_dodge);

	int armor_chance, low_def, high_def;

	low_def = p.a.defense / 5;

	high_def = 4*(p.a.defense);

	armor_chance = (rand () % high_def) + low_def;

	shield_defense = (rand () % p.s.defense);

	armor_chance += shield_defense;

	int shield_percent = counterattack(p);

	shield_effect = (10 - shield_percent);

	if(e.stunned > 0)
	{ 
		//Nothing
	}
			
	else
	{
		if(enemy_landchance == 0 || enemy_landchance == 1 || enemy_landchance == 2)
		{
			switch(echoice)
			{
				case 0:
				{
					if(armor_chance < (e.cdamage*shield_effect)/10)
					{
						p.HP = p.HP - (e.cdamage*shield_effect)/10 + armor_chance - stressfac * p.smHP;

						e.enemydoes = e.cattack;

						if(p.riposte > 0)
						{
							e.HP -= (e.cdamage*shield_effect)/50;
						}

						p.stress+=3;

						e.enemychance = 1;
					}
									
					else
					{
						if(p.stress > 0) p.stress -= 1;	

						e.enemydoes = e.cattack;

						e.enemychance = 3;
					}
				}
				break;
					
				default:
				{	
					if(armor_chance < (e.damage*shield_effect)/10)
					{
						p.HP = p.HP - (e.damage*shield_effect)/10 + armor_chance - stressfac * p.smHP;

						e.enemydoes = e.nattack;

						if(p.riposte > 0)
						{
							e.HP -= (e.damage*shield_effect)/50;
						}

						p.stress++;

						e.enemychance = 1;
					}
									
					else
					{
						e.enemychance = 3;

						e.enemydoes = e.nattack;

						if(p.stress > 0) p.stress -= 1;	 	
					}
				}
				break;
			}
		}

		else
		{
			e.enemychance = 2;

			e.enemydoes = e.cattack;

			if(p.stress > 0) p.stress -= 5;	
		}
	}	

	if(e.bleeding > 0)
	{
		e.HP -= (5*e.HP)/100;
	}

	if(e.poisoned > 0)
	{
		e.HP -= (1*e.HP)/10;
	}

	p.damage_taken = p_temphealth - p.HP;
	p.armor_defence = armor_chance;

	c = WHITE;
	setcolor();

	return 0;
}

int panicattack_setup(player&p, player&temp)
{
	return 0;
}

int panicattack(player&p)
{
	if(p.stress >= p.stress_limit)
	{
		c = RED;
		setcolor();

		cout<<"\nYou have a panic attack, and thus die of stress"<<endl;

		p.HP = 0;
	}

	c = WHITE;
	setcolor();

	return 0;
}

int panicattack_reverse(player&p, player&temp)
{
	return 0;
}

int output_battle(player&p, enemy&e, int check, int shield_effect)
{
	switch(p.playerdoes)
	{
		case 1:
		{
			if(p.crit == true && p.playerchance != "MISSED")
			{
				c = GREEN;
				setcolor();

				cout<<"\n[CRIT] ";

				c = WHITE;
				setcolor();
			}

			else
			{
				cout<<"\n";
			}

			cout<<"You used "<<p.playerdone<<" and it ";

			if(p.playerchance == "LANDED")
			{
				c = GREEN;
				setcolor();
			}

			else
			{
				c = RED;
				setcolor();
			}

			cout<<p.playerchance;

			c = WHITE;
			setcolor();

			if(e.damage_taken > 0)
			{
				cout<<" doing "<<e.damage_taken<<" damage"<<endl;
			}

			else
			{
				cout<<endl;
			}
		}
		break;

		case 2:
		{
			cout<<"\nYou used "<<p.playerdone<<" and it was ";

			if(p.playersuccess == "SUCCESSFUL")
			{
				c = GREEN;
				setcolor();
			}

			else
			{
				c = RED;
				setcolor();
			}

			cout<<p.playersuccess;

			c = WHITE;
			setcolor();

			if(e.damage_taken > 0)
			{
				cout<<" doing "<<e.damage_taken<<" damage"<<endl;
			}

			else
			{
				cout<<endl;
			}
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
			cout<<"\nYou used "<<p.playerdone<<" and it was ";

			if(p.playersuccess == "SUCCESSFUL")
			{
				c = GREEN;
				setcolor();
			}

			else
			{
				c = RED;
				setcolor();
			}

			cout<<p.playersuccess<<endl;

			c = WHITE;
			setcolor();
		}
		break;

		case 6:
		{
			if(p.playerchance == "SUCCESSFUL")
			{
				cout<<"\nYou climb upon the Titan, and so you can attack it better. Your attack increases by 25"<<endl;	
			}

			else
			{
				cout<<"\nYou attempt to climb the Titan fails, and the Titan throws you off, damaging you by 50"<<endl;
			}
		}
		break;

		case 7:
		{
			cout<<"\nYou climb down from the Titan. Your attack returns to normal"<<endl;	
		}
	}

	if(check == 0)
	{
		//Nothing
	}

	else if(check == 1)
	{
		//Nothing
	}

	else if(check == 2)
	{
		cout<<"\n"<<e.name<<" is";

		c = GREEN;
		setcolor();

		cout<<" CONFUSED";

		c = WHITE;
		setcolor();

		cout<<", and thus hits itself"<<endl;
	}

	else if(check == 3)
	{
		cout<<"\n"<<e.name<<" is hit with the";

		c = GREEN;
		setcolor();

		cout<<" FIREBALL";

		c = WHITE;
		setcolor();
	}

	else if(check == 4)
	{
		cout<<"\n"<<e.name<<" is hit by the";

		c = GREEN;
		setcolor();

		cout<<" FIRE RAM";

		c = WHITE;
		setcolor();

		cout<<" thus making it dazed"<<endl;
	}

	else if(check == 5)
	{
		cout<<"\n"<<e.name<<" is hit by the";

		c = GREEN;
		setcolor();

		cout<<" FIRE HOUND";

		c = WHITE;
		setcolor();
	}

	else if(check == 6)
	{
		cout<<"\n"<<e.name<<" is trapped in the";

		c = GREEN;
		setcolor();

		cout<<" FIRE STORM"<<endl;

		c = WHITE;
		setcolor();

		cout<<" thus making it dazed"<<endl;
	}

	if(e.stunned <= 0)
	{
		if(e.boss == true && (e.enemydoes == "bm11" || e.enemydoes == "bm12" || e.enemydoes == "bm21" || e.enemydoes == "bm22"))
		{
			if(e.enemydoes == "bm11")
			{
				cout<<"\n"<<e.name<<" used SWING and it";

				c = RED;
				setcolor();

				cout<<" LANDED";

				c = WHITE;
				setcolor();

				cout<<" doing "<<p.damage_taken<<" damage"<<endl;
			}

			else if(e.enemydoes == "bm12")
			{
				cout<<"\n"<<e.name<<" used TITANITE SHIELD and";

				c = RED;
				setcolor();

				cout<<" REVERSED";

				c = WHITE;
				setcolor();

				cout<<" all the damage of your attack"<< endl;
			}

			else if(e.enemydoes == "bm21")
			{

			}

			else if(e.enemydoes == "bm22")
			{

			}
		}

		else
		{
			cout<<"\n"<<e.name<<" used "<<e.enemydoes;

			switch(e.enemychance)
			{
				case 1:
				{
					cout<<" and it";

					c = RED;
					setcolor();

					cout<<" LANDED";

					c = WHITE;
					setcolor();

					cout<<" doing "<<p.damage_taken<<" damage"<<endl;
				}
				break;

				case 2:
				{
					cout<<" but you";

					c = GREEN;
					setcolor();

					cout<<" DODGED";

					c = WHITE;
					setcolor();

					cout<<" it"<<endl;
				}
				break;

				case 3:
				{
					cout<<" but your armor";

					c = GREEN;
					setcolor();

					cout<<" DEFLECTED";

					c = WHITE;
					setcolor();

					cout<<" it"<<endl;
				}
				break;
			}	

			c = WHITE;
			setcolor();
		}
	}

	else
	{
		cout<<"\n"<<e.name<<" is";

		c = GREEN;
		setcolor();

		cout<<" STUNNED"<<endl;

		c = WHITE;
		setcolor();

		e.stunned--;
	}

	if(e.bleeding > 0)
	{
		cout<<"\nThe "<<e.name;

		c = GREEN;
		setcolor();

		cout<<" BLEEDS";

		c = WHITE;
		setcolor();

		cout<<" causing it to lose 5 percent of its HP"<<endl;

		e.bleeding--;
	}

	if(e.poisoned > 0)
	{
		cout<<"\nThe "<<e.name<<" is";

		c = GREEN;
		setcolor();

		cout<<" POISONED";

		c = WHITE;
		setcolor();

		cout<<" causing it to lose 10 percent of its HP"<<endl;

		e.poisoned--;
	}

	if(p.riposte > 0)
	{
		cout<<"\nYour";

		c = GREEN;
		setcolor();

		cout<<" RIPOSTE";

		c = WHITE;
		setcolor();

		cout<<" reflects damage on the enemy"<<endl;

		p.riposte--;
	}

	
	if(p.damage_taken > 0 && check != 10)
	{
		cout<<"\nYour armor defends you from ";

		c = GREEN;
		setcolor();

		cout<<p.armor_defence;

		c = WHITE;
		setcolor();

		cout<<" damage"<<endl;
	}

	if(p.w.dh == false && p.s.name != "No Shield" && p.s.name != "Intelligence Talisman" && p.s.name != "Warlock Talisman" && p.damage_taken > 0)
	{
		cout<<"\nYour shield defends you by ";
		c = GREEN;
		setcolor();

		cout<<(10-shield_effect)*10;

		c = WHITE;
		setcolor();

		cout<<" percent"<<endl;
	}

	return 0;
}

int battle(player&p,enemy&e)
{
	srand(time(0));
	
	int dead=0;
	
	int drop_chance, check=0, choice, flee_chance, shield_effect, choice_ability;
	player temp_ability, temp_panic;

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
		cout<<"\n5. Flee"<<endl;
			
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

						e.stunned = 0;
						e.bleeding = 0;
						e.poisoned = 0;

						empty();

						return 5;
					}
					break;
				}
			}
		}

		p.playerdoes = choice;

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
			empty();
			
			dead=0;
			break;
		}

		line();
	}

	ability_reverse(p,temp_ability);
	panicattack_reverse(p, temp_panic);
	
	system("cls");

	e.stunned = 0;
	e.bleeding = 0;
	e.poisoned = 0;
	
	drop_chance = (rand() % 5);
	
	switch(drop_chance)
	{
		case 0: 
		{
			loot_weapon(p);
			empty();
		}
		break;
		
		default:
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

		case 3:
		{
			loot_shield(p);
			empty();
		}
		break;
	}
	
	cout<<"\nYou gained XP"<<endl;
	
	p.xp += 50 * ((e.damage/40) + (e.maxHP/400));
	
	cout<<"\nXP : "<<p.xp<<endl;
	
	cout<<"\nThe enemy dropped money"<<endl;
	
	p.i.money += 50 * ((e.damage/40) + (e.maxHP/400));
	
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
	
		drop_chance = (rand() % 4);
	
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

int wolf_battle(player&p,enemy&e)
{
	e.name = "Wolf";
	e.damage = 7;
	e.cdamage = 20;
	e.HP = 50;
	e.maxHP = e.HP;

	e.nattack = "BITE";
	e.cattack = "FANGED FURY";

	srand(time(0));
	
	int dead=0;
	
	int drop_chance, check=0, choice, flee_chance, shield_effect, choice_ability;
	player temp_ability, temp_panic;

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
				check = spell1(p,e);
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

			default:
			{
				//Nothing
			}
		}

		if(choice == 1 || choice == 2 || choice == 3) p.playerdoes = choice;

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
			empty();
			
			dead=0;
			break;

			c = WHITE;
			setcolor();
		}

		line();
	}

	return 0;
}

