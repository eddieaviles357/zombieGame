#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
private:
	// Where is the bullet
	sf::Vector2f m_Position;

	// What each bullet looks like
	sf::RectangleShape m_BulletShape;

	// Is this bullet currently wizzing in the air
	bool m_InFlight = false;

	// How fast does a bullet travel
	float m_BulletSpeed = 1000.0f;

	// What fraction of 1 pixel does the bullet travel
	// Horizontally and vertically each frame?
	// These values will be derived from m_BulletSpeed
	float m_BulletDistanceX;
	float m_BulletDistanceY;

	// Where is this bullet headed to?
	float m_XTarget;
	float m_YTarget;

	// Some boundaries so the bullets don't fly forever
	float m_MaxX;
	float m_MinX;
	float m_MaxY;
	float m_MinY;
public:
	Bullet();
	void stop();				// Stop the bullet
	bool isInFlight();			// Returns the value of m_InFlight

	// Launch the bullet
	void shoot( float startX, float startY, float targetX, float targetY );

	sf::FloatRect getPosition();    // Tell the calling code where the bullet is in the world
	sf::RectangleShape getShape();  // Return the actual shape ( for drawing )
	void update(float elapsedTime); // Update the bullet each frame
};

#endif