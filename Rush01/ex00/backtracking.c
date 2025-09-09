/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:57:05 by dcresce           #+#    #+#             */
/*   Updated: 2025/08/30 13:57:07 by dcresce          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/* *******************************Includes*********************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* ********************************Defines*********************************** */
#define SIZE	4

//function prototypes
unsigned int	**complete_grid(unsigned int **grid, unsigned int **pairs);
unsigned int	**generate_candidate(unsigned int **grid, unsigned int *pos, unsigned int num);
unsigned int	*get_free_square(unsigned int **grid);
unsigned int	check_sudoku(unsigned int **grid, unsigned int *pos);
unsigned int	check_views(unsigned int **grid, unsigned int **pairs, unsigned int *pos);
unsigned int    check_views_up(unsigned int **grid, unsigned int **pairs, unsigned int *pos);
unsigned int    check_views_bottom(unsigned int **grid, unsigned int **pairs, unsigned int *pos);
unsigned int    check_views_left(unsigned int **grid, unsigned int **pairs, unsigned int *pos);
unsigned int    check_views_right(unsigned int **grid, unsigned int **pairs, unsigned int *pos);

//complete_grid
// function : generates the first solution to the problem
// input(s) : unsigned int **grid: a pointer of pointers to integers representing the numbers in the grid
// && unsigned int **pairs: a pointer of pointers to integers representing the pairs of numbers in the rows and cols
// output(s) : unsigned int **grid_c: the filled up solution
unsigned int **complete_grid(unsigned int **grid, unsigned int **pairs)
{
	unsigned int    **grid_c;
	unsigned int    num;
	unsigned int    *pos;

	num = 1;
	pos = get_free_square(grid);
	if (pos[0] == '!')
		return grid;
	while (num <= SIZE)
	{
		grid_c = generate_candidate(grid, pos, num);
		if (check_views(grid_c, pairs, pos) == 1 && check_sudoku(grid_c, pos) == 1)
			grid_c = complete_grid(grid_c, pairs);
		else
		{
			num++;
			continue;
		}
		if (get_free_square(grid_c)[0] != '!')
		{
			num++;
			continue;
		}
		else
			return grid_c;
	}
	return generate_candidate(grid, pos, 0);
}

//generate_candidate
// function : generates a candidate grid
// inputs(s) : unsigned int **grid: the original grid
// & unsigned int *pos: 2 numbers representing the row and col in the grid
// & unsigned int num: the number to be added at the position pos in the grid 
// output(s) : unsigned int **grid_c: a candidate solution
unsigned int **generate_candidate(unsigned int **grid, unsigned int *pos, unsigned int num)
{
	unsigned int **grid_c;

	grid_c = grid;
	grid_c[pos[0]][pos[1]] = num;
	return grid_c;
}

//get_free_square
// function  : gets the next free square in a grid going row by row
// input(s)  : unsigned int **grid: the grid of numbers
// output(s) : unsigned int *pos: the row and col of the next free square
unsigned int	*get_free_square(unsigned int **grid)
{
	int	i;
	int	j;
	unsigned int	*pos;

	i = 0;
	j = 0;
	pos = (unsigned int *)malloc(sizeof(int)*2);
	if (pos == NULL)
	{
		write(1, "Malloc failure", 14);
		return (0);
	}
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if(!(grid[i][j]))
			{
				pos[0] = i;
				pos[1] = j;
				return (pos);
			}
			j++;
		}
		i++;
	}
	pos[0] = '!';
	return (pos);
}

