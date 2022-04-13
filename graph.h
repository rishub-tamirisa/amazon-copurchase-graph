#pragma once
#include <vector>
#include <unordered_map>
#include <list>


class Graph {
    public:
        class Edge; // forward declaration

        class Vertex {
            public:
                int degree;
                std::list<Edge*> list;
        };

        class Edge {
            public:
                int weight;
                Vertex* v1;
                Vertex* v2;
                Edge(Vertex* _v1, Vertex* _v2, int w) : weight(w), v1(_v1), v2(_v2) {}
        };

        void insertVertex(int key);

        void insertEdge(Vertex* v1, Vertex* v2, int w);

        std::list<Edge*> incidentEdges(Vertex* v);

        bool areAdjacent(Vertex* v1, Vertex* v2);

        //BFS

        //BRANDES

        //FORCE-DIRECTED DRAWING

    private:
        std::unordered_map<int, Vertex*> adj_list;
        std::vector<Edge*> edge_list;

};