#pragma once
#include <vector>
#include <unordered_map>
#include <list>
#include <stdexcept>

class Graph {
    public:
        class Edge; // forward declaration

        class Vertex {
            public:
                int ID;
                int degree;
                std::list<Edge*> edges;
                Vertex(int id) : ID(id) {}
        };

        class Edge {
            public:
                int weight;
                Vertex* v1;
                Vertex* v2;
                Edge(Vertex* _v1, Vertex* _v2, int w) : weight(w), v1(_v1), v2(_v2) {}
        };

        void insertVertex(int key);

        void insertEdge(int k1, int k2, int w);

        std::list<Edge*> incidentEdges(int key);

        bool areAdjacent(int k1, int k2);


        //access vertices
        Vertex* operator[](int key) { return adj_list.at(key); }

        //BFS
        std::vector<int> BFS(int root, int target);

        

        //BRANDES

        //FORCE-DIRECTED DRAWING

        ~Graph();
        
        //testing purposes
        std::unordered_map<int, Vertex*>& getAdjList() { return adj_list; }

        std::vector<Edge*>& getEdgeList() { return edge_list; }

    private:
        std::unordered_map<int, Vertex*> adj_list;
        std::vector<Edge*> edge_list;

};