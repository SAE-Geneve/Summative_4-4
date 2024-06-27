#ifndef API_GRAPHICS_TILEMAP_H_
#define API_GRAPHICS_TILEMAP_H_

#include <iostream>
#include <vector>
#include <functional>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

#include "Tile.h"

class Tilemap final : public sf::Drawable
{
	
public:
	void Setup(sf::Vector2u playground_size_u, sf::Vector2u playground_tile_offset_u);
	void HandleEvent(const sf::Event& event);

	Tilemap() = default;

	void Generate();
	std::vector<sf::Vector2f> GetWalkables();

	std::function<void(Tile&)> ClickedTile;

private:
	sf::Vector2u playground_size_u_;
	sf::Vector2u playground_tile_offset_u_;

	std::vector<Tile> tiles_;

	Tile* tileSelected_;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
	