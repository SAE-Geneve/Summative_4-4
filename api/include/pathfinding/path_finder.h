#ifndef API_PATH_FINDING_PATH_FINDER_H
#define API_PATH_FINDING_PATH_FINDER_H

#include <array>

#include "path.h"


struct PathPoint
{


	sf::Vector2f position;

	// Members
	float f;
	float g;
	float h;

	PathPoint* parent;

	// Ctor
	PathPoint() = default;
	PathPoint(float g, float h, sf::Vector2f position, const PathPoint& parent) : g(g), h(h), position(position)
	{
		this->parent = new PathPoint(parent);
		f = g + h;
	}
	PathPoint(float g, float h, sf::Vector2f position) : g(g), h(h), position(position)
	{
		this->parent = nullptr;
		f = g + h;
	}

	// Methods
	//int f() const { return g + h; } // Total cost function

	//// Operators
	//bool operator<(const PathPoint& other) const {
	//	return this->f() < other.f();
	//}
	//bool operator>(const PathPoint& other) const {
	//	return this->f() > other.f();
	//}
	
	// Operators
	bool operator<(const PathPoint& other) const {
		return this->f < other.f;
	}
	bool operator>(const PathPoint& other) const {
		return this->f > other.f;
	}
};


const std::array kNeighbours = {
	sf::Vector2f(0,1),
	sf::Vector2f(1,0),
	sf::Vector2f(0,-1),
	sf::Vector2f(-1, 0)
};


class PathFinder
{
private:
	std::vector<sf::Vector2f> ConstructPath(const PathPoint& exit_point);

public:
	Path CalculatePath(std::vector<sf::Vector2f> positions, sf::Vector2f start, sf::Vector2f end, int tile_map_offset);

};

#endif // API_PATH_FINDING_PATH_FINDER_H
