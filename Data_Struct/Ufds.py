# Weighted quick-union with path compression
class UFDS:
    def __init__(self, n):
        self.store = list(range(n))  # 父节点
        self.num = [1] * n  # 节点的数量
        self.n = n  # 连通分量

    # 找到n的根节点
    def root(self, n):
        while self.store[n] != n:
            self.store[n] = self.store[self.store[n]]  # path compression
            n = self.store[n]
        return n

    def find(self, a, b):
        return self.root(a) == self.root(b)

    def union(self, a, b):
        one = self.root(a)
        two = self.root(b)
        # 节点少的加到节点多的里面
        if one == two:
            return
        if self.num[one] < self.num[two]:
            self.store[one] = two
            self.num[two] += self.num[one]
            self.n -= 1
        else:
            self.store[two] = one
            self.num[one] += self.num[two]
            self.n -= 1


a = UFDS(10)
a.union(3, 4)
a.union(4, 9)
a.union(8, 0)
a.union(2, 3)
a.union(5, 6)
a.union(5, 9)
a.union(7, 3)
a.union(4, 8)
a.union(6, 1)
print(a.find(1, 6))
print(a.store)
print(a.num)
print(a.n)
