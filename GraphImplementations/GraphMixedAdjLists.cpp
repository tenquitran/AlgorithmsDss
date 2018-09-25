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

template <typename Vertex>
GraphMixedAdjLists<Vertex>::GraphMixedAdjLists()
{
}

template <typename Vertex>
GraphMixedAdjLists<Vertex>::~GraphMixedAdjLists()
{
}

template <typename Vertex>
bool GraphMixedAdjLists<Vertex>::addVertex(size_t index, const Vertex& v)
{
	// Add empty vertex list.

	std::pair<std::map<VertexIndex, VertexList>::iterator, bool> res =
		m_vertices.emplace(std::pair<VertexIndex, VertexList>(index, VertexList()));

	if (!res.second)
	{
		std::cerr << "Duplicate index: " << index << '\n';
		return false;
	}

	// Add the leading vertex to the vertex list.
	
	res.first->second.push_back(v);

	return true;
}