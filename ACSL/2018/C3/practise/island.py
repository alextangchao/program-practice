class Solution:
    """
    ：后面指的是这个变量的类型
    -> 后面指的是这个函数的返回类型
    看不懂的话就当作是这样的：def maxAreaOfIsland(self, grid):
    """

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        def ingrid(row, col):
            return True if 0 <= row < len(grid) and 0 <= col < len(grid[0]) else False

        def getsurround(row, col):
            surround = []
            if ingrid(row - 1, col):
                surround.append((row - 1, col))
            if ingrid(row, col - 1):
                surround.append((row, col - 1))
            if ingrid(row + 1, col):
                surround.append((row + 1, col))
            if ingrid(row, col + 1):
                surround.append((row, col + 1))
            return surround

        # 递归搜索
        def spread(row, col, num):
            num += 1  # 岛的大小+1
            visit[row][col] = 1  # 这个点已经访问过了
            surround = getsurround(row, col)  # 得到周围的点
            for i in surround:
                if grid[i[0]][i[1]] == 1 and visit[i[0]][i[1]] == 0:
                    num = spread(i[0], i[1], num)  # 递归，转到下一个点进行搜索，这个递归结束后更新岛的大小
            return num

        # visit 初始化
        def begin():
            for i in range(len(grid)):
                visit.append([0 for k in grid[i]])

        visit = []  # 储存地图中访问过的点
        begin()
        large = 0
        for i in range(len(grid)):
            for k in range(len(grid[i])):
                if grid[i][k] == 1 and visit[i][k] == 0:
                    large = max(large, spread(i, k, 0))
        return large
