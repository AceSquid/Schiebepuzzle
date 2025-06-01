#pragma once

#include "vector_stack.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dls{

    vector<string> goal = {"1","2","3","4","5","6","7","8","e"};
    VectorStack visited;
    VectorStack path;

    public:

        void reset(){
            VectorStack stack;
            visited = stack;
        }

        bool search(vector<string> input, int limit) {
            VectorStack storage;
            if(input == goal){
                printVector(goal);
                return true;
            }
            storage.push(input);
                while(!storage.empty()){
                vector<string> current = storage.top();
                vector<string> neighbor = nextNeighbor(current);
                
                if(!neighbor.empty()){
                        if(neighbor == goal) {
                            path = storage;
                            return true;
                        }
                        if(storage.size() < limit && !storage.hasElement(neighbor)){
                            storage.push(neighbor);
                        }
                }else{
                        storage.pop();
                }
            }
            return false;
        }

        /*
        bool search(vector<string> input, int limit) {
            VectorStack storage;
            if(input == goal){
                printVector(goal);
                return true;
            }
            storage.push(input);
            while(!storage.empty()){
                vector<string> current = storage.top();
                vector<vector<string>> neighbors = nextNeighbors(current);
                bool pushed = false;
                if(!neighbors.empty()){
                    for(auto neighbor : neighbors){
                        if(neighbor == goal) {
                            path = storage;
                            return true;
                        }
                        if(!pushed && storage.size() < limit && !storage.hasElement(neighbor)){
                            storage.push(neighbor);
                            pushed = true;
                        }
                    }
                }
                if(!pushed){
                    storage.pop();
                }

            }
            return false;
        }

        */
        
        void printStack(){

            VectorStack inv_stack;

            while (!path.empty()){
                inv_stack.push(path.top());
                path.pop();
            }

            while(!inv_stack.empty()){
                printVector(inv_stack.top());
                inv_stack.pop();
            }

            printVector(goal);
            
        }

    private:

        void printVector(vector<string> input){

            for(auto component : input){
                cout << component + " ";
            }

            cout << endl;
        }

        vector<string> nextNeighbor(vector<string> current){
            vector<string> neighbor = current;
            int loc_e = 0;

            while (current[loc_e] != "e")
            {
                loc_e++;
            }

            if(loc_e < 0 || loc_e > 8){
                cout << "Error with Boundaries";
                return neighbor;
            }

            int row = loc_e / 3;
            int col = loc_e % 3;

            if(row > 0){
                neighbor = current;h
                neighbor[loc_e] = current[loc_e - 3];
                neighbor[loc_e - 3] = "e";
                if(!visited.hasElement(neighbor)){
                    visited.push(neighbor);
                    return neighbor;
                }
            }

            if(row < 2){
                neighbor = current;
                neighbor[loc_e] = current[loc_e + 3];
                neighbor[loc_e + 3] = "e";
                 if(!visited.hasElement(neighbor)){
                    visited.push(neighbor);
                    return neighbor;
                }
            }

            if (col > 0){
                neighbor = current;
                neighbor[loc_e] = current[loc_e - 1];
                neighbor[loc_e - 1] = "e";
                 if(!visited.hasElement(neighbor)){
                    visited.push(neighbor);
                    return neighbor;
                }
            }

            if (col < 2){
                neighbor = current;
                neighbor[loc_e] = current[loc_e + 1];
                neighbor[loc_e + 1] = "e";
                 if(!visited.hasElement(neighbor)){
                    visited.push(neighbor);
                    return neighbor;
                }
            }

            return {};
    }

    /*

    vector<vector<string>> nextNeighbors(vector<string> current){
            vector<string> neighbor = current;
            vector<vector<string>> neighbors;
            int loc_e = 0;

            while (current[loc_e] != "e")
            {
                loc_e++;
            }

            if(loc_e < 0 || loc_e > 8){
                cout << "Error with Boundaries";
                return neighbors;
            }

            int row = loc_e / 3;
            int col = loc_e % 3;

            if(row > 0){
                neighbor[loc_e] = current[loc_e - 3];
                neighbor[loc_e - 3] = "e";
                if(!visited.hasElement(neighbor)){
                    visited.push(neighbor);
                    neighbors.push_back(neighbor);
                }
            }

            if(row < 2){
                neighbor = current;
                neighbor[loc_e] = current[loc_e + 3];
                neighbor[loc_e + 3] = "e";
                 if(!visited.hasElement(neighbor)){
                    visited.push(neighbor);
                    neighbors.push_back(neighbor);
                }
            }

            if (col > 0){
                neighbor = current;
                neighbor[loc_e] = current[loc_e - 1];
                neighbor[loc_e - 1] = "e";
                 if(!visited.hasElement(neighbor)){
                    visited.push(neighbor);
                    neighbors.push_back(neighbor);
                }
            }

            if (col < 2){
                neighbor = current;
                neighbor[loc_e] = current[loc_e + 1];
                neighbor[loc_e + 1] = "e";
                 if(!visited.hasElement(neighbor)){
                    visited.push(neighbor);
                    neighbors.push_back(neighbor);
                }
            }

            if(neighbors.empty()){
                return {};
            }

            return neighbors;
    }

    */
};
    
