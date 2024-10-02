#include<stdio.h>

int main(){
    int row, column;                                                                //basis matrix
    int vrow, vcolumn;                                                              //villige location
    int mrow, mcolumn;                                                              //monster location

    printf("Input the number of row and column for the map:\n");
    scanf("%d %d", &row, &column);
    char map[row][column];

    for (int i = 0; i < row;i++){                                                   //make all '.' matrix
        for (int j = 0; j < column;j++){
            map[i][j] = '.';
        }
    }

    for (int i = 0; i < 1;i++){                                                     //locate the village
        printf("Input the row and column for the village location:\n");
        scanf("%d %d", &vrow, &vcolumn);
        if(vrow>=row||vrow<0||vcolumn>=column||vcolumn<0){
            printf("the location is outside the map\n");
            i--;
        }
    }
    map[vrow][vcolumn] = 'v';

    printf("You need to assign location for %d monsters in total\n", (row / 10) + (row % 10));

    for (int i = 0; i < (row / 10) + (row % 10);i++){                               //locate the monster
        printf("Input the row and column for monster %d:\n", i);
        scanf("%d %d", &mrow, &mcolumn);

        if(mrow>=row||mrow<0||mcolumn>=column||mcolumn<0){
            printf("the location is outside the map\n");
            i--;
            continue;
        }

        if(map[mrow][mcolumn]!='.'){
            printf("the location is occupied\n");
            i--;
            continue;
        }
        
        map[mrow][mcolumn] = 'm';
    }
    printf("=== MAP ===\n");                                                        //print out the map
    for (int i = 0; i < row;i++){
        for (int j = 0; j < column;j++){
            printf("%c ", map[i][j]);
            if (column-1==j){
                printf("\n");
            }
        }
    }
    printf("=== MAP ===\n");
}