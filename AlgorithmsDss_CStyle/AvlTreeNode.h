#pragma once


namespace AlgorithmsDss_CStyle
{
    // Balance factor of an AVL tree node.
    // Suppose the balance factor is (right_subtree_height - left_subtree_height).
    enum class BalanceFactor
    {
        // We don't need the default "undefined" value.
        // If a node has no children, both its subtrees have a zero height, hence the node is balanced.
        LeftHeavy = -1,
        Balanced = 0,
        RightHeavy = 1
    };


    // AVL tree node has been intentionally made independent of other binary tree nodes.
    struct AvlTreeNode
    {
    public:
        AvlTreeNode();

        explicit AvlTreeNode(int key);

        virtual ~AvlTreeNode();

    public:
        // Left child of the tree node.
        AvlTreeNode *m_pLeft;

        // Right child of the tree node.
        AvlTreeNode *m_pRight;

        // Unique key to distinguish tree nodes.
        // In our simple tree implementations, the key is the only data stored in the tree node.
        int m_key;

#if 0
        BalanceFactor m_balanceFactor;
#else
        // Height of the node. Note that it can be minus one (for non-existing nodes).
        int m_height;
#endif
    };
}
