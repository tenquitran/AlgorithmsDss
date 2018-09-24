#pragma once


namespace GraphBasicAlgorithms
{
	// Breadth-first traversal algorithms.
	class BFS
	{
	public:
		// Breadth-first traversal.
		// Works with the adjacency matrix representation of the graph.
		// Ignores vertices unreachable from the source vertex.
		// The graph should NOT contain loops.
		//
		// Parameters: graph - graph to traverse;
		//             source - index of the source vertex (zero-based);
		//             distances - distances of each vertex from the source (measured in number of edges between the vertices);
		//             predecessors - predecessors of each vertex (or -1 if the vertex is not reachable from the source vertex).
		// Returns: true on successful algorithm execution, false otherwise.
		template <typename Vertex, typename Matrix, Matrix matrixDefault, Matrix matrixEdge>
		static bool bfsAdjacencyMatrix_ReachablePaths_NoLoops(
			const GraphMixedAdjMatrix<Vertex, Matrix, matrixDefault, matrixEdge>& graph,
			size_t source,
			std::vector<int>& distances,
			std::vector<int>& predecessors);

		// Breadth-first traversal.
		// Works with the adjacency matrix representation of the graph.
		// Ignores vertices unreachable from the source vertex.
		// The graph can contain loops (which will be ignored).
		//
		// Parameters: graph - graph to traverse;
		//             source - index of the source vertex (zero-based);
		//             distances - distances of each vertex from the source (measured in number of edges between the vertices);
		//             predecessors - predecessors of each vertex (or -1 if the vertex is not reachable from the source vertex).
		// Returns: true on successful algorithm execution, false otherwise.
		template <typename Vertex, typename Matrix, Matrix matrixDefault, Matrix matrixEdge>
		static bool bfsAdjacencyMatrix_ReachablePaths_CanHaveLoops(
			const GraphMixedAdjMatrix<Vertex, Matrix, matrixDefault, matrixEdge>& graph,
			size_t source,
			std::vector<int>& distances,
			std::vector<int>& predecessors);
	};
}

#include "BFS.cpp"
