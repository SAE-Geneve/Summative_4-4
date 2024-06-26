#include "gameplay/mill.h"

#include "graphics/ressource_manager.h"

Mill::Mill(float x, float y) : Building(x,y)
{
	DefineTexture();
}

void Mill::DefineTexture()
{
	shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kBuildingMill_01));
}
