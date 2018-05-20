# 从小往大找
def small(current):
    # 寻找哪一位需要变换
    for a in range(len(current) - 1, -1, -1):
        if order[a] < len(current) - a - 1:
            # 调换顺序
            # 最后两位换顺序
            if a == len(current) - 2:
                current[a], current[a + 1] = current[a + 1], current[a]
                order[a] = 1
                return current
            # 第a位和后面最小的换顺序
            current = current[:a + 1] + sorted(current[a + 1:])
            for i in range(a + 1, len(current)):
                if current[a] < current[i]:
                    current[a], current[i] = current[i], current[a]
                    break
            current = current[:a + 1] + sorted(current[a + 1:])  # 第a位后面的从小往大排，完成变换
            # 重新计数
            order[a] += 1
            for i in range(a + 1, len(current) - 1):
                order[i] = 0
            return current


# 从大往小找
def large(current):
    # 寻找哪一位需要变换
    for a in range(len(current) - 1, -1, -1):
        if order[a] < len(current) - a - 1:
            # 调换顺序
            # 最后两位换顺序
            if a == len(current) - 2:
                current[a], current[a + 1] = current[a + 1], current[a]
                order[a] = 1
                return current
            # 第a位和后面最大的换顺序
            temp = sorted(current[a + 1:])
            temp.reverse()
            current = current[:a + 1] + temp
            for i in range(a + 1, len(current)):
                if current[a] > current[i]:
                    current[a], current[i] = current[i], current[a]
                    break
            temp = sorted(current[a + 1:])
            temp.reverse()
            current = current[:a + 1] + temp  # 第a位后面的从大往小排，完成变换
            # 重新计数
            order[a] += 1
            for i in range(a + 1, len(current) - 1):
                order[i] = 0
            return current


# 把开头的0去掉
def cal(a):
    b = ""
    begin = False
    for i in a:
        if i != "0":
            begin = True
        if begin:
            b += i
    return b


data = open("#6_data.in", "r").read().split("\n")
for p in range(2):
    word = [i for i in data[p].split(",")[0]]
    word.sort()
    n = int(data[p].split(",")[1])
    print(cal("".join(word)))  # 最小的数

    # 计算第50大的数
    current = word[:]
    current.reverse()
    mean = (int("".join(current), 36) + int("".join(word), 36)) / 2  # 平均值
    print(cal("".join(current)))  # 最大的数
    order = [0 for i in range(len(word) - 1)] + [1]
    for i in range(49):
        current = large(current)
    print(cal("".join(current)))  # 第50大的数

    # 计算第n小的数
    current = word[:]
    order = [0 for i in range(len(word) - 1)] + [1]
    for i in range(n - 1):
        current = small(current)
    print(cal("".join(current)))  # 第n小的数

    # 计算离平均数最近的数
    current = word[:]
    current.reverse()
    order = [0 for i in range(len(word) - 1)] + [1]
    little = int("".join(current), 36)  # 相差最小的数
    ans = {}  # {和平均值的差：36进制的数}
    # 全部遍历一遍
    while True:
        current = large(current)
        # 这个差出现过
        if abs(int("".join(current), 36) - mean) in ans:
            ans[abs(int("".join(current), 36) - mean)] = ans[abs(int("".join(current), 36) - mean)][:] + [current[:]]
        # 这个差没出现过
        else:
            ans[abs(int("".join(current), 36) - mean)] = [current[:]]
        # 更新最小的差
        if little > abs(int("".join(current), 36) - mean):
            little = abs(int("".join(current), 36) - mean)
        if word == current:
            break

    for i in ans[little]:
        print(cal("".join(i)), end=" ")  # 离平均数最近的数
    print()
