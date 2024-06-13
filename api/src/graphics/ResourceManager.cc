#include "graphics/RessourceManager.h"

void ResourceManager::LoadTextures()
{

	textures_.clear();
	textures_.resize(static_cast<int>(Texture::kMax));

	// Textures -----------------
	blank_texture_ = sf::Texture();
	textures_.at(static_cast<int>(Texture::kBtnFrame)).loadFromFile("../resources/sprites/yellow_button00.png");
	textures_.at(static_cast<int>(Texture::kTerrainGround)).loadFromFile("../resources/sprites/Tile/medievalTile_57.png");
	textures_.at(static_cast<int>(Texture::kTerrainForest)).loadFromFile("../resources/sprites/Tile/medievalTile_43.png");
	textures_.at(static_cast<int>(Texture::kBuildingHouse)).loadFromFile("../resources/sprites/Structure/medievalStructure_17.png");
	textures_.at(static_cast<int>(Texture::kBuildingShop)).loadFromFile("../resources/sprites/Structure/medievalStructure_21.png");
	textures_.at(static_cast<int>(Texture::kBuildingMill_01)).loadFromFile("../resources/sprites/Structure/medievalStructure_Mill_01.png");
	textures_.at(static_cast<int>(Texture::kBuildingMill_02)).loadFromFile("../resources/sprites/Structure/medievalStructure_Mill_02.png");
	textures_.at(static_cast<int>(Texture::kBuildingMill_03)).loadFromFile("../resources/sprites/Structure/medievalStructure_Mill_03.png");

}

void ResourceManager::LoadCursors()
{

	cursor_images_.clear();
	cursor_images_.resize(static_cast<int>(CursorImage::kMax));

	//cursors_.emplace_back();
	cursor_images_.at(static_cast<int>(CursorImage::kBasic)).loadFromFile("../resources/sprites/pointer_scifi_a.png");
	cursor_images_.at(static_cast<int>(CursorImage::kBuild)).loadFromFile("../resources/sprites/tool_hammer.png");

}

ResourceManager& ResourceManager::Get()
{
	static ResourceManager instance_;
	return instance_;
}

ResourceManager::ResourceManager()
{
	LoadTextures();
	LoadCursors();
}

sf::Texture& ResourceManager::GetTexture(Texture resource_id) {

	if (static_cast<int>(resource_id) < textures_.size()) {
		return textures_.at(static_cast<int>(resource_id));
	}
	else
	{
		return blank_texture_;
	}

}

sf::Image& ResourceManager::GetCursor(CursorImage cursor_id)
{
	if (static_cast<int>(cursor_id) < cursor_images_.size()) {
		return cursor_images_.at(static_cast<int>(cursor_id));
	}
	else
	{
		return blank_cursor_image_;
	}



}


