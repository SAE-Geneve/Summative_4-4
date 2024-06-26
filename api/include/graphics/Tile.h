#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "graphics/ressource_manager.h"

class Tile : public sf::Drawable {

public:
	enum class TileType
	{
		kGround,
		kForest
	};

	Tile(TileType type_, float x, float y, bool is_walkable);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Sprite sprite_;
	sf::RectangleShape outline_;

	bool isWalkable_;
	bool isSelected_ = false;

	TileType type_;

public:
	bool Walkable() const { return isWalkable_; }
	sf::Vector2f Position() const { return sprite_.getPosition(); }
	TileType Type() const { return type_; }

	void Select();
	void Unselect();
	sf::Texture& GetFromType();
};

#endif // TILE_H
