#include "Zombie.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>

Zombie::Zombie()
{

}

// spawn new zombie
void Zombie::spawn(float startX, float startY, int type, int seed)
{
	switch (type)
	{
	case 0:
		// Bloater
		m_Sprite = sf::Sprite(TextureHolder::GetTexture("graphics/bloater.png"));
		//m_Speed = BLOATER_SPEED;
		//m_Health = BLOATER_HEALTH;
		m_Speed = 40;
		m_Health = 5;
		break;
	case 1:
		// Chaser
		m_Sprite = sf::Sprite(TextureHolder::GetTexture("graphics/chaser.png"));
		//m_Speed = CHASER_SPEED;
		//m_Health = CHASER_HEALTH;
		m_Speed = 70;
		m_Health = 1;
		break;
	case 2:
		// Crawler
		m_Sprite = sf::Sprite(TextureHolder::GetTexture("graphics/crawler.png"));
		//m_Speed = CRAWLER_SPEED;
		//m_Health = CRAWLER_HEALTH;
		m_Speed = 20;
		m_Health = 3;
		break;
	}

	// modify the speed to make the zombie unique
	// Every zombie is unique. Create a speed modifier
	srand(static_cast<int>(time(0) * seed));

	// somewhere between 80 and 100
	float modifier = (rand() % MAX_VARRIANCE) + OFFSET;

	// Express this as a fraction of 1
	modifier /= 100;
	// Now equals between 0.7f and 1.0f
	m_Speed *= modifier;

	// Initialize its location
	m_Position.x = startX;
	m_Position.y = startY;

	// Set its origin to its center
	m_Sprite.setOrigin(25, 25);

	// Set its posistion
	m_Sprite.setPosition(m_Position);
}

// Handle when a bullet hits a zombie
bool Zombie::hit()
{
	m_Health--;
	if (m_Health < 0)
	{
		// dead
		m_Alive = false;
		m_Sprite.setTexture(TextureHolder::GetTexture("graphics/blood.png"));
		return true;
	}
	// Injured but not dead
	return false;
}

// Find out if the zombie is alive
bool Zombie::isAlive()
{
	return m_Alive;
}

// Return a rectangle that is the position in the world
sf::FloatRect Zombie::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

// Get a copy of the sprite to draw
sf::Sprite Zombie::getSprite()
{
	return m_Sprite;
}

// Update the zombie each frame
void Zombie::update(float elapsedTime, sf::Vector2f playerLocation)
{
	float playerX = playerLocation.x;
	float playerY = playerLocation.y;

	// Update the zombie position variable
	if (playerX > m_Position.x)
	{
		m_Position.x = m_Position.x + m_Speed * elapsedTime;
	}

	if (playerY > m_Position.y)
	{
		m_Position.y = m_Position.y + m_Speed * elapsedTime;
	}

	if (playerX < m_Position.x)
	{
		m_Position.x = m_Position.x - m_Speed * elapsedTime;
	}

	if (playerY < m_Position.y)
	{
		m_Position.y = m_Position.y - m_Speed * elapsedTime;
	}

	// Move the sprite
	m_Sprite.setPosition(m_Position);

	// Face the sprite in the correct direction
	float angle = (atan2(playerY - m_Position.y, playerX - m_Position.x) * 180) / 3.141;
	m_Sprite.setRotation(angle);
}

Zombie::~Zombie()
{

}