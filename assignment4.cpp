/*********************************************************************
** Program Filename: main.cpp
** Author: Joel Smith 
** Date: February 8, 2015
** Description: assignment3
** Input: User choice of character to fight
** Output: Outcome of fight output to screen
*********************************************************************/


#include <unistd.h>
#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <ctime>
#include "Dice.hpp"
#include "Dice.cpp"
#include "Character.hpp"
#include "Character.cpp"
#include "Barbarian.hpp"
#include "Barbarian.cpp"
#include "BlueMen.hpp"
#include "BlueMen.cpp"
#include "Goblin.hpp"
#include "Goblin.cpp"
#include "ReptilePeople.hpp"
#include "ReptilePeople.cpp"
#include "TheShadow.hpp"
#include "TheShadow.cpp"




int main()
{

	//std::vector<Character*> characterVector;

	int player1queuesize;
	int player1stacksize;
	int player2queuesize;
	int player2stacksize;
	bool player1alive;
	bool player2alive;

	int creatureLineupSize;

	std::cout << "Assignment4." << std::endl;

	std::cout << "Player1: Choose the character lineup size for each player: " << std::endl;

	std::cin >> creatureLineupSize;

	while (std::cin.fail())
	{

		std::cout << "Invalid value. Enter again: ";
		std::cin.clear();
		std::cin.ignore(9999, '\n');
		std::cin >> creatureLineupSize;


	}

	//player 1 lineup queue
	std::queue<Character*> player1CharacterQueue;

	//player 2 lineup queue
	std::queue<Character*> player2CharacterQueue;

	//player 1 loser stack
	std::queue<Character*> player2LoserCharacterStack;

	//player 2 loser stack
	std::queue<Character*> player1LoserCharacterStack;

	for (int i = 0; i < creatureLineupSize; i++)
	{

		std::cout << "Player1: Choose a creature your your lineup: " << std::endl;

		std::cout << "1: Goblin" << std::endl << "2: Barbarian" << std::endl << "3: Reptile People" << std::endl << "4: Blue Men" << std::endl << "5: The Shadow" << std::endl;

		int choice;

		std::cin >> choice;

		if (choice == 1)
		{


			player1CharacterQueue.push(new Goblin());

		}

		else if (choice == 2)
		{

			player1CharacterQueue.push(new Barbarian());

		}


		else if (choice == 3)
		{

			player1CharacterQueue.push(new ReptilePeople());

		}


		else if (choice == 4)
		{

			player1CharacterQueue.push(new BlueMen());

		}

		else if (choice == 5)
		{

			player1CharacterQueue.push(new TheShadow());

		}



	}

	
	for (int i = 0; i < creatureLineupSize; i++)
	{

		std::cout << "Player2: Choose a creature your your lineup: " << std::endl;

		std::cout << "1: Goblin" << std::endl << "2: Barbarian" << std::endl << "3: Reptile People" << std::endl << "4: Blue Men" << std::endl << "5: The Shadow" << std::endl;

		int choice;

		std::cin >> choice;

		if (choice == 1)
		{


			player2CharacterQueue.push(new Goblin());

		}

		else if (choice == 2)
		{

			player2CharacterQueue.push(new Barbarian());

		}


		else if (choice == 3)
		{

			player2CharacterQueue.push(new ReptilePeople());

		}


		else if (choice == 4)
		{

			player2CharacterQueue.push(new BlueMen());

		}

		else if (choice == 5)
		{

			player2CharacterQueue.push(new TheShadow());

		}



	}

	while((player1CharacterQueue.size() != 0) && (player2CharacterQueue.size() != 0))
	{

		player1queuesize = player1CharacterQueue.size();
		player1stacksize = player1LoserCharacterStack.size();
		player1alive = player1CharacterQueue.front()->isAlive ;
		player2alive = player2CharacterQueue.front()->isAlive ;
		player2queuesize = player2CharacterQueue.size();
		player2stacksize = player2LoserCharacterStack.size();
		

		player1CharacterQueue.front()->fightToTheDeath(player2CharacterQueue.front());

		if (player1CharacterQueue.front()->isAlive == false)
		{

			//remove from queue and put on stack

			

			

			player1LoserCharacterStack.push(player1CharacterQueue.front());
			player1CharacterQueue.pop();
			

			

			player2CharacterQueue.front()->recover();

		}

		if (player2CharacterQueue.front()->isAlive == false)
		{

			//remove from queue and put on stack

			//player2LoserCharacterStack.push(player2CharacterQueue.pop());

			player2LoserCharacterStack.push(player2CharacterQueue.front());
			player2CharacterQueue.pop();

			player1CharacterQueue.front()->recover();

		}


	}

	if (player1CharacterQueue.size() == 0)
	{
		std::cout << "Player 2 wins." << std::endl;
		//player2 wins
	}

	else if (player2CharacterQueue.size() == 0) 
	{

		std::cout << "Player 1 wins." << std::endl;
		//player 1 wins

	}

	
	//std::cout << characterVector[0]->armor;

	//characterVector[0]->fightToTheDeath(characterVector[1]);

}
