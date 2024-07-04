#ifndef API_BT_TREE_BT_LEAF_H
#define API_BT_TREE_BT_LEAF_H

#include <functional>

#include "bt_node.h"

namespace behaviour_tree
{
	class BtLeaf final : public BtNode
	{

	private:
		std::function<Status()> leaf_action_;

	public:
		BtLeaf(const std::function<Status()>& leaf_action) : leaf_action_(leaf_action) {};

		Status Process() override;

	};
}
#endif // API_BT_TREE_BT_LEAF_H
