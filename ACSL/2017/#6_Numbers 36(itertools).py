import itertools


def cal(a):
    for i in range(len(a)):
        if a[i] != "0":
            return a[i:]


data = open("#6_data.in", "r").read().split("\n")
for p in range(2):
    line = data[p].split(", ")
    small = sorted([i for i in line[0]])
    large = sorted([i for i in line[0]], reverse=True)
    print(cal("".join(small)))
    print(cal("".join(large)))
    count = 1
    for i in itertools.permutations(large, len(large)):
        if count == 50:
            print(cal("".join(i)))
            break
        count += 1
    count = 1
    for i in itertools.permutations(small, len(small)):
        if count == int(line[1]):
            print(cal("".join(i)))
            break
        count += 1
    ans = []
    mean = (int("".join(large), 36) + int("".join(small), 36)) / 2
    little = abs(int("".join(large), 36) - mean)
    for i in itertools.permutations(small, len(small)):
        num = abs(int("".join(i), 36) - mean)
        if num < little:
            little = num
            ans = ["".join(i)]
        elif num == little:
            ans.append("".join(i))
    for i in ans:
        print(cal(i), end=" ")
    print()
