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
void checkCycle(vector<int> adj[],int V,map<int,int> &srcPath,int* srcOrdes,int* countNodeDis,int* NearestNode){
    vector<bool> vis(V+1,0);
    bool srcCycle = checkdfs(9,adj,V,vis,-1,false,srcPath,srcOrdes,countNodeDis,NearestNode);
    vis.clear();
    vis.resize(V+1,0);
    bool desCycle = checkdfs(2,adj,V,vis,-1,true,srcPath,srcOrdes,countNodeDis,NearestNode);
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
    checkCycle(adj,arr.size(),srcPath,&srcOrdes,&countNodeDis,&NearestNode);
    cout<<"Nearest Cell : "<<NearestNode;
    return 0;
}