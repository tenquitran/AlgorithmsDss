#pragma once


namespace AlgorithmsDss_CStyle
{
    // Weight of the edge. 
    // Some graph algorithms can work with negative weights (but using 64-bit integers is probably an overkill for now).
    typedef int EdgeWeight;

#if 1
    // Vertex tag uniquely identifies a vertex in the graph (a non-negative integer will do).
    // Unsigned because vertex tag is compared to maximum number of possible vertices 
    // when this number is fixed (e.g. in an adjacency matrix representation of a graph).
    typedef size_t VertexTag;
#else
    // Vertex tag uniquely identifies vertex in the graph.
    // For vertex identification, non-negative integers should be used.
    // However, the data type is signed to allow representation of "non-existing" vertices as negative values 
    // (e.g. in the "vertex predecessors" collection in some graph algorithms such as DFS).
    typedef int VertexTag;
#endif

    // Index of a vertex in a graph.
    // Should be signed because a negative value -1 means "invalid index" 
    // but larger than the VertexTag data type (because the latter is unsigned).
    typedef long long int VertexIndex;


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

#if 0
        // Get weight of the edge.
        // Parameters: src - source vertex;
        //             dst - destination vertex;
        //             weight - edge weight (valid only if the function returns true).
        // Returns: true if the edge exists and has weight; false otherwise.
        virtual bool getEdgeWeight(VertexTag src, VertexTag dst, EdgeWeight& weight) const = 0;
#else
        // Get weight of the edge.
        // Parameters: src - source vertex;
        //             dst - destination vertex.
        // Returns: edge weight if the edge exists.
        // Throws: ExceptionA.
        virtual EdgeWeight getEdgeWeight(VertexTag src, VertexTag dst) const = 0;
#endif

    protected:
        // Graph vertices.
        std::vector<VertexTag> m_vertices;
    };
}
