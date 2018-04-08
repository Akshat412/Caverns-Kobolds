#include"menu.h"

using namespace std;

int story(player&p,enemy&e,int input)
{
	c = WHITE;
	setcolor();

	int choice, dead = 0, classchoice, check = 1;
	int max_level = 4;
	
	while(p.level <= max_level)
	{
		switch(p.level)
		{
			case 0:
			{
				line();

				cout<<"\nYou are a prisoner of a Bandit Chief, currently locked up in a cell inside his stronghold"<<endl;
				cout<<"\nYou awaken from a deep sleep. You look around and realise you are a......."<<endl;

				cout<<"\n...you are a.."<<endl;

				race(p);

				cout<<"\nSuddenly, a guard bangs on your cell door"<<endl;
				cout<<"\nGuard : The Chief has asked for you. Come with me. "<<endl;
				
				line();
				
				cout<<"\nShackled, you are put in front of the Chief"<<endl;
				cout<<"\nBandit Chief : Hello Prisoner! Tell me your name.";

				c = RED;
				setcolor();

				cout<<" [No spaces please]"<<endl;

				c = WHITE;
				setcolor();

				cout<<"\nInput Choice : ";
				
				cin>>p.name;

				system("cls");
								
				cout<<"\nBandit Chief : So, "<<p.name<<", do you know what we do prisoners around here?"<<endl;
				cout<<"\nThe Chief points to a cage on the side, containing wolves and many corpses"<<endl;
				cout<<"\nBandit Chief : But..for you, I have an offer. I have a task for you. Finish it alive and I shall let you free."<<endl;
				
				cout<<"\nBandit Chief : Tell me now, do you accept?"<<endl;
				cout<<"\n1. Yes"<<endl;
				cout<<"\n2. No"<<endl;
				
				cout<<"\nInput Choice : ";
				cin>>choice;
				
				system("cls");

				switch(choice)
				{
					case 2:
					{
						cout<<"\nBandit Chief : Ok. Can't say I didn't warn you."<<endl;
						cout<<"\nA guard drags you into the wolf cage"<<endl;
						dead = 1;
						
						return dead;
					}
					break;
					
					default:
					{
						cout<<"\nBandit Chief : A very wise decision."<<endl;
					}
					break;
				}

				
				
				cout<<"\nBandit Chief : Now, on to what the task is..."<<endl;

				cout<<"\nBandit Chief : Around this valley are three extremely dangerous regions, guarded by gigantic creatures known as the Collosi. Your job is to slay every one of these beasts, as they are stopping my people from gathering resources in these regions"<<endl;

				cout<<"\nBandit Chief : I shall provide you with some basic equipment from my Armoury, and you can come back every time you defeat a Collosus to take rest."<<endl;

				cout<<"\nBandit Chief : Finish this task in one piece and I shall set you free."<<endl;	
				
				gamesave(p,input);
			}
			break;
			
			case 1:
			{
				line();
				
				cout<<"\nA guard escorts you to the Armoury"<<endl;
				cout<<"\nBlacksmith : Hi there "<<p.name<<"! I'm the Blacksmith of this here stronghold. The Chief told me about ye..said yeh needed some basic equipment to help ye not die"<<endl;
				
				cout<<"\nBlacksmith : So tell me, which kind of build would ye want?"<<endl;
				
				classchoice = playerclass(p);
				
				cout<<"\nHealth : "<<p.HP<<endl;
				cout<<"\nMagic Level : "<<p.spellno<<endl;
				cout<<"\nStarting Weapon : "<<p.w.name<<endl;
				cout<<"\nStarting Armor : "<<p.a.name<<endl;
				
				cout<<"\nBlacksmith : Here, take these "<<p.no_hp<<" Healing Potions, and these 10 Ales."<<endl;
				
				p.i.hp += p.no_hp;
				p.i.sp += 10;

				gamesave(p,input);
			}
			break;

			case 2:
			{	
				line();

				cout<<"\nYou are summoned back in front of the Chief"<<endl;
				cout<<"\nBandit Chief : The first area you go to is called the Northen Cavern,the largest iron mines in then region, in which the first Collosi resides. Slay him so that I can start collection of ore there"<<endl;
				
				cout<<"\nBandit Chief : So, you may go to the Cavern right away, or you can go read up in the Library. It contains books that may help you stay alive. You can also visit the Blacksmith; he can sell you some things."<<endl;
				
				

				while(check == 1)
				{
					cout<<"\nWhere do you go?"<<endl;
					cout<<"\n1. Go to Northern Cavern"<<endl;
					cout<<"\n2. Blacksmith's Shop"<<endl;
					cout<<"\n3. Library"<<endl;
					cout<<"\nInput choice : ";
					cin>>choice;
					
					system("cls");
				
					switch(choice)
					{
						case 1:
						{
							check = 0;
							cout<<"\nA chariot takes you to the Northern Caverns. The guards at the mouth of the Caverns let you enter"<<endl;
							cout<<"\nThe Cavern is dark and cold. You move inward..."<<endl;
				
							dead = move(p,e);
				
							if(dead==1)
							{
								return dead;
							}
				
							cout<<"\nYou move into a large chamber. Suddenly..."<<endl;
							
							line();
				
							dead = battle_collosus1(p,e);
				
							if(dead==1)
							{
								return dead;
							}	
				
							cout<<"\nYou emerge out of the Cavern, and the guards look at you in disbelief."<<endl;
							cout<<"\nYou move over to the chariot, and it takes you back to the stronghold"<<endl;
							
							
						}
						break;
					
						case 2:
						{
							shop(p);
							check = 1;
						}
						break;
						
						case 3:
						{
							library();
							check = 1;
						}
						break;
					}
				}
				
				cout<<"\nBandit Chief : I'm impressed. You have certainly proven yourself."<<endl;
				cout<<"\nBandit Chief : Go rest. You may choose to start whenever you like"<<endl;
				cout<<"\nYou go back to your cell and rest"<<endl;
				
				p.HP = p.maxHP;
				p.stamina = 5;
				p.mana = p.maxM;
				p.ability_point = 5;

				line();

				cout<<"\nYou are summoned by the Blacksmith"<<endl;
				cout<<"\nBlacksmith : So lad, picked up some weapons did ya? I can give ye some coin for that."<<endl;
				
				p.i.money += p.i.weapons * 50;
				p.i.money += p.i.armors * 100;
				
				cout<<"\nBlacksmith gives you "<<p.i.weapons * 50<<" coins for the weapons and "<<p.i.armors * 100<<" coins for the armor"<<endl;
				
				p.i.weapons = 0;
				p.i.armors = 0;
				p.initialize_inventory();
				
				gamesave(p,input);
			}
			break;
			
			case 3:
			{
				line();
				
				cout<<"\nYou are summoned in front of the Bandit Chief"<<endl;

				cout<<"\nBandit Chief : The second area you must travel to is the Cove. The Second Collosus rests there. You must slay it so we can start fishing in those regions"<<endl;
				
				cout<<"\nBandit Chief : You may go right away, or visit the shop or library. You are also free to help my men clear out the Northern Caverns further."<<endl;
				
				check = 1;
				
				while(check == 1)
				{
					cout<<"\nWhere do you go?"<<endl;
					cout<<"\n1. Go to Cove"<<endl;
					cout<<"\n2. Go to Northern Cavern"<<endl;
					cout<<"\n3. Blacksmith's Shop"<<endl;
					cout<<"\n4. Library"<<endl;
					cout<<"\nInput choice : ";
					cin>>choice;
					
					system("cls");
				
					switch(choice)
					{
						case 1:
						{
							check = 0;
							cout<<"\nA chariot takes you to the Cove. The guards let you through"<<endl;
							cout<<"\nThe skies are grey with fog, and the waves crash against the coast. You move forward...."<<endl;
							
							empty();
							
							dead = move(p,e);
							
							if(dead==1)
							{
								return dead;
							}
							
							dead = 0;
							
							cout<<"\nYou suddenly observe a shadow on the horizon...."<<endl;

							line();
							
							dead = battle_collosus2(p,e);
							
							if(dead==1)
							{
								return dead;
							}
							
							dead = 0;
							
							cout<<"\nYou emerge out of the Cove, and the guards look at you in disbelief."<<endl;
							cout<<"\nYou move over to the chariot, and it takes you back to the stronghold"<<endl;
						}
						break;
						
						case 2:
						{
							check = 1;
							cout<<"\nA chariot takes you to the Northern Caverns. The guards at the mouth of the Caverns let you enter"<<endl;
							cout<<"\nThe Cavern is dark and cold. You move inward..."<<endl;
							
							empty();
				
							dead = move(p,e);
				
							if(dead==1)
							{
								return dead;
							}
				
							cout<<"\nYou emerge out of the Caverns. A guard walks up to you"<<endl;
							
							cout<<"\nGuard : Thanks for the help! Here's some coin"<<endl;
							
							p.i.money += 100;
							
							cout<<"\nMoney : "<<p.i.money<<endl;
							
							empty();
							
							cout<<"\nA chariot takes you back to the stronghold. You rest in your cell"<<endl;
							
							p.HP = p.maxHP;
							p.stamina = 5;
							p.mana = p.maxM;
							
							empty();
							
							cout<<"\nYou are summoned by the Blacksmith"<<endl;
							cout<<"\nBlacksmith : So lad, picked up some weapons did ya? I can give ye some coin for that."<<endl;
				
							p.i.money += p.i.weapons * 50;
							p.i.money += p.i.armors * 100;
							
							cout<<"\nBlacksmith gives you "<<p.i.weapons * 50<<" coins for the weapons and "<<p.i.armors * 100<<" coins for the armor"<<endl;
							
							p.i.weapons = 0;
							p.i.armors = 0;
							p.initialize_inventory();
						}
						break;
					
						case 3:
						{
							shop(p);
							check = 1;
						}
						break;
						
						case 4:
						{
							library();
						}
					}
				}

				cout<<"\nYou are summoned by the Bandit Chief"<<endl;
				cout<<"\nBandit Chief : You have proven yourself yet again. Well done"<<endl;
				cout<<"\nYou go back to your cell and rest"<<endl;
				
				Sleep(1000);
					
				p.HP = p.maxHP;
				p.stamina = 5;
				p.mana = p.maxM;
					
				gamesave(p,input);
			}
			break;
			
			case 4:
			{
				cout<<"\nYou finished what I have so far!"<<endl;
				gamesave(p,input);
				
				system("pause");

				return 0;
			}
			break;
		}
	}
}	

int main()
{
	system("Color 0F");
	system("cls");

	c = WHITE;
	setcolor();

	player p;
	enemy e;
	int input;

	menu(p,input);
	
	int dead = 0;
	
	dead = story(p,e,input);
	
	if(dead==1)
	{
		c = RED;
		setcolor();

		
		cout<<"\nGame Over"<<endl;
		empty();
		return 0;
	}
	
	cout<<"\nAll for now"<<endl;
	
	return 0;
}

