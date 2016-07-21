/*
 * Given numRows, generate the first numRows of Pascal's triangle.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int **arr, int size, int row)
{
    for(int i= 0; i < size; i++)
        for (int j=0; j < row; j++)
            printf(" %d \t", arr[i][j]);

    printf("\n");
}

int *arrayify_pascal_num(int n, int row) 
{
    int *r_arr = malloc(sizeof(int) * (row+1));
    
    memset(r_arr, 0, sizeof(int) * (row + 1));

    /* row number tells me how many times to divide the number
     * and extract the remainder
     */

    while (row >= 0) {
        r_arr[row] = n % 10;
        row--;
        n = n / 10;
    }

    return r_arr;
}

int* generate_pascal_number(int row) {
    int p_num = 1, p_row = 0;
    int *arr;

    p_row = row;
    while (p_row) {
        p_num = p_num * 11;
        p_row--;
    }

    arr = arrayify_pascal_num(p_num, row);

    return arr;
}

int main()
{
    int n_rows = 5, n_row = 0;
    int **r_arr_arr = malloc(sizeof(int) * n_rows);

    while (n_row != n_rows)
    {
        r_arr_arr[n_row] = generate_pascal_number(n_row);
        n_row++;
    }


    return 0;
}
