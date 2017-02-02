Goblin::Goblin()
{

	attackPoints[0] = 2;

	attackPoints[1] = 6;

	defensePoints[0] = 1;

	defensePoints[1] = 6;

	armor = 3;

	strength = 8;

	className = "Goblin";

}

int Goblin::returnAttack()
{

	Dice die1(6);

	Dice die2(6);

	return (die1.rollDice() + die2.rollDice());

}

int Goblin::returnDefense()
{

	Dice die1(6);

	

	return (die1.rollDice());	

}


