# https://cses.fi/problemset/task/1068/
n = int(input())
res = []
while n != 1:
    res.append(n)
    if n&1:
        n = (n*3)+1
    else:
        n>>=1
print(" ".join([str(x) for x in res] + ["1"]))