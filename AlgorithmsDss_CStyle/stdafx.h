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

#include "../CommonLib/CommonLib.h"

// Graph implementations.
#include "GraphBase.h"
#include "GraphMixedAdjMatrix.h"
#include "GraphMixedAdjLists.h"

// Graph algorithms.
#include "Dijkstra_ShortestPaths.h"
