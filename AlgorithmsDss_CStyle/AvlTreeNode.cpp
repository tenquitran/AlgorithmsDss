#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace AlgorithmsDss_CStyle;

//////////////////////////////////////////////////////////////////////////


AvlTreeNode::AvlTreeNode()
    : m_pLeft(nullptr), m_pRight(nullptr), m_key{}, m_height{} /*m_balanceFactor(BalanceFactor::Balanced)*/
{
}

AvlTreeNode::AvlTreeNode(int key)
    : m_pLeft(nullptr), m_pRight(nullptr), m_key(key), m_height{} /*m_balanceFactor(BalanceFactor::Balanced)*/
{
}

AvlTreeNode::~AvlTreeNode()
{
}
