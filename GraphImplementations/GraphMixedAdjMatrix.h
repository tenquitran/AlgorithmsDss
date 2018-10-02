#pragma once


namespace GraphImplementations
{
	// Mixed graph using an adjacency matrix representation.
	//
	// Template arguments:
	//     Vertex: vertex data type
	//     Matrix: adjacency matrix data type
	//     matrixDefault: default value of the adjacency matrix
	//     matrixEdge: value of the adjacency matrix that represents an edge. Should differ from defaultValue.
	// Can be the same for directed and undirected edge - in an adjacency matrix representation,
	// the position of the value in the matrix matters.
	template <typename Vertex, typename Matrix, Matrix matrixDefault, Matrix matrixEdge>
	class GraphMixedAdjMatrix
	{
	public:
		// Parameters: maxVertexCount - maximum number of vertices in the graph.
		// Throws: std::invalid_argument, std::bad_alloc
		explicit GraphMixedAdjMatrix(size_t maxVertexCount);

		virtual ~GraphMixedAdjMatrix();

		// Add vertex to the graph.
		bool addVertex(const Vertex& vertex);

		// Add directed edge.
		// Parameters: source - index of the source vertex (zero-based);
		//             destination - index of the destination vertex (zero-based).
		bool addEdgeDirected(size_t source, size_t destination);

		// Add undirected edge.
		// Parameters: source - index of the source vertex (zero-based);
		//             destination - index of the destination vertex (zero-based).
		bool addEdgeUndirected(size_t source, size_t destination);

		// Get maximum number of vertices (the adjacency matrix width).
		size_t getMaxVertexCount() const;

	private:
		GraphMixedAdjMatrix(const GraphMixedAdjMatrix&) = delete;
		GraphMixedAdjMatrix& operator=(const GraphMixedAdjMatrix&) = delete;

	private:
		// Maximum number of vertices in the graph.
		//
		// NOTE: using the actual (existing) number of vertices may cause non-obvious bugs on traversing the graph.
		const size_t MaxVertexCount;

		// Vertices of the graph.
		std::vector<Vertex> m_vertices;

	// The adjacency matrix is public to make the graph algorithms more clear.
	public:
		// Adjacency matrix.
		//
		// NOTE: a single-dimensional array simulating a matrix would make code less readable and slower 
		// (while speed is one of the main benefits of an adjacency matrix representation).
		std::unique_ptr< std::unique_ptr<Matrix[]>[] > m_adjMatrix;
	};
}

#include "GraphMixedAdjMatrix.cpp"
