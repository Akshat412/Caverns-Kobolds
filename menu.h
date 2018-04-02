#pragma once

#include"resources.h"
#include"initialization.h"
#include"battle.h"
#include"move.h"
#include"events.h"

using namespace std;

int test();

int menu(player&p,int&input)
{
	int choice;
	
	int check = 1;
	
	while(check == 1)
	{
		c = GREEN;
		setcolor();
		
		t = MAINSCREEN;
		textart();
                                                                                                                                                                                                                                                                                                 
		c = WHITE;
		setcolor();

		cout<<"\n1. Start new game"<<endl;
		cout<<"\n2. Continue game"<<endl;
		cout<<"\n3. Controls"<<endl;
		cout<<"\n4. About"<<endl;
	
		cout<<"\nInput choice : ";
		cin>>choice;

		system("cls");
	
		switch(choice)
		{
			case 1: 
			{
				cout<<"\nYou have chosen to start a new game. Please enter the save slot number you want to save in "<<endl;
				cout<<"\n1. Save Slot 1"<<endl;
				cout<<"\n2. Save Slot 2"<<endl;
				cout<<"\n3. Save Slot 3"<<endl;
				cout<<"\n4. Save Slot 4"<<endl;
				cout<<"\n5. Save Slot 5"<<endl;
				cout<<"\nInput choice : ";
				cin>>input;

				c = GREEN;
				setcolor();

				cout<<"\nSaving in Save Slot "<<input<<endl;

				c = WHITE;
				setcolor();

				return 0;
			}
			break;
				
			case 2:
			{
				cout<<"\nPlease enter the save slot to be loaded"<<endl;
				cout<<"\n1. Save Slot 1"<<endl;
				cout<<"\n2. Save Slot 2"<<endl;
				cout<<"\n3. Save Slot 3"<<endl;
				cout<<"\n4. Save Slot 4"<<endl;
				cout<<"\n5. Save Slot 5"<<endl;
				cout<<"\nInput choice : ";
				cin>>input;

				gameload(p,input);

				cout<<"\nLoaded Save Game : ";

				c = GREEN;
				setcolor();

				cout<<p.name;

				cout<<" : ";

				cout<<p.race<<" "<<p.pclass<<endl;

				c = WHITE;
				setcolor();

				return 0;
			}
			break;

			case 3:
			{
				cout<<"\nAll controls in the game are menu-based, and use the number keys. Follow on-screen keybinds to play"<<endl;
				check = 1;

				line();
			}
			break;
		
			case 4:
			{
				cout<<"\nInitial design on Turbo C++. Made on C++"<<endl;
				check =1;

				line();
			}
			break;
			
			case 420:
			{
				test();
			}
			break;
		}	
	}
}

int test()
{
	player p;
	enemy e;
	
	race(p);

	playerclass(p);

	enemyclass(p,e);

	p.level = 3;

	display_battlestats(p,e);
	empty();
}

