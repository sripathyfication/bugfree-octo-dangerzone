#!/usr/bin/python
import sys

def unique(grid):
    paths = 0
    for i in range(0,len(grid)):
        for j in range(0,len(grid[i])):
            grid[i][j] = 1
        paths = paths + 1
    return paths  

def main():
    m = input("Enter the grid size - rows\n")
    n = input("Enter the grid size - columns\n")
    grid = [[0 for x in range(0,n)] for y in range(0,m)]
    print len(grid)
    paths = unique(grid)
    print paths

if __name__ == '__main__':
   main()

