#ifndef BUILDING_MANAGER_H_
#define BUILDING_MANAGER_H_

#include <graphics/Tile.h>

#include "building.h"


class BuildingManager : public sf::Drawable
{
private:
	bool is_active_ = true;

	std::vector<Building> buildings_;

public :
	void AddBuilding(const Tile& tile);
	void SetActive(bool active);
	bool GetActive() const;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif // BUILDING_MANAGER_H_