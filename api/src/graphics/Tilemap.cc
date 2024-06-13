#include <random>
#include <SFML/Graphics/RenderTarget.hpp>

#include "graphics/Tilemap.h"
#include "graphics/RessourceManager.h"
#include "../../../core/include/maths/PerlinNoise.h"

//// Fix 1 : initiate static in the cc file
//sf::Vector2u Tilemap::playground_size_u_ = sf::Vector2u(15, 10);
//sf::Vector2u Tilemap::playground_tile_offset_u_ = sf::Vector2u(18, 18);

int generated = 0;

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

			const siv::PerlinNoise::seed_type seed = generated++;
			const siv::PerlinNoise perlin{ seed };

			double rng = perlin.octave2D_01(x, y, 4);
			std::cout << "Perlin noise value : " << rng << std::endl;

			if (rng >= 0.5f)
			{
				tiles_.emplace_back(ResourceManager::Resource::TerrainGround, x * playground_tile_offset_u_.x, y * playground_tile_offset_u_.y, true);
			}
			else
			{
				tiles_.emplace_back(ResourceManager::Resource::TerrainForest, x * playground_tile_offset_u_.x, y * playground_tile_offset_u_.y, false);
			}

		}
	}
}

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	// Draw all tiles
	for(const auto& tile : tiles_)
	{
		target.draw(tile, states);
	}

	/*
	 *Draw all walkable tiles

	auto tile = tiles_.begin();
	while (tile != tiles_.end())
	{
		tile = std::find_if(tile, tiles_.end(), [](const Tile& t) {return t.Walkable(); });
		if(tile != tiles_.end())
		{
			target.draw(*tile, states);
			++tile;
		}

	}
	*/

	/*
	 *Draw only the tiles that are in the view

	auto tile = tiles_.begin();
	while (tile != tiles_.end())
	{
		tile = std::find_if(tile, tiles_.end(), [](const Tile& t) {return t.Position().x > 20 && t.Position().x < 150; });
		if (tile >= tiles_.end())
			break;

		//
		target.draw(*tile, states);
		++tile;
	}
	*/
}


