/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:57:05 by dcresce           #+#    #+#             */
/*   Updated: 2025/08/30 13:57:07 by dcresce          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
/* *******************************Includes*********************************** */
#include <stdlib.h>
#include <stdio.h>
//#include <unistd.h>
/* ********************************Defines*********************************** */
#define SIZE	4
/* *************************Functions prototypes***************************** */
void	put_grid(unsigned int **grid);
void	check_max(unsigned int **grid, unsigned int **pairs);
void	fill_max(unsigned int **grid, int r_c, int direction, int pos);
void	fill_ones(unsigned int **grid, unsigned int **pairs);
/* ********************************Functions********************************* */

// fill_grid
// function : fill the grid
// input(s) : int **grid: the grid to fill.
//			  int **pairs: the pairs of numbers.
// output(s) :
void	fill_grid(unsigned int **grid, unsigned int **pairs)
{
	check_max(grid, pairs);
	fill_ones(grid, pairs);
}

// check_max
// function : looks for lines where the max value is needed
// input(s) : int **grid: the grid to fill.
//			  int **pairs: pairs of numbers on each column
// output(s) :
void	check_max(unsigned int **grid, unsigned int **pairs)
{
	int	check;

	check = 0;
	while (check < SIZE)
	{
		if (pairs[check][0] == SIZE)
			fill_max(grid, 1, 1, check);
		else if (pairs[check][1] == SIZE)
			fill_max(grid, 1, 0, check);
		check++;
	}
	while (check < (SIZE * 2))
	{
		if (pairs[check][0] == SIZE)
			fill_max(grid, 0, 1, (check - SIZE));
		else if (pairs[check][1] == SIZE)
			fill_max(grid, 0, 0, (check - SIZE));
		check++;
	}
}

// fill_max
// function : fill the lines and columns where there is the max value
// input(s) : int **grid: the grid to fill.
//			  int r_c: row or column selector. Row = 0, Col = 1.
//			  int direction: if col: 1 = from top, 0 = from bottom
//							 if row: 1 = from left, 0 = from right
// output(s) :
void	fill_max(unsigned int **grid, int r_c, int direction, int pos)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (direction)
	{
		if (r_c)
			while (i++ < SIZE)
				grid[i - 1][pos] = i;
		else
			while (i++ < SIZE)
				grid[pos][i - 1] = i;
	}
	else
	{
		i = SIZE;
		if (r_c)
			while (i--)
				grid[j++][pos] = i + 1;
		else
			while (i--)
				grid[pos][j++] = i + 1;
	}
}

// fill_ones
// function : fill the lines and columns where there is the max value
// input(s) : int **grid: the grid to fill.
//			  int r_c: row or column selector. Row = 0, Col = 1.
//			  int direction: if col: 1 = from top, 0 = from bottom
//							 if row: 1 = from left, 0 = from right
// output(s) :
void	fill_ones(unsigned int **grid, unsigned int **pairs)
{
	int	check;

	check = 0;
	while (check < SIZE)
	{
		if (pairs[check][0] == 1)
			grid[0][check] = SIZE;
		else if (pairs[check][1] == 1)
			grid[SIZE - 1][check] = SIZE;
		check++;
	}
	while (check < (SIZE * 2))
	{
		if (pairs[check][0] == 1)
			grid[check - SIZE][0] = SIZE;
		else if (pairs[check][1] == 1)
			grid[check - SIZE][SIZE - 1] = SIZE;
		check++;
	}
}
