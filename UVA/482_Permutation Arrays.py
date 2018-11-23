def cal():
    temp = list(zip(first, second))
    temp.sort()
    for i in temp:
        print(i[1])


n = int(input())
for i in range(n):
    if i:
        print()
    input()
    first = [int(i) for i in input().split(" ")]
    second = input().split(" ")
    cal()
