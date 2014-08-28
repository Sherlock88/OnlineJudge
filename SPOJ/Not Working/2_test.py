
MAX_LIMIT = 1000000001

def list_prime():
	keys = range(1, MAX_LIMIT + 1)
	values = [0] * MAX_LIMIT
	D = dict(zip(keys, values))
	print D[10]
	
list_prime()