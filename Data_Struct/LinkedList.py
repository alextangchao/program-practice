class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

    def get(self, index):
        if index == 0:
            return self.value
        return self.next.get(index - 1)

    def add(self, value):
        if self.next is None:
            self.next = Node(value)
        else:
            self.next.add(value)

    def remove(self, index):
        if index == 0:
            self.value = self.next.value
            index = 1
        if index == 1:
            self.next = self.next.next
        else:
            self.next.remove(index - 1)

    def set(self, index, value):
        if index == 0:
            self.value = value
        else:
            self.next.set(index - 1, value)


a = Node(3)
a.next = Node(4)
a.next.next = Node(5)
a.set(2, 1)
a.add(6)
a.remove(0)
print(a.get(0))
print(a.get(1))
print(a.get(2))
