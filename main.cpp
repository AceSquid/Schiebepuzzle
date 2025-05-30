#include "parameter_reader.h"
#include "dls2.h"
#include "vector_stack.h"
#include <iostream>


using namespace std;

bool checkPossibility(vector<string> input_vector){
   //Berechnen der Anzahl der Inversionen, um die Loesbarkeit festzustellen. Ist die Zahl der Inversionen gerade, existiert eine Lösung, ist sie ungerade gibt es keine Lösung.
   int anzahlInversionen = 0;
   for(int i = 0; i < input_vector.size(); i++){
    for(int j = i + 1; j < input_vector.size(); j++){
        if(input_vector[i] != "e" && input_vector[j] != "e"){
            if(input_vector[i] > input_vector[j]){
                anzahlInversionen++;
            }
        }
    }
   }
   
   if(anzahlInversionen % 2 != 0){
        cout << "NO SOLUTION" << endl;
        return 0;
    }else{
        return 1;
    }
}


int lowerBoundHeuristic(vector<string> input){
    int heuristic = 0;
    vector<string> goal = {"1","2","3","4","5","6","7","8","e"};

    for(int i = 0; i <= 8; i++){
        if(input[i] != goal[i]){
            heuristic++;
        } 
    }

    if(heuristic == 0){
        return 1;
    }

    return heuristic;
}

/*
bool ids(vector<string> input, int upper_bound){
    int limit = 1;
    Dls dls;
    while(limit < upper_bound){
        if(dls.search(input, limit)){
            dls.printStack();
            return true;
        }else{
            dls.reset();
            limit++;
            cout << limit;
            cout << endl;
        }
    }

    cout << "NO SOLUTION";
    cout << endl;

}
*/

bool ids(vector<string> input, int upper_bound){

    int l = lowerBoundHeuristic(input);
    int u = upper_bound;
    bool found = false;
    Dls dls;

    while(l < u){
        int q = (u + l) / 2;
        if(!dls.search(input, q)){
            cout << q;
            cout << endl;
            l = q + 1;
            dls.reset();
        }else{
            u = q;
            cout << q;
            cout << endl;
            found = true;
        }

    }
     dls.printStack();
    return found;

}


int main(int argc, char** argv) {
    vector<string> input_vector = input_to_vector(argc, argv); // the input given in console is now in input_vector (e.g. for input "hallo 1 a b" input_vector is {"hallo", "1", "a", "b"})

    /*
    cout << input_vector[0] + input_vector[1] + input_vector[2] + "\n" + input_vector[3] + input_vector[4] + input_vector[5] + "\n" + input_vector[6] + input_vector[7] + input_vector[8] + "\n";                                                           
    vector<string> test = nextNeighbor(input_vector, 5);
    cout << endl;
    cout << test[0] + test[1] + test[2] + "\n" + test[3] + test[4] + test[5] + "\n" + test[6] + test[7] + test[8] + "\n";                                                         
    */



    //cout << checkPossibility(input_vector);
    //ids(input_vector, 31);

    Dls dls;
    cout << dls.search(input_vector, 31);

   



}

