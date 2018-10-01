#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace GraphBasicAlgorithms;

//////////////////////////////////////////////////////////////////////////


template <typename Vertex, typename Matrix, Matrix matrixDefault, Matrix matrixEdge>
void DFS::dfsAdjacencyMatrix_ReachablePaths_CanHaveLoops(
	const GraphMixedAdjMatrix<Vertex, Matrix, matrixDefault, matrixEdge>& graph, 
	size_t source, 
	std::vector<int>& distances, 
	std::vector<int>& predecessors)
{
	const size_t VertexCount = graph.getMaxVertexCount();

	distances.assign(VertexCount, (std::numeric_limits<int>::max)());

	predecessors.assign(VertexCount, -1);

	// Initialize data for the source vertex.

	distances[source] = {};

	// Coloring the vertices allows to avoid an infinite cycle on encountering a loop.
	// However, loops will be ignored because their "source" vertices will be immediately colored in gray.
	std::vector<EVertexColor> colors(VertexCount, EVertexColor::White);

	dfsVisitVertex(graph, source, distances, predecessors, colors);
}

template <typename Vertex, typename Matrix, Matrix matrixDefault, Matrix matrixEdge>
void DFS::dfsVisitVertex(
	const GraphMixedAdjMatrix<Vertex, Matrix, matrixDefault, matrixEdge>& graph, 
	size_t currentVertex, 
	std::vector<int>& distances, 
	std::vector<int>& predecessors, 
	std::vector<EVertexColor>& colors)
{
	colors[currentVertex] = EVertexColor::Gray;

	const size_t VertexCount = graph.getMaxVertexCount();

	// Explore the neighbour vertices.
	for (size_t i = {}; i < VertexCount; ++i)
	{
		Matrix val = graph.m_adjMatrix[currentVertex][i];

		if (   matrixEdge == val
			&& EVertexColor::White == colors[i])
		{
			// Even if a graph contains a loop, consider this loop to be of length one.
			distances[i] = distances[currentVertex] + 1;
			predecessors[i] = currentVertex;

			dfsVisitVertex(graph, i, distances, predecessors, colors);
		}
	}

	colors[currentVertex] = EVertexColor::Black;
}
