#ifndef API_BT_TREE_BT_TREE_H
#define API_BT_TREE_BT_TREE_H

#include <memory>

#include "bt_node.h"

namespace behaviour_tree
{
	class BtTree
	{
		BtNode* root_;

	public:

		~BtTree();

		void Tick();
		void AttachNode(BtNode* node);

	};

}

#endif

