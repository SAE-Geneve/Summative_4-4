#include "gameplay/building_manager.h"

void BuildingManager::SetActive(bool active)
{
	is_active_ = active;
}
bool BuildingManager::GetActive()
{
	return is_active_;
}

void BuildingManager::AddBuilding()
{
	if(!is_active_)
	{
		return;
	}

}

