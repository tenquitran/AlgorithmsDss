#pragma once


namespace GraphImplementations
{
	// Mixed graph using an adjacency lists representation (via STL collections).
	// 
	// Template arguments:
	//     Vertex: vertex data type.
	template <typename Vertex>
	class GraphMixedAdjLists
	{
		typedef size_t VertexIndex;

		typedef std::list<Vertex> VertexList;

	public:
#if 0
		explicit GraphMixedAdjLists(size_t vertexCount);
#endif

		GraphMixedAdjLists(void);

		virtual ~GraphMixedAdjLists();

#if 1
		bool addVertex(size_t index, const Vertex& v);
#endif

	private:
		GraphMixedAdjLists(const GraphMixedAdjLists&) = delete;
		GraphMixedAdjLists& operator=(const GraphMixedAdjLists&) = delete;

	private:
#if 0
		// Number of vertices in the graph.
		const size_t VertexCount;
#endif

		// Vertices of the graph.
		// Key: index of the vertex.
		std::map<VertexIndex, VertexList> m_vertices;
	};
}

#include "GraphMixedAdjLists.cpp"
