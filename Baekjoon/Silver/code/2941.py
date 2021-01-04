import sys

str = input()
alpha = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
res = 0
for c in alpha:
    id = str.find(c)
    while(id != -1):
        str = str[0:id] + ''.join([' ' for i in range(len(c))]) + str[id+len(c):]
        res+=1
        id = str.find(c, id)
res += len(''.join(str.split()))
print(res)
