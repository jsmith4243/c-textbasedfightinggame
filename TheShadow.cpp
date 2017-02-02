TheShadow::TheShadow()
{

	attackPoints[0] = 2;

	attackPoints[1] = 10;

	defensePoints[0] = 1;

	defensePoints[1] = 6;

	armor = 0; //special

	strength = 12;

	className = "The Shadow";

}

int TheShadow::returnAttack()
{

	Dice die1(10);

	Dice die2(10);

	return (die1.rollDice() + die2.rollDice());

}

int TheShadow::returnDefense()
{

	Dice die1(6);

	return (die1.rollDice());	

}
