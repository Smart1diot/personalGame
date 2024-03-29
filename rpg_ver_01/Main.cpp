#include <iostream>
#include <string>
#include <string_view>

class Goblin
{
	std::string name{"Small Goblin"};
	int health{10};


public:
	std::string_view getName()
	{
		return name;
	}

	int getHealth() { return health; }
	void setDeathHealthZero() { health = 0; }

	void takeDamage(int damage)
	{
		health -= damage;
	}
	

	void printStats()
	{
		std::cout << getName() << '\n';
		std::cout << "Health:	" << health << '\n';

		std::cout << '\n' << '\n';
	}
};


class Player
{
	std::string name{"Player_Name"};
	int health{ 50 };
	int attack{ 5 };

public: 
	std::string_view getName()
	{
		return name;
	}

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
		}
	}

	if (smallGoblin.getHealth() <= 0)
	{
		smallGoblin.setDeathHealthZero();

		std::cout << "You Win!" << '\n';
	}

}

int main()
{
	Goblin smallGoblin;
	Player user;
	
	battle(smallGoblin, user);
	
	std::cout << '\n';

	smallGoblin.printStats();

	return 0;
}
