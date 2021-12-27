/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

Example 1:

Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
Example 2:

Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
*/

import java.util.*; 

boolean dfsCheck(ArrayList<ArrayList<Integer>> adj, int node, int color[]) {
		for(Integer it: adj.get(node)) {
			if(color[it] == -1) {
				color[it] = 1 - color[node]; 
				if(!dfsCheck(adj, it, color)) return false; 
			}
			else if(color[it] == color[node]) return false; 
		}
    return true; 
}

boolean checkBipartite(ArrayList<ArrayList<Integer>> adj, int n){
   int color[] = new int[n];
   for(int i = 0;i<n;i++) {
      color[i] = -1; 
   }
   for(int i = 0;i<n;i++) {
      if(color[i] == -1) {
        	if(!dfsCheck(adj, i, color)) return false;
      }
   }
   return true; 
}
    
public static void main(String args[]) {
    int n = 7;
    ArrayList<ArrayList<Integer> > adj = new ArrayList<ArrayList<Integer> >();
		
		for (int i = 0; i < n; i++)  adj.add(new ArrayList<Integer>());
    
		adj.get(0).add(1);
		adj.get(1).add(0);
		adj.get(1).add(2);
		adj.get(2).add(1);
		adj.get(2).add(3);
		adj.get(3).add(2);
		adj.get(4).add(3);
		adj.get(3).add(4);
		adj.get(4).add(5);
		adj.get(5).add(4);
		adj.get(4).add(6);
		adj.get(6).add(4);
		adj.get(1).add(6);
		adj.get(6).add(1);
		
		if(checkBipartite(adj, n) == true) System.out.println("Yes Bipartite"); 
		else System.out.println("Not Bipartite"); 
    }
}
