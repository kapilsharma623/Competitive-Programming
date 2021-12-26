/*
Detect cycle in an undirected graph:

Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Output: 1
Explanation: 1->2->3->4->1 is a cycle.

*/

bool dfs(int node,int prev,int V, vector<int> adj[], vector<int> &vis){
    vis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x]){
           if(dfs(x,node,V,adj,vis)) return true;
        }
        else if(x!=prev) return true;
    }  
    return false;
}
bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V+1,0);
    for(int i=0;i<V;i++){
        if(vis[i]==0){
           if(dfs(i,-1,V,adj,vis)) return 1;
        }
    }
    return 0;
}    
int main()
{
    vector<int> arr={4,4,1,4,13,8,8,8,0,8,14,9,15,11,-1,10,15,22,22,22,22,22,21};
    vector<int> adj[arr.size()];
    for(int i=0;i<arr.size();i++){
        adj[i].push_back(arr[i]);
    }
    cout<<"Ckeck Cycle : "<<isCycle(arr.size(),adj);
    return 0;
}
