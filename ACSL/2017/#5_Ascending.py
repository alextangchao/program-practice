# 写到后面已经思维混乱了
# 寻找num里最小的n位数
def findnum():
    store = ""
    if len(num) < n:
        return store
    num.sort()
    # 处理首位不能为0
    for i in range(n):
        if not i:
            index = 0
            while index < len(num) and num[index] == "0":
                index += 1
            if index == len(num):
                return store
            store += num[index]
            num.pop(index)
        else:
            store += num[0]
            num.pop(0)
    return store


data = open("#5_data.in", "r").read().split("\n")
for p in range(10):
    n = int(data[p][0])  # 多少位
    num = [i for i in data[p][1:]]  # 存储数字
    num.sort()
    ans = ""  # 最终答案
    last = "0"  # 上一次选择的数字
    back = []  # 要再次加进num的数字

    if len(num) >= n:
        curr = findnum()
    while True:
        if curr == "" or len(curr) == 0:
            break
        # 如果跟上一次选的一样大
        while curr <= last:
            num += [curr[i] for i in range(len(curr) - 1)]  # 除了最后一位，其他的数字重新加进num再次选择
            back += [curr[-1]]  # 将选错数字的保存起来
            curr = findnum()
            if curr == "":
                break
        if curr == "" or len(curr) == 0:
            break
        ans += " " + curr  # 加进最终答案
        last = curr
        # 选错的数字重新加进num
        if len(back):
            num += back
        back = []
        if len(num) < n:
            break
        curr = findnum()

    print(ans[1:])
