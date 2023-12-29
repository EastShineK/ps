#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>   

int x, y;
int l = 0;
int lastl = 0;
int row, col;
int sum=0;

int find(int** arr, int x, int y, int row, int col)
{

    if (x == row - 1 && y == col - 1)
    {
        lastl = l;

        if (lastl > l)
        {
            lastl = l;
        }
        printf("%d\n", lastl);
        l = 0;
        lastl = 0;

        return 0;
    }
   // printf("%d %d\n", x, y);
    //if (arr[x][y] == 48)

    //{

    l += 1;
    if (x + 1 < row) {
        if (arr[x + 1][y] == 48)
        {
            arr[x + 1][y] = 'x';           
            find(arr, x + 1, y, row, col);
           // l++;

        }
    }
    if (y + 1 < col) {
        if (arr[x][y + 1] == 48)
        {
            arr[x][y + 1] = 'x';
            find(arr, x, y + 1, row, col);
          

        }
    }
    if (x - 1 > -1) {
        if (arr[x - 1][y] == 48)
        {
            arr[x - 1][y] = 'x';
            find(arr, x - 1, y, row, col);
           

        }
    }
    if (y - 1 > -1) {
        if (arr[x][y - 1] == 48)
        {
            arr[x][y - 1] = 'x';
            find(arr, x, y - 1, row, col);
            
        }
    }
    arr[x][y] = 'x';

    //}
    //else
    //{
    //    ;

   // }
}




int main(void)
{

    char f1[10];

    scanf("%s", f1);

    while (1)
    {

        FILE* fp;
        fp = fopen(f1, "r");

        fscanf(fp, "%d %d", &row, &col);


        if ((row > 0) && (col > 0))
        {
            int** d_Array = malloc(sizeof(int*) * row);
            for (int i = 0; i < row; i++)
            {
                d_Array[i] = malloc(sizeof(int) * col);
            }

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    d_Array[i][j] = 0;
                }
            }

            int num;


            for (int i = 0; i < row; i++)
            {

                for (int j = 0; j < col; j++)
                {
                    num = fgetc(fp);
                    if (num == 10)
                    {
                        num = fgetc(fp);
                    }
                    d_Array[i][j] = num;
                }

            }

            int k = 0;

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (d_Array[i][j] == EOF)
                    {
                        printf("Wrong file\n");
                        k = 50;
                        break;
                    }
                }
            }

            if (k == 50)
            {
                k = 0;
            }
           /* else
            {
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        printf("%c ", d_Array[i][j]);

                    }
                    printf("\n");
                }
            }*/


            if (d_Array[0][0] == '0')
            {

                find(d_Array, 0, 0, row, col);
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        printf("%c ", d_Array[i][j]);

                    }
                    printf("\n");
                }
            }
            else
            {
                printf("Wrong file\n");

            }






            for (int i = 0; i < row; i++)
            {
                free(d_Array[i]);
            }

            free(d_Array);

        }

        else
        {
            printf("Wrong file\n");
        }

        fclose(fp);
        row = 0;
        col = 0;
        scanf("%s", f1);
        if (f1[0] == '-' && f1[1] == '1')
        {
            return 0;
        }
    }

    return 0;

}