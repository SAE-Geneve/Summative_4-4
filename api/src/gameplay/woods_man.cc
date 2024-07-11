
#include "gameplay/woods_man.h"

#include <iostream>

#include "sfml_vec2f.h"
#include "bt_tree/bt_leaf.h"
#include "bt_tree/bt_selector.h"
#include "bt_tree/bt_sequence.h"

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
	stamina_ = 30;

	Path p = Pathfinder::CalculatePath(tilemap_.GetWalkables(), LastDestination(), getPosition(), 64);
	set_path(p);

	BtLeaf* check_stamina = new BtLeaf("check stamina", [this]()
		{

			std::cout << "Check Stamina : " << stamina_ << std::endl;

			if (stamina_ >= 0)
				return Status::kSuccess;
			else
				return Status::kFailure;

		}
	);

	BtLeaf* seek_wood = new BtLeaf("seek", [this]()
		{
			return SeekWood();
		}
	);

	BtLeaf* gather_wood = new BtLeaf("gather", [this]()
		{
			return GatherWood();
		}
	);

	BtLeaf* back_home = new BtLeaf("back", [this]()
		{
			return BackHome();
		}
	);

	BtLeaf* refill_stamina = new BtLeaf("check stamina", [this]()
		{
			stamina_ = 30;
			std::cout << "Refill Stamina : " << stamina_ << std::endl;
			return Status::kFailure;
		}
	);

	BtSelector* main_select = new BtSelector();

	BtSequence* gather_sequence = new BtSequence();
	BtSequence* home_sequence = new BtSequence();

	main_select->AddNode(gather_sequence);
	main_select->AddNode(home_sequence);

	gather_sequence->AddNode(check_stamina);
	gather_sequence->AddNode(seek_wood);
	gather_sequence->AddNode(gather_wood);

	home_sequence->AddNode(back_home);
	home_sequence->AddNode(refill_stamina);

	bt_tree_.AttachNode(main_select);

}

void Woodsman::Tick()
{
	// -------------------------------------
	Walker::Tick();
	// -------------------------------------
	bt_tree_.Tick();
}

Status Woodsman::SeekWood()
{
	sf::Vector2f closestTree = tilemap_.GetClosestTree(getPosition());

	if (squaredMagnitude(closestTree - path_.FinalDestination()) > std::numeric_limits<float>::epsilon())
	{
		std::cout << "Recalculate path" << std::endl;
		Path p = Pathfinder::CalculatePath(tilemap_.GetWalkables(), LastDestination(), closestTree, 64);
		set_path(p);

		// - - - - - - - - - - - - - - -
		stamina_ -= p.GetSteps().size();

	}

	if (!path_.IsAvailable())
	{
		std::cout << "Path not available" << std::endl;
		return Status::kFailure;
	}

	float sq_mag = squaredMagnitude(getPosition() - path_.FinalDestination());
	if (sq_mag < std::numeric_limits<float>::epsilon())
	{
		std::cout << "Arrived !!!!!!" << std::endl;
		return Status::kSuccess;
	}
	else
	{
		//std::cout << "Not arrived yet" << std::endl;
		return Status::kRunning;
	}

}


Status Woodsman::GatherWood()
{

	if (tilemap_.GatherTree(getPosition()))
	{
		std::cout << "Cutting trees" << std::endl;
		return Status::kSuccess;
	}

	//std::cout << "not Cutting trees" << std::endl;
	return Status::kFailure;

}

Status Woodsman::BackHome()
{

	sf::Vector2f homePosition = sf::Vector2f(0, 0);

	if (squaredMagnitude(homePosition - path_.FinalDestination()) > std::numeric_limits<float>::epsilon())
	{
		Path p = Pathfinder::CalculatePath(tilemap_.GetWalkables(), LastDestination(), homePosition, 64);
		set_path(p);
	}

	if (!path_.IsAvailable())
	{
		std::cout << "Path not available" << std::endl;
		return Status::kFailure;
	}

	if (squaredMagnitude(getPosition() - path_.FinalDestination()) < std::numeric_limits<float>::epsilon())
	{
		std::cout << "Arrived at home !!!!!!" << std::endl;
		return Status::kSuccess;
	}
	else
	{
		std::cout << "Not arrived yet at home" << std::endl;
		return Status::kRunning;
	}

}