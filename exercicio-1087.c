#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    unsigned short startRow, startCol, endRow, endCol;

    while (true)
    {
        scanf("%hd %hd %hd %hd", &startRow, &startCol, &endRow, &endCol);

        if (startRow == 0 && startCol == 0 && endRow == 0 && endCol == 0)
            break;

        if (startRow == endRow && startCol == endCol)
            printf("0\n");
        else if (abs(endRow - startRow) == abs(endCol - startCol))
            printf("1\n");
        else if (startRow == endRow || startCol == endCol)
            printf("1\n");
        else
            printf("2\n");
    }
}
