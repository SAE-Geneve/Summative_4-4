#ifndef API_GRAPHICS_RESOURCEMANAGER_H
#define API_GRAPHICS_RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class ResourceManager {

public:
	enum class Resource
	{
		btnFrame,
		TerrainGround,
		TerrainForest,
		Building_House,
		Building_Shop,

		// Last value of enum used to get the number of resources
		Max
	};

private:
	std::vector<sf::Texture> textures_;
	sf::Texture blankTexture_;

	ResourceManager();
	void LoadAllTextures();

public:
	static ResourceManager& Get();
	
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;

	sf::Texture& GetTexture(Resource resourceId);

};

#endif
