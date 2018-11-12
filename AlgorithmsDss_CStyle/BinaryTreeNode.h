#pragma once


namespace AlgorithmsDss_CStyle
{
    struct BinaryTreeNode
    {
    public:
        BinaryTreeNode();

        // We need the tree nodes to be polymorphic, 
        // and currently the destructor is the only function that fits the purpose.
        virtual ~BinaryTreeNode();

    public:
        // Left child of the tree node.
        BinaryTreeNode *m_pLeft;

        // Right child of the tree node.
        BinaryTreeNode *m_pRight;

        // Unique key to distinguish tree nodes.
        // In our simple tree implementations, the key is the only data stored in the tree node.
        int m_key;
    };
}
