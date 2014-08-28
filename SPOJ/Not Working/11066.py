t = input()
for i in range(t):
	p, q, s = [int(x) for x in raw_input().split()]
	temp = 7*p + 5*q +2*s
	n1 = int((temp + ((temp * temp) - 4 * 12 * s * (p+q))**0.5)/(2*(p+q)))
	n2 = int((temp - ((temp * temp) - 4 * 12 * s * (p+q))**0.5)/(2*(p+q)))
	if n1 != 6:
		d1 = int((q-p)/(n1-6))
	if n2 != 6:
		d2 = int((q-p)/(n2-6))
	f1 = p-2*d1
	#f2 = p-2*d2
	s1 = n1/2*(2*f1 + (n1 - 1)*d1)
	#s2 = n2/2*(2*f2 + (n2 - 1)*d2)
	if s1 == s:
		n = n1
		d = d1
	else:
		n = n2
		d = d2
	print n
	print (p-2*d),
	print (p-d),
	print p,
	for j in range(n-3):
		p = p + d
		print p,