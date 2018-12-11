import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class UVa_11138 {
	static ArrayList<Integer>[] adj;
	static int[] match;
	static boolean[] vis;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// Bipartite graph with n vertices in one side and m vertices in the other
		int n = sc.nextInt();
		int m = sc.nextInt();
		adj = new ArrayList[n];
		// a directed edge is only ever defined from a vertex in n to a vertex in m
		// store edges in an adjacency list
		for(int i=0; i<n; i++) {
			adj[i] = new ArrayList<>();
			for(int j=0; j<m; j++) if(sc.nextInt()==1) adj[i].add(j);
		}
		match = new int[m];
		Arrays.fill(match, -1);
		vis = new boolean[n];
		int mcbm = 0;
		for(int l=0; l<n; l++) {
			Arrays.fill(vis, false);
			mcbm+=aug(l);
		}
		System.out.println("Found "+mcbm+" matchings");
	}
	
	// augmenting path algorithm
	static int aug(int l) {
		if(vis[l]) return 0;
		vis[l] = true;
		for(int j=0; j<adj[l].size(); j++) {
			int r = adj[l].get(j);
			if(match[r]==-1 || aug(match[r])>0) {
				match[r] = l;
				return 1;
			}
		}
		return 0;
	}
}
