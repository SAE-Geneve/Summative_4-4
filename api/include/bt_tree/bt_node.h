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
	
	public:
		virtual ~BtNode() = default;
		virtual Status Process() = 0;

		virtual void AddNode(const BtNode& node) = 0;

	};

	class BtNodeList : public BtNode
	{
	protected:
		std::vector<BtNode> children_;

	public:
		void AddNode(const BtNode& node) override;

	};

}
#endif // BT_NODE_H
