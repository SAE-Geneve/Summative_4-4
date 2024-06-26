
#include <SFML/Graphics/RenderTarget.hpp>

#include "graphics/sprite_entity.h"
#include "graphics/ressource_manager.h"

SpriteEntity::SpriteEntity(float x, float y)
{
	shape_.setPosition(x, y);
}

void SpriteEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape_, states);
}
