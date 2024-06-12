#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "graphics/RessourceManager.h"

class Tile : public sf::Drawable {

public:
	Tile(ResourceManager::Resource resource, float x, float y, bool is_walkable);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Sprite sprite_;
	bool isWalkable_;
public:
	bool Walkable() const { return isWalkable_; }
	sf::Vector2f Position() const { return sprite_.getPosition(); }

};

#endif // TILE_H
