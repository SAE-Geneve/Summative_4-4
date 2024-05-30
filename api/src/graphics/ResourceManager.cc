#include "graphics/RessourceManager.h"

void ResourceManager::LoadAllTextures()
{
    // Textures -----------------
    blankTexture_ = sf::Texture();
    textures_[Resource::YellowFrame].loadFromFile("../resources/sprites/yellow_button00.png");
    textures_[Resource::TerrainGround].loadFromFile("../resources/sprites/tile_0005.png");

}

ResourceManager::ResourceManager()
{
    LoadAllTextures();
}

sf::Texture& ResourceManager::GetTexture(Resource resourceId) {

	if (textures_.contains(resourceId)) {
        return textures_.at(resourceId);
    }
	else
    {
        return blankTexture_;
    }

    

}
