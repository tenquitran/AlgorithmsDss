#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace CommonLib;
using namespace AlgorithmsDss_CStyle;

//////////////////////////////////////////////////////////////////////////


AvlTree::AvlTree()
    : m_pRoot(nullptr)
{
}

AvlTree::~AvlTree()
{
    // TODO: delete the nodes
    assert(false);
}

int AvlTree::getTreeHeight(AvlTreeNode* pNode) const
{
    if (!pNode)
    {
        return 0;
    }

    return ((std::max)(getTreeHeight(pNode->m_pLeft), getTreeHeight(pNode->m_pRight)) + 1);
}

void AvlTree::recalculateNodeHeight(AvlTreeNode* pNode)
{
#if 1
    // By convention, height of the empty node is minus one.
    int height = -1;
#else
    int height = {};
#endif

    if (pNode->m_pLeft)
    {
        height = (std::max)(height, pNode->m_pLeft->m_height);
    } 
    
    if (pNode->m_pRight)
    {
        height = (std::max)(height, pNode->m_pRight->m_height);
    }

    pNode->m_height = (height + 1);
}

int AvlTree::calculateBalanceFactor(AvlTreeNode* pNode) const
{
    int leftHeight  = {};
    int rightHeight = {};

    if (pNode->m_pLeft)
    {
        leftHeight = pNode->m_pLeft->m_height + 1;
    }

    if (pNode->m_pRight)
    {
        rightHeight = pNode->m_pRight->m_height + 1;
    }

    return (leftHeight - rightHeight);
}

AvlTreeNode* AvlTree::insert(int key)
{
    // TODO: temp
#if 1
    int height1 = getTreeHeight(m_pRoot);
#endif

    if (!m_pRoot)
    {
        // Insert root node.
        m_pRoot = new AvlTreeNode(key);
        return m_pRoot;
    }

    AvlTreeNode *pNewRoot = m_pRoot;

    // true if the insertion has been made to the right subtree.
    bool insertedToRight = false;

    while (true)
    {   // Find a place for node insertion.

        if (key == pNewRoot->m_key)
        {
            return pNewRoot;    // node with this key already exists
        }
        else if (key > pNewRoot->m_key)    // move to the right
        {
            if (!pNewRoot->m_pRight)
            {
                pNewRoot->m_pRight = new AvlTreeNode(key);

                insertedToRight = true;
                break;
            }

            pNewRoot = pNewRoot->m_pRight;
        }
        else if (key < pNewRoot->m_key)    // move to the left
        {
            if (!pNewRoot->m_pLeft)
            {
                pNewRoot->m_pLeft = new AvlTreeNode(key);
                break;
            }

            pNewRoot = pNewRoot->m_pLeft;
        }

    }   // Find a place for node insertion.

#if 0
    // Update height of the node.
    recalculateNodeHeight(pNewRoot);
#endif

    // Rebalance the tree if required.

    if (insertedToRight)
    {
        if (-2 == calculateBalanceFactor(pNewRoot))
        {
            if (key > pNewRoot->m_pRight->m_key)
            {
                pNewRoot = rotateLeft(pNewRoot);
            } 
            else
            {
                pNewRoot = rotateRight(pNewRoot);
                pNewRoot = rotateLeft(pNewRoot);
            }
        }
    } 
    else
    {
        if (2 == calculateBalanceFactor(pNewRoot))
        {
            if (key <= pNewRoot->m_pLeft->m_key)
            {
                pNewRoot = rotateRight(pNewRoot);
            } 
            else
            {
                pNewRoot = rotateLeft(pNewRoot);
                pNewRoot = rotateRight(pNewRoot);
            }
        }
    }

    // TODO: temp
#if 1
    int height2 = getTreeHeight(m_pRoot);
#endif

#if 1
    // Update height of the node.
    recalculateNodeHeight(pNewRoot);
#endif

    return pNewRoot;
}

AvlTreeNode* AvlTree::rotateLeft(AvlTreeNode* pR)
{
    if (!pR)
    {
        assert(false); throw EXCEPTION_A("Root node is NULL");
    }
    else if (!pR->m_pRight)
    {
        assert(false); throw EXCEPTION_A("Root node\'s right child is NULL");
    }

    // Rotate subtree rooted with R to the left (C - child, G - grandchild, TN - subtrees).
    // The rotation involves R, C and T2 which is the left subtree of the child.
    //
    //      R
    //    /   \
    //   T1    C
    //       /   \
    //      T2    G
    //          /   \
    //         T3    T4

    AvlTreeNode *pC = pR->m_pRight;    // C
    AvlTreeNode *p2 = pC->m_pLeft;     // T2

    // Rotate.
    pC->m_pLeft  = pR;
    pR->m_pRight = p2;

    // Recalculate height of the nodes.
    recalculateNodeHeight(pR);
    recalculateNodeHeight(pC);

    return pC;
}

AvlTreeNode* AvlTree::rotateRight(AvlTreeNode* pR)
{
    if (!pR)
    {
        assert(false); throw EXCEPTION_A("Root node is NULL");
    }
    else if (!pR->m_pLeft)
    {
        assert(false); throw EXCEPTION_A("Root node\'s left child is NULL");
    }

    // Rotate subtree rooted with R to the right (C - child, G - grandchild, TN - subtrees).
    // The rotation involves R, C and T2 which is the right subtree of the child.
    //
    //            R
    //          /   \
    //         C     T1
    //       /   \
    //      G     T2
    //    /   \
    //   T3   T4

    AvlTreeNode *pC = pR->m_pLeft;     // C
    AvlTreeNode *p2 = pC->m_pRight;    // T2

    // Rotate.
    pC->m_pRight = pR;
    pR->m_pLeft  = p2;
    
    // Recalculate height of the nodes.
    recalculateNodeHeight(pR);
    recalculateNodeHeight(pC);

    return pC;
}
