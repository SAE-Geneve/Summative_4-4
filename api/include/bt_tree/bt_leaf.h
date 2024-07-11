#ifndef API_BT_TREE_BT_LEAF_H
#define API_BT_TREE_BT_LEAF_H

#include <functional>
#include <memory>
#include <string>

#include "bt_node.h"

namespace behaviour_tree
{
	class BtLeaf final : public BtNode
	{

	private:
		std::function<Status()> leaf_action_;
		std::string name_;

	public:
		~BtLeaf() override = default;
		BtLeaf(std::string name, const std::function<Status()>& leaf_action) : leaf_action_(leaf_action), name_(name) {};

		Status Process() override;

	};
}
#endif // API_BT_TREE_BT_LEAF_H
