#include "graphics/Tilemap.h"

#include <random>
#include <SFML/Graphics/RenderTarget.hpp>

#include "graphics/RessourceManager.h"

//// Fix 1 : initiate static in the cc file
//sf::Vector2u Tilemap::playground_size_u_ = sf::Vector2u(15, 10);
//sf::Vector2u Tilemap::playground_tile_offset_u_ = sf::Vector2u(18, 18);

void Tilemap::Setup(sf::Vector2u playground_size_u, sf::Vector2u playground_tile_offset_u)
{
	playground_size_u_ = playground_size_u;
	playground_tile_offset_u_ = playground_tile_offset_u;
}

void Tilemap::Generate()
{

	tiles_.clear();
	tiles_.erase(tiles_.begin(), tiles_.end());
	tiles_.reserve(playground_size_u_.x * playground_size_u_.y);

	for (unsigned int x = 0; x < playground_size_u_.x; x++)
	{
		for (unsigned int y = 0; y < playground_size_u_.y; y++)
		{
			std::cout << "Add a sprite in that position " << x << ":" << y << std::endl;


			// Perlin noise ????
			// For instance, just random
			// Seed with a real random value, if available
			std::random_device r;

			// Choose a random mean between 1 and 6
			std::default_random_engine e1(r());
			std::uniform_int_distribution<int> uniform_dist(1, 2);

			int rnd = uniform_dist(e1);
			if (rnd == 1)
			{
				tiles_.emplace_back(ResourceManager::Resource::TerrainGround, x * playground_tile_offset_u_.x, y * playground_tile_offset_u_.y, true);
			}
			else if (rnd == 2)
			{
				tiles_.emplace_back(ResourceManager::Resource::TerrainForest, x * playground_tile_offset_u_.x, y * playground_tile_offset_u_.y, false);
			}


		}
	}
}

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	auto tile = tiles_.begin();

	//while (tile != tiles_.end())
	//{
	//	tile = std::find_if(tile, tiles_.end(), [](const Tile& t) {return t.Walkable(); });
	//	if(tile != tiles_.end())
	//	{
	//		target.draw(*tile, states);
	//		++tile;
	//	}

	//}

	while (tile != tiles_.end())
	{
		tile = std::find_if(tile, tiles_.end(), [](const Tile& t) {return t.Position().x > 20 && t.Position().x < 150; });
		if (tile >= tiles_.end())
			break;

		//
		target.draw(*tile, states);
		++tile;
	}

}


