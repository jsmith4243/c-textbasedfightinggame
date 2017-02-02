Barbarian::Barbarian()
{

	attackPoints[0] = 2;

	attackPoints[1] = 6;

	defensePoints[0] = 2;

	defensePoints[1] = 6;

	armor = 0;

	strength = 12;

	className = "Barbarian";

}

int Barbarian::returnAttack()
{

	Dice die1(6);

	Dice die2(6);

	return (die1.rollDice() + die2.rollDice());

}

int Barbarian::returnDefense()
{

	Dice die1(6);

	Dice die2(6);

	return (die1.rollDice() + die2.rollDice());	

}
