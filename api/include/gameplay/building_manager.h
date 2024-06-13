#ifndef BUILDING_MANAGER_H_
#define BUILDING_MANAGER_H_

class BuildingManager
{
private:
	bool is_active_;

public :
	void AddBuilding();
	void SetActive(bool active);
	bool GetActive();
};
#endif // BUILDING_MANAGER_H_
