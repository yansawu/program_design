#include<stdio.h>

int row, column;//basis matrix                                                               
int vrow, vcolumn;//village location                                                              
int mrow, mcolumn;//monster location
int prow, pcolumn;//player location
char map[10000][10000];


void create_map();
void print_map();
void setup_village();
void setup_monster();
int check_boundary();
int check_availability();
void setup_player();
void go_up();
void go_down();
void go_right();
void go_left();
void create_a_whole_map();
int check_move();

int main(){
    int move = 0;
    create_a_whole_map();
    setup_player();
    while(move!=5){
        print_map();
        printf("[1] go up [2] go down [3] go right [4] go left [5] exit: ");
        scanf("%d", &move);
        switch(move){
            case 1:
                go_up();
                break;
            case 2:
                go_down();
                break;
            case 3:
                go_right();
                break;
            case 4:
                go_left();
                break;
            case 5:
                break;
            default:
                break;
        }
    }
    return 0;
}

//include the monster's and village's location
void create_a_whole_map(){
    create_map();
    setup_village();
    setup_monster();
    print_map();
    int choose=0;
    printf("[1] Create a new map [2] Start travel the map:");
    scanf("%d", &choose);
    if (choose==1)
        create_a_whole_map(); //create a new map
}

//make an all '.' matrix
void create_map(){
    printf("Input the number of row and column for the map:\n");
    scanf("%d %d", &row, &column);
    
    for (int i = 0; i < row;i++){                               
        for (int j = 0; j < column;j++){
            map[i][j] = '.';
        }
    }
}

//print the map
void print_map(){
    printf("=== MAP ===\n");                                                        
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

//locate the village
int j = 0;
void setup_village(){
    for (j = 0; j < 1;j++){                                                     
        printf("Input the row and column for the village location:\n");
        scanf("%d%d", &vrow, &vcolumn);
        if(check_boundary(vrow,vcolumn)){
            j--;
        }
    }
    map[vrow][vcolumn] = 'v';
}

//locate the monster
int i = 0;
void setup_monster(){
    printf("You need to assign location for %d monsters in total\n", (row / 10) + (row % 10));

    for ( i = 0; i < (row / 10) + (row % 10);i++){                               
        printf("Input the row and column for monster %d:\n", i);
        scanf("%d %d", &mrow, &mcolumn);

        if(check_boundary(mrow,mcolumn)){
            i--;
        }

        else if(check_availability(mrow,mcolumn)){
            i--;
        }
        
        else{
            map[mrow][mcolumn] = 'm';
        }
    }
}

int check_boundary(int row2,int column2){
    if(row2>=row || row2<0 || column2>=column || column2<0){
        printf("the location is outside the map\n");
        return 1;
    }
    else
        return 0;
}

int check_availability(int row3,int column3){
    if(map[row3][column3]!='.'){
        printf("the location is occupied\n");
        return 1;
    }
    else
        return 0;
}

void setup_player(){
    printf("Input the row and column for player:\n");
    scanf("%d%d", &prow, &pcolumn);
    if(check_boundary(prow,pcolumn)){
        setup_player();
    }
    else if(check_availability(prow,pcolumn)){
        setup_player();
    }
        
    else{
        map[prow][pcolumn] = 'p';
    }
}

int check_move(int row1,int column1){
    if(row1>=row || row1<0 || column1>=column || column1<0 || map[row1][column1]!='.'){
        printf("you can't go there\n");
        return 0;
    }
    else
        return 1;
}

void go_up(){
    if(check_move(prow - 1, pcolumn)){
        map[prow][pcolumn] = '.';
        map[prow - 1][pcolumn] = 'p';
        prow -= 1;
    }
}

void go_down(){
    if(check_move(prow + 1, pcolumn)){
        map[prow][pcolumn] = '.';
        map[prow + 1][pcolumn] = 'p';
        prow += 1;
    }
}

void go_right(){
    if(check_move(prow , pcolumn+1)){
        map[prow][pcolumn] = '.';
        map[prow][pcolumn+1] = 'p';
        pcolumn += 1;
    }
}

void go_left(){
    if(check_move(prow , pcolumn-1)){
        map[prow][pcolumn] = '.';
        map[prow ][pcolumn-1] = 'p';
        pcolumn -= 1;
    }
}