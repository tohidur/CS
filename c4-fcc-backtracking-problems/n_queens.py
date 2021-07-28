from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        solutions = []
        state = []
        self.search(state, solutions, n)
        return solutions

    def is_valid_state(self, state, n):
        return len(state) == n

    def get_candidates(self, state, n):
        if not state:
            return range(n)

        position = len(state)
        candidates = set(range(n))
        # purne down candidates that place the queen into attacks
        for row, col in enumerate(state):
            # discard column index if it's occupied by queen
            candidates.discard(col)
            dist = position - row

            # discard diagonals
            candidates.discard(col + dist)
            candidates.discard(col - dist)
        return candidates

    def search(self, state, solutions, n):
        if self.is_valid_state(state, n):
            solutions.append(state.copy())
            return

        for candidate in self.get_candidates(state, n):
            state.append(candidate)
            self.search(state, solutions, n)
            state.pop()


if __name__ == "__main__":
    sol = Solution()
    print(sol.solveNQueens(4))

