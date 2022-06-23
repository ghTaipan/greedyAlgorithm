#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;

#define V 11

void display(int path[])
{
    for(int i = 0; i<V;i++){
        if(path[i] == -1){
            break;
        }
        if(path[i+1] != -1)
            cout<<path[i]<<" ";
        else{
            cout<<path[i];
        }
    }
    cout<<endl;
}
 

void greedyAlgorithm(double graph[V][V],int src)
{
    int key = src;
    int temp_key = key;
    double min = INT_MAX;
    int path[V];
    int path_index = 1;

    int scorer_index = -1;
    
    bool check[V]; 
    for(int i = 0; i<V;i++){
        check[i] = false;
        path[i] = -1;
    }
    path[0] = key;
 
    for (int count = 0; count < V - 1; count++)
    {
        if(graph[src][src] !=0){
            break;
        }
        int u = key;
        
        check[u] = true;

        for (int v = 0; v < V; v++){
            if(graph[u][v] != 0 && graph[v][v] != 0 && graph[u][v]<min){
                if(scorer_index == -1)
                    scorer_index = v;
                else{
                    if(graph[u][v] < graph[u][scorer_index])
                        scorer_index = v;
                }
            }
            if (graph[u][v] != 0 && check[v] == false && graph[u][v] < min )
                temp_key = v, min = graph[u][v];}
        if(scorer_index != -1){
            path[path_index] = temp_key;
            break;
        }
        key = temp_key;
        path[path_index] = key;
        min = INT_MAX;
        path_index++;
    }
    display(path);
  
}
int main(int argc, char** argv) {

    string path = argv[1];

    int k = atoi(argv[2]);
    
    ifstream in(path);

    string line, field;

    vector<vector<double>> array; // the 2D array
    vector<double> v;             // array of values for one line only

    while (getline(in, line)) // get next line in file
    {
        v.clear();
        stringstream ss(line);

        while (getline(ss, field, ',')) // break line into comma delimitted fields
        {
            v.push_back(std::stod(field)); // add each field to the 1D array
        }

        array.push_back(v); // add the 1D array to the 2D array
    }
    double times[V][V];

    for(int i = 0;i<11;i++){
        for(int j = 0;j<11;j++){
            times[i][j] = array[i][j];
            if(j<10)
                cout<<array[i][j]<<",";
            else{
                cout<<array[i][j]<<endl;
            }
        }
    
    }
    greedyAlgorithm(times,k);
    return 0;
}