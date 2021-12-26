/*
You are given a maze with N cells. Each cell may have multiple entry points but not more than one exit (ie. entry/exit points are unidirectional doors like valves).
The cells are named with an integer value from 0 to N-1. 
You have to find: Nearest meeting cell: Given any two cells – C1, C2, find the closest cell Cm that can be reached from both C1 and C2. 
        
INPUT FORMAT:
1)An integer T, denoting the number of testcases, followed by 3T lines, as each testcase will contain 3 lines.
2)The first line of each testcase has the number of cells N
3)The second line of each testcase has a list of N values of the edge[] array. edge[i] contains the cell number that can be reached from cell ‘i’ in one step. edge[i] is -1 if he ‘i’th cell doesn’t have an exit.
Third line for each testcase contains two cell numbers whose nearest meeting cell needs to be found. (return-1 if there is no meeting cell from the two given cells)

OUTPUT FORMAT:
For each testcase given, output a single line that denotes the nearest meeting cell (NMC) 

Sample Input & Output:
Input:
1
23
4 4 1 4 1 3 8 8 8 0 8 1 4 9 15 11-1 10 15 22 22 22 22 22 21 
9 2
Output: 4
*/

![Converging_Maze_Nearest_Meeting_Cell](https://user-images.githubusercontent.com/65452458/147403320-811e5683-6ba2-49b8-96af-8a4302b03d94.jpeg)

#include <bits/stdc++.h>
using namespace std;

bool checkdfs(int node,vector<int> adj[],int V,vector<bool> &vis,int parent,bool isdes,map<int,int> &srcPath,int* srcOrdes,int* countNodeDis,int* NearestNode){
    vis[node]=1;
    if(isdes == false){
        srcPath.insert({node,*countNodeDis++});
    }
    else{
        if(srcPath.find(node)!=srcPath.end()){
            if(srcOrdes==0){
                *NearestNode=node;
                srcOrdes++;
            }
        }
    }
    for(int x:adj[node]){
        if(!vis[x]){
            if(checkdfs(x,adj,V,vis,node,isdes,srcPath,srcOrdes,countNodeDis,NearestNode)) return true;
        }
        else if(x!=parent){
            *NearestNode=x;
            return true;
        }
    }
    return false;
}
void checkCycle(vector<int> adj[],int V,map<int,int> &srcPath,int* srcOrdes,int* countNodeDis,int* NearestNode,int src,int des){
    vector<bool> vis(V+1,0);
    bool srcCycle = checkdfs(src,adj,V,vis,-1,false,srcPath,srcOrdes,countNodeDis,NearestNode);
    vis.clear();
    vis.resize(V+1,0);
    bool desCycle = checkdfs(des,adj,V,vis,-1,true,srcPath,srcOrdes,countNodeDis,NearestNode);
}

int main()
{
    vector<int> arr={4,4,1,4,13,8,8,8,0,8,14,9,15,11,-1,10,15,22,22,22,22,22,21};
    vector<int> adj[arr.size()];
    for(int i=0;i<arr.size();i++){
        adj[i].push_back(arr[i]);
    }
    map<int,int> srcPath;
    int srcOrdes=0;
    int countNodeDis=0;
    int NearestNode=-1;
    int src=9;
    int des=2;
    checkCycle(adj,arr.size(),srcPath,&srcOrdes,&countNodeDis,&NearestNode,src,des);
    cout<<"Nearest Cell : "<<NearestNode;
    return 0;
}
