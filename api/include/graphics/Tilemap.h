#ifndef API_GRAPHICS_TILEMAP_H_
#define API_GRAPHICS_TILEMAP_H_

#include <iostream>
#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

#include "Tile.h"

class Tilemap final : public sf::Drawable
{
	
public:

	sf::Vector2u playground_size_u_;
	sf::Vector2u playground_tile_offset_u_;

	void Setup(sf::Vector2u playground_size_u, sf::Vector2u playground_tile_offset_u);

	Tilemap()
	{
		//tiles_.reserve(playground_size_u_.x * playground_size_u_.y);
	}	

	void Generate();

private:
	std::vector<Tile> tiles_;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
	