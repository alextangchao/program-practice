# 半成品
def small(word, n, order, count):  # 单词，调换第几个，第几小，第几次
    if n == 1:
        pass
    for i in range(n):
        temp = small(word, n - 1, order, count + 1)# temp[int(判断是否返回),第order小的单词]
        if temp[0]:
            return temp[1]


def large(word, n):
    pass


data = open("#6_data.in", "r").read().split("\n")
for p in range(2):
    word = data[p]
word = [i for i in data[0].split(",")[0]]
n = data[0].split(",")[1]
print(word, n)
