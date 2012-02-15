import math

def isPen(n):
	"""
	To determin weather n is pentagonal 
	"""
	temp = int(math.sqrt(1 + 24 * n))
	if (temp * temp == (1 + 24 * n)):
		if ( (1 + temp) % 6 == 0):
			return True
	return False

def fun(n):
	return n * (3 * n - 1) / 2

x = 1
ans = -1
while True and x <= 6000:
	x += 1
	fx = fun(x)
	for y in range(1 , x - 1 , 1):
		fy = fun(y)
		if (isPen( fx + fy ) == True and isPen( fx - fy ) == True ):
			ans = fx - fy
			print fx , fy
			break
	if (ans != -1):
		break
print ans
