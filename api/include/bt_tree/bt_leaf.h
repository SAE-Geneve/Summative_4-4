#ifndef API_BT_TREE_BT_LEAF_H
#define API_BT_TREE_BT_LEAF_H

#include <functional>
#include <memory>

#include "bt_node.h"

namespace behaviour_tree
{
	class BtLeaf final : public BtNode
	{

	private:
		std::function<Status()> leaf_action_;
		std::unique_ptr<BtNode> child_;

	public:
		~BtLeaf() override = default;
		BtLeaf(const std::function<Status()>& leaf_action) : leaf_action_(leaf_action) {};

		Status Process() override;
		void AddNode(const BtNode& node) override {};

		void AttachNode(std::unique_ptr<BtNode> node);

	};
}
#endif // API_BT_TREE_BT_LEAF_H
