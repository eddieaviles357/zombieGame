#include "ZombieArena.h"
#include "Zombie.h"

Zombie* createHorde(int numZombies, sf::IntRect arena)
{
	Zombie* zombies = new Zombie[numZombies];
	int maxY = arena.height - 20;
	int minY = arena.top + 20;
	int maxX = arena.width - 20;
	int minX = arena.left + 20;
	for (size_t i = 0; i < numZombies; i++)
	{
		// Which side should the zombie spawn
		srand(static_cast<int>(time(0) * i));

		int side = (rand() % 4);
		float x = 0.0;
		float y = 0.0;
		switch (side)
		{
		case 0:
			// Left
			x = minX;
			y = (rand() % maxY) + minY;
			break;
		case 1:
			// Right
			x = maxX;
			y = (rand() % maxY) + minY;
			break;
		case 2:
			// Top
			x = (rand() % maxY) + minX;
			y = minY;
			break;
		case 3:
			// Bottom
			x = (rand() % maxX) + minX;
			y = maxY;
			break;
		}

		// Bloater, crawler or runner
		srand(static_cast<int>(time(0) * i * 2)); // between 0 and 2

		int type = (rand() % 3);

		// Spawn the new zombie into the array
		zombies[i].spawn(x, y, type, i);
	}
	return zombies;
}