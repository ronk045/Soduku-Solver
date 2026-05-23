# Soduku-Solver

This project implements a Sudoku solver in C using a recursive backtracking algorithm. The goal is to automatically solve standard 9×9 Sudoku puzzles by filling in empty cells while respecting all Sudoku constraints.

Overview

A valid Sudoku puzzle consists of a 9×9 grid divided into nine 3×3 subgrids (zones). Each row, column, and subgrid must contain all digits from 1 to 9 exactly once. Some cells are pre-filled, and the remaining cells (represented as 0s) must be completed.

This program reads an input puzzle and produces a completed solution if one exists.

Approach

The solver is built using a classic backtracking algorithm, which explores possible number placements recursively and undoes (“backtracks”) choices that lead to invalid states.

Core Idea

1. Find the next empty cell (value 0).
2. Try placing digits 1 through 9 in that cell.
3. For each candidate number:
    * Check if it is valid according to Sudoku rules.
    * If valid, place it and recursively attempt to solve the rest of the grid.
    * If the recursion succeeds, return success.
    * Otherwise, reset the cell and try the next number.
4. If no number works, return failure and backtrack.
