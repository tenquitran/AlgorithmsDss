// GraphBasicAlgorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace CommonLib;

using namespace GraphImplementations;

using namespace GraphBasicAlgorithms;

//////////////////////////////////////////////////////////////////////////


int _tmain(int /*argc*/, _TCHAR* /*argv[]*/)
{
	// CommonLib test.
#if 1
	try
	{
		// Test clearing of the console.

#if 0

		ConsoleWnd console;

		TCHAR chars[] = { 'a', 'b', 'c', 'd', 'e' };

		const size_t ArrLen = _countof(chars);

		WORD colors[ArrLen] = { FOREGROUND_RED, FOREGROUND_GREEN, FOREGROUND_BLUE, FOREGROUND_RED, FOREGROUND_GREEN };

		for (size_t i = {}; i < 150; ++i)
		{
			size_t index = i % ArrLen;

			if (!console.clear(chars[index], colors[index]))
			{
				int tmp = 1;
			}

			::Sleep(100);
		}
#endif
	}
	catch (const ExceptionA& ex)
	{
		std::cerr << ex.message() << '\n';
	}
#endif

	// GraphImplementations test.
#if 1
	const size_t MaxVertices = 5;

	//GraphMixedAdjMatrix<VertexDataStatic<int, double>, char> g1(MaxVertices);
	GraphMixedAdjMatrix<VertexDataStatic<int, double>, char, ' ', 'v'> g1(MaxVertices);
	//GraphMixedAdjMatrix<VertexDataStatic<int, double>, EEdgeDirection> g1(MaxVertices);

	for (size_t i = {}; i < MaxVertices; ++i)
	{
		g1.addVertex(VertexDataStatic<int, double>(i, i));
	}

	g1.addEdgeDirected(2, 1);
	g1.addEdgeDirected(1, 0);

	g1.addEdgeUndirected(3, 4);
	
#if 0
	g1.addEdgeDirected(2, 2);    // add loop
#endif

	std::vector<int> distances;
	std::vector<int> predecessors;

	bool res1 = BFS::bfsAdjacencyMatrix_ReachablePaths_CanHaveLoops(g1, 2, distances, predecessors);

	bool res2 = BFS::bfsAdjacencyMatrix_ReachablePaths_NoLoops(g1, 2, distances, predecessors);

#endif


#if 1
	GraphMixedAdjLists< VertexDataStatic<int, double> > g2;

	for (int i = {}; i < 5; ++i)
	{
		g2.addVertex(i, VertexDataStatic<int, double>(i, i));
	}

	g2.addVertex(0, VertexDataStatic<int, double>(1, 1.1));
	
#endif

	return 0;
}
