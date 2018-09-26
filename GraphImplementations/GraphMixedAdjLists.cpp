#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace GraphImplementations;

//////////////////////////////////////////////////////////////////////////


#if 0
template <typename Vertex>
GraphMixedAdjLists<Vertex>::GraphMixedAdjLists(size_t vertexCount)
	: VertexCount(vertexCount)
{
	for (size_t i = {}; i < VertexCount; ++i)
	{
		m_vertices.insert(i, VertexList());
	}
}
#endif

template <typename Vertex, typename Weight, typename EdgeWeight>
GraphMixedAdjLists<Vertex, Weight, EdgeWeight>::GraphMixedAdjLists()
{
}

template <typename Vertex, typename Weight, typename EdgeWeight>
GraphMixedAdjLists<Vertex, Weight, EdgeWeight>::~GraphMixedAdjLists()
{
}

template<typename VertexLabel, typename VertexData, typename EdgeWeight>
bool GraphMixedAdjLists<VertexLabel, VertexData, EdgeWeight>::addVertex(VertexLabel label, const VertexData& vertexData)
{
	// Add vertex data.

	std::pair< std::map<VertexLabel, VertexData>::iterator, bool > vertexItr = 
		m_vertices.insert(std::pair<VertexLabel, VertexData>(label, vertexData));

	if (!vertexItr.second)
	{
		std::cerr << "Duplicate vertex label (graph): " << label << '\n';
		return false;
	}

	// Add adjacency lists data (initially empty).

	std::pair< std::map<VertexLabel, VertexList>::iterator, bool > adjListItr = 
		m_adjacencyLists.insert(std::pair<VertexLabel, VertexList>(label, VertexList()));

	if (!adjListItr.second)
	{
		std::cerr << "Duplicate vertex label (adjacency lists): " << label << '\n';
		return false;
	}

	return true;
}

#if 0
template <typename Vertex, typename Weight>
bool GraphMixedAdjLists<Vertex, Weight>::addEdge(size_t source, size_t destination)
{
	// Find the source vertex.

	std::map<VertexIndex, VertexList>::iterator srcItr = m_vertices.find(source);

	if (m_vertices.cend() == srcItr)
	{
		std::cerr << "Source vertex not found: " << source << '\n';
		return false;
	}

	for (auto& itr : srcItr->second)
	{
		itr->
	}

	srcItr->second.

	return ;
}

template <typename Vertex, typename Weight>
bool GraphMixedAdjLists<Vertex, Weight>::addEdge(size_t source, size_t destination, Weight weight)
{
	// TODO: stub
	return false;
}
#endif
