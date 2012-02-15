import sys
import math

def isPrime(n):
    sq = math.sqrt(n)
    sq = int(sq)
    for i in range(2 , sq + 1):
        if (n % i ==0):
            return False
    return True

cnt = 5
total = 9
for l in range(7 , 1000000 , 2):
    cor = l * l
    a = cor
    b = cor - l + 1
    c = b - l + 1
    d = c - l + 1
    if (isPrime(a)):
        cnt += 1
    if (isPrime(b)):
        cnt += 1
    if (isPrime(c)):
        cnt += 1
    if (isPrime(d)):
        cnt += 1
    total += 4
    if (cnt / total < 0.1):
        break;
print (l)
