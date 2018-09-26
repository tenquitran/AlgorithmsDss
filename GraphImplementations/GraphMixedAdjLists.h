#pragma once


namespace GraphImplementations
{
	// Mixed graph using an adjacency lists representation (via STL collections).
	// This implementation prefers clarity to performance 
	// (in particular, vertex list is an STL list instead of an STL map).
	// 
	// Template arguments:
	//     VertexLabel - type of the vertex label (an integer, a char, etc.) that should uniquely represent vertex in the graph;
	//     VertexData  - type of the additional data about the vertex;
	//     EdgeWeight  - edge weight type.
	//template <typename Vertex, typename Weight>
	template<typename VertexLabel, typename VertexData, typename EdgeWeight>
	class GraphMixedAdjLists
	{
		typedef std::pair<VertexLabel, VertexData> VertexListEntry;

		typedef std::list<VertexListEntry> VertexList;

	public:
		GraphMixedAdjLists(void);

		virtual ~GraphMixedAdjLists();

		bool addVertex(VertexLabel label, const VertexData& vertexData);

		// TODO: fix. The vertex list should contain both labels and data
#if 0
		// Add non-weighted edge (the "weight" will be considered equal to one).
		// Parameters: source - source vertex;
		//             destination - destination vertex.
		bool addEdge(size_t source, size_t destination);

		// Add weighted edge.
		// Parameters: source - source vertex;
		//             destination - destination vertex;
		//             weight - weight of the edge.
		bool addEdge(size_t source, size_t destination, Weight weight);
#endif

	private:
		GraphMixedAdjLists(const GraphMixedAdjLists&) = delete;
		GraphMixedAdjLists& operator=(const GraphMixedAdjLists&) = delete;

	private:
		// Graph vertices.
		std::map<VertexLabel, VertexData> m_vertices;

		// Adjacency lists for the graph vertices.
		std::map<VertexLabel, VertexList> m_adjacencyLists;
	};
}

#include "GraphMixedAdjLists.cpp"
