#pragma once


namespace AlgorithmsDss_CStyle
{
    class AvlTree
    {
    public:
        AvlTree();

        virtual ~AvlTree();

        // Insert node with the specified key.
        // Returns: newly inserted node or an existing node (if the key was found).
        // Throws: std::bad_alloc
        AvlTreeNode* insert(int key);

    private:
        // Recalculate height of the node.
        void recalculateNodeHeight(AvlTreeNode* pNode);

        // Calculate and return balance factor of the node.
        int calculateBalanceFactor(AvlTreeNode* pNode) const;

        // Rotate subtree to the left.
        // Parameters: pR - root of the subtree.
        // Returns: new root of the subtree.
        AvlTreeNode* rotateLeft(AvlTreeNode* pR);

        // Rotate subtree to the right.
        // Parameters: pR - root of the subtree.
        AvlTreeNode* rotateRight(AvlTreeNode* pR);

    private:
        AvlTreeNode *m_pRoot;
    };
}
