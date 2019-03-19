"""
这个解法只能过113个test case中的108个，说明这个算法是正确的但是效率不高
ACSL不存在效率的问题，所以这道题在leetcode上报Time Limit Exceeded就可以算作完成了
"""


class Solution:
    """
    ：后面指的是这个变量的类型
    -> 后面指的是这个函数的返回类型
    看不懂的话就当作是这样的：def pacificAtlantic(self, matrix):
    """

    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:

        # 判断在哪个海
        # 0指右下边
        # 1指左上边
        def judge(row, col, direction):
            if direction == 1 and (row == 0 or col == 0):
                return True
            if direction == 0 and (row == len(matrix) - 1 or col == len(matrix[0]) - 1):
                return True
            return False

        def ingrid(row, col):
            return True if 0 <= row < len(matrix) and 0 <= col < len(matrix[0]) else False

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
        def spread(row, col, direction):
            if judge(row, col, direction):
                return True
            visit[(row, col)] = 1  # 现在这个点已经访问过了
            surround = getsurround(row, col)  # 得到周围的点
            for i in surround:
                if (i[0], i[1]) not in visit and matrix[i[0]][i[1]] <= matrix[row][col]:
                    reach = spread(i[0], i[1], direction)  # 递归，转到下一个点进行搜索
                    if reach:
                        return True
            return False

        ans = []
        visit = {}  # 储存搜索过程中访问过的点
        for i in range(len(matrix)):
            for k in range(len(matrix[i])):
                visit.clear()
                # 能不能达到右下方的海
                if spread(i, k, 0):
                    visit.clear()
                    # 能不能达到左上方的海
                    if spread(i, k, 1):
                        ans.append([i, k])
        return ans
