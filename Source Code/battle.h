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
	}
}

int attack(player&p,enemy&e,string&playerdone,string&playerchance)
{
	int choice, landchance, chance, temp, damage_dealt, stressfac, stress, knock_fac;
	temp = e.HP;

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

	cout<<"(1/2x Damage, Causes Enemey Status Effect)"<<endl;

	c = WHITE;
	setcolor();
			
	cout<<"\n4. "<<p.w.r_attack;

	c = GREEN;
	setcolor();

	cout<<"(1/4x Damage, Activates Riposte For 2 Turns)"<<endl;

	c = WHITE;
	setcolor();

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
			playerdone = p.w.c_attack;

			if(((30 - (p.w.weight + e.sdodge)) + p.wh - stressfac * p.smDEX) > 1) chance = (30 - (p.w.weight + e.sdodge)) + p.wh - stressfac * p.smDEX; else chance = 1;
					
			landchance = (rand () % chance);
					
			switch(landchance)
			{
				default:
				{
					playerchance = "LANDED";

					e.HP = e.HP - 2 * (p.w.damage + p.damage);

					knock_fac = (rand () % 10);

					p.HP -= knock_fac * p.w.weight;

					p.stress += 4;
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
			playerdone = p.w.n_attack;

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
		break;

		case 3:
		{
			playerdone = p.w.s_attack;

			int effect_chance;

			if(((30 - (p.w.weight + e.sdodge)) + p.wh - stressfac * p.smDEX) > 1) chance = (30 - (p.w.weight + e.sdodge)) + p.wh - stressfac * p.smDEX; else chance = 1;
					
			landchance = (rand () % chance);
					
			switch(landchance)
			{
				default:
				{
					playerchance = "LANDED";

					if(((p.w.damage + p.damage)/2 - stressfac*p.smDM) > 0) e.HP = e.HP - (p.w.damage + p.damage)/2 + stressfac * p.smDM; else e.HP = e.HP;

					switch(p.w.type)
					{
						case HV_BLUDGE: case STAFF:
						{	
							effect_chance = (rand () % 2);

							if(effect_chance < 1)
							{
								e.stunned = 2;
							}
						}
						break;

						case HV_AXE: case HV_SWORD: case SWORD: case AXE: case SPEAR:
						{
							effect_chance = (rand () % 7);

							if(effect_chance < 2)
							{
								e.bleeding = 4;
							}						
						}
						break;

						case DAGGER:
						{
							effect_chance = (rand () % 10);

							if(effect_chance < 2)
							{
								e.poisoned = 4;
							}	
						}
						break;
					}
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

		case 4:
		{
			playerdone = p.w.r_attack;

			if(((30 - (p.w.weight + e.sdodge)) + p.wh - stressfac * p.smDEX) > 1) chance = (30 - (p.w.weight + e.sdodge)) + p.wh - stressfac * p.smDEX; else chance = 1;
					
			landchance = (rand () % chance);
					
			switch(landchance)
			{
				default:
				{
					playerchance = "LANDED";

					if(((p.w.damage + p.damage)/4 - stressfac*p.smDM) > 0) e.HP = e.HP - (p.w.damage + p.damage)/4 + stressfac * p.smDM; else e.HP = e.HP;

					p.riposte = 3;
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
	}


	c = WHITE;
	setcolor();
}

int ability(player&p,string&playerdone,string&playersuccess)
{
	system("cls");

	int temp_h = p.HP;

	if(p.race == "Orc")
	{
		if(p.ability_point > 0 && p.ability == false)
		{
			playerdone = "BERSERK";

			playersuccess = "SUCCESSFUL";

			p.STR *= 2;
			p.VIT *= 2;
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

	if(p.race == "Half-Elf")
	{
		if(p.ability_point > 0 && p.ability == false)
		{
			playerdone = "FAITH MIRACLE";

			playersuccess = "SUCCESSFUL";

			p.FAI *= 4;
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

	if(p.race == "Half-Orc")
	{
		if(p.ability_point > 0 && p.ability == false)
		{
			playerdone = "GIFT OF THE ORCS";

			playersuccess = "SUCCESSFUL";

			p.STR *= 2;
			p.ability_point --;
			p.ability = true;
		}

		else
		{
			playerdone = "GIFT OF THE ORCS";

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

			p.STA *= 4;
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

	if(p.race == "Elf")
	{
		if(p.ability_point > 0 && p.ability == false)
		{
			playerdone = "ELVEN MIRACLE";

			playersuccess = "SUCCESSFUL";

			p.INE *= 2;
			p.ability_point --;
			p.ability = true;
		}

		else
		{
			playerdone = "ELVEN MIRACLE";

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
	temp = p;
}

int ability_reverse(player&p,player&temp)
{
	int HP = p.HP, mana = p.mana, stress = p.stress;

	p = temp;

	p.setattributes();

	if(HP <= p.maxHP) p.HP = HP;
	if(stress <= p.stress_limit) p.stress = stress;
	if(mana <= p.maxM) p.mana = mana;
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
			cout<<"\n2. Stun : "<<m_stun<<" Mana"<<endl;
			cout<<"\n3. Confuse : "<<m_confuse<<" Mana"<<endl;
			cout<<"\n4. Fireball : "<<m_fireball<<" Mana"<<endl;
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
		break;
		
		default:
		{
			cout<<"\nWhich spell would you like?"<<endl;
			cout<<"\n1. Heal : "<<m_heal<<" Mana"<<endl;
			cout<<"\n2. Stun : "<<m_stun<<" Mana"<<endl;
			cout<<"\n3. Confuse : "<<m_confuse<<" Mana"<<endl;
			cout<<"\n4. Fireball : "<<m_fireball<<" Mana"<<endl;
			cout<<"\n5. Fire Storm : "<<m_firestorm<<" Mana"<<endl;
			cout<<"\n6. Cleanse Aura : "<<m_cleanse<<" Mana"<<endl;
			cout<<"\n7. Mana Increase by 100"<<endl;
			
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
				
				case 5:
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

				case 6:
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
				
				case 7:
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

int counterattack(player&p)
{
	srand(time(0));

	int shield_fac = (rand () % p.s.defense);

	if(p.w.dh == false && p.s.name != "No Shield" && p.s.name != "Intelligence Talisman" && p.s.name != "Warlock Talisman")
	{
		if(shield_fac >= (9*p.s.defense)/10)//90 Percent
		{
			return 3;
		}

		else if(shield_fac >= (8*p.s.defense)/10)//80 Percent
		{
			return 3;
		}

		else if(shield_fac >= (7*p.s.defense)/10)//70 Percent
		{
			return 3;
		}

		else if(shield_fac >= (6*p.s.defense)/10)//60 Percent
		{
			return 2;
		}

		else if(shield_fac >= (5*p.s.defense)/10)//50 Percent
		{
			return 2;
		}

		else if(shield_fac >= (4*p.s.defense)/10)//40 Percent
		{
			return 2;
		}

		else if(shield_fac >= (3*p.s.defense)/10)//30 Percent
		{
			return 1;
		}

		else if(shield_fac >= (2*p.s.defense)/10)//20 Percent
		{
			return 1;
		}

		else if(shield_fac >= (1*p.s.defense)/10)//10 Percent
		{
			return 0;
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

int enemy_attack(player&p, enemy&e, int check, int&enemychance, string&enemydoes, int&shield_effect)
{
	srand(time(0));

	int echoice, enemy_landchance, self_dodge, stressfac, stress;	

	self_dodge = (10 - p.a.weight)/4 + p.dodge;

	stress = (p.stress/5) + 1;

	stressfac = (rand () % stress);

	echoice = (rand () % 10);
			
	enemy_landchance = (rand () % self_dodge);

	int armor_chance, low_def, high_def;

	low_def = p.a.defense / 5;

	high_def = p.a.defense - low_def;

	armor_chance = (rand () % high_def) + low_def;

	int shield_percent = counterattack(p);

	shield_effect = (10 - shield_percent);

	if(e.stunned > 0)
	{ 
		//Nothing
	}
			
	else
	{
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
								if(armor_chance < (e.cdamage*shield_effect)/10)
								{
									p.HP = p.HP - (e.cdamage*shield_effect)/10 + armor_chance - stressfac * p.smHP;

									enemydoes = e.cattack;

									if(p.riposte > 0)
									{
										e.HP -= (e.cdamage*shield_effect)/10;
									}

									p.stress+=3;

									enemychance = 1;
								}
									
								else
								{
									if(p.stress > 0) p.stress -= 1;	

									enemydoes = e.cattack;

									enemychance = 3;
								}
							}
							break;
					
							default :
							{	
								if(armor_chance < (e.damage*shield_effect)/10)
								{
									p.HP = p.HP - (e.damage*shield_effect)/10 + armor_chance - stressfac * p.smHP;

									enemydoes = e.nattack;

									if(p.riposte > 0)
									{
										e.HP -= (e.damage*shield_effect)/10;
									}

									p.stress++;

									enemychance = 1;
								}
									
								else
								{
									enemychance = 3;

									enemydoes = e.nattack;

									if(p.stress > 0) p.stress -= 1;	 	
								}
							}
							break;
						}
					}
					break;
				
					default:
					{
						enemychance = 2;

						enemydoes = e.cattack;

						if(p.stress > 0) p.stress -= 1;	
					}
					break;
				}
			}
			break;
					
			case 1:
			{
				enemychance = 0;

				e.stunned = 3;
			}
			break;
					
			case 2:
			{	
				enemychance = 0;

				e.HP = e.HP - e.cdamage;
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
								if(armor_chance < (e.cdamage*shield_effect)/10)
								{
									p.HP = p.HP - (e.cdamage*shield_effect)/10 + armor_chance - stressfac * p.smHP;

									enemydoes = e.cattack;

									if(p.riposte > 0)
									{
										e.HP -= (e.cdamage*shield_effect)/10;
									}

									p.stress+=3;

									enemychance = 1;
								}
									
								else
								{
									if(p.stress > 0) p.stress -= 1;	

									enemydoes = e.cattack;

									enemychance = 3;
								}
							}
							break;
					
							default :
							{	
								if(armor_chance < (e.damage*shield_effect)/10)
								{
									p.HP = p.HP - (e.damage*shield_effect)/10 + armor_chance - stressfac * p.smHP;

									enemydoes = e.nattack;

									if(p.riposte > 0)
									{
										e.HP -= (e.damage*shield_effect)/10;
									}

									p.stress++;

									enemychance = 1;
								}
									
								else
								{
									if(p.stress > 0) p.stress -= 1;

									enemydoes = e.nattack;		

									enemychance = 3;
								}
							}
							break;
						}
					}
					break;
				
					default:
					{
						if(p.stress > 0) p.stress -= 1;	

						enemydoes = e.cattack;

						enemychance = 2;
					}
					break;
				}
			}
			break;
				
			case 4:
			{		
				e.HP = e.HP - 500;

				enemychance = 0;
			}
			break;
		}
	}	

	if(e.bleeding > 0)
	{
		e.HP -= (2*e.HP)/10;
	}

	if(e.poisoned > 0)
	{
		e.HP -= (4*e.HP)/10;
	}

	c = WHITE;
	setcolor();
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
}

int panicattack_reverse(player&p, player&temp)
{
	return 0;
}

int output_battle(player&p, string&playerdone, string&playerchance, string&enemydoes,int playerdoes, enemy&e, int enemychance, int check, int shield_effect)
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

		case 7:
		{
			if(playerchance == "SUCCESSFUL")
			{
				cout<<"\nThe Hydra, afraid of torchlight, cowers in fear, and thus gets stunned"<<endl;	
			}

			else
			{
				cout<<"\nYou do not have any torches left"<<endl;
			}
		}
	}

	if(e.stunned <= 0)
	{
		switch(check)
		{
			case 0:
			{
				cout<<"\n"<<e.name<<" used "<<enemydoes;

				switch(enemychance)
				{
					case 1:
					{
						cout<<" and it";

						c = RED;
						setcolor();

						cout<<" LANDED"<<endl;

						c = WHITE;
						setcolor();
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
			break;

			case 1:
			{
				cout<<"\n"<<e.name<<" becomes";

				c = GREEN;
				setcolor();

				cout<<" STUNNED"<<endl;

				c = WHITE;
				setcolor();
			}
			break;

			case 2:
			{
				cout<<"\n"<<e.name<<" is";

				c = GREEN;
				setcolor();

				cout<<" CONFUSED";

				c = WHITE;
				setcolor();

				cout<<", and thus hits itself"<<endl;
			}
			break;

			case 3:
			{
				cout<<"\n"<<e.name<<" is hit with the";

				c = GREEN;
				setcolor();

				cout<<" FIREBALL";

				c = WHITE;
				setcolor();

				cout<<" and used "<<enemydoes;

				switch(enemychance)
				{
					case 1:
					{
						cout<<" and it";

						c = RED;
						setcolor();

						cout<<" LANDED"<<endl;

						c = WHITE;
						setcolor();
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
			break;

			case 4:
			{
				cout<<"\n"<<e.name<<" is trapped in the";

				c = GREEN;
				setcolor();

				cout<<" FIRE STORM"<<endl;

				c = WHITE;
				setcolor();
			}	
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

		cout<<" causing it to lose 20 percent of its HP"<<endl;

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

		cout<<" causing it to lose 40 percent of its HP"<<endl;

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

	if(p.w.dh == false && p.s.name != "No Shield" && p.s.name != "Intelligence Talisman" && p.s.name != "Warlock Talisman")
	{
		cout<<"\nYour shield defends you by ";
		c = GREEN;
		setcolor();

		cout<<(10-shield_effect)*10;

		c = WHITE;
		setcolor();

		cout<<" percent"<<endl;
	}
}

int battle(player&p,enemy&e)
{
	srand(time(0));
	
	int dead=0;
	
	int drop_chance, check=0, choice, flee_chance, playerdoes, shield_effect;
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
	int enemychance;//0 = Nothing, 1 = Landed, 2 = Missed, 3 = Deflected
	
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

						e.stunned = 0;
						e.bleeding = 0;
						e.poisoned = 0;

						return 5;
					}
					break;
				}
			}
		}

		playerdoes = choice;

		//Enemy move
		enemy_attack(p,e,check,enemychance,enemydoes,shield_effect);

		system("cls");

		display_battlestats(p,e);

		output_battle(p,playerdone, playerchance, enemydoes, playerdoes, e, enemychance, check, shield_effect);
			
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

