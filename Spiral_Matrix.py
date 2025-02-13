class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        v = []

        row_size = len(matrix)
        if row_size == 0:
            return v
        col_size = len(matrix[0])

        top, bottom = 0, row_size - 1
        left, right = 0, col_size - 1

        while top <= bottom and left <= right:
            for j in range(left, right + 1):
                v.append(matrix[top][j])
            top += 1

            for i in range(top, bottom + 1):
                v.append(matrix[i][right])
            right -= 1

            if top <= bottom:
                for j in range(right, left - 1, -1):
                    v.append(matrix[bottom][j])
                bottom -= 1

            if left <= right:
                for i in range(bottom, top - 1, -1):
                    v.append(matrix[i][left])
                left += 1

        return v

