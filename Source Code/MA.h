#pragma once

#include"resources.h"
#include"loot.h"

using namespace std;

int ability(player&p)
{
	system("cls");

	if(p.race == "Orc")
	{
		if(p.ability_point > 0 && p.ability == false)
		{
			p.playerdone = "BERSERK";

			p.playersuccess = "SUCCESSFUL";

			p.STR *= 2;
			p.VIT *= 2;
			p.ability_point --;
			p.ability = true;
		}

		else
		{
			p.playerdone = "BERSERK";

			p.playersuccess = "UNSUCCESSFUL";
			p.stress++;
		}
	}

	if(p.race == "Half-Elf")
	{
		if(p.ability_point > 0 && p.ability == false)
		{
			p.playerdone = "FAITH MIRACLE";

			p.playersuccess = "SUCCESSFUL";

			p.FAI *= 4;
			p.ability_point --;
			p.ability = true;
		}

		else
		{
			p.playerdone = "FAITH MIRACLE";

			p.playersuccess = "UNSUCCESSFUL";
			p.stress++;
		}	
	}

	if(p.race == "Half-Orc")
	{
		if(p.ability_point > 0 && p.ability == false)
		{
			p.playerdone = "GIFT OF THE ORCS";

			p.playersuccess = "SUCCESSFUL";

			p.STR *= 4;
			p.ability_point --;
			p.ability = true;
		}

		else
		{
			p.playerdone = "GIFT OF THE ORCS";

			p.playersuccess = "UNSUCCESSFUL";
			p.stress++;
		}
	}

	if(p.race == "Half-Lizard")
	{
		if(p.ability_point > 0 && p.ability == false)
		{
			p.playerdone = "SHADOW STEP";

			p.playersuccess = "SUCCESSFUL";

			p.STA *= 4;
			p.ability_point --;
			p.ability = true;
		}

		else
		{
			p.playerdone = "SHADOW STEP";

			p.playersuccess = "UNSUCCESSFUL";
			p.stress++;
		}	
	}

	if(p.race == "Elf")
	{
		if(p.ability_point > 0 && p.ability == false)
		{
			p.playerdone = "ELVEN MIRACLE";

			p.playersuccess = "SUCCESSFUL";

			p.INE *= 4;
			p.ability_point --;
			p.ability = true;
		}

		else
		{
			p.playerdone = "ELVEN MIRACLE";

			p.playersuccess = "UNSUCCESSFUL";
			p.stress++;
		}	
	}

	p.setattributes();

	c = WHITE;
	setcolor();

	return 0;
}

int ability_setup(player&p,player&temp)
{
	temp = p;

	return 0;
}

int ability_reverse(player&p,player&temp)
{
	int HP = p.HP, mana = p.mana, stress = p.stress, ability_point = p.ability_point;

	p = temp;

	p.setattributes();

	if(HP <= p.maxHP) p.HP = HP;
	if(stress <= p.stress_limit) p.stress = stress;
	if(mana <= p.maxM) p.mana = mana;
	p.ability_point = ability_point;
	p.ability = false;

	return 0;
}

