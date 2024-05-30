#include "graphics/Tilemap.h"

#include <SFML/Graphics/RenderTarget.hpp>

#include "graphics/RessourceManager.h"

// Fix 1 : initiate static in the cc file
sf::Vector2u Tilemap::playground_size_u_ = sf::Vector2u(5, 5);
sf::Vector2u Tilemap::playground_tile_offset_u_ = sf::Vector2u(18, 18);

void Tilemap::Generate()
{

	tiles_.clear();

	for (unsigned int x = 0; x < playground_size_u_.x; x++)
	{
		for (unsigned int y = 0; y < playground_size_u_.x; y++)
		{
			std::cout << "Add a sprite in that position " << x << ":" << y << std::endl;

			int idx = x * playground_size_u_.x + y;
			tiles_.emplace_back() = sf::Sprite();
			tiles_[idx].setTexture(ResourceManager::Get().GetTexture(ResourceManager::Resource::TerrainGround));
			tiles_[idx].setPosition(x * playground_tile_offset_u_.x, y * playground_tile_offset_u_.y);

		}
	}
}

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(auto tile : tiles_)
	{
		std::cout << "Draw a sprite in that position " << tile.getPosition().x << ":" << tile.getPosition().y << std::endl;

		target.draw(tile, states);
	}
}

