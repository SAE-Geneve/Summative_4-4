#include <random>
#include <SFML/Graphics/RenderTarget.hpp>

#include "sfml_vec2f.h"
#include "graphics/Tilemap.h"
#include "graphics/ressource_manager.h"
#include "../../../core/include/maths/perlin_noise.h"

//// Fix 1 : initiate static in the cc file
//sf::Vector2u Tilemap::playground_size_u_ = sf::Vector2u(15, 10);
//sf::Vector2u Tilemap::playground_tile_offset_u_ = sf::Vector2u(18, 18);

int generated = 0;

void Tilemap::Setup(sf::Vector2u playground_size_u, sf::Vector2u playground_tile_offset_u)
{
	playground_size_u_ = playground_size_u;
	playground_tile_offset_u_ = playground_tile_offset_u;
	tileSelected_ = nullptr;
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
			//std::cout << "Add a sprite in that position " << x << ":" << y << std::endl;

			const siv::PerlinNoise::seed_type seed = generated++;
			const siv::PerlinNoise perlin{ seed };

			double rng = perlin.octave2D_01(x, y, 4);
			//std::cout << "Perlin noise value : " << rng << std::endl;
			double tile_x = x * playground_tile_offset_u_.x;
			double tile_y = y * playground_tile_offset_u_.y;

			if (rng >= 0.4f)
			{
				tiles_.emplace_back(Tile::TileType::kGround, tile_x, tile_y, true);
			}
			else
			{
				tiles_.emplace_back(Tile::TileType::kForest, tile_x, tile_y, false);
				trees_.emplace_back(tile_x, tile_y);
			}

		}
	}

	tileSelected_ = &(*tiles_.begin());
	tileSelected_->Unselect();

}

std::vector<sf::Vector2f> Tilemap::GetWalkables()
{

	std::vector<sf::Vector2f> walkables;

	std::for_each(tiles_.begin(), tiles_.end(), [&walkables](const Tile& t) {

		if (t.is_walkable())
		{
			walkables.emplace_back(t.Position());
		}

		});

	return walkables;

}

sf::Vector2f Tilemap::GetClosestTree(sf::Vector2f pos)
{
	sf::Vector2f closestTree;

	float closest_tree_distance = std::numeric_limits<float>::infinity();

	// TODO : fill what the closest tree is
	std::for_each(trees_.begin(), trees_.end(), [&closest_tree_distance, &closestTree, pos](const sf::Vector2f& tree)
		{

			const float sq_dist = squaredMagnitude(tree - pos);

			if(sq_dist < closest_tree_distance)
			{
				closestTree = tree;
				closest_tree_distance = sq_dist;
			}

		});

	return closestTree;

}

bool Tilemap::GatherTree(sf::Vector2f pos)
{

	auto tree = std::find_if(trees_.begin(), trees_.end(), [pos](const sf::Vector2f& t) { return pos == t; });

	if(tree != trees_.end())
	{
		trees_.erase(tree);

		// change tile type -----------
		auto tile = std::find_if(tiles_.begin(), tiles_.end(), [pos](const Tile& t) { return pos == t.Position(); });

		if(tile != tiles_.end())
		{
			tile->SetType(Tile::TileType::kCutTree);
		}

		return true;
	}else
	{
		return false;
	}


}


void Tilemap::HandleEvent(const sf::Event& event)
{
	// Check for mouse button pressed event
	if (event.type == sf::Event::MouseMoved) {

		sf::Vector2f mousePosition = sf::Vector2f(
			event.mouseMove.x - event.mouseMove.x % playground_tile_offset_u_.x,
			event.mouseMove.y - event.mouseMove.y % playground_tile_offset_u_.y
		);

		// Unselect one cached
		if (tileSelected_) {
			tileSelected_->Unselect();
		}

		// Unselect all
		//std::for_each(tiles_.begin(), tiles_.end(), [](Tile& t) {t.Unselect(); });

		auto tileFound = std::find_if(tiles_.begin(), tiles_.end(), [&mousePosition](Tile& t) {return t.Position() == mousePosition; });
		if (tileFound != tiles_.end()) {
			tileSelected_ = &(*tileFound);
			tileSelected_->Select();
		}

	}


	if (event.type == sf::Event::MouseButtonReleased)
	{
		// Check if the left mouse button is pressed
		if (event.mouseButton.button == sf::Mouse::Left) {
			// Code � faire pour le bouton ---------------------------------------------------
			if (ClickedTile && tileSelected_ != nullptr) {
				ClickedTile(*tileSelected_);
			}
			else
			{
				std::cout << "No callback defined...";
			}
		}
	}

}

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Draw all tiles
	for (const auto& tile : tiles_)
	{
		target.draw(tile, states);
	}
}


