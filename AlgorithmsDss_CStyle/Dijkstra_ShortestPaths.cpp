#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace AlgorithmsDss_CStyle;

//////////////////////////////////////////////////////////////////////////


void shortestPaths_Dijkstra_AdjMatrix(
    const GraphMixedAdjMatrix& graph,
    VertexTag srcVertex,
    std::vector<int>& distances,
    std::vector<VertexIndex>& predecessors)
{
    const size_t VertexCount = graph.getMaxVertexCount();

    // Initialize the data structures used for searching.

    std::vector<bool> visited;
    visited.assign(VertexCount, false);

    distances.assign(VertexCount, (std::numeric_limits<int>::max)());

    predecessors.assign(VertexCount, -1);

    // Initialize the source vertex distance from itself.

    distances[srcVertex] = 0;

    while (true)
    {
        // Find an unvisited vertex with the shortest distance from the source vertex.

        bool found = false;

        //VertexIndex currVertex = -1;    // causes warnings when used as an index in the visited vertices collection
        VertexTag currVertex = {};

        int shortestDistance = (std::numeric_limits<int>::max)();

        for (size_t i = {}; i < VertexCount; ++i)
        {
            if (   !visited[i]
                && distances[i] < shortestDistance)
            {
                currVertex = i;
                shortestDistance = distances[i];
                found = true;
            }
        }

        if (!found)
        //if ((std::numeric_limits<int>::max)() == shortestDistance)   // error-prone
        {
            std::cout << "No unvisited reachable vertices left" << std::endl;
            return;
        }

        // Update the shortest paths info for adjacent vertices.

        visited[currVertex] = true;

        for (size_t adjVertex = {}; adjVertex < VertexCount; ++adjVertex)
        {
            if (adjVertex == currVertex)
                {continue;}

            EdgeWeight weight = graph.getEdgeWeight(currVertex, adjVertex);

            // Compute distances using long long int (as it's guaranteed to be larger than int).
            long long int newDistance = distances[currVertex] + weight;

            if (newDistance < distances[adjVertex])
            {
                // TODO: warning C4244: '=' : conversion from '__int64' to 'int', possible loss of data
                distances[adjVertex]    = newDistance;
                predecessors[adjVertex] = currVertex;
            }
        }
    }
}
