#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE	4

//Function prototypes
unsigned int	check_input(char *input);
unsigned int	**create_pairs(char *input);
unsigned int	check_pairs(unsigned int **pairs);
unsigned int	**initialize_grid(void);
unsigned int	*get_free_square(unsigned int **grid);
unsigned int	check_views(unsigned int **grid, unsigned int **pairs, unsigned int *pos);
unsigned int	check_sudoku(unsigned int **grid, unsigned int *pos);
unsigned int	**complete_grid(unsigned int **grid, unsigned int **pairs);
unsigned int	**generate_candidate(unsigned int **grid, unsigned int *pos, unsigned int num);
void	fill_grid(unsigned int **grid, unsigned int **pairs);
void    put_pairs(unsigned int **pairs);
void	put_grid(unsigned int **grid);

//argument to use: "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
//command to run with gdb: gdb --args ./a.out <arg1>

int main(int argc, char **argv)
{
	unsigned int	**pairs;
	unsigned int	**grid;
	int empty;

	empty = argc;
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
	unsigned int	*pos_2;

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
        if (grid_c[pos[0]][pos[1]] == 0)
        {
			num++;
            continue;
		}
        else
        	return grid_c;
    }
    return generate_candidate(grid, pos, 0);
}