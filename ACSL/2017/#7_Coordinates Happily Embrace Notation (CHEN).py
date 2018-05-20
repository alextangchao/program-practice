# 无法把小数四舍五入到跟答案一样
import math


# 计算a,b两点之间的距离
def caldistance(a, b):
    return math.sqrt((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2)


# 计算a,b,c三点围成三角形的面积
def calarea(a, b, c):
    one = caldistance(a, b)
    two = caldistance(a, c)
    three = caldistance(b, c)
    s = (one + two + three) / 2
    return math.sqrt(s * (s - one) * (s - two) * (s - three))


# 计算在a线上点point的y值
def calyvalue(a, point):
    return a[0] * point[0] + a[1]


# 计算过a,b两点的直线的表达式
def calline(a, b):
    x = (a[1] - b[1]) / (a[0] - b[0])
    y = a[1] - x * a[0]
    return (x, y)  # （a,b）  y=ax+b


# 用定比分点坐标公式来计算a,b和c,d两直线的交点
def calpoint(a, b, c, d):
    one = calarea(a, b, c)
    two = calarea(a, b, d)
    return (one * d[0] + two * c[0]) / (one + two)


def main(point):
    try:
        cutline = calline(point[3], point[4])  # 切线的表达式
        left, right = [], []
        # 把三角形的顶点和四边形的定点区分出来
        for i in range(3):
            if calyvalue(cutline, point[i]) < point[i][1]:  # cutline[0] * point[i][0] + cutline[1]
                left.append(point[i])
            else:
                right.append(point[i])
    # 如果切线是一条竖线
    except:
        left, right = [], []
        # 把三角形的顶点和四边形的定点区分出来
        for i in range(3):
            if point[i][0] < point[3][0]:
                left.append(point[i])
            else:
                right.append(point[i])
    triangle = []  # 第一个为三角形的顶点坐标，后面两个为四边形的顶点坐标
    if len(left) == 1:
        triangle = [left[0], right[0], right[1]]
    else:
        triangle = [right[0], left[0], left[1]]
    # 计算切线产生的两点的x坐标
    first = (calpoint(point[3], point[4], triangle[0], triangle[1]), 0)
    second = (calpoint(point[3], point[4], triangle[0], triangle[2]), 0)
    # 计算两点的坐标
    try:
        one = calline(triangle[0], triangle[1])
        first = (first[0], calyvalue(one, first))
    # 如果三角形一条边是一条竖线
    except:
        first = (first[0], calyvalue(cutline, first))
    # 计算两点的坐标
    try:
        two = calline(triangle[0], triangle[2])
        second = (second[0], calyvalue(two, second))
    # 如果三角形一条边是一条竖线
    except:
        second = (second[0], calyvalue(cutline, second))
    print(calarea(triangle[0], first, second))  # 求面积


data = open("#7_data.in", "r").read().split("\n")
points = []  # n个点的坐标
temp = data[0].split(", ")
for i in range(int(temp[0])):
    points.append((int(temp[2 * i + 1]), int(temp[2 * i + 2])))
dicts = dict(zip("ABCDEFGHIJKLMNOPQRSTUVWXYZ", range(26)))
for i in range(10):
    temp = []  # 选中的5个点
    word = data[i + 1]
    for i in word:
        if i in dicts:
            temp.append(points[dicts[i]])
    main(temp)
