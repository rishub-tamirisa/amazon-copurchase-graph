#include "NodeReader.h"
#include <iostream>
#include <fstream>
#include <sstream>

NodeReader::NodeReader(std::string filename) {
        src_file = filename;
}
        
void NodeReader::readInEdgeList(Graph& graph) {
    std::ifstream file;
    file.open(src_file);
    std::stringstream sstream;
    std::string line;
    int FromNodeID, ToNodeID;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line[0] != '#') {
                sstream << line;
                sstream >> FromNodeID >> ToNodeID;
                sstream.clear();
                graph.insertVertex(FromNodeID);
                graph.insertVertex(ToNodeID);
                graph.insertEdge(FromNodeID, ToNodeID, 1);

                // Use below code to automate REQUIRE statements for testcases
                // std::cout << "REQUIRE(graph.areAdjacent(" << FromNodeID << ", " << ToNodeID << "));" << std::endl;
            }
        }
        file.close();
    }
}

void NodeReader::readInLabels(std::string filename) {
    std::ifstream file;
    file.open(filename);
    std::stringstream sstream;
    std::string line;
    int NodeID;
    std::string Title;

    if (file.is_open()) {
        while (getline(file, line)) {
            sstream << line;
            sstream >> NodeID;
            sstream.clear();
            getline(file, line);
            sstream << line;
            sstream >> Title;
            sstream.clear();

            Title = Title.substr(8, Title.size());
            labels_hash[NodeID] = Title;
        }
        file.close();
    }

}

std::string  NodeReader::getLabel(int NodeID) {
    return labels_hash[NodeID];
}
