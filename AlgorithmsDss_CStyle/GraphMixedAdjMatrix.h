#pragma once


namespace AlgorithmsDss_CStyle
{
    // Mixed graph: adjacency matrix representation.
    class GraphMixedAdjMatrix 
        : public GraphBase
    {
    private:
        // Default weight of the edge.
        // The weights can be negative, zero or positive. Nevertheless, the adjacency matrix needs some default value ("no edge").
        const EdgeWeight EdgeWeightDefault = (std::numeric_limits<EdgeWeight>::min)();

    public:
        explicit GraphMixedAdjMatrix(size_t maximumVertexCount);

        virtual ~GraphMixedAdjMatrix();

        // Get maximum number of vertices (the adjacency matrix width).
        size_t getMaxVertexCount() const;

        // Add vertex with the specified tag.
        virtual void addVertex(VertexTag vertexTag) override;

        // Add directed edge.
        // Parameters: src - source vertex;
        //             dst - destination vertex;
        //             weight - edge weight (by default, one).
        virtual void addEdgeDirected(VertexTag src, VertexTag dst, EdgeWeight weight = 1) override;

        // Add non-directed edge.
        // Parameters: src - source vertex;
        //             dst - destination vertex;
        //             weight - edge weight (by default, one).
        virtual void addEdgeUndirected(VertexTag src, VertexTag dst, EdgeWeight weight = 1) override;

    private:
        // Maximum number of vertices in the graph.
        // For adjacency matrix representation, sets the matrix size.
        //
        // NOTE: an attempt to optimize using the number of actual (existing) vertices is just plain wrong.
        // A matrix row is not guaranteed to be completely filled - and if it's not, your indices will be incorrect.
        const size_t MaximumVertexCount;

        // Adjacency matrix.
        //
        // NOTE: a single-dimensional array simulating a matrix would make code less readable and slower 
        // (while speed is one of the main benefits of an adjacency matrix representation).
        std::unique_ptr< std::unique_ptr<EdgeWeight[]>[] > m_adjMatrix;
    };
}
