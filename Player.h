#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
private:
	const float START_SPEED = 200.0f;
	const float START_HEALTH = 100.0f;
	// Where is the player
	sf::Vector2f m_Position;
	// Need a sprite
	sf::Sprite m_Sprite;

	// Add a texture;
	// spcecial changes here
	sf::Texture m_Texture;

	// What is screen resolution
	sf::Vector2f m_Resolution;
	// What size is the current arena
	sf::IntRect m_Arena;
	// How big is each tile of the arena
	int m_TileSize;
	// Which direction(s) is the player currently moving in
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;
	// How much health has the player got?
	int m_Health;
	// What is the maximun health the player can have
	int m_MaxHealth;
	// When was the player last hit
	sf::Time m_LastHit;
	// Speed in pixels per second
	float m_Speed;
	// All our public functions will come next

public:
	Player();

	void spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize);
	// call this at the end of every game
	void resetPlayerStats();
	// Handle the player getting hit by a zombie
	bool hit(sf::Time timeHit);
	// How long ago	was the player last hit
	sf::Time getLastHitTime();
	// Where is the player
	sf::FloatRect getPosition();
	// Where is the center of the player
	sf::Vector2f getCenter();
	// What angle is the player facing
	float getRotation();
	// Send a copy of the sprite to the main function
	sf::Sprite getSprite();
	// The next functions move the player
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	// Stop the player from moving
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();
	// We will call this function once every frame
	void update(float elapsedTime, sf::Vector2i mousePosition);
	// Give the player a speed boost
	void upgradeSpeed();
	// Give the player some health
	void upgradeHealth();
	// Increase the maximum amount of health the player can have
	void increaseHealthLevel(int amount);
	// How much health does the player currently have got?
	int getHealth();

	~Player();
};



#endif