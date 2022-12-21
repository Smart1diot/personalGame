#include <iostream>

int main()
{
	while (true)
	{
		static int characterMoves{ 5 };

		int world{ 1 };
		for (; world <= 100; ++world)
		{
			if (world == characterMoves)
			{
				std::cout << "[X]" << '\t';
			}
			else
			{
				std::cout << "[ ]" << '\t';

			}
			if (world % 10 == 0)
			{
				std::cout << '\n';
			}
		}

		char down{};
		std::cin >> down;

		switch (down)
			{
			case 'w':
			{
				characterMoves -= 10;
				break;
			}
			case 'a':
			{
				characterMoves -= 1;
				break;
			}
			case 's':
			{
				characterMoves += 10;
				break;
			}
			case 'd':
			{
				characterMoves += 1;
				break;
			default:
					std::cout << "select a valid option" << '\n';
			}
		}

	}
	return 0;
}