
#include "gameplay/woods_man.h"

Woodsman::Woodsman(float x, float y, float linear_speed) : Walker(x,y, linear_speed)
{
	DefineTexture();
}

void Woodsman::DefineTexture()
{
	shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kWoodsMan));
}
