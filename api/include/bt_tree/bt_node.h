#ifndef API_BT_TREE_BT_NODE_H_
#define API_BT_TREE_BT_NODE_H_

#include <vector>

namespace behaviour_tree
{
	enum class Status
	{
		kRunning,
		kFailure,
		kSuccess
	};

	class BtNode
	{
	private:
		std::vector<BtNode> childrens_;

	protected:

	public:
		~BtNode() = default;
		virtual Status Process();

		void AddNode(const BtNode& node);

	};

}
#endif // BT_NODE_H
