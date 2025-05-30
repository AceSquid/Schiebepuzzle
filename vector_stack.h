#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class VectorStack{

    private:
        
        vector<vector<string>> stack;

    public: 

        void push(vector<string> input){
            stack.push_back(input);
        }

        void pop(){
            if(!stack.empty()){
                stack.pop_back();
            }else{
                cout << "Stack Error: No Elements in Stack.\n";
            }
        }

        vector<string> top(){
            if(!stack.empty()){
                return stack.back();
            }else{
                cout << "Stack Error: No Elements in Stack.\n";
            }
        }

        int size(){
            return stack.size();
        }

        bool hasElement(vector<string> element){
            
            for(int i = 0; i < stack.size(); i++){
                if(stack[i] == element){
                    return true;
                }
            }

            return false;
        }

        bool empty(){
            return stack.empty();
        }



};