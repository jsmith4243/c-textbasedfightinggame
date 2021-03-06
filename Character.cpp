/*********************************************************************
** Function: void Character::fightToTheDeath(Character* enemy)
** Description: Fights the two characters until one runs out of strenght
** Parameters: Character* enemy. pointer to enemy character to right
** Pre-Conditions: Enemy character is instantiated.
** Post-Conditions: Fight is fought. Results are output to screen.
*********************************************************************/
void Character::fightToTheDeath(Character* enemy)
{

	if (this->strength <= 0)
	{

		std::cout << this->className << " cannot fight because it is dead." << std::endl;

		return;

	}

	else if (enemy->strength <= 0)
	{

		std::cout << enemy->className << " cannot fight because it is dead." << std::endl;

		return;

	}

	while ((this->strength >= 0) && (enemy->strength >= 0))
	{

		std::cout.flush();

		sleep(1); //1 second

		this->attack(enemy);

		if (enemy->strength <= 0)
		{

			std::cout << enemy->className << " died." << std::endl;

			enemy->isAlive = false;

			enemy->strength = 0;

			break;

		}

		std::cout.flush();

		sleep(1); //1 second

		enemy->attack(this);

		if (this->strength <= 0)
		{

			std::cout << this->className << " died." << std::endl;

			this->isAlive = false;

			this->strength = 0;

			break;

		}

	
			


	}


}


void Character::recover()
{

	std::cout << this->className << " recovered " << 2 << " strength points." << std::endl;

	this->strength = this->strength + 2;

	return ;

}

Character::Character()
{

	isAlive = true;

}



/*********************************************************************
** Function: void Character::attack(Character* enemy)
** Description: Calculates the appropriate damage dealth to enemy according to stats fo enemy
** Parameters: Character* enemy. pointer to enemy character to right
** Pre-Conditions: Enemy character is instantiated.
** Post-Conditions: Result of attack is recordied in attribute strength of enemy
*********************************************************************/
void Character::attack(Character* enemy)
{ 

	std::cout << this->className << " attacks " << enemy->className << std::endl;

	int attack;

	int defense;

	int damage;

	int damageMinusArmor;

	attack = this->returnAttack();

	defense = enemy->returnDefense();

	damage = attack - defense;

	damageMinusArmor = damage - enemy->armor;

	if(damageMinusArmor <= 0)
	{

		std::cout << "No damage caused." << std::endl;

	}

	else if (damageMinusArmor >= 0)
	{

		std::cout << damageMinusArmor << " damage caused." << std::endl; 

		enemy->strength = enemy->strength - damageMinusArmor;

	}

}

int Character::returnAttack()
{

}

int Character::returnDefense()
{

}

	


