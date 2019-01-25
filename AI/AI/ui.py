import cv2 as cv
import numpy as np


class drawpicture:
    def __init__(self, direction=[], maps=[], name=""):
        self.name = name
        self.store = maps
        self.direction = direction
        self.n = len(self.store)
        self.leftbase = 25
        self.upbase = 25
        self.recside = 80
        self.rechalfside = self.recside // 2
        self.lineside = 15
        self.gap = 20
        self.changecolor = {3: (200, 100, 190), -1: (0, 0, 220), 1: (0, 220, 220), 2: (250, 170, 100), 0: (0, 200, 0)}
        self.changedirection = {"U": (0, -1), "D": (0, 1), "L": (-1, 0), "R": (1, 0)}

    def show(self, a):
        for i in a:
            cv.imshow(str(i), i)
        cv.waitKey(0)

    def getrecposition(self, x, y):
        return self.leftbase + x * (self.recside + self.gap), self.upbase + y * (self.recside + self.gap)

    def getlineposition(self, x, y):
        x, y = self.getrecposition(x, y)
        return x + self.rechalfside + self.lineside // 2, y + self.rechalfside + self.lineside // 2

    def drawrec(self, img, x, y, color):
        x1, y1 = self.getrecposition(x, y)
        cv.rectangle(img, (x1, y1), (x1 + self.recside, y1 + self.recside), color, -1)

    def getdirection(self, x, y, direction):
        x += self.changedirection[direction][0]
        y += self.changedirection[direction][1]
        return x, y

    def drawline(self, img, x0, y0, direction):
        for i in direction:
            x1, y1 = self.getlineposition(x0, y0)
            x, y = self.getdirection(x0, y0, i)
            x2, y2 = self.getlineposition(x, y)
            # print(x0, y0, x, y)
            cv.line(img, (x1, y1), (x2, y2), (0, 0, 0), 10)

    def draw(self):
        # print("len ", self.n)
        # print(self.store)
        img = np.zeros([1024, 1024, 3], dtype=np.uint8)
        img.fill(255)
        for i in range(self.n):
            for k in range(self.n):
                # print(i, k)
                self.drawrec(img, k, i, self.changecolor[self.store[i][k]])
        """
        for i in range(self.n):
            for k in range(self.n):
                self.drawline(img, k, i, self.direction[i][k])
        """
        # cv.line(img, (50, 50), (200, 200), (255, 0, 0), 10)
        # self.show([img])
        cv.imwrite((self.name + ".jpg"), img)


def getinput():
    lines = open("ansmap.txt", "r").read().strip().split("\n")
    maps = [list(map(int, i.strip().split(" "))) for i in lines]
    # print(direction)
    return maps


maps = getinput()
#print("origin:", maps)
# print(maps, "\n", direction)
a = drawpicture([], maps, "shortest_path")
a.draw()
