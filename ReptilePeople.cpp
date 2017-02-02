ReptilePeople::ReptilePeople()
{

	attackPoints[0] = 3;

	attackPoints[1] = 6;

	defensePoints[0] = 1;

	defensePoints[1] = 6;

	armor = 7;

	strength = 18;

	className = "Reptile People";

}

int ReptilePeople::returnAttack()
{

	Dice die1(6);

	Dice die2(6);

	Dice die3(6);

	return (die1.rollDice() + die2.rollDice() + die3.rollDice());

}

int ReptilePeople::returnDefense()
{

	Dice die1(6);

	return (die1.rollDice());	

}
