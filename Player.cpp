#include "Player.h"
#include "TextureHolder.h"
#include <iostream>

// We can remove the ( this KEYWORD bc we named out member variables with m_ so we know whats a member var )
Player::Player() : 
	m_TileSize(0),
	m_UpPressed(false),
	m_DownPressed(false),
	m_LeftPressed(false),
	m_RightPressed(false),
	m_Health(START_HEALTH), 
	m_MaxHealth(START_HEALTH),
	m_Speed(START_SPEED)
{
	// Associate a texture with the sprite
	// !Watch this space!!
	this->m_Sprite = sf::Sprite(TextureHolder::GetTexture("graphics/player.png"));
	// Set the origin of the sprite, for smooth rotation
	this->m_Sprite.setOrigin(25, 25);

}

void Player::spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize)
{
	// Place the player in the middle of the arena
	this->m_Position.x = arena.width / 2;
	this->m_Position.y = arena.height / 2;

	// Copy the details of the arena to the players m_Arena
	this->m_Arena.left = arena.left;
	this->m_Arena.width = arena.width;
	this->m_Arena.top = arena.top;
	this->m_Arena.height = arena.height;

	// Remember how big the tiles are for this arena
	this->m_TileSize = tileSize;

	// Store the resolution for future use
	this->m_Resolution.x = resolution.x;
	this->m_Resolution.y = resolution.y;
}

// call this at the end of every game
void Player::resetPlayerStats()
{
	this->m_Speed = START_SPEED;
	this->m_Health = START_HEALTH;
	this->m_MaxHealth = START_HEALTH;
}

// Handle the player getting hit by a zombie
bool Player::hit(sf::Time timeHit)
{
	if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200)
	{
		this->m_LastHit = timeHit;
		this->m_Health -= 10;
		return true;
	}
	else
	{
		return false;
	}
}

//////////////
//	Getters //
//////////////

// How long ago	was the player last hit
sf::Time Player::getLastHitTime()
{
	return this->m_LastHit;
}

// Where is the player
sf::FloatRect Player::getPosition()
{
	return this->m_Sprite.getGlobalBounds();
}

// Where is the center of the player
sf::Vector2f Player::getCenter()
{
	return this->m_Position;
}

// What angle is the player facing
float Player::getRotation()
{
	return this->m_Sprite.getRotation();
}

// Send a copy of the sprite to the main function
sf::Sprite Player::getSprite()
{
	return this->m_Sprite;
}


// How much health does the player currently have got?
int Player::getHealth()
{
	return this->m_Health;
}

////////////////////////////////////////
// The next functions move the player //
////////////////////////////////////////
void Player::moveLeft()
{
	this->m_LeftPressed = true;
}

void Player::moveRight()
{
	this->m_RightPressed = true;
}

void Player::moveUp()
{
	this->m_UpPressed = true;
}

void Player::moveDown()
{
	this->m_DownPressed = true;
}

// Stop the player from moving
void Player::stopLeft()
{
	this->m_LeftPressed = false;
}

void Player::stopRight()
{
	this->m_RightPressed = false;
}

void Player::stopUp()
{
	this->m_UpPressed = false;
}

void Player::stopDown()
{
	this->m_DownPressed = false;
}

// We will call this function once every frame
void Player::update(float elapsedTime, sf::Vector2i mousePosition)
{
	if (this->m_UpPressed)
	{
		this->m_Position.y -= this->m_Speed * elapsedTime;
	}

	if (this->m_DownPressed)
	{
		this->m_Position.y += this->m_Speed * elapsedTime;
	}

	if (this->m_RightPressed)
	{
		this->m_Position.x += this->m_Speed * elapsedTime;
	}

	if (this->m_LeftPressed)
	{
		this->m_Position.x -= this->m_Speed * elapsedTime;
	}

	this->m_Sprite.setPosition(this->m_Position);

	// Keep the player in the arena
	if (this->m_Position.x > this->m_Arena.width - this->m_TileSize)
	{
		//  Player won't stray of the width of Arena in pixels
		this->m_Position.x = this->m_Arena.width - this->m_TileSize;
	}

	if (this->m_Position.x < this->m_Arena.left + this->m_TileSize)
	{
		this->m_Position.x = this->m_Arena.left + this->m_TileSize;
	}

	if (this->m_Position.y > this->m_Arena.height - this->m_TileSize)
	{
		//  Player won't stray of the Arenas height size pixels
		this->m_Position.y = this->m_Arena.height - this->m_TileSize;
	}

	if (this->m_Position.y < this->m_Arena.top + this->m_TileSize)
	{
		this->m_Position.y = this->m_Arena.top + this->m_TileSize;
	}

	// calculate the angle the player is facing, trig function
	float angle = 
		( atan2( mousePosition.y - this->m_Resolution.y / 2,				// arc tangent <cmath>
			mousePosition.x - this->m_Resolution.x / 2 ) * 180 ) / 3.141;

	m_Sprite.setRotation( angle );
}

// Give the player a speed boost
void Player::upgradeSpeed()
{
	// 20% speed upgrade
	this->m_Speed += (this->START_HEALTH * 0.2);
}

// Give the player some health
void Player::upgradeHealth()
{
	// 20% health upgrade
	this->m_MaxHealth += (this->START_HEALTH * 0.2);
}

// Increase the maximum amount of health the player can have
void Player::increaseHealthLevel(int amount)
{
	this->m_Health += amount;
	// But not beyond the maximum
	if (this->m_Health > m_MaxHealth)
	{
		this->m_Health = m_MaxHealth;
	}
}


Player::~Player()
{

}