#ifndef GRAPH_H
#define GRAPH_H

#include <string>

struct Node {
    std::string portName;
    Node* next;
    
    Node(const std::string& name);
};

struct Edge {
    int destination;
    int weight;
    Edge* next;
    
    Edge(int dest, int w);
};

class Graph {
private:
    int numPorts;
    Node** ports;
    Edge** adjacencyList;
    
    int findPortIndex(const std::string& portName);
    void printPath(int* parent, int destination, std::string& path);

public:
    Graph(int capacity);
    ~Graph();
    
    void addPort(const std::string& portName, int index);
    void addRoute(const std::string& from, const std::string& to, int distance);
    bool portExists(const std::string& portName);
    void findOptimalRoute(const std::string& start, const std::string& end, std::string& route, int& distance);
};

#endif