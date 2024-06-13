#include "graphics/RessourceManager.h"

void ResourceManager::LoadAllTextures()
{

	textures_.clear();
	textures_.resize(static_cast<int>(Resource::Max));

	// Textures -----------------
	blankTexture_ = sf::Texture();
	textures_.at(static_cast<int>(Resource::btnFrame)).loadFromFile("../resources/sprites/yellow_button00.png");
	textures_.at(static_cast<int>(Resource::TerrainGround)).loadFromFile("../resources/sprites/Tile/medievalTile_57.png");
	textures_.at(static_cast<int>(Resource::TerrainForest)).loadFromFile("../resources/sprites/Tile/medievalTile_43.png");
	textures_.at(static_cast<int>(Resource::Building_House)).loadFromFile("../resources/sprites/Structure/medievalStructure_17.png");
	textures_.at(static_cast<int>(Resource::Building_Shop)).loadFromFile("../resources/sprites/Structure/medievalStructure_21.png");

}

ResourceManager& ResourceManager::Get()
{
	static ResourceManager instance_;
	return instance_;
}

ResourceManager::ResourceManager()
{
	LoadAllTextures();
}

sf::Texture& ResourceManager::GetTexture(Resource resourceId) {

	if (static_cast<int>(resourceId) < textures_.size()) {
		return textures_.at(static_cast<int>(resourceId));
	}
	else
	{
		return blankTexture_;
	}

}
