to_win = [[2, 5, 8], [2, 4, 6], [3, 4, 5], [0, 1, 2], [1, 4, 7], [0, 3, 6], [0, 4, 8], [6, 7, 8]]

def get_by_number(grid, n):
    p = n // 3
    q = n % 3
    return grid[p][q]

for _ in range(int(input())):
    grid = [list(input().strip()) for i in range(3)]
    number_of_O = 0
    number_of_X = 0
    O_won = False
    X_won = False
    last_by_X = None
    blank_left = False
    for column in grid:
        for box in column:
            if box == 'X':
                number_of_X += 1
            elif box == 'O':
                number_of_O += 1
            else:
                blank_left = True

    if (number_of_X == number_of_O):
        last_by_X = False
    elif number_of_O + 1 == number_of_X:
        last_by_X = True
    else:
        print(3)
        continue

    for required in to_win:
        s = ""
        for n in required:
            p = n // 3
            q = n % 3
            s += grid[p][q]
        if s == "XXX":
            X_won = True
        elif s == "OOO":
            O_won = True

    if (X_won and O_won) or (X_won and (not last_by_X)) or (O_won and last_by_X):
        print(3)
    elif X_won or O_won:
        print(1)
    elif blank_left:
        print(2)
    else:
        print(1)