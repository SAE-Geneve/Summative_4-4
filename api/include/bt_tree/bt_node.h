#ifndef API_BT_TREE_BT_NODE_H_
#define API_BT_TREE_BT_NODE_H_

#include <vector>

namespace behaviour_tree
{
	class BtLeaf;

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

	};

	class BtNodeList : public BtNode
	{

	protected:
		int current_child_ = 0;
		std::vector<BtNode*> children_;

	public:
		~BtNodeList() override
		{
			for(const auto& ptr : children_)
			{
				delete ptr;
			}
		}
		void AddNode(BtNode* node);

	};


	inline void BtNodeList::AddNode(BtNode* node)
	{
		// Controls ?
		//std::unique_ptr<BtNode> truc = std::make_unique<BtLeaf>();

		children_.push_back(node);
	}

}
#endif // BT_NODE_H
