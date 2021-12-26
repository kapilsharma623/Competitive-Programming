/*
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.

    0
1       2

Output: 1
Explanation: The given graph can be colored in two colors so, it is a bipartite graph.

    0        1    
2       3

Output: 0
Explanation: The given graph cannot be colored in two colors such that color of adjacent vertices differs.

Your Task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no
of vertices and adj denoting adjacency list of graph and returns a boolean value true if graph is bipartite otherwise returns false.

*/

 bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; 
            }
        }
    }
    return true; 
 }
bool isBipartite(int n, vector<int>adj[]){
	  int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            if(!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true; 
}
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    int N = 6;
    vector<int> adj[N + 1];
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 1);
  
    if (isBipartite(N,adj)) {
        cout << "Graph is Bipartite";
    }
    else {
        cout << "Graph is not Bipartite";
    }
    return 0;
}
