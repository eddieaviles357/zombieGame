#ifndef PICKUP_H
#define PICKUP_H

#include <SFML/Graphics.hpp>

class Pickup
{
private:
	// Start values for health pickups
	const int HEALTH_START_VALUE = 50;
	const int AMMO_START_VALUE = 12;
	const int START_WAIT_TIME = 10;
	const int START_SECONDS_TO_LIVE = 5;

	sf::Sprite m_Sprite;	// The sprite that represents this pick up
	sf::IntRect m_Arena;	// The arena it exist in
	int m_Value;			// How much is this pickup worth

	// what type of pick up is this
	int m_Type;				// 1 = health, 2 = ammo

	// Handle spawning and dissapearing
	bool m_Spawned;
	float m_SecondsSinceSpawn;
	float m_SecondsSinceDeSpawn;
	float m_SecondsToLive;
	float m_SecondsToWait;
public:
	Pickup(int type);

	// Prepare a new pickup
	void setArena(sf::IntRect arena);
	void spawn();

	// Check the position of the pickup
	sf::FloatRect getPosition();

	// Get the sprite for  drawing
	sf::Sprite getSprite();

	// Let the pickup update itself each frame
	void update(float elapsedTime);

	// Is this pickup currently spawned
	bool isSpawned();

	// Get the goodness from the pickup
	int gotIt();

	// Update the value of each pickup
	void upgrade();
};

#endif