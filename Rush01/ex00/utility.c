/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:57:05 by dcresce           #+#    #+#             */
/*   Updated: 2025/08/30 13:57:07 by dcresce          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//Used to address the pairs array
#define SIZE	4

//Function prototypes
unsigned int	check_input(char *input);
unsigned int	**create_pairs(char *input);
unsigned int	check_pairs(unsigned int **pairs);
unsigned int	**initialize_grid(void);
void			put_pairs(unsigned int **pairs);
void			put_grid(unsigned int **grid);

//check_input
//function  : check if the parameters put on the input are between 1 and 
//size, if the number of input are equal to 4*size and if we have only one 
//space after 
//the numbers.
//input(s)  : char *input :
//output(s) : unsigned int :
unsigned int	check_input(char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i] != '\0' && i < SIZE * 8)
	{
		if (!(input[i] >= '1' && input[i] <= '0' + SIZE))
			return (0);
		else if (((input[i + 1] != ' ') && (input[i + 1] != 0)))
			return (0);
		i += 2;
		j++;
	}
	if (j != 4 * SIZE)
		return (0);
	return (1);
}

//create_pairs
//function  : create the pairs for the grid
//input(s)  : char *input : the string given in argv
//output(s) : unsigned int **pairs : 2 dimension array with the pairs
unsigned int	**create_pairs(char *input)
{
	unsigned int	**pairs;
	int				i;
	int				j;

	i = 0;
	j = 0;
	pairs = (unsigned int **) malloc(sizeof(unsigned int *) * (SIZE * 2));
	while (i < SIZE * 2)
		pairs[i++] = (unsigned int *) malloc(sizeof(unsigned int) * 2);
	i = 0;
	if (pairs == NULL)
	{
		write(1, "Malloc failure", 14);
		return (0);
	}
	while (i < (SIZE * 2))
	{
		if (input[i] != ' ')
		{
			pairs[j][0] = input[i] - '0';
			pairs[j][1] = input[i + (SIZE * 2)] - '0';
			j++;
		}
		i++;
	}
	i += SIZE * 2;
	while ((input[i]) && (j < (SIZE * 2)))
	{
		if (input[i] != ' ')
		{
			pairs[j][0] = input[i] - '0';
			pairs[j][1] = input[i + (SIZE * 2)] - '0';
			j++;
		}
		i++;
	}
	return (pairs);
}

//check_pairs
//function  : checks the pairs and ensures they are valid
//input(s)  : unsigned int **pairs: a 2-dim array of length 2*SIZE and width 2
//output(s) : unsigned int valid: 1 if valid, 0 if not
unsigned int	check_pairs(unsigned int **pairs)
{
	unsigned int	i;
	unsigned int	max;
	unsigned int	min;

	i = 0;
	max = SIZE + 1;
	if (SIZE <= 2)
		min = max;
	else
		min = 3;
	while (i < 2 * SIZE)
	{
		if (pairs[i][0] + pairs[i][1] < min
			|| pairs[i][0] + pairs [i][1] > max)
			return (0);
		i++;
	}
	return (1);
}

//create grid
// function : initialize the grid to a 2-dim array of integers with a zero value
// input(s) : /
// output(s) : generated grid with zero values
unsigned int	**initialize_grid(void)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	**grid;

	i = 0;
	grid = (unsigned int **) malloc(sizeof(int *) * (SIZE));
	if (grid == NULL)
	{
		write(1, "Malloc failure", 14);
		return (0);
	}
	while (i < SIZE)
	{
		grid[i] = (unsigned int *) malloc(sizeof(int) * (SIZE));
		j = 0;
		while (j < SIZE)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}

//put_pairs
//function : print the pairs on the standard output
//input(s): unsigned int **pairs: a 2-dim array of unsigned integers
//output(s) : /
void	put_pairs(unsigned int **pairs)
{
	int	i;
	int	j;
	char	ch;

	i = 0;
	while (pairs[i])
	{
		j = 0;
		while (j < 2)
		{
			ch = '0' + pairs[i][j];
			write(1, &ch, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

//put_grid
//function : print the grid on the standard output
//input(s): unsigned int **grid: a 2-dim array of unsigned integers
//output(s) : /
void	put_grid(unsigned int **grid)
{
	int	i;
	int	j;
	char	ch;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			ch = '0' + grid[i][j];
			write(1, &ch, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
