#include <iostream>
#include <string>
#include <string_view>
#include <random>

int randomNumber()
{
	std::random_device rd;
	std::seed_seq ss{ rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd() };

	std::mt19937 mt{ ss };

	std::uniform_int_distribution die100{ 1,100 };

	int randomNumber{ die100(mt) };

	return randomNumber;
}

//-----------------------------------------------------------------------

class Goblin // Goblin stats and functions
{
	std::string name{ "Small Goblin" };
	int health{ 10 };
	int attack{ 10 };
	int accuracy{ 50 };

public:
	std::string_view getName()
	{
		return name;
	}

	int getAccuracy() { return accuracy; }
	int getAttack() { return attack; }

	int getHealth() { return health; }
	void setDeathHealthZero() { health = 0; }

	void takeDamage(int damage){ health -= damage; }

	void printStats()
	{
		std::cout << getName() << '\n';
		std::cout << "Health:	" << health << '\n';
		std::cout << "Attack:	" << attack << '\n';

		std::cout << '\n' << '\n';
	}
};


class Player //Player stats and functions
{
	std::string name{ "Player_Name" };
	int health{ 50 };
	int attack{ 2 };

public:
	std::string_view getName()
	{
		return name;
	}

	void takeDamage(int damage) { health -= damage; }

	int getAttack()
	{
		return attack;
	}

	void printStats()
	{
		std::cout << getName() << '\n';
		std::cout << "Health:	" << health << '\n';
		std::cout << "Attack:	" << attack << '\n';

		std::cout << '\n' << '\n';
	}

};

//----------------------------------------------------------------------------

void battle(Goblin& smallGoblin, Player& user)
{
	while (smallGoblin.getHealth() > 0)
	{
		user.printStats();
		smallGoblin.printStats();

		std::cout << "What will you do?" << '\n';
		std::cout << "(1)Attack	(2)Run" << '\n';

		int userOption{};
		std::cin >> userOption;
		std::cout << '\n';

		switch (userOption)
		{
		case 1: smallGoblin.takeDamage(user.getAttack());
			break;

		case 2: std::cout << "You ran away successfully" << '\n';
			return;

		default: std::cout << "Error: wtf is happening with my game?" << '\n';
		}

		int randomNum{randomNumber()};
		if (randomNum >= 1 && randomNum <= smallGoblin.getAccuracy())
		{
			for (int i{ 1 }; i < 50; ++i)
			{
				std::cout << '-';

				if (i % 50 == 0)
				{
					std::cout << '\n';
				}
			}
			user.takeDamage(smallGoblin.getAttack());
			std::cout << "goblin attacked!" << '\n';
		}
		else
		{
			for (int i{ 1 }; i < 50; ++i)
			{
				std::cout << '-';

				if (i % 50 == 0)
				{
					std::cout << '\n';
				}
			}
			std::cout << "goblin missed!" << '\n';
		}
	}

	if (smallGoblin.getHealth() <= 0)
	{
		smallGoblin.setDeathHealthZero();

		std::cout << "You Win!" << '\n';
	}
}

//-----------------------------------------------------------------------

int main()
{
	Goblin smallGoblin;
	Player user;

	battle(smallGoblin, user);

	std::cout << '\n';

	//smallGoblin.printStats();

	return 0;
}