from bisect import bisect_left
# sqrt(1000000000) = 31622
__primes = sieve(31622)
def isprime(n):
    # if prime is already in the list, just pick it
    if n <= 31622:
        i = bisect_left(__primes, n)
        return i != len(__primes) and __primes[i] == n
    # Divide by each known prime
    limit = int(n ** .5)
    for p in __primes:
        if p > limit: return True
        if n % p == 0: return False
    # fall back on trial division if n > 1 billion
    for f in range(31627, limit, 6): # 31627 is the next prime
        if n % f == 0 or n % (f + 4) == 0:
            return False
    return True

t = input()
for i in range(t):
	m, n = [int(x) for x in raw_input().split()]
	for j in xrange(m, n):
		if isprime(j):
				print j
	print "\n"