class TreeNode:
    def __init__(self, value, depth, parent):
        self.value = value
        self.left = None
        self.right = None
        self.depth = depth
        self.parent = parent


def cal(node):
    if node is None:
        return
    if node.left is None and node.right is None:
        num[1] += 1
        if node.depth > num[0]:
            num[0] = node.depth
        num[4] += node.depth * 2 + 2
    if (node.left is None and node.right is not None) or (node.right is None and node.left is not None):
        num[2] += 1
        num[4] += node.depth + 1
    num[3] += node.depth
    cal(node.left)
    cal(node.right)


def create(node, value):
    if value <= node.value:
        if node.left is None:
            node.left = TreeNode(ch, node.depth + 1, node)
        else:
            create(node.left, value)
    else:
        if node.right is None:
            node.right = TreeNode(ch, node.depth + 1, node)
        else:
            create(node.right, value)


letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
data = open("#8_data.in", "r").read().split("\n")
for i in range(2):
    word = data[i]
    root = TreeNode(word[0], 0, None)
    for ch in word[1:]:
        if ch in letter:
            create(root, ch)

    num = [0, 0, 0, 0, 0]  # depth, leaf, onechild, inter
    cal(root)
    for i in num:
        print(i)
