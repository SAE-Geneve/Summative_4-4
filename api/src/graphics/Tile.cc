#include "graphics/Tile.h"

Tile::Tile(ResourceManager::Resource resource, float x = 0, float y = 0, bool is_walkable = true)
{
	sprite_.setTexture(ResourceManager::Get().GetTexture(resource));
	sprite_.setPosition(x, y);

	isWalkable_ = is_walkable;
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite_, states);
}
