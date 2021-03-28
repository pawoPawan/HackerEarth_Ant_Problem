//
//  main.cpp
//  HackerEarth_Ant
//
//  Created by Pawan Kumar on 28/03/21.
//
//https://www.hackerearth.com/problem/algorithm/ants/

#include <iostream>
#include <vector>
using namespace std;
// Function Declaration
void Traverse(vector<int> &arr_coord, vector<int> & curr_path,
              vector<int> & path_vals);

void TraverseEachNode(int curr_node, vector<int> & nodes_to_travel,
                      vector<int> & curr_path,
                      vector<int> & path_vals);

int CalculatePathMagnitude(vector<int> & path);

void GetRemainigNodeToTravel(int curr_node, vector<int> & nodes_to_travel,
                             vector<int> & rem_node_to_travel);

int GetHCF(int a, int b);

// Function Definition

void GetRemainigNodeToTravel(int curr_node,vector<int> & nodes_to_travel ,vector<int> & rem_node_to_travel)
{
    for(auto itr = nodes_to_travel.begin(); itr != nodes_to_travel.end(); itr++)
    {
        if(*itr != curr_node)
            rem_node_to_travel.push_back(*itr);
    }
}

int CalculatePathMagnitude(vector<int> & path)
{
    int nPath_mag = 0;
    int lastval = 0;
    // Traverse through each item of vector
    for(auto itr = path.begin(); itr != path.end(); itr++)
    {
        nPath_mag += abs(*itr - lastval);
        lastval = *itr;
    }
    return nPath_mag;
}
void TraverseEachNode(int curr_node, vector<int> & nodes_to_travel, vector<int> & curr_path,
                      vector<int> & path_vals)
{
    // Append a new node to travel except curr node
    curr_path.push_back(curr_node);
    cout << curr_node << endl;
    vector<int> rem_node_to_travel;
    GetRemainigNodeToTravel(curr_node,nodes_to_travel,rem_node_to_travel);
    
    int nSizeToTravel = rem_node_to_travel.size();
    if(nSizeToTravel > 1)
        Traverse(rem_node_to_travel, curr_path, path_vals);
    else
    {
        // Append last element in curr_path
        curr_path.push_back(rem_node_to_travel[0]);
        //Calculate path from stored values
        int path_mag = CalculatePathMagnitude(curr_path);
        // Pop out last value
        curr_path.pop_back();
        //store path magnitude
        path_vals.push_back(path_mag);
    }
}

void Traverse(vector<int> &arr_coord, vector<int> & curr_path, vector<int> & path_vals)
{
    // Node to Travel from curr node is arr_coord - currnode
    // for loop on each node
    int nSize = arr_coord.size();
    for(int i = 0; i < nSize; i++)
    {
        TraverseEachNode(arr_coord[i], arr_coord,curr_path,path_vals);
        if(curr_path.size() > 0)curr_path.pop_back();
        //curr_path.push_back(arr_coord[i]);
    }
}

int GetHCF(int a, int b)
{
    if(0 == b)return a;
    if(0 == a)return b;
    
    return GetHCF(b, a%b);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int N = 0;
    int Sum = 0;
    vector<int>arr_coord;
    vector<int> curr_path;
    vector<int> path_vals;
    int SumOfAllPossiblePaths = 0;
//    cout << "No Of sugar cups: "<<endl;;
//    cin >> N;
//    cout << "Enter Co-ordinates"<<endl;
//    //int * arr_coord = new int[N] ;
//    for(int i = 0; i < N; i++)
//    {
//        int temp;
//        cin >> temp;
//        arr_coord.push_back(temp);
//    }
    N = 3;

    arr_coord.push_back(2);
    arr_coord.push_back(3);
    arr_coord.push_back(5);


    // All integers are kind of nodes
    Traverse(arr_coord,curr_path,path_vals);
    
    // Add Values of all paths
    for(auto itr = path_vals.begin(); itr != path_vals.end(); itr++)
    SumOfAllPossiblePaths += *itr;
    
    // Convert to smallerst possible fraction value of average
    // Get HCF of both nos. and divde both no by hcf
    int hcf = GetHCF(SumOfAllPossiblePaths,path_vals.size());
    cout << SumOfAllPossiblePaths/hcf << " " << path_vals.size()/hcf<< endl;

    return 0;
}
