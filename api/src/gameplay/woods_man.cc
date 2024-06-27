
#include "gameplay/woods_man.h"

Woodsman::Woodsman(float x, float y, float linear_speed) : Walker(x,y, linear_speed)
{
	DefineTexture();

	rect_.setPosition(shape_.getGlobalBounds().getPosition());
	rect_.setSize(shape_.getGlobalBounds().getSize());

}

void Woodsman::DefineTexture()
{
	shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kWoodsMan));
}
