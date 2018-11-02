def cal(temp):
    begin = index[0]
    store = []  # 一行打印的词
    while True:
        if index[0] == 6 or temp < len(word[index[0]]):
            break
        store.append(word[index[0]])
        temp -= len(word[index[0]]) + 1
        index[0] += 1
    num = index[0] - begin  # 一行有几个词
    temp += 1  # 最后一个词后面不用加点
    if num == 1:
        return store[0] + "." * temp
    gap = temp // (num - 1) + 1  # 每个间隙几个点
    space = [gap for i in range(num)]  # 每个间隙要有几个点
    remain = temp % (num - 1)  # 多出来要重新分配的点
    for i in range(remain):
        space[i] += 1
    ans = ""  # 最终答案
    for i in range(num - 1):
        ans += store[i] + "." * space[i]
    return ans + store[num - 1]


n = int(input())
word = ["WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"]
index = [0]  # 全局变量
while index[0] < 6:
    print(cal(n))