//check_sudoku
// function  : checks if the number at the position is valid with the sudoku rule
// input(s)  : unsigned int **grid: the grid of numbers
//			   unsigned int **pos: the position row, col to check
// output(s) : a 1 if valid and a 0 if invalid
// descripton: the function checks first that the sum in the row works,
// 			   then repeats the same process for the column
unsigned int	check_sudoku(unsigned int **grid, unsigned int *pos)
{
	unsigned int	row[SIZE];
	unsigned int	col[SIZE];
	unsigned int	i;
	unsigned int	val;

	i = 0;
	val = grid[pos[0]][pos[1]];
	while (i < SIZE)
	{
		row[i] = grid[pos[0]][i];
		col[i] = grid[i][pos[1]];
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		if (i != pos[1] && row[i] == val)
			return (0);
		if (i != pos[0] && col[i] == val)
			return (0);
		i++;
	}
	return (1);
}

//check_views
// function  : checks that the number at the position is valid with the views
// input(s)  : unsigned int **grid : the grid filled up with numbers
//			   unsigned int **pairs : the pairs provided
//			   unsigned int *pos : the position to check
// output(s) : 1 if valid, 0 if invalid
unsigned int	check_views(unsigned int **grid, unsigned int **pairs, unsigned int *pos)
{
	if (check_views_up(grid, pairs, pos)
		&& check_views_bottom(grid, pairs,pos)
		&& check_views_left(grid, pairs, pos)
		&& check_views_right(grid, pairs, pos))
		return (1);
	else
		return (0);
}

//check_views_*
// function  : checks the views obtained at a position in the grid
//			   and assesses whether they are compatible with the pairs
// input(s)  : unsigned int **grid : the grid filled up with numbers
// 			   unsigned int **pairs : the pairs provided
//			   unsigned int *pos : the position to check
// output(s) : 1 if valid, 0 if invalid
unsigned int    check_views_up(unsigned int **grid, unsigned int **pairs, unsigned int *pos)
{
	unsigned int    i;
	unsigned int    count;
	unsigned int    view;
	unsigned int    max;

	i = 0;
	count = 0;
	view = pairs[pos[1]][0];
	max = 0;
	while (i < SIZE)
	{
		if (grid[i][pos[1]] == 0)
			return (1);
		if (grid[i][pos[1]] > max)
		{
			max = grid[i][pos[1]];
			count++;
		}
		i++;
	}
	if (count != view)
		return (0);
	return (1);
}

unsigned int    check_views_bottom(unsigned int **grid, unsigned int **pairs, unsigned int *pos)
{
	unsigned int    i;
	unsigned int    count;
	unsigned int    view;
	unsigned int    max;

	i = 0;
	count = 0;
	view = pairs[pos[1]][1];
	max = 0;
	while (i < SIZE)
	{
		if (grid[SIZE - i - 1][pos[1]] == 0)
			return (1);
		if (grid[SIZE - i - 1][pos[1]] > max)
		{
			max = grid[SIZE - i -1][pos[1]];
			count++;
		}
		i++;
	}
	if (count != view)
		return (0);
	return (1);
}

unsigned int    check_views_left(unsigned int **grid, unsigned int **pairs, unsigned int *pos)
{
	unsigned int    i;
	unsigned int    count;
	unsigned int    view;
	unsigned int    max;

	i = 0;
	count = 0;
	view = pairs[SIZE + pos[0]][0];
	max = 0;
	while (i < SIZE)
	{
		if (grid[pos[0]][i] == 0)
			return (1);
		if (grid[pos[0]][i] > max)
		{
			max = grid[pos[0]][i];
			count++;
		}
		i++;
	}
	if (count != view)
		return (0);
	return (1);
}

unsigned int    check_views_right(unsigned int **grid, unsigned int **pairs, unsigned int *pos)
{
	unsigned int    i;
	unsigned int    count;
	unsigned int    view;
	unsigned int    max;

	i = 0;
	count = 0;
	view = pairs[SIZE + pos[0]][1];
	max = 0;
	while (i < SIZE)
	{
		if (grid[pos[0]][SIZE - i - 1] == 0)
			return (1);
		if (grid[pos[0]][SIZE - i - 1] > max)
		{
			max = grid[pos[0]][SIZE - i - 1];
			count++;
		}
		i++;
	}
	if (count != view)
		return (0);
	return (1);
}
