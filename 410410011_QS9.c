#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void print_board();
void input_x();
void input_o();
int random_select();
int determine_winner();
int board[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int main(){
    while(1){
    print_board();
    input_x();
    if(determine_winner()){
        break;
    }
    input_o();
    if(determine_winner()){
        break;
    }
    }
}

int input;
void input_x(){
    while(1){
        printf("player 1 ->");
        scanf("%d", &input);
        if (board[input-1]!=10 && board[input-1]!=11){          //10 means X, 11 means O
            break;
        }
        printf("Choose again!\n");
    }
    board[input - 1] = 10;
}

void input_o(){
    int random = random_select();
    printf("player 2 ->%d\n",random);
    board[random - 1] = 11;
}

int num = 0;
void print_board(){
    printf("Player-1==>X \nPlayer-2==>O\n");
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3;j++){
            if (board[num]==10){
                printf("X   ");
                num++;
            }
            else if(board[num]==11){
                printf("O   ");
                num++;
            }
            else{
                printf("%d   ", board[num]);
                num++;
            }
        }
        printf("\n__  __  __\n");

    }
    num = 0;
}

//random select a number from 1 to 9
int random_select(){
    int random;
    while(1){
    srand(time(NULL));
    random = rand() % 9+1;                              
    if (board[random-1]!=10 && board[random-1]!=11){
        break;
    }
    }
    return random;
}

int determine_winner(){
    if (board[0]==board[1]&&board[1]==board[2]){
        if(board[0]==10){
            print_board();
            printf("player-1 wins");
        }
        else{
            print_board();
            printf("player-2 wins");
        }
        return 1;
    }
    else if (board[3]==board[4]&&board[4]==board[5]){
        if(board[3]==10){
            print_board();
            printf("player-1 wins");
        }
        else{
            printf("player-2 wins");
            print_board();
        }
        return 1;
    }
    else if (board[6]==board[7]&&board[7]==board[8]){
        if(board[6]==10){
            print_board();
            printf("player-1 wins");
        }
        else{
            print_board();
            printf("player-2 wins");
        }
        return 1;
    }
    else if (board[0]==board[3]&&board[3]==board[6]){
        if(board[0]==10){
            print_board();
            printf("player-1 wins");
        }
        else{
            print_board();
            printf("player-2 wins");
        }
        return 1;
    }
    else if (board[1]==board[4]&&board[4]==board[7]){
        if(board[1]==10){
            print_board();
            printf("player-1 wins");
        }
        else{
            print_board();
            printf("player-2 wins");
        }
        return 1;
    }
    else if (board[2]==board[5]&&board[5]==board[8]){
        if(board[2]==10){
            print_board();
            printf("player-1 wins");
        }
        else{
            print_board();
            printf("player-2 wins");
        }
        return 1;
    }
    else if (board[0]==board[4]&&board[4]==board[8]){
        if(board[0]==10){
            print_board();
            printf("player-1 wins");
        }
        else{
            print_board();
            printf("player-2 wins");
        }
        return 1;
    }
    else if (board[2]==board[4]&&board[4]==board[6]){
        if(board[2]==10){
            print_board();
            printf("player-1 wins");
        }
        else{
            print_board();
            printf("player-2 wins");
        }
        return 1;
    }
    else if (board[0]!=1 && board[1]!=2 && board[2]!=3 && board[3]!=4 && board[4]!=5 && board[5]!=6 && board[6]!=7 && board[7]!=8 && board[8]!=9){
        print_board();
        printf("Tie");
        return 1;
    }
    else
        return 0;
}
