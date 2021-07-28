def is_valid_state(state):
    # check if it's a valid solution
    # for n queues
    #    1. All n queues are placed
    #    2. No 2 queues can attack each other
    return True


def get_candidates(state):
    # List of candidates can be used to construct the next state
    return []


def search(state, solutions):
    # Checks if state is the valid solution to our backtracking problem,
    # Recursively
    # It records all possible solutions

    if is_valid_state(state):
        solutions.append(state.copy())
        # return

    for candidate in get_candidates(state):
        state.add(candidate)
        search(state, solutions)
        state.remove(candidate)


def solve():
    solutions = []
    state = set()
    search(state, solutions)
    return solutions
