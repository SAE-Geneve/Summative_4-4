#ifndef API_GAMEPLAY_WOODS_MAN_H
#define API_GAMEPLAY_WOODS_MAN_H

#include "pathfinding/path_finder.h"
#include "Walker.h"
#include "bt_tree/bt_tree.h"
#include "graphics/Tilemap.h"

class Woodsman : public Walker
{
private:
	Tilemap& tilemap_;

	behaviour_tree::BtTree bt_tree_;

	int stamina_ = 0;

public:
	Woodsman(float x, float y, float linear_speed, Tilemap& tilemap);

	void DefineTexture() override;

	void InitiateBehaviours();
	void Tick();

	behaviour_tree::Status SeekWood();
	behaviour_tree::Status GatherWood();
	behaviour_tree::Status BackHome();
};

#endif // WOODS_MAN_H
