/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utily.c                                            :+:      :+:    :+:   */
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
#define	COL1	0
#define	COL2	1
#define	COL3	2
#define	COL4	3

#define	ROW1	5
#define	ROW2	6
#define	ROW3	7
#define	ROW9	8

#define SIZE	4

//check_input
//function  : check if the parameters put on the input are betwenn 1 and size 
//and if the number of input are equal to : 4*size.
//input(s)  : char *input :
//output(s) : unsigned int :
unsigned int	check_input(char *input)
{
    int i;
    int j;

    i = j = 0;
    while (input[i] != '\0')
    {
        if (input[i] >= '1' && input[i] <= '0' + SIZE)
            j++;
        i++;
    }
    if (j != SIZE * 4)
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
	pairs = (unsigned int **)malloc(sizeof(int*)*(SIZE*2));
	while (i < SIZE*2)
		pairs[i++] = (unsigned int *)malloc(sizeof(int)*2);
	i = 0;
	while (i < SIZE)
	{
		if (input[i] != ' ')
		{
			pairs[j][0] = input[i] - '0';
			pairs[j][1] = input[i + (SIZE*2)] - '0';
		}
		else
		{
			pairs[j][0] = input[i + 1] - '0';
			pairs[j][1] = input[i + (SIZE*2) + 1] - '0';
		}
		i++;
		j++;
	}
	i =+ SIZE*2;
	while ((input[i]) && (j < (SIZE * 2)))
	{
		if (input[i] != ' ')
		{
			pairs[j][0] = input[i] - '0';
			pairs[j][1] = input[i + (SIZE*2)] - '0';
		}
		else
		{
			pairs[j][0] = input[i + 1] - '0';
			pairs[j][1] = input[i + (SIZE*2) + 1] - '0';
		}
		i++;
		j++;
	}
	return (pairs);
}

//check_pairs
//function  : checks the pairs and ensures they are valid
//input(s)  : unsigned int **pairs: a 2-dim array of length 2*SIZE and width 2
//output(s) : unsigned int valid: 1 if valid, 0 if not
unsigned int	check_pairs(unsigned int **pairs)
{
    unsigned int    i;
    unsigned int    max;
    unsigned int    min;

    i = 0;
    max = SIZE + 1;
    if (SIZE <= 3)
        min = max;
    else
        min = 4;
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
unsigned int **initialize_grid(void)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	**grid;

	i = 0;
	grid = (unsigned int **)malloc(sizeof(int*)*(SIZE));
	while (i < SIZE)
    	{
		grid[i] = (unsigned int *)malloc(sizeof(int)*(SIZE));
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

//main
// function : run the program
// input(s) : int argc: an integer containing the number of args from the command line (expect 1) + 1
// input(s) : char **argv: a 2-dim array pointing to each string provided as argument 
// output(s) : generated grid (+ error messages if incorrect input)
int main(void)
{
	unsigned int	**pairs;

    if (check_input(argv[1]))
	{
		write(1, "oui", 3);
		pairs = create_pairs(argv);
	}
	else
	{
		write (1, "non", 3);
		return (0);
	}
	write(1, "\n", 1);
	if (check_pairs(pairs))
		write(1, "ok", 2);
	else
		write(1, "nop", 3);

	grid = initialize_grid();
}