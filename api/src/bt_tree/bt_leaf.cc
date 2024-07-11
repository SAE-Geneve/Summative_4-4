#include "bt_tree/bt_leaf.h"

using namespace behaviour_tree;

//void BtLeaf::AttachNode(std::unique_ptr<BtNode> node)
//{
//	// Controls ??????
//	child_ = std::move(node);
//}

Status BtLeaf::Process()
{
	if(leaf_action_ != nullptr)
		return leaf_action_();
	else
		return Status::kFailure;

}
