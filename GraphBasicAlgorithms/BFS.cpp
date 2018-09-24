#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace GraphBasicAlgorithms;

//////////////////////////////////////////////////////////////////////////


template <typename Vertex, typename Matrix, Matrix matrixDefault, Matrix matrixEdge>
bool GraphBasicAlgorithms::BFS::bfsAdjacencyMatrix_ReachablePaths_NoLoops(
	const GraphMixedAdjMatrix<Vertex, Matrix, matrixDefault, matrixEdge>& graph, 
	size_t source, 
	std::vector<int>& distances, 
	std::vector<int>& predecessors)
{
	// Initialize distances and predecessors data.

	const size_t VertexCount = graph.getMaxVertexCount();

	distances.assign(VertexCount, (std::numeric_limits<int>::max)());

	predecessors.assign(VertexCount, -1);

	// Initialize data for the source vertex.

	distances[source] = {};

	// Traverse the graph.

	std::queue<size_t> queue;
	queue.push(source);

	while (!queue.empty())
	{
		size_t current = queue.front();
		
		// Explore the neighbour vertices.
		for (size_t i = {}; i < VertexCount; ++i)
		{
			Matrix val = graph.m_adjMatrix[current][i];

			if (matrixEdge == val)
			{
				distances[i] = distances[current] + 1;
				predecessors[i] = current;

				queue.push(i);
			}
		}

		// Note: pop the current vertex from the queue only AFTER processing all its neighbour vertices.
		queue.pop();
	}

	return true;
}

template <typename Vertex, typename Matrix, Matrix matrixDefault, Matrix matrixEdge>
bool BFS::bfsAdjacencyMatrix_ReachablePaths_CanHaveLoops(
	const GraphMixedAdjMatrix<Vertex, Matrix, matrixDefault, matrixEdge>& graph, 
	size_t source, 
	std::vector<int>& distances, 
	std::vector<int>& predecessors)
{
	// Initialize distances and predecessors data.

	const size_t VertexCount = graph.getMaxVertexCount();

	distances.assign(VertexCount, (std::numeric_limits<int>::max)());

	predecessors.assign(VertexCount, -1);

	// Coloring the vertices allows to avoid an infinite cycle on encountering a loop.
	// However, loops will be ignored because their "source" vertices will be immediately colored in gray.
	std::vector<EVertexColor> colors(VertexCount, EVertexColor::White);

	// Initialize data for the source vertex.

	distances[source] = {};

	colors[source] = EVertexColor::Gray;

	// Traverse the graph.

	std::queue<size_t> queue;
	queue.push(source);

	while (!queue.empty())
	{
		size_t current = queue.front();

		// Explore the neighbour vertices.
		for (size_t i = {}; i < VertexCount; ++i)
		{
			Matrix val = graph.m_adjMatrix[current][i];

			if (   matrixEdge == val
				&& EVertexColor::White == colors[i])
			{
				// Even if a graph contains a loop, consider this loop to be of length one.
				distances[i] = distances[current] + 1;
				predecessors[i] = current;

				colors[i] = EVertexColor::Gray;

				queue.push(i);
			}
		}

		// Note: pop the current vertex from the queue only AFTER processing all its neighbour vertices.
		queue.pop();

		colors[current] = EVertexColor::Black;
	}

	return true;
}
