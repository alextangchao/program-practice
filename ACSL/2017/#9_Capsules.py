class cell:
    def __init__(self, value, up, right, down, left):
        self.value = value
        self.up = up
        self.right = right
        self.down = down
        self.left = left
        self.belong = None  # 属于哪个区域
        self.range = None  # 这个区域一共有多少块


# 16进制变为4位的2进制
def changehex(a):
    temp = bin(int(a, 16))[2:]
    while len(temp) < 4:
        temp = "0" + temp
    return temp


# 计算内部节点
def interinter():
    count = 0
    for i in range(row - 1):
        for k in range(col - 1):
            if not (store[i][k].up or store[i][k].right or store[i + 1][k + 1].down or store[i + 1][k + 1].left):
                count += 1
    return count


# 计算有多少个区域
def belong(row, col, count):
    if (row, col) in appear:  # 已经计算过
        return
    ranges[count] += 1
    store[row][col].belong = count
    appear.append((row, col))
    if store[row][col].up == 0 and row + 1 < int(line[0]):
        belong(row + 1, col, count)
    if store[row][col].right == 0 and col + 1 < int(line[1]):
        belong(row, col + 1, count)
    if store[row][col].down == 0 and row - 1 >= 0:
        belong(row - 1, col, count)
    if store[row][col].left == 0 and col - 1 >= 0:
        belong(row, col - 1, count)
    return


# 能否使用num这个数字
def canfill(row, col, num):
    if row + 1 < int(line[0]) and col - 1 >= 0:
        if store[row + 1][col - 1].value == num:
            return False
    if row + 1 < int(line[0]):
        if store[row + 1][col].value == num:
            return False
    if row + 1 < int(line[0]) and col + 1 < int(line[1]):
        if store[row + 1][col + 1].value == num:
            return False
    if col - 1 >= 0:
        if store[row][col - 1].value == num:
            return False
    if col + 1 < int(line[1]):
        if store[row][col + 1].value == num:
            return False
    if row - 1 >= 0 and col - 1 >= 0:
        if store[row - 1][col - 1].value == num:
            return False
    if row - 1 >= 0:
        if store[row - 1][col].value == num:
            return False
    if row - 1 >= 0 and col + 1 < int(line[1]):
        if store[row - 1][col + 1].value == num:
            return False
    return True


# 查找下一个位置
def next(row, col):
    if col + 1 < int(line[1]):
        fill(row, col + 1)
        return
    else:
        if row + 1 < int(line[0]):
            fill(row + 1, 0)
            return
    return


# 是否全部都填满了
def isfill():
    for i in range(int(line[0])):
        for k in range(int(line[1])):
            if store[i][k].value is None:
                return False
    return True


# 填充
def fill(row, col):
    if store[row][col].value is None:
        for i in range(1, store[row][col].range + 1):
            # 如果这个数字没使用过和周边的也没有使用
            if (i not in appear[store[row][col].belong]) and canfill(row, col, i):
                store[row][col].value = i
                appear[store[row][col].belong].append(i)
                next(row, col)
                if isfill():
                    return
                appear[store[row][col].belong].remove(i)
                store[row][col].value = None
        return
    # 题目有给数字
    else:
        appear[store[row][col].belong].append(store[row][col].value)
        next(row, col)
        if isfill():
            return
    return


data = open("#9_data.in", "r").read().split("\n")
for p in range(2):
    line = data[p].split(", ")
    row = int(line[0])
    col = int(line[1])
    store = [[None for i in range(col)] for i in range(row)]  # 二维数组
    for i in range(row):
        for k in range(col):
            num = changehex(line[2][i * col + k])
            store[i][k] = cell(None, int(num[0]), int(num[1]), int(num[2]), int(num[3]))

    # 内部节点
    print(interinter())

    # 区域数量
    rank = []  # 每个区域的大小
    ranges = [0 for i in range(row + col)]  # 每个区域的大小
    appear = []  # 出现过的数字
    region = 0  # 区域数量
    for i in range(row):
        for k in range(col):
            if (i, k) not in appear:
                belong(i, k, region)
                region += 1
    print(region)

    # 空的区域
    origin = [0 for i in range(region)]  # 每个区域有没有数字
    for i in range(int(line[3])):
        order = line[4 + i]
        store[int(order[0]) - 1][int(order[1]) - 1].value = int(order[2])
        origin[store[int(order[0]) - 1][int(order[1]) - 1].belong] += 1
    count = 0
    for i in origin:
        if not i:
            count += 1
    print(count)  # 空的区域的数量

    # 保存每块所属区域的大小
    for i in range(row):
        for k in range(col):
            store[i][k].range = ranges[store[i][k].belong]

    appear = [[] for i in range(region)]  # 出现过的数字

    fill(0, 0)  # 填充数字

    # 计算上层的和
    topsum = 0
    for i in range(col):
        topsum += store[row - 1][i].value
    print(topsum)

    # 计算最左侧的和
    leftsum = 0
    for i in range(row):
        leftsum += store[i][0].value
    print(leftsum)
