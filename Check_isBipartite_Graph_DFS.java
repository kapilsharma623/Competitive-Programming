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
