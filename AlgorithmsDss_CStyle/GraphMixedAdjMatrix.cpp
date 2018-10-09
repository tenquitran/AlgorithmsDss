#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace CommonLib;
using namespace AlgorithmsDss_CStyle;

//////////////////////////////////////////////////////////////////////////


GraphMixedAdjMatrix::GraphMixedAdjMatrix(size_t maximumVertexCount)
    : MaximumVertexCount(maximumVertexCount)
{
    if (MaximumVertexCount < 1)
    {
        throw std::invalid_argument("Maximum vertex count should be positive");
    }

    m_vertices.reserve(MaximumVertexCount);

    // Allocate the adjacency matrix and initialize it with empty values.

    m_adjMatrix = std::make_unique< std::unique_ptr<EdgeWeight[]>[] >(MaximumVertexCount);

    for (size_t i = {}; i < MaximumVertexCount; ++i)
    {
        m_adjMatrix[i] = std::make_unique<EdgeWeight[]>(MaximumVertexCount);

        for (size_t j = {}; j < MaximumVertexCount; ++j)
        {
            m_adjMatrix[i][j] = EdgeWeightDefault;
        }
    }
}

GraphMixedAdjMatrix::~GraphMixedAdjMatrix()
{
}

size_t GraphMixedAdjMatrix::getMaxVertexCount() const
{
    return MaximumVertexCount;
}

void GraphMixedAdjMatrix::addVertex(VertexTag vertexTag)
{
    // Adjacency matrix have a predefined size and cannot be grown.
    if (m_vertices.size() >= MaximumVertexCount)
    {
        std::cerr << "Maximum number of vertices is reached\n";
        assert(false); return;
    }

    m_vertices.push_back(vertexTag);
}

void GraphMixedAdjMatrix::addEdgeDirected(VertexTag src, VertexTag dst, EdgeWeight weight /*= 1*/)
{
    // To add a directed edge, we need to change a single matrix element: [source, destination]

    if (   src >= MaximumVertexCount
        || dst >= MaximumVertexCount)
    {
        std::cerr << "Invalid source (" << src << ") and/or destination (" << dst << ") vertex indices\n";
        assert(false); return;
    }

    m_adjMatrix[src][dst] = weight;
}

void GraphMixedAdjMatrix::addEdgeUndirected(VertexTag src, VertexTag dst, EdgeWeight weight /*= 1*/)
{
    // To add an undirected edge, we need to change two matrix elements: [source, destination] and [destination, source]

    if (   src >= MaximumVertexCount
        || dst >= MaximumVertexCount)
    {
        std::cerr << "Invalid source (" << src << ") and/or destination (" << dst << ") vertex indices\n";
        assert(false); return;
    }

    m_adjMatrix[src][dst] = weight;
    m_adjMatrix[dst][src] = weight;
}

#if 0
bool GraphMixedAdjMatrix::getEdgeWeight(VertexTag src, VertexTag dst, EdgeWeight& weight) const
{
    weight = {};

    if (   src >= MaximumVertexCount
        || dst >= MaximumVertexCount)
    {
        std::cerr << "Invalid source (" << src << ") and/or destination (" << dst << ") vertex indices\n";
        assert(false); return false;
    }

    weight = m_adjMatrix[src][dst];
    return true;
}
#else
EdgeWeight GraphMixedAdjMatrix::getEdgeWeight(VertexTag src, VertexTag dst) const
{
    if (   src >= MaximumVertexCount
        || dst >= MaximumVertexCount)
    {
        assert(false);
        // Windows-specific: typecast to output size_t both in 32- and 64-bit versions.
        throw EXCEPTION_A_FMT("No edge (%I64u, %I64u)", static_cast<unsigned __int64>(src), static_cast<unsigned __int64>(dst));
    }

    // The edge weight can be equal to EdgeWeightDefault (that is, no edge).
    assert(false);

    return m_adjMatrix[src][dst];
}
#endif
