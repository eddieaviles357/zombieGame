#include "TextureHolder.h"
#include <assert.h> // used to end the program with a certain condition is met http://www.cplusplus.com/reference/cassert/assert/

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder()
{
	assert(m_s_Instance == nullptr); // if instance is already created ends program
	m_s_Instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename)
{
	// get a reference to m_Textures using m_s_Instance
	//std::map<std::string, sf::Texture>& m = m_s_Instance->m_Textures;	// long way of declaring
	auto& m = m_s_Instance->m_Textures;

	// create an iterator to hold a key-value-pair ( KVP ) and search for the required ( KVP ) using the passed in file name
	//std::map<std::string, sf::Texture>::iterator keyValuePair = m.find(filename);	// long way of declaring
	auto keyValuePair = m.find(filename);

	// Did we find a match?
	if (keyValuePair != m.end())
	{
		// Yes, return the texture, the second part of the KVP ( the texture ) { key(first): value( second ) }
		return keyValuePair->second;
	}
	else
	{
		// File not found, Create a new key value pair using the filenme
		auto& texture = m[filename];

		// Load the texture from file in the usual way
		texture.loadFromFile(filename);

		// Return the texture to the calling code
		return texture;
	}
}