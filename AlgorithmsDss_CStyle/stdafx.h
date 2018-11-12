// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


//////////////////////////////////////////////////////////////////////////
// Additional headers our program requires.
//////////////////////////////////////////////////////////////////////////

#include <memory>
#include <limits>
#include <algorithm>

#include "../CommonLib/CommonLib.h"

// Sorting algorithms.
#include "SelectionSort.h"
#include "SelectionSortTemplate.h"

// Graph implementations.
#include "GraphBase.h"
#include "GraphMixedAdjMatrix.h"
#include "GraphMixedAdjLists.h"

// Graph algorithms.
#include "Dijkstra_ShortestPaths.h"

// Tree implementations.
#include "BinaryTreeNode.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "AvlTreeNode.h"
#include "AvlTree.h"
