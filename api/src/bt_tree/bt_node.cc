
#include "bt_tree/bt_node.h"

using namespace behaviour_tree;

Status BtNode::Process()
{
	return Status::kFailure;
}

void BtNode::AddNode(const BtNode& node)
{
	// Controls ??????
	childrens_.emplace_back(node);
}
