import math
x = 285
while True:
	x = x + 1
	s = x * (x + 1) / 2
	t1 = 1 + 8 * s
	t2 = 1 + 24 * s
	sq1 = int(math.sqrt(t1))
	sq2 = int(math.sqrt(t2))
	if (sq1 * sq1 == t1 and sq2 * sq2 == t2):
		if ((1 + sq1) % 4 == 0 and (1 + sq2) % 6 == 0):
			print x,(1 + sq1)/4 , (1 + sq2)/6 , s
			break
	
