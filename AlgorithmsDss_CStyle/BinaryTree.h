#pragma once


namespace AlgorithmsDss_CStyle
{
    // TODO: for now, consider implementing AFTER finishing the binary search tree implementation.
    class BinaryTree
    {
    public:
        BinaryTree();

        virtual ~BinaryTree();

    private:
        BinaryTreeNode *m_pRoot;
    };
}
