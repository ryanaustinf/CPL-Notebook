// function int f(int x) is defined as the cycle algorithm, ie. f(x) = the next element from x in the cycle
ii floydCycleFinding(int x0) { 
	// 1st part: finding k*mu, hare’s speed is 2x tortoise’s
	int tortoise = f(x0), hare = f(f(x0)); // f(x0) is the node next to x0 
	while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
	// 2nd part: finding mu, hare and tortoise move at the same speed
	int mu = 0; hare = x0;
	while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++;}
	// 3rd part: finding lambda, hare moves, tortoise stays
	int lambda = 1; hare = f(tortoise);
	while (tortoise != hare) { hare = f(hare); lambda++; }
	return ii(mu, lambda);
}