#ifndef API_BT_TREE_BT_SEQUENCE_H
#define API_BT_TREE_BT_SEQUENCE_H

#include <iostream>

#include "bt_tree/bt_node.h"

using namespace behaviour_tree;

class BtSequence : public BtNodeList
{
public:
	~BtSequence() override = default;

	Status Process() override;
	void ResetSequence();

};

inline Status BtSequence::Process()
{

	if (current_child_ < children_.size())
	{
		const Status status = children_[current_child_]->Process();

		if (status == Status::kSuccess)
		{
			std::cout << "Next sequence !" << std::endl;

			current_child_++;
			if (current_child_ >= children_.size())
			{
				current_child_ = 0;
				return Status::kSuccess;
			}
			else
			{
				return Status::kRunning;
			}
		}

		return status;


	}

	return Status::kFailure;

}

inline void BtSequence::ResetSequence()
{
	current_child_ = 0;
}

#endif

