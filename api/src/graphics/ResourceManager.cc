#include "graphics/RessourceManager.h"

void ResourceManager::LoadAllTextures()
{

    textures_.clear();
    textures_.resize(static_cast<int>(Resource::Max));

    // Textures -----------------
    blankTexture_ = sf::Texture();
    textures_.at(static_cast<int>(Resource::YellowFrame)).loadFromFile("../resources/sprites/yellow_button00.png");
    textures_.at(static_cast<int>(Resource::TerrainGround)).loadFromFile("../resources/sprites/tile_0005.png");
    textures_.at(static_cast<int>(Resource::TerrainForest)).loadFromFile("../resources/sprites/tile_0018.png");

}

ResourceManager::ResourceManager()
{
    LoadAllTextures();
}

sf::Texture& ResourceManager::GetTexture(Resource resourceId) {

    if(static_cast<int>(resourceId) < textures_.size()){
        return textures_.at(static_cast<int>(resourceId));
    }
	else
    {
        return blankTexture_;
    }

}
