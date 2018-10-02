#pragma once


namespace AlgorithmsDss_CStyle
{
    // Weight of the edge. 
    // Some graph algorithms can work with negative weights (but using 64-bit integers is probably an overkill for now).
    typedef int EdgeWeight;

    // Vertex tag uniquely identifies a vertex in the graph (a non-negative integer will do).
    typedef size_t VertexTag;


    // Abstract base class for graph implementations.
    class GraphBase
    {
    public:
        GraphBase();

        virtual ~GraphBase();

        // Add vertex with the specified tag.
        virtual void addVertex(VertexTag vertexTag) = 0;

        // Add directed edge.
        // Parameters: src - source vertex;
        //             dst - destination vertex;
        //             weight - edge weight (by default, one).
        virtual void addEdgeDirected(VertexTag src, VertexTag dst, EdgeWeight weight = 1) = 0;

        // Add non-directed edge.
        // Parameters: src - source vertex;
        //             dst - destination vertex;
        //             weight - edge weight (by default, one).
        virtual void addEdgeUndirected(VertexTag src, VertexTag dst, EdgeWeight weight = 1) = 0;

    protected:
        // Graph vertices.
        std::vector<VertexTag> m_vertices;
    };
}
