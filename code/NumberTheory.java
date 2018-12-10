import java.util.*;

public class NumberTheory {
	static BitSet sieve; // used for generating primes
	static ArrayList<Integer> primes; // change to long if necessary
	static int[] nDiffPF; // for modified sieve
	static int bound; // array cap, usually 10^7
	static int[] e; // for modified sieve euler phi
	
	static void generatePrimes() {
		sieve.set(2, bound);
		for(int i=2; i<bound; i++)
			if(sieve.get(i)) {
				primes.add(i);
				for(int j=i+i; i<bound; j+=i) sieve.set(j, false);
			}
	}
	
	static boolean isPrime(int n) {
		if(n<bound) return sieve.get(n);
		for(int i=0; i<primes.size(); i++)
			if(n%primes.get(i)==0) return false;
		return true;
	}
	
	// assumption: a>=b
	static int gcd(int a, int b) {
		return b==0 ? a : gcd(b, a%b);
	}
	
	// alternative: get max of powers across all prime factors of a and b
	static int lcm(int a, int b) {
		return a*(b/gcd(a, b));
	}
	
	// returns map of format <factor, power>
	// convert to TreeMap if you need order
	// easy to tweak to count all PF, count distinct PF, sum PF, num Div
	static HashMap<Integer, Integer> getPrimeFactors(int n) {
		HashMap<Integer, Integer> factors = new HashMap<>();
		int pIndex = 0, p = primes.get(pIndex);
		while(p*p<=n) {
			while(n%p==0) {
				factors.put(p, factors.containsKey(p) ? factors.get(p)+1 : 1);
				n/=p;
			}
			p = factors.get(++pIndex);
		}
		if(n!=1) factors.put(n, factors.containsKey(n) ? factors.get(n)+1 : 1);
		return factors;
	}
	
	static int eulerPhi(int n) {
		int pIndex = 0, p = primes.get(pIndex), ans = n;
		while(p*p<=n) {
			if(n%p==0) ans-=ans/p;
			while(n%p==0) n/=p;
			p = primes.get(++pIndex);
		}
		if(n!=1) ans-=ans/n;
		return ans;
	}
	
	// more efficient way to count num of different PF of many numbers
	static void modifiedSieve() {
		nDiffPF = new int[bound];
		for(int i=2; i<bound; i++)
			if(nDiffPF[i]==0) for(int j=i; j<bound; j+=i) nDiffPF[j]++;
	}
	
	static void modifiedEulerPhi() {
		e = new int[bound];
		for(int i=1; i<bound; i++) e[i] = i;
		for(int i=2; i<bound; i++)
			if(e[i]==i) for(int j=i; j<bound; j+=i) e[j] = (e[j]/i)*(i-1);
	}
}
