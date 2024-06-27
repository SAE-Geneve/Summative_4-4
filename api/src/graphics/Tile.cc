#include "graphics/Tile.h"
#include <iostream>

Tile::Tile(TileType type, float x = 0, float y = 0, bool is_walkable = true)
{

	type_ = type;
	
	sprite_.setTexture(GetFromType());
	sprite_.setPosition(x, y);

	outline_.setSize(sf::Vector2f(sprite_.getTexture()->getSize()));
	outline_.setPosition(x, y);
	outline_.setFillColor(sf::Color(255, 255, 255, 0));
	outline_.setOutlineColor(sf::Color::White);
	outline_.setOutlineThickness(-1);

	is_walkable_ = is_walkable;
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite_, states);

	if (is_selected_) {
		//std::cout << "draw selected tile [" << outline_.getPosition().x << ":" << outline_.getPosition().y << "]" << std::endl;
		target.draw(outline_, states);
	}
}

void Tile::set_walkable(const bool is_walkable)
{
	is_walkable_ = is_walkable;
}

void Tile::Select()
{
	is_selected_ = true;
}
void Tile::Unselect()
{
	is_selected_ = false;
}

sf::Texture& Tile::GetFromType()
{
	switch (type_)
	{
	case TileType::kForest:
		if(rand() % 2 != 0)
			return ResourceManager::Get().GetTexture(ResourceManager::Texture::kTerrainForest);
		else
			return ResourceManager::Get().GetTexture(ResourceManager::Texture::kTerrainForest);
		break;

	case TileType::kGround:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::kTerrainGround);
		break;

	}



}
