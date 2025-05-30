#pragma once

#include "vector_stack.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dls {
    vector<string> goal = {"1","2","3","4","5","6","7","8","e"};
    VectorStack visited;
    VectorStack path;

public:
    void reset() {
        VectorStack stack;
        visited = stack;
        path = stack;
    }

    bool search(vector<string> input, int limit) {
        reset();
        VectorStack storage;
        storage.push(input);
        
        while (!storage.empty()) {
            vector<string> current = storage.top();
            
            if (current == goal) {
                path = storage;
                return true;
            }
            
            vector<vector<string>> neighbors = getAllNeighbors(current);
            bool foundUnvisited = false;
            
            for (auto neighbor : neighbors) {
                if (!visited.hasElement(neighbor)) {
                    if (storage.size() < limit) {
                        visited.push(neighbor);
                        storage.push(neighbor);
                        foundUnvisited = true;
                        break;
                    }
                }
            }
            
            if (!foundUnvisited) {
                storage.pop();
            }
        }
        return false;
    }

    void printStack() {
        VectorStack inv_stack;

        while (!path.empty()) {
            inv_stack.push(path.top());
            path.pop();
        }

        while (!inv_stack.empty()) {
            printVector(inv_stack.top());
            inv_stack.pop();
        }

        if (!inv_stack.empty()) {
            printVector(goal);
        }
    }

private:
    void printVector(vector<string> input) {
        for (auto component : input) {
            cout << component + " ";
        }
        cout << endl;
    }

    vector<vector<string>> getAllNeighbors(vector<string> current) {
        vector<vector<string>> neighbors;
        int loc_e = 0;

        while (current[loc_e] != "e") {
            loc_e++;
        }

        if (loc_e < 0 || loc_e > 8) {
            cout << "Error with Boundaries";
            return neighbors;
        }

        int row = loc_e / 3;
        int col = loc_e % 3;

        if (row > 0) {
            vector<string> neighbor = current;
            neighbor[loc_e] = current[loc_e - 3];
            neighbor[loc_e - 3] = "e";
            neighbors.push_back(neighbor);
        }

        if (row < 2) {
            vector<string> neighbor = current;
            neighbor[loc_e] = current[loc_e + 3];
            neighbor[loc_e + 3] = "e";
            neighbors.push_back(neighbor);
        }

        if (col > 0) {
            vector<string> neighbor = current;
            neighbor[loc_e] = current[loc_e - 1];
            neighbor[loc_e - 1] = "e";
            neighbors.push_back(neighbor);
        }

        if (col < 2) {
            vector<string> neighbor = current;
            neighbor[loc_e] = current[loc_e + 1];
            neighbor[loc_e + 1] = "e";
            neighbors.push_back(neighbor);
        }

        return neighbors;
    }
};