int weapon_ability(player&p, enemy&e)
{
	int temp_health = e.HP;

	switch(p.w.type)
	{
		case HV_BLUDGE:
		{
			if(p.ability_point > 0 && p.wability == false)
			{
				p.playerdone = "BLUDGEONING STRIKE";
				p.playersuccess = "SUCCESSFUL";

				e.HP -= 3*(p.w.damage + p.damage);
				e.stunned = 2;

				p.ability_point--;
			}

			else
			{
				p.playerdone = "BLUDGEONING STRIKE";
				p.playersuccess = "UNSUCCESSFUL";
				p.stress++;
			}	
		}
		break;

		case HV_SWORD:
		{
			if(p.ability_point > 0 && p.wability == false)
			{
				p.playerdone = "POWER SWING";
				p.playersuccess = "SUCCESSFUL";

				e.HP -= 3*(p.w.damage + p.damage);
				e.bleeding = 2;

				p.ability_point--;
			}

			else
			{
				p.playerdone = "POWER SWING";
				p.playersuccess = "UNSUCCESSFUL";
				p.stress++;
			}	
		}
		break;

		case HV_AXE:
		{
			if(p.ability_point > 0 && p.wability == false)
			{
				p.playerdone = "BRUTAL SWING";
				p.playersuccess = "SUCCESSFUL";

				e.HP -= 2.5*(p.w.damage + p.damage);
				e.bleeding = 3;

				p.ability_point--;
			}

			else
			{
				p.playerdone = "BRUTAL SWING";
				p.playersuccess = "UNSUCCESSFUL";
				p.stress++;
			}	
		}
		break;

		case SWORD:
		{
			if(p.ability_point > 0 && p.wability == false)
			{
				p.playerdone = "KNIGHT'S JAB";
				p.playersuccess = "SUCCESSFUL";

				e.HP -= 2*(p.w.damage + p.damage);
				e.bleeding = 4;

				p.ability_point--;
			}

			else
			{
				p.playerdone = "KNIGHT'S JAB";
				p.playersuccess = "UNSUCCESSFUL";
				p.stress++;
			}	
		}
		break;

		case SPEAR:
		{
			if(p.ability_point > 0 && p.wability == false)
			{
				p.playerdone = "ADEPT THROW";
				p.playersuccess = "SUCCESSFUL";

				e.HP -= 2*(p.w.damage + p.damage);
				e.stunned = 4;

				p.ability_point--;
			}

			else
			{
				p.playerdone = "ADEPT THROW";
				p.playersuccess = "UNSUCCESSFUL";
				p.stress++;
			}	
		}
		break;

		case AXE:
		{
			if(p.ability_point > 0 && p.wability == false)
			{
				p.playerdone = "SLEIGHT OF HAND";
				p.playersuccess = "SUCCESSFUL";

				e.HP -= 2*(p.w.damage + p.damage);
				e.bleeding += 2;
				e.stunned = 2;

				p.ability_point--;
			}

			else
			{
				p.playerdone = "SLEIGHT OF HAND";
				p.playersuccess = "UNSUCCESSFUL";
				p.stress++;
			}	
		}
		break;

		case DAGGER:
		{
			if(p.ability_point > 0 && p.wability == false)
			{
				p.playerdone = "POISONOUS JAB";
				p.playersuccess = "SUCCESSFUL";

				e.HP -= 2*(p.w.damage + p.damage);
				e.poisoned = 4;

				p.ability_point--;
			}

			else
			{
				p.playerdone = "POISONOUS JAB";
				p.playersuccess = "UNSUCCESSFUL";
				p.stress++;
			}	
		}
		break;

		case STAFF:
		{
			if(p.ability_point > 0 && p.wability == false)
			{
				p.playerdone = "MEDITATIVE BLOW";
				p.playersuccess = "SUCCESSFUL";

				e.HP -= 3*(p.w.damage + p.damage);
				e.stunned = 4;

				p.ability_point--;
			}

			else
			{
				p.playerdone = "MEDITATIVE BLOW";
				p.playersuccess = "UNSUCCESSFUL";
				p.stress++;
			}	
		}
		break;
	}

	e.damage_taken = temp_health - e.HP;

	return 0;
}

