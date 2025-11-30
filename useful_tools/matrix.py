class Matrix:
    def __init__(self, data):
        self.data = data
        self.rows = len(data)
        self.cols = len(data[0]) if data else 0

    def __str__(self):
        return '\n'.join(['\t'.join(map(str, row)) for row in self.data])

    def __add__(self, other):
        if self.rows != other.rows or self.cols != other.cols:
            raise ValueError("矩阵维度不匹配，无法相加")
        return Matrix([[self.data[i][j] + other.data[i][j] for j in range(self.cols)] for i in range(self.rows)])

    def __sub__(self, other):
        if self.rows != other.rows or self.cols != other.cols:
            raise ValueError("矩阵维度不匹配，无法相减")
        return Matrix([[self.data[i][j] - other.data[i][j] for j in range(self.cols)] for i in range(self.rows)])

    def __matmul__(self, other):  # 使用 @ 运算符实现矩阵乘法
        if self.cols != other.rows:
            raise ValueError("矩阵维度不匹配，无法相乘")
        result = [[sum(self.data[i][k] * other.data[k][j] for k in range(self.cols)) for j in range(other.cols)] for i in range(self.rows)]
        return Matrix(result)

    def determinant(self):
        if self.rows != self.cols:
            raise ValueError("行列式只对方阵定义")
        return self._det_recursive(self.data)

    def _det_recursive(self, mat):
        n = len(mat)
        if n == 1:
            return mat[0][0]
        if n == 2:
            return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0]
        det = 0
        for c in range(n):
            sub_mat = [row[:c] + row[c+1:] for row in mat[1:]]
            det += ((-1)**c) * mat[0][c] * self._det_recursive(sub_mat)
        return det


# 示例使用
A = Matrix([[1, 0, 1], [1, -1, 0], [0, 1, 2]])
B = Matrix([[1, 0, 0], [-1, -1, 0], [0, 1, 2]])

print("矩阵 A:")
print(A)
print("\n矩阵 B:")
print(B)

# print("\nA + B:")
# print(A + B)

# print("\nA - B:")
# print(A - B)

# print("\nA * B:")
# print(A @ B)

print("\nA 的行列式:")
print(A.determinant())
