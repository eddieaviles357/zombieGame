#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

#include <SFML/graphics.hpp>
#include <map>

class TextureHolder
{
private:
	// A map container from the STL
	std::map<std::string, sf::Texture> m_Textures;
	// A pointer of the same class itself
	// The one and only instance
	static TextureHolder* m_s_Instance;
public:
	TextureHolder();

	// Returns a reference of object TextureHolder
	static sf::Texture& GetTexture(std::string const& filename);
};

#endif