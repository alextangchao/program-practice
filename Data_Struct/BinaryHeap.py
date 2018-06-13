class BinaryHeap:
    import operator

    def __init__(self, fn=operator.gt):
        self.heap = [None]
        self.fn = fn

    def push(self, value):
        self.heap.append(value)
        index = len(self.heap) - 1
        while index > 1 and self.canMoveUp(index):
            self.change(index, self.getParentIndex(index))
            index = self.getParentIndex(index)

    def pop(self, index=0):
        if len(self.heap) == 2:
            return self.heap.pop()
        index += 1
        ans = self.heap[index]
        self.heap[index] = self.heap.pop()
        while 1 <= index < len(self.heap):
            if self.canMoveUp(index):
                self.change(index, self.getParentIndex(index))
            elif self.canMoveDown(index):
                self.change(index, self.getDownIndex(index))
            else:
                break
        return ans

    def peek(self):
        return self.heap[1]

    def getParentIndex(self, index):
        return index // 2 if index // 2 > 0 else False

    def getLeftIndex(self, index):
        return index * 2 if index * 2 < len(self.heap) else False

    def getRightIndex(self, index):
        return index * 2 + 1 if index * 2 + 1 < len(self.heap) else False

    def getDownIndex(self, index):
        left = self.getLeftIndex(index)
        right = self.getRightIndex(index)
        if not left:
            return None
        if not right:
            return left
        if self.fn(self.heap[left], self.heap[right]):
            return left
        return right

    def change(self, index1, index2):
        self.heap[index1], self.heap[index2] = self.heap[index2], self.heap[index1]

    def canMoveUp(self, index):
        return self.fn(self.heap[index], self.heap[self.getParentIndex(index)]) if self.getParentIndex(index) else False

    def canMoveDown(self, index):
        if not self.getLeftIndex(index):
            return False
        if not self.getRightIndex(index):
            return self.fn(self.heap[self.getLeftIndex(index)], self.heap[index]) if self.getLeftIndex(index) else False
        return self.fn(self.heap[self.getLeftIndex(index)], self.heap[index]) or self.fn(
            self.heap[self.getRightIndex(index)], self.heap[index])
