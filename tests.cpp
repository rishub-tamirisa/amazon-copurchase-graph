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
      graph.insertEdge(graph[3], graph[4], 1);
      graph.insertEdge(graph[1], graph[2], 1);
      REQUIRE(graph.getEdgeList().size() == 2);
      //verify edges
      REQUIRE(graph.areAdjacent(graph[3], graph[4]));
      REQUIRE(graph.areAdjacent(graph[1], graph[2]));
      //verify non-edges
      REQUIRE(!graph.areAdjacent(graph[1], graph[3]));
      REQUIRE(!graph.areAdjacent(graph[2], graph[4]));

   }
   REQUIRE(graph.getAdjList().size() == 4);
}

