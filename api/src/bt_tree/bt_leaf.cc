#include "bt_tree/bt_leaf.h"

#include <iostream>

using namespace behaviour_tree;

//void BtLeaf::AttachNode(std::unique_ptr<BtNode> node)
//{
//	// Controls ??????
//	child_ = std::move(node);
//}

Status BtLeaf::Process()
{

	//std::cout << "Leaf Process : " << name_ << std::endl;

	if(leaf_action_ != nullptr)
		return leaf_action_();
	else
		return Status::kFailure;

}
