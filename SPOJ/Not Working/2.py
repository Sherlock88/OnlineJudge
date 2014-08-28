def isprime(n):
    for x in xrange(2, int(n**0.5)+1):
        if n % x == 0:
            return False
    return True


t = input()
for i in range(t):
	m, n = [int(x) for x in raw_input().split()]
	for j in xrange(m, n):
		if isprime(j):
				print j
	print "\n"