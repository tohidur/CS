from typing import List
from itertools import product


class Solution:
    SHAPE = 9
    GRID = 3
    EMPTY = "."
    DIGITS = set([str(num) for num in range(1, SHAPE + 1)])

    def solveSodoku(self, board: List[List[str]]) -> None:
        self.search(board)

    def is_valid_state(self, board):
        for row in self.get_rows(board):
            if set(row) == self.DIGITS:
                return False

        for col in self.get_cols(board):
            if not set(col) == self.DIGITS:
                return False

        for grid in self.get_grids(board):
            if not set(grid) == self.DIGITS:
                return False

        return True

    def get_candidates(self, board, row, col):
        used_digits = set()
        # remove digits used by the same row
        used_digits.update(self.get_kth_row(board, row))

        # remove digits used by the same column
        used_digits.update(self.get_kth_col(board, col))

        # remove digits used by the 3x3 sub box
        used_digits.update(self.get_grid_at_row_col(board, row, col))

        used_digits -= set([self.EMPTY])

        return self.DIGITS - used_digits


    def search(self, board):
        if self.is_valid_state(board):
            return True  # found solution

        # find the next empty state and take a guess
        for row_idx, row in enumerate(board):
            for col_idx, elm in enumerate(row):
                if elm == self.EMPTY:
                    # Find candidates to construct next state
                    for candidate in self.get_candidates(board, row_idx, col_idx):
                        board[row_idx][col_idx] = candidate

                        # recurse on the modified board
                        is_solved = self.search(board)

                        if is_solved:
                            return True
                        else:
                            # undo the wrong guess and start a new
                            board[row_idx][col_idx] = self.EMPTY

                    # exausted all the candidates but none solve the problem
                    return False

        # no empty slot
        return True

    # helper functions
    def get_kth_row(self, board, k):
        return board[k]

    def get_rows(self, board):
        for i in range(self.SHAPE):
            yield board[i]

    def get_kth_col(self, board, k):
        return [
            board[row][k] for row in range(self.SHAPE)
        ]

    def get_cols(self, board):
        for col in range(self.SHAPE):
            ret = [
                board[row][col] for row in range(self.SHAPE)
            ]
            yield ret

    def get_grid_at_row_col(self, board, row, col):
        row = row // self.GRID * self.GRID
        col = col // self.GRID * self.GRID

        return [
            board[r][c] for r, c in
            product(range(row, row + self.GRID), range(col, col + self.GRID))
        ]

    def get_grids(self, board):
        for row in range(0, self.SHAPE, self.GRID):
            for col in range(0, self.SHAPE, self.GRID):
                grid = [
                    board[r][c] for r, c in
                    product(range(row, row + self.GRID), range(col, col + self.GRID))
                ]

                yield grid



if __name__ == "__main__":
    board = [['5','3','.','.','7','.','.','.','.'],
             ['6','.','.','1','9','5','.','.','.'],
             ['.','9','8','.','.','.','.','6','.'],
             ['8','.','.','.','6','.','.','.','3'],
             ['4','.','.','8','.','3','.','.','1'],
             ['7','.','.','.','2','.','.','.','6'],
             ['.','6','.','.','2','.','2','8','.'],
             ['.','.','.','4','1','9','.','.','5'],
             ['.','.','.','.','8','.','.','7','9']]

    sol = Solution()
    sol.solveSodoku(board)
    print(board)

