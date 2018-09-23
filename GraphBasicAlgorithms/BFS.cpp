#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace GraphBasicAlgorithms;

//////////////////////////////////////////////////////////////////////////


template <typename Vertex, typename Matrix, Matrix matrixDefault, Matrix matrixEdge>
bool GraphBasicAlgorithms::BFS::bfsAdjacencyMatrix_ReachablePaths(
	const GraphMixedAdjMatrix<Vertex, Matrix, matrixDefault, matrixEdge>& graph, 
	size_t source, 
	std::vector<int>& distances, 
	std::vector<int>& predecessors)
{
	// TODO: stub
	return false;
}
