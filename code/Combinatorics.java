
public class Combinatorics {
	static int[] fibo(int n) {
		int[] f = new int[n];
		f[0] = f[1] = 1;
		for(int i=2; i<n; i++) f[i] = f[i-1]+f[i-2];
		return f;
	}
	
	// alternatively: 
	// nCk = n!/(k!*(n-k)!)
	// nPk = n!/(n-k)!
	// add a memo table if needed to reduce overlaps
	static int binomialCoefficient(int n, int k) {
		if(n==k || k==0) return 1;
		return binomialCoefficient(n-1,k-1)+binomialCoefficient(n-1,k);
	}
	
	static int[] catalan(int n) {
		int[] cat = new int[n];
		cat[0] = 1;
		for(int i=1; i<n; i++) cat[i] = ((2*i*(2*i-1)) / ((i+1)*i))*cat[i-1];
		return cat;
	}
}
