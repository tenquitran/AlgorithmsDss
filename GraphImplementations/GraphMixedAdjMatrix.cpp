#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace GraphImplementations;

//////////////////////////////////////////////////////////////////////////


template <typename Vertex, typename Matrix, Matrix matrixDefault, Matrix matrixEdge>
GraphMixedAdjMatrix<Vertex, Matrix, matrixDefault, matrixEdge>::GraphMixedAdjMatrix(size_t maxVertexCount)
	: MaxVertexCount(maxVertexCount)
{
	if (MaxVertexCount < 1)
	{
		throw std::invalid_argument("Maximum vertex count should be positive");
	}

	m_vertices.reserve(MaxVertexCount);

	m_adjMatrix = std::make_unique< std::unique_ptr<Matrix[]>[] >(MaxVertexCount);

	for (size_t i = {}; i < MaxVertexCount; ++i)
	{
		m_adjMatrix[i] = std::make_unique<Matrix[]>(MaxVertexCount);

		for (size_t j = {}; j < MaxVertexCount; ++j)
		{
			m_adjMatrix[i][j] = matrixDefault;
		}
	}
}

template <typename Vertex, typename Matrix, Matrix matrixDefault, Matrix matrixEdge>
GraphMixedAdjMatrix<Vertex, Matrix, matrixDefault, matrixEdge>::~GraphMixedAdjMatrix()
{
}

template <typename Vertex, typename Matrix, Matrix matrixDefault, Matrix matrixEdge>
size_t GraphMixedAdjMatrix<Vertex, Matrix, matrixDefault, matrixEdge>::getMaxVertexCount() const
{
	return MaxVertexCount;
}

template <typename Vertex, typename Matrix, Matrix matrixDefault, Matrix matrixEdge>
bool GraphMixedAdjMatrix<Vertex, Matrix, matrixDefault, matrixEdge>::addVertex(const Vertex& vertex)
{
	if (m_vertices.size() >= MaxVertexCount)
	{
		std::cerr << "Maximum number of vertices is reached\n";
		return false;
	}

	m_vertices.push_back(vertex);
	return true;
}

template <typename Vertex, typename Matrix, Matrix matrixDefault, Matrix matrixEdge>
bool GraphMixedAdjMatrix<Vertex, Matrix, matrixDefault, matrixEdge>::addEdgeDirected(size_t source, size_t destination)
{
	// To add a directed edge, we need to change a single matrix element: [source, destination] 
	//
	// Thus, for adjacency matrix representation used by simple BFS and DFS, 
	// the edge direction is not required. But in the future, we may have to use an edge weight instead.

	if (   source      >= MaxVertexCount
		|| destination >= MaxVertexCount)
	{
		assert(false); return false;
	}

	m_adjMatrix[source][destination] = matrixEdge;

	return true;
}

template <typename Vertex, typename Matrix, Matrix matrixDefault, Matrix matrixEdge>
bool GraphMixedAdjMatrix<Vertex, Matrix, matrixDefault, matrixEdge>::addEdgeUndirected(size_t source, size_t destination)
{
	// To add an undirected edge, we need to change two matrix elements: [source, destination] and [destination, source]
	//
	// Thus, for adjacency matrix representation used by simple BFS and DFS, 
	// the edge direction is not required. But in the future, we may have to use an edge weight instead.

	if (   source      >= MaxVertexCount
		|| destination >= MaxVertexCount)
	{
		assert(false); return false;
	}

	m_adjMatrix[source][destination] = matrixEdge;
	m_adjMatrix[destination][source] = matrixEdge;

	return true;
}
