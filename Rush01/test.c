#include <stdio.h>
#include <unistd.h>

unsigned int	check_input(char *input);
unsigned int	**create_pairs(char *input);
unsigned int	check_pairs(unsigned int **pairs);
unsigned int    **initialize_grid(void);
void	fill_grid(unsigned int **grid, unsigned int **pairs);
//void check_max(unsigned int **grid, unsigned int **pairs);
//void	fill_max(unsigned int **grid, int r_c, int direction, int pos);
void    put_grid(unsigned int **grid);
void    put_pairs(unsigned int **pairs);

void    test_check_pairs_1(void)
{
    char *input = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
    unsigned int pairs_origin[8][2] = {
        {4, 1},
        {3, 2},
        {2, 2},
        {1, 2},
        {4, 1},
        {3, 2},
        {2, 2},
        {1, 2},
    };
    int l = 8;
    int c = 2;
    unsigned int **pairs;

    printf("Expected:\n");
    for (int i = 0; i < l; i++) {
        printf("\n");
        for (int j = 0; j < c; j++) {
            printf("%d ", pairs_origin[i][j]);}
        }

    printf("\n\nObtained:\n");
    pairs = create_pairs(input);
    check_pairs(pairs);
    put_pairs(pairs);
}

void    test_check_pairs_2(void)
{
    char *input = "1 2 2 4 4 2 2 1 1 2 2 4 4 2 2 1";
    unsigned int pairs_origin[8][2] = {
        {1, 4},
        {2, 2},
        {2, 2},
        {4, 1},
        {1, 4},
        {2, 2},
        {2, 2},
        {4, 1},
    };
    int l = 8;
    int c = 2;
    unsigned int **pairs;

    printf("Expected:\n");
    for (int i = 0; i < l; i++) {
        printf("\n");
        for (int j = 0; j < c; j++) {
            printf("%d ", pairs_origin[i][j]);}
        }

    printf("\n\nObtained:\n");
    pairs = create_pairs(input);
    check_pairs(pairs);
    put_pairs(pairs);
}

void    test_check_input_1(void)
{
    char *input = "1 2 4 3 1 3 4 2 1 3 4 2 3 2 2 2";

    printf("Expected: %d\n", 1);
    printf("Obtained: %d\n\n", check_input(input));
}

void    test_check_input_2(void)
{
    char *input = "1 2 2 4 4 2 2 1 1 2 2 4 4 2 2 1";

    printf("Expected: %d\n", 1);
    printf("Obtained: %d\n\n", check_input(input));
}

void    test_main_1(void)
{
    char *input = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
    
    unsigned int result[4][4] = {
        {1, 2, 3, 4},
        {2, 3, 4, 1},
        {3, 4, 1, 2},
        {4, 1, 2, 3},
        };
    int lignes = 4;
    int colonnes = 4;

    printf("Expected:\n");
    for (int i = 0; i < lignes; i++) {
        printf("\n");
        for (int j = 0; j < colonnes; j++) {
            printf("%d ", result[i][j]);}
        }
    printf("\n\nObtained:\n");
    unsigned int **grid;
    unsigned int **pairs;
    pairs = create_pairs(input);
    grid = initialize_grid();
    fill_grid(grid, pairs);
}
    
void    test_main_2(void)
{
    char *input = "1 2 2 4 4 2 2 1 1 2 2 4 4 2 2 1";
    
    unsigned int result[4][4] = {
        {4, 3, 2, 1},
        {3, 4, 1, 2},
        {2, 1, 4, 3},
        {1, 2, 3, 4},
        };
    int lignes = 4;
    int colonnes = 4;

    printf("Expected:\n");
    for (int i = 0; i < lignes; i++) {
        printf("\n");
        for (int j = 0; j < colonnes; j++) {
            printf("%d ", result[i][j]);}
        }
    printf("\n\nObtained:\n");
    unsigned int **grid;
    unsigned int **pairs;
    pairs = create_pairs(input);
    grid = initialize_grid();
    fill_grid(grid, pairs);
}

int main(void)
{
    printf("\nTEST 1 :\n\n");

    printf("TEST CHECK_INPUT\n\n");
    test_check_input_1();

    printf("TEST CHECK_PAIRS\n\n");
    test_check_pairs_1();

    printf("\nTEST MAIN\n\n");
    test_main_1();


    printf("\nTEST 2 :\n\n");

    printf("TEST CHECK_INPUT\n\n");
    test_check_input_2();

    printf("TEST CHECK_PAIRS\n\n");
    test_check_pairs_2();

    printf("\nTEST MAIN\n\n");
    test_main_2();
}