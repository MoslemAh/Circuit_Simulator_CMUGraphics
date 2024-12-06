#pragma once
#include "Cell.h"
#include <vector>
using namespace std;

class Node
{
private:
    Cell cellPos;                         // Cell position of the node
    int numberOfNodes = 0;                // Unique node number
    int nodeNumber;                       // Node number entered by user
    vector<Cell> connections;             // List of connected cells

public:
    // Default constructor
    Node() : cellPos(-1, -1)
    {
        nodeNumber = 0;
        numberOfNodes++; 
    } 

    // Constructor with initial values
    Node(Cell cell, int num) : cellPos(cell), nodeNumber(num) 
    {
        if (nodeNumber == numberOfNodes + 1)
        {
            numberOfNodes++;
        }
        // might need more validations
    } 

    // Getter for cell position
    Cell GetCell() const { return cellPos; }

    // Setter for cell position
    void SetCell(Cell cell) { cellPos = cell; }

    // Getter for node number
    int GetNodeNumber() const { return nodeNumber; }

    // Setter for node number
    void SetNodeNumber(int num) { nodeNumber = num; }

    // Add a connection to the node
    void AddConnection(Cell cell) { connections.push_back(cell); }

    // Get all connections of the node
    vector<Cell> GetConnections() const { return connections; }
};