int spell1(player&p,enemy&e)
{
	int spellchoice, check = 0; 
	
	int m_heal = 100;
	int m_cleanse = 150;
	int m_stun = 500;
	int m_confuse = 750;
	int m_fireball = 150;
	int m_firestorm = 1000;

	e.damage_taken = 0;
	
	switch(p.spellno)
	{
		case 0:
		{
			p.playerdone  = "NO MAGIC";	
			p.playersuccess = "UNSUCCESSFUL";
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
					p.playerdone = "HEAL";

					if(p.mana>=m_heal)
					{
						p.playersuccess = "SUCCESSFUL";

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
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;	
					}
				}
				break;

				case 2:
				{
					p.playerdone = "CLEANSE AURA";

					if(p.mana >= m_cleanse)
					{
						p.playersuccess = "SUCCESSFUL";

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
						p.playersuccess = "UNSUCCESSFUL";
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
					p.playerdone = "HEAL";

					if(p.mana>=m_heal)
					{
						p.playersuccess = "SUCCESSFUL";

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
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 2:
				{
					p.playerdone = "STUN";

					if(p.mana >= m_stun)
					{
						p.playersuccess = "SUCCESSFUL";
						check = 1;
						p.mana = p.mana - m_stun;
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;

				case 3:
				{
					p.playerdone = "CLEANSE AURA";

					if(p.mana >= m_cleanse)
					{
						p.playersuccess = "SUCCESSFUL";

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
						p.playersuccess = "UNSUCCESSFUL";
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
					p.playerdone = "HEAL";

					if(p.mana>=m_heal)
					{
						p.playersuccess = "SUCCESSFUL";

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
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 2:
				{
					p.playerdone = "STUN";

					if(p.mana >=m_stun)
					{
						p.playersuccess = "SUCCESSFUL";
						check = 1;
						p.mana = p.mana - m_stun;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 3:
				{
					p.playerdone = "CONFUSE";

					if(p.mana >= m_confuse)
					{
						p.playersuccess = "SUCCESSFUL";

						check = 2;
						p.mana = p.mana - m_confuse;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 4:
				{
					p.playerdone = "CLEANSE AURA";

					if(p.mana >= m_cleanse)
					{
						p.playersuccess = "SUCCESSFUL";

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
						p.playersuccess = "UNSUCCESSFUL";
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
					p.playerdone = "HEAL";

					if(p.mana >= m_heal)
					{
						p.playersuccess = "SUCCESSFUL";

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
						p.playersuccess = "UNSUCCESSFUL";	
						p.stress++;
					}
				}
				break;

				case 2:
				{
					p.playerdone = "STUN";

					if(p.mana >= m_stun)
					{
						p.playersuccess = "SUCCESSFUL";
						check = 1;
						p.mana = p.mana - m_stun;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 3:
				{
					p.playerdone = "CONFUSE";

					if(p.mana >= m_confuse)
					{
						p.playersuccess = "SUCCESSFUL";
						check = 2;
						p.mana = p.mana - m_confuse;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 4:
				{
					p.playerdone = "FIREBALL";

					if(p.mana >= m_fireball)
					{
						p.playersuccess = "SUCCESSFUL";

						check = 3;
						p.mana = p.mana - m_fireball;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;

				case 5:
				{
					p.playerdone = "CLEANSE AURA";

					if(p.mana >= m_cleanse)
					{
						p.playersuccess = "SUCCESSFUL";

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
						p.playersuccess = "UNSUCCESSFUL";
					}
				}
				break;
				
				case 6:
				{
					p.playerdone = "MANA BOOST";

					p.playersuccess = "SUCCESSFUL";

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
			cout<<"\n2. Stun : "<<m_stun<<" Mana"<<endl;
			cout<<"\n3. Confuse : "<<m_confuse<<" Mana"<<endl;
			cout<<"\n4. Fireball : "<<m_fireball<<" Mana"<<endl;
			cout<<"\n5. Conjure Fire Ram : "<<2*m_fireball<<" Mana"<<endl;
			cout<<"\n6. Cleanse Aura : "<<m_cleanse<<" Mana"<<endl;
			cout<<"\n7. Mana Increase by 100"<<endl;
			
			cout<<"\nInput Choice : ";
			cin>>spellchoice;

			system("cls");
			
			switch(spellchoice)
			{
				case 1:
				{
					p.playerdone = "HEAL";

					if(p.mana >= m_heal)
					{
						p.playersuccess = "SUCCESSFUL";

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
						p.playersuccess = "UNSUCCESSFUL";	
						p.stress++;
					}
				}
				break;

				case 2:
				{
					p.playerdone = "STUN";

					if(p.mana >= m_stun)
					{
						p.playersuccess = "SUCCESSFUL";
						check = 1;
						p.mana = p.mana - m_stun;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 3:
				{
					p.playerdone = "CONFUSE";

					if(p.mana >= m_confuse)
					{
						p.playersuccess = "SUCCESSFUL";
						check = 2;
						p.mana = p.mana - m_confuse;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 4:
				{
					p.playerdone = "FIREBALL";

					if(p.mana >= m_fireball)
					{
						p.playersuccess = "SUCCESSFUL";

						check = 3;
						p.mana = p.mana - m_fireball;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;

				case 5:
				{
					p.playerdone = "CONJURE FIRE RAM";

					if(p.mana >= 2*m_fireball)
					{
						p.playersuccess = "SUCCESSFUL";

						check = 4;

						p.mana = p.mana - m_fireball;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;

				case 6:
				{
					p.playerdone = "CLEANSE AURA";

					if(p.mana >= m_cleanse)
					{
						p.playersuccess = "SUCCESSFUL";

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
						p.playersuccess = "UNSUCCESSFUL";
					}
				}
				break;
				
				case 7:
				{
					p.playerdone = "MANA BOOST";

					p.playersuccess = "SUCCESSFUL";

					if(p.mana + 100<p.maxM) p.mana = p.mana + 100; else p.mana = p.maxM;
				}
				break;
			}	
		}
		break;

		case 6:
		{
			cout<<"\nWhich spell would you like?"<<endl;
			cout<<"\n1. Heal : "<<m_heal<<" Mana"<<endl;
			cout<<"\n2. Stun : "<<m_stun<<" Mana"<<endl;
			cout<<"\n3. Confuse : "<<m_confuse<<" Mana"<<endl;
			cout<<"\n4. Fireball : "<<m_fireball<<" Mana"<<endl;
			cout<<"\n5. Conjure Fire Ram : "<<2*m_fireball<<" Mana"<<endl;
			cout<<"\n6. Conjure Fire Hound : "<<3*m_fireball<<" Mana"<<endl;
			cout<<"\n7. Cleanse Aura : "<<m_cleanse<<" Mana"<<endl;
			cout<<"\n8. Mana Increase by 100"<<endl;
			
			cout<<"\nInput Choice : ";
			cin>>spellchoice;

			system("cls");
			
			switch(spellchoice)
			{
				case 1:
				{
					p.playerdone = "HEAL";

					if(p.mana >= m_heal)
					{
						p.playersuccess = "SUCCESSFUL";

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
						p.playersuccess = "UNSUCCESSFUL";	
						p.stress++;
					}
				}
				break;

				case 2:
				{
					p.playerdone = "STUN";

					if(p.mana >= m_stun)
					{
						p.playersuccess = "SUCCESSFUL";
						check = 1;
						p.mana = p.mana - m_stun;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 3:
				{
					p.playerdone = "CONFUSE";

					if(p.mana >= m_confuse)
					{
						p.playersuccess = "SUCCESSFUL";
						check = 2;
						p.mana = p.mana - m_confuse;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 4:
				{
					p.playerdone = "FIREBALL";

					if(p.mana >= m_fireball)
					{
						p.playersuccess = "SUCCESSFUL";

						check = 3;
						p.mana = p.mana - m_fireball;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;

				case 5:
				{
					p.playerdone = "CONJURE FIRE RAM";

					if(p.mana >= 2*m_fireball)
					{
						p.playersuccess = "SUCCESSFUL";

						check = 4;

						p.mana = p.mana - 2*m_fireball;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;

				case 6:
				{
					p.playerdone = "CONJURE FIRE HOUND";

					if(p.mana >= 3*m_fireball)
					{
						p.playersuccess = "SUCCESSFUL";

						check = 5;

						p.mana = p.mana - 3*m_fireball;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}	
				}
				break;

				case 7:
				{
					p.playerdone = "CLEANSE AURA";

					if(p.mana >= m_cleanse)
					{
						p.playersuccess = "SUCCESSFUL";

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
						p.playersuccess = "UNSUCCESSFUL";
					}
				}
				break;
				
				case 8:
				{
					p.playerdone = "MANA BOOST";

					p.playersuccess = "SUCCESSFUL";

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
			cout<<"\n5. Conjure Fire Ram : "<<2*m_fireball<<" Mana"<<endl;
			cout<<"\n6. Conjure Fire Hound : "<<3*m_fireball<<" Mana"<<endl;
			cout<<"\n7. Fire Storm : "<<m_firestorm<<" Mana"<<endl;
			cout<<"\n8. Cleanse Aura : "<<m_cleanse<<" Mana"<<endl;
			cout<<"\n9. Mana Increase by 100"<<endl;
			
			cout << "\nInput Choice : ";
			cin >> spellchoice;

			system("cls");
			
			switch(spellchoice)
			{
				case 1:
				{
					p.playerdone = "HEAL";

					if(p.mana >= m_heal)
					{
						p.playersuccess = "SUCCESSFUL";

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
						p.playersuccess = "UNSUCCESSFUL";	
						p.stress++;
					}
				}
				break;

				case 2:
				{
					p.playerdone = "STUN";

					if(p.mana >= m_stun)
					{
						p.playersuccess = "SUCCESSFUL";
						check = 1;
						p.mana = p.mana - m_stun;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 3:
				{
					p.playerdone = "CONFUSE";

					if(p.mana >= m_confuse)
					{
						p.playersuccess = "SUCCESSFUL";
						check = 2;
						p.mana = p.mana - m_confuse;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;
				
				case 4:
				{
					p.playerdone = "FIREBALL";

					if(p.mana >= m_fireball)
					{
						p.playersuccess = "SUCCESSFUL";

						check = 3;
						p.mana = p.mana - m_fireball;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;

				case 5:
				{
					p.playerdone = "CONJURE FIRE RAM";

					if(p.mana >= 2*m_fireball)
					{
						p.playersuccess = "SUCCESSFUL";

						check = 4;

						p.mana = p.mana - 2*m_fireball;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}
				}
				break;

				case 6:
				{
					p.playerdone = "CONJURE FIRE HOUND";

					if(p.mana >= 3*m_fireball)
					{
						p.playersuccess = "SUCCESSFUL";

						check = 5;

						p.mana = p.mana - 3*m_fireball;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}	
				}
				break;

				case 7:
				{
					p.playerdone = "FIRE STORM";

					if(p.mana >= m_firestorm)
					{
						p.playersuccess = "SUCCESSFUL";

						check = 6;

						p.mana = p.mana - m_firestorm;	
					}
					
					else
					{
						p.playersuccess = "UNSUCCESSFUL";
						p.stress++;
					}	
				}
				break;

				case 8:
				{
					p.playerdone = "CLEANSE AURA";

					if(p.mana >= m_cleanse)
					{
						p.playersuccess = "SUCCESSFUL";

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
						p.playersuccess = "UNSUCCESSFUL";
					}
				}
				break;
				
				case 9:
				{
					p.playerdone = "MANA BOOST";

					p.playersuccess = "SUCCESSFUL";

					if(p.mana + 100<p.maxM) p.mana = p.mana + 100; else p.mana = p.maxM;
				}
				break;
			}	
		}
		break;
	}

	c = WHITE;
	setcolor();

	int temp_health = e.HP;
	
	if(check == 0)
	{
		//Do nothing
	}

	else if(check == 1)
	{
		e.stunned = 2;
	}

	else if(check == 2)
	{
		e.HP = e.HP - e.cdamage;
	}

	else if(check == 3)
	{
		e.HP -= e.HP - p.fire;
	}

	else if(check == 4)
	{
		e.HP -= e.HP - p.fire;
	}	

	else if(check == 5)
	{
		e.HP -= e.HP - p.fire;

		e.stunned = 2;
	}

	else if(check == 6)
	{
		e.HP -= e.HP - 2 * p.fire;

		e.bleeding = 2;
	}

	else if(check == 7)
	{
		e.HP -= e.HP - 5 * p.fire;

		e.stunned = 1;
	}

	e.damage_taken = temp_health - e.HP;

	return check;
}