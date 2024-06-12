#ifndef API_GRAPHICS_RESOURCEMANAGER_H
#define API_GRAPHICS_RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class ResourceManager {

public:
	enum class Resource
	{
		YellowFrame,
		TerrainGround,
		TerrainForest,

		// Last value of enum used to get the number of resources
		Max
	};

private:
	std::vector<sf::Texture> textures_;
	sf::Texture blankTexture_;

	void LoadAllTextures();

public:
	static ResourceManager& Get() {
		static ResourceManager instance_;
		return instance_;
	}

	
	ResourceManager();
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;

	sf::Texture& GetTexture(Resource resourceId);

};

#endif
