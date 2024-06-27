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

	bool is_walkable_;
	bool is_selected_ = false;

	TileType type_;

public:

	bool is_walkable() const { return is_walkable_; }
	void set_walkable( bool is_walkable);

	sf::Vector2f Position() const { return sprite_.getPosition(); }
	TileType Type() const { return type_; }

	void Select();
	void Unselect();
	sf::Texture& GetFromType();
};

#endif // TILE_H
