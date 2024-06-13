
#include <SFML/Graphics/RenderTarget.hpp>

#include "gameplay/building.h"
#include "graphics/RessourceManager.h"

Building::Building(float x, float y)
{
	shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kBuildingHouse));
	shape_.setPosition(x, y);
}

void Building::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape_, states);
}