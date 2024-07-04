
#include "gameplay/woods_man.h"

#include <iostream>

#include "bt_tree/bt_leaf.h"

Woodsman::Woodsman(float x, float y, float linear_speed, Tilemap& tilemap) : tilemap_(tilemap), Walker(x, y, linear_speed)
{
	DefineTexture();

	rect_.setPosition(shape_.getGlobalBounds().getPosition());
	rect_.setSize(shape_.getGlobalBounds().getSize());

	//tilemap_ = tilemap;
}

void Woodsman::DefineTexture()
{
	shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kWoodsMan));
}

void Woodsman::InitiateBehaviours()
{

	behaviour_tree::BtLeaf* seek_wood = new behaviour_tree::BtLeaf([this]()
		{
			return SeekWood();
		});

	bt_tree_.AttachNode(seek_wood);

}

void Woodsman::Tick()
{
	// -------------------------------------
	Walker::Tick();
	// -------------------------------------
	bt_tree_.Tick();
}

behaviour_tree::Status Woodsman::SeekWood()
{
	// TODO : closest tree ????
	sf::Vector2f destination = tilemap_.GetClosestTree();

	Path p = Pathfinder::CalculatePath(tilemap_.GetWalkables(), LastDestination(), destination, 64);
	set_path(p);

	std::cout << "Execute seek wood" << std::endl;
	return behaviour_tree::Status::kSuccess;
}
