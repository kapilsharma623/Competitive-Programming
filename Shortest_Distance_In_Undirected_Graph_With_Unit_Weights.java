/*
Print the Shortest Path distance from node 0 to each node.
Nodes ranges from 0 to 8.

Ajacency List for given
0 -> 1,3
1 -> 0,2,3
2 -> 1,6
3 -> 0,4
4 -> 3,5
5 -> 4,6
6 -> 2,5,7,8
7 -> 6,8
8 -> 6,7

Find the Shortest path distance from node 0 to each node,and print distance of each node from node 0.
*/
import java.util.ArrayList;

public class Shortest_Distance_In_Undirected_Graph_With_Unit_Weights {

	static void dfs(int node,ArrayList<ArrayList<Integer> > adj,ArrayList<Integer> distance) {
		for(Integer itr:adj.get(node)) {
			if(distance.get(itr) > distance.get(node)+1) {
				distance.set(itr,distance.get(node)+1);
				dfs(itr,adj,distance);
			}
		}
	}
	public static void main(String[] args) {
		ArrayList<ArrayList<Integer> > adj=new ArrayList<>();
		ArrayList<Integer> distance=new ArrayList<>();
		
		ArrayList<Integer> elements=new ArrayList<>();
		elements.add(1);
		elements.add(3);
		adj.add(elements);
		
		elements=new ArrayList<>();
		elements.add(0);
		elements.add(2);
		elements.add(3);
		adj.add(elements);
		
		elements=new ArrayList<>();
		elements.add(1);
		elements.add(6);
		adj.add(elements);
		
		elements=new ArrayList<>();
		elements.add(0);
		elements.add(4);
		adj.add(elements);
		
		elements=new ArrayList<>();
		elements.add(3);
		elements.add(5);
		adj.add(elements);
		
		elements=new ArrayList<>();
		elements.add(4);
		elements.add(6);
		adj.add(elements);
		
		elements=new ArrayList<>();
		elements.add(2);
		elements.add(5);
		elements.add(7);
		elements.add(8);
		adj.add(elements);
		
		elements=new ArrayList<>();
		elements.add(6);
		elements.add(8);
		adj.add(elements);
		
		elements=new ArrayList<>();
		elements.add(6);
		elements.add(7);
		adj.add(elements);
		
		for(int i=0;i<adj.size();i++) {
			distance.add(Integer.MAX_VALUE);
		}
		distance.set(0,0);
		dfs(0,adj,distance);
		int i=0;
		for(Integer ele:distance) {
			System.out.println(i++ + " Minimum Distance is " +ele);
		}
	}
}
