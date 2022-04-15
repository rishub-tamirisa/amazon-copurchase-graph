#include "catch.hpp"

#include <string>
#include <iostream>
#include <vector>
#include "graph.h"
#include "NodeReader.h"

TEST_CASE("Graph Insert Nodes Correctly", "[graph][insert]") {
   Graph graph;
   graph.insertVertex(1);
   graph.insertVertex(2);
   graph.insertVertex(3);
   graph.insertVertex(4);

   SECTION("Graph Insert Edges Correctly") {
      graph.insertEdge(3, 4, 1);
      graph.insertEdge(1, 2, 1);
      REQUIRE(graph.getEdgeList().size() == 2);
      //verify edges
      REQUIRE(graph.areAdjacent(3, 4));
      REQUIRE(graph.areAdjacent(1, 2));
      //verify non-edges
      REQUIRE(!graph.areAdjacent(1, 3));
      REQUIRE(!graph.areAdjacent(2, 4));

   }
   REQUIRE(graph.getAdjList().size() == 4);
}

TEST_CASE("Graph Incident Edges", "[graph][incident]") {
   Graph graph;
   graph.insertVertex(1);
   graph.insertVertex(2);
   graph.insertVertex(3);
   graph.insertVertex(4);
   graph.insertVertex(5);
   graph.insertVertex(6);

   graph.insertEdge(3, 4, 1);
   graph.insertEdge(3, 5, 1);
   graph.insertEdge(3, 6, 1);

   //verify incident edge size
   REQUIRE(graph.incidentEdges(3).size() == 3);
   REQUIRE(graph.areAdjacent(3, 4));
   REQUIRE(graph.areAdjacent(3, 5));
   REQUIRE(graph.areAdjacent(3, 6));

   REQUIRE(!graph.areAdjacent(3, 1));
   REQUIRE(!graph.areAdjacent(3, 2));
   
}

TEST_CASE("NodeReader reads SNAP format", "[graph][reader]") {
   Graph graph;
   NodeReader reader("225FPDataset/test.txt");
   reader.readInEdgeList(graph);
   REQUIRE(graph.areAdjacent(1, 2));
   REQUIRE(graph.areAdjacent(1, 3));
   REQUIRE(graph.areAdjacent(1, 7));
   REQUIRE(graph.areAdjacent(1, 9));
   REQUIRE(graph.areAdjacent(1, 10));
   REQUIRE(graph.areAdjacent(1, 11));
   REQUIRE(graph.areAdjacent(1, 12));
   REQUIRE(graph.areAdjacent(2, 1));
   REQUIRE(graph.areAdjacent(2, 5));
   REQUIRE(graph.areAdjacent(2, 13));
   REQUIRE(graph.areAdjacent(3, 1));
   REQUIRE(graph.areAdjacent(3, 6));
   REQUIRE(graph.areAdjacent(3, 8));
   REQUIRE(graph.areAdjacent(4, 5));
   REQUIRE(graph.areAdjacent(4, 13));
   REQUIRE(graph.areAdjacent(4, 18));
   REQUIRE(graph.areAdjacent(5, 2));
   REQUIRE(graph.areAdjacent(5, 4));
   REQUIRE(graph.areAdjacent(5, 6));
   REQUIRE(graph.areAdjacent(5, 17));
   REQUIRE(graph.areAdjacent(6, 3));
   REQUIRE(graph.areAdjacent(6, 5));
   REQUIRE(graph.areAdjacent(7, 1));
   REQUIRE(graph.areAdjacent(7, 8));
   REQUIRE(graph.areAdjacent(7, 9));
   REQUIRE(graph.areAdjacent(8, 3));
   REQUIRE(graph.areAdjacent(8, 7));
   REQUIRE(graph.areAdjacent(8, 14));
   REQUIRE(graph.areAdjacent(8, 15));
   REQUIRE(graph.areAdjacent(9, 1));
   REQUIRE(graph.areAdjacent(9, 7));
   REQUIRE(graph.areAdjacent(9, 10));
   REQUIRE(graph.areAdjacent(9, 14));
   REQUIRE(graph.areAdjacent(10, 1));
   REQUIRE(graph.areAdjacent(10, 9));
   REQUIRE(graph.areAdjacent(10, 11));
   REQUIRE(graph.areAdjacent(11, 1));
   REQUIRE(graph.areAdjacent(11, 10));
   REQUIRE(graph.areAdjacent(11, 12));
   REQUIRE(graph.areAdjacent(12, 1));
   REQUIRE(graph.areAdjacent(12, 11));
   REQUIRE(graph.areAdjacent(12, 13));
   REQUIRE(graph.areAdjacent(13, 2));
   REQUIRE(graph.areAdjacent(13, 4));
   REQUIRE(graph.areAdjacent(13, 12));
   REQUIRE(graph.areAdjacent(13, 18));
   REQUIRE(graph.areAdjacent(14, 8));
   REQUIRE(graph.areAdjacent(14, 9));
   REQUIRE(graph.areAdjacent(15, 8));
   REQUIRE(graph.areAdjacent(15, 16));
   REQUIRE(graph.areAdjacent(16, 17));
   REQUIRE(graph.areAdjacent(17, 5));
   REQUIRE(graph.areAdjacent(17, 16));
   REQUIRE(graph.areAdjacent(17, 18));
   REQUIRE(graph.areAdjacent(18, 4));
   REQUIRE(graph.areAdjacent(18, 13));
   REQUIRE(graph.areAdjacent(18, 17));

   REQUIRE(graph.getEdgeList().size() == 29);
}
