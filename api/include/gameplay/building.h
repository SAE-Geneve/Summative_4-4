#ifndef BUILDING_H
#define BUILDING_H
#include <SFML/Graphics/Sprite.hpp>

class Building : public sf::Drawable{

public:
	Building(float x, float y);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Sprite shape_;

};


#endif // BUILDING_H
