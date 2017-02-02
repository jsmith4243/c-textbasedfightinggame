BlueMen::BlueMen()
{

	attackPoints[0] = 2;

	attackPoints[1] = 10;

	defensePoints[0] = 3;

	defensePoints[1] = 6;

	armor = 3;

	strength = 12;

	className = "Blue Men";

}

int BlueMen::returnAttack()
{

	Dice die1(10);

	Dice die2(10);

	return (die1.rollDice() + die2.rollDice());

}

int BlueMen::returnDefense()
{

	Dice die1(6);

	Dice die2(6);
	
	Dice die3(6);

	return (die1.rollDice() + die2.rollDice() + die3.rollDice());	

}
