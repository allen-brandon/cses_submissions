class PSTNode():
    l = r = None
    def __init__(self, val, l=None, r=None):
        self.val=val
        self.l=l
        self.r=r
    
    def copy(self):
        return PSTNode(self.val,self.l,self.r)
    
    def __str__(self):
        l = self.__list__()
        return str(l)
    def __list__(self):
        res = []
        q = deque([self])
        while q:
            u = q.pop()
            res.append(u.val)
            for v in (u.l, u.r):
                if v: q.appendleft(v)
        return res
        
#Persistent Segment Tree (Explicit)
from functools import partial
class PST:
    def __init__(self, a, S, S_id, op, mapping, S_inv=lambda x:x):
        self.S, self.S_id, self.S_inv = S, S_id, S_inv
        self.op, self.mapping = op, mapping
        n = 1
        while n<len(a):
            n<<=1
        self.n = n
        arr = [PSTNode(S_id) for _ in range(n)] + [PSTNode(S(x)) for x in a] + [PSTNode(S_id) for _ in range(n-len(a))]
        self.versions = [arr[1]]
        for i in range(n-1, 0, -1):
            arr[i].l=arr[i*2]
            arr[i].r=arr[i*2+1]
            arr[i].val = op(arr[i].l.val, arr[i].r.val)
        
    def update(self, ver, i, x):
        self.S, self.S_id, self.S_inv = S, S_id, S_inv
        self.op, self.mapping = op, mapping
        st = [(self.versions[ver].copy(),-1)]
        pop = self.n>>1
        while pop:
            if i>=pop:
                i-=pop
                st.append((st[-1][0].r.copy(),1))
            else:
                st.append((st[-1][0].l.copy(),0))
            pop>>=1
        v, lr = st.pop()
        v.val = mapping(x, v.val)
        while st:
            u, u_lr = st.pop()
            if lr:
                u.r=v
            else:
                u.l=v
            u.val = op(u.l.val, u.r.val)
            v, lr = u, u_lr
        self.versions.append(v)
    
    def query(self, ver, l, r):
        self.S, self.S_id, self.S_inv = S, S_id, S_inv
        self.op, self.mapping = op, mapping
        st = [(self.versions[ver],0, self.n)]
        res = S_id
        while st:
            u, lb, rb = st.pop()
            if l<=lb and rb<=r:
                res = op(res, u.val)
                continue
            mid = lb+(rb-lb)//2
            if l<mid:
                st.append((u.l, lb, mid))
            if r>mid:
                st.append((u.r, mid, rb))
        return res
    
#op: sum, map: set
S = lambda x: x
S_id = 0
S_inv = lambda x: x
op = lambda x, y: x+y
mapping = lambda f, s: s if f is None else f

import sys
print = lambda x: sys.stdout.write(str(x)+'\n')
inp = sys.stdin.read().split('\n')
n, q = map(int, inp[0].split())
a = [*map(int, inp[1].split())]
st = PST(a, S, S_id, op, mapping, S_inv)
versions = [0]
for i in range(q):
    query = [*map(int, inp[i+2].split())]
    if query[0] == 1:
        k, a, x = query[1:]
        ver = versions[k-1]
        st.update(ver, a-1, x)
        # print(f'updaing {a-1} in version {ver} to {x}')
        versions[k-1]=len(st.versions)-1
    elif query[0] == 2:
        k, a, b = query[1:]
        ver = versions[k-1]
        # print(f'querying version {ver} from {a-1} to {b}')
        print(st.query(ver, a-1, b))
    else:
        k = query[1]
        ver = versions[k-1]
        st.update(ver, 0, None)
        # print(f'copying version {ver}')
        versions.append(len(st.versions)-1)
    # for i, x in enumerate(versions):
    #     print(f'version {i}: {st.versions[x]}')