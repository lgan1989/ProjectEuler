import sys
import copy

f = open('cipher1.txt' , 'r')

backup = f.read()
backup = backup.split(',')
content = copy.deepcopy(backup)

# 103 111 100
pwd = (103 , 111 ,100)
idx = 0
ans = 0
for key in content:
    key = int(key) ^ pwd[idx]
    idx = idx + 1
    idx %= 3
    ans += int(key)
print (ans)

