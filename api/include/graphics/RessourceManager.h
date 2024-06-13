#ifndef API_GRAPHICS_RESOURCEMANAGER_H
#define API_GRAPHICS_RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class ResourceManager {  // NOLINT(cppcoreguidelines-special-member-functions)

public:
	enum class Texture
	{
		kBtnFrame,
		kTerrainGround,
		kTerrainForest,
		kBuildingHouse,
		kBuildingShop,
		kBuildingMill_01,
		kBuildingMill_02,
		kBuildingMill_03,

		// Last value of enum used to get the number of resources
		kMax
	};
	enum class CursorImage
	{
		kBasic,
		kBuild,

		// Last value of enum used to get the number of resources
		kMax
	};

private:
	std::vector<sf::Texture> textures_;
	std::vector<sf::Image> cursor_images_;

	sf::Texture blank_texture_;
	sf::Image blank_cursor_image_;

	ResourceManager();
	void LoadTextures();
	void LoadCursors();

public:
	static ResourceManager& Get();
	
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;

	sf::Texture& GetTexture(Texture resource_id);
	sf::Image& GetCursor(CursorImage cursor_id);

};

#endif
