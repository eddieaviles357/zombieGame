#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <SFML/Graphics.hpp>

class Zombie
{
private:
	// How fast is each zombie type?
	const float BLOATER_SPEED = 40;
	const float CHASER_SPEED = 80;
	const float CRAWLER_SPEED = 20;
	
	// How tough is each zombie type
	const float BLOATER_HEALTH = 5;
	const float CHASER_HEALTH = 1;
	const float CRAWLER_HEALTH = 3;

	// Make each zombie vary its speed slightly
	const int MAX_VARRIANCE = 30;
	const int OFFSET = 101 - MAX_VARRIANCE;

	// Where is this zombie
	sf::Vector2f m_Position;
	// A sprite for the zombie
	sf::Sprite m_Sprite;
	// How fast can it run/crawl
	float m_Speed;
	// How much health has it got
	float m_Health;
	// Is it still alive
	bool m_Alive;

public:
	Zombie();
	// Handle when a bullet hits a zombie
	bool hit();
	// Find out if the zombie is alive
	bool isAlive();
	// spawn new zombie
	void spawn(float startX, float startY, int type, int seed);
	// Return a rectangle that is the position in the world
	sf::FloatRect getPosition();
	// Get a copy of the sprite to draw
	sf::Sprite getSprite();
	// Update the zombie each frame
	void update(float elapsedTime, sf::Vector2f playerLocation);
	~Zombie();
};

#endif