# sample test第9个错误，我自己笔算都算不出来...
# 看在不在连通图中
def find(num):
    for i in mark:
        if num in i:
            return True
    return False


# dfs
def cal(num, count):
    temp.append(num)
    for i in range(n):
        if place[num][i] and not find(i):
            mark[count].append(i)
    for i in range(n):
        if place[num][i] and (i not in temp):
            cal(i, count)


datas = open("#4_data.in", "r").read().split("\n")
for p in range(10):
    data = datas[p].split(", ")
    n = int(data[0])  # 有多少个节点
    num = ""
    # 计算2进制数字
    for i in data[1]:
        temp = bin(int(i, 16))[2:]
        while len(temp) < 4:
            temp = "0" + temp
        num += temp

    place = [[0 for i in range(n)] for i in range(n)]  # 邻接矩阵
    index = 0
    # 构建邻接矩阵
    for i in range(n - 1, 0, -1):
        for k in range(i):
            place[n - i - 1][k + n - i] = int(num[index])
            place[k + n - i][n - i - 1] = int(num[index])
            index += 1

    mark = []  # 连通分量
    temp = []  # 去过的点
    count = -1
    for i in range(n):
        if not find(i):
            mark.append([i])
            count += 1
            cal(i, count)

    # 从A开始的
    first = ""
    change = dict(zip(range(26), "ABCDEFGHIJKLMNOPQRSTUVWXYZ"))
    mark[0].sort()
    for k in range(len(mark[0])):
        first += change[mark[0][k]]

    print(count + 1, first)
