#!/usr/bin/python3
""" Island Perimeter """


def island_perimeter(grid):
    """
        Module that returns the perimeter of the island described in grid
        water is 0 and land is 1.
        Args:
            grid (list): list of integers
    """
    rows = len(grid)
    cols = len(grid[0])
    permiter = 0

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                if row == 0 or grid[row - 1][col] == 0:
                    permiter += 1
                if row == rows - 1 or grid[row + 1][col] == 0:
                    permiter += 1
                if col == 0 or grid[row][col - 1] == 0:
                    permiter += 1
                if col == cols - 1 or grid[row][col + 1] == 0:
                    permiter += 1
    return permiter
