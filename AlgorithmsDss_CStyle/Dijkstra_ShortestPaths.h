#pragma once


namespace AlgorithmsDss_CStyle
{
    // Dijkstra's shortest paths algorithm implementation for graphs.
    // Works with the adjacency matrix graph representation.
    //
    // Parameters: graph - graph to process;
    //             source - index of the source vertex (zero-based);
    //             distances - distances of each vertex from the source (measured in number of edges between the vertices);
    //             predecessors - predecessors of each vertex. A negative value -1 means "no predecessor" 
    // (i.e. the vertex is not reachable from the source vertex).
    void shortestPaths_Dijkstra_AdjMatrix(
        const GraphMixedAdjMatrix& graph,
        VertexTag srcVertex,
        std::vector<int>& distances,
        std::vector<VertexIndex>& predecessors);
}

#if 0
class Dijkstra_ShortestPaths
{
public:
    Dijkstra_ShortestPaths();
    ~Dijkstra_ShortestPaths();
};
#endif
