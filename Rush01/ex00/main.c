/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:22:36 by dcresce           #+#    #+#             */
/*   Updated: 2025/08/30 13:22:38 by dcresce          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/* *******************************Includes*********************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* *************************Functions from files***************************** */
//check correct value (1 - Size) and correct quantity (4*Size)
unsigned int	check_input(char *input);
//create the pairs
unsigned int	**create_pairs(char *input);
//check that all pairs are valid (size - 1 =< sum of elements <= size + 1)
unsigned int	check_pairs(unsigned int **pairs);
//display the pairs
void			put_pairs(unsigned int **pairs);
//initialize the grid to a 2-dim array of size SIZE filled with zeroes
unsigned int	**initialize_grid(void);
//fill the grid
void			fill_grid(unsigned int **grid, unsigned int **pairs);
//display the grid
void			put_grid(unsigned int **grid);
//"complete grid"
unsigned int	**complete_grid(unsigned int **grid, unsigned int **pairs);
/* *****************************Main program********************************* */
int main(int argc, char **argv)
{
	unsigned int	**pairs;
	unsigned int	**grid;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
    if (check_input(argv[1]))
	{
		write(1, "Good input\n", 11);
	}
	else
	{
		write (1, "Wrong input\n", 12);
		return (0);
	}
	write(1, "\n", 1);

	pairs = create_pairs(argv[1]);
	if (check_pairs(pairs))
		write(1, "Good pairs\n", 12);
	else
		write(1, "Wrong pairs\n", 13);
	put_pairs(pairs);
	write(1,"\n",1);
	
	grid = initialize_grid();
	write(1, "Grid initialized\n", 17);
    put_grid(grid);
	write(1,"\n",1);

	fill_grid(grid, pairs);
	write(1, "Grid pre-filled\n", 16);
	put_grid(grid);
	write(1, "\n", 1);

	grid = complete_grid(grid, pairs);
	write(1, "Grid completed\n", 15);
	put_grid(grid);
}