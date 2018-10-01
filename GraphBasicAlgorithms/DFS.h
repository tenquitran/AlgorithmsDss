#pragma once


namespace GraphBasicAlgorithms
{
	// Depth-first traversal algorithms.
	class DFS
	{
	public:
		// Depth-first traversal.
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
		static void dfsAdjacencyMatrix_ReachablePaths_CanHaveLoops(
			const GraphMixedAdjMatrix<Vertex, Matrix, matrixDefault, matrixEdge>& graph,
			size_t source,
			std::vector<int>& distances,
			std::vector<int>& predecessors);

	private:
		// Visit current vertex (part of the DFS traversal).
		template <typename Vertex, typename Matrix, Matrix matrixDefault, Matrix matrixEdge>
		static void dfsVisitVertex(
			const GraphMixedAdjMatrix<Vertex, Matrix, matrixDefault, matrixEdge>& graph,
			size_t currentVertex,
			std::vector<int>& distances,
			std::vector<int>& predecessors,
			std::vector<EVertexColor>& colors);
	};
}

#include "DFS.cpp"
