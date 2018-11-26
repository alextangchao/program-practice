def findplace(a):
    for i in range(len(store)):
        for k in range(len(store[i])):
            if store[i][k] == a:
                return i, k


def back(row, col):
    for i in store[row][col:]:
        store[row].remove(i)
        store[i] = [i]


def valid(a, b):
    if a == b:
        return True
    return findplace(a)[0] == findplace(b)[0]


def move_onto(a, b):
    row, col = findplace(a)
    back(row, col + 1)
    store[row].remove(a)
    row, col = findplace(b)
    back(row, col + 1)
    store[row].append(a)


def move_over(a, b):
    row, col = findplace(a)
    back(row, col + 1)
    store[row].remove(a)
    row, col = findplace(b)
    store[row].append(a)


def pile_onto(a, b):
    row, col = findplace(b)
    back(row, col + 1)
    pile_over(a, b)


def pile_over(a, b):
    row, col = findplace(a)
    rows, cols = findplace(b)
    store[rows] += store[row][col:]
    for i in store[row][col:]:
        store[row].remove(i)


n = int(input())
store = []
for i in range(n):
    store.append([i])

while True:
    order = input().split(" ")
    if order[0] == "quit":
        break
    if valid(int(order[1]), int(order[3])):
        continue
    if order[0] == "move":
        if order[2] == "onto":
            move_onto(int(order[1]), int(order[3]))
        else:
            move_over(int(order[1]), int(order[3]))
    else:
        if order[2] == "onto":
            pile_onto(int(order[1]), int(order[3]))
        else:
            pile_over(int(order[1]), int(order[3]))

for i in range(n):
    print(str(i) + ":", end="")
    for k in store[i]:
        print(" " + str(k), end="")
    print()

"""
move_onto(9, 1)
move_over(8, 1)
move_over(7, 1)
move_over(6, 1)
pile_over(8, 5)
move_over(2, 1)
move_over(4, 9)
print(store)
"""
