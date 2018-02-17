#include <iostream>
#include "courtPlayerList.h"
#include "benchPlayerList.h"
#include "Player.h"
#include "courtPlayer.h"
#include "benchPlayer.h"
#include <ctime>
#include <math.h>
using namespace std;

int main()
{

//Initialize
	srand(time(NULL));
	Player locker[12];
	courtPlayerList CourtP;
	benchPlayerList BenchP;
	CirnodeType<courtPlayer> tCplayer;
	nodeType<benchPlayer> tBplayer;
	int lockerrand = 0;
	int prevlockrand = 0;

	//Assign number and age
	for (int i = 0; i < 12; i++)
	{
		locker[i].number = i + 1;
		locker[i].age = rand() % 41 + 10;
	}

	//Bench all players
	for (int i = 0; i < 12; i++)
	{
		tBplayer.info = locker[i];
		BenchP.insert(tBplayer.info);
	}


	//Choose 5 random players to play on court
	for (int i = 0; i < 5; i++)
	{
		lockerrand = rand() % 13 + 1;
		if (lockerrand != prevlockrand)
		{
			tCplayer.info = locker[lockerrand];
			prevlockrand = lockerrand;
		}
	}


	//Clock
	for (int i = 0; i < 4; i++) //4 quarters
	{
		double gameTime = 0; //timer automatically resets on each quarter
		int benched = 0; //tracks how many players are benched

		while (gameTime < 12.0)
		{
			tCplayer = CourtP.pointToFront();//Temporary current player node 

			//Cycle through the circular linked list to find player to bench
			
			//If the one after is not front, we continue cycling
			while (tCplayer.link->info.number != CourtP.pointToFront().info.number) //Cycle through the circular linked list to find player to bench
			{
				if (tCplayer.info.age*0.1 == gameTime) //If current time is the same as the current game time, we bench
				{
					tBplayer.info = tCplayer.info;
					BenchP.insert(tBplayer.info); //insert player into bench
					CourtP.deleteNode(tCplayer.info); //delete court player
					benched++; //bench counter
				}


				//Replacement
				int counter = 0;
				lockerrand = 0; //reuse variable for RNG
				tBplayer.info = BenchP.front(); //Reuse variable to traverse 
				while (counter < benched)
				{
					lockerrand = rand() % 13 + 1; //RNG 1 to 12
					if (tBplayer.info.number == lockerrand)
					{
						tCplayer.info = tBplayer.info; //convert
						CourtP.insert(tCplayer.info);
						counter++;
					}

					//Move to next node
					if (tBplayer.next != NULL)
					{
						tBplayer = *tBplayer.next;
					}
					else
					{
						*tBplayer.next = BenchP.pointToFront();
					}
				}

				tCplayer = *tCplayer.link;

			}//end while



			gameTime += 0.1; //increment by a second
		} //end outermost while
	}//end for

	return 0;
}