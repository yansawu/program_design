#include<stdio.h>

int main(){
    int blood = 10, strength = 2, num, i = 1;
    printf("Welcome, Adventurer!\n");
    while (i){
        printf("You have %d blood and %d strength.\n", blood, strength);                    //顯示血量及攻擊力
        printf("Please choose which monster (1 to 4) you want to fight:");
        scanf("%d",&num);

        if (num<1 || num>4){                                                                //輸入1~4以外的數字會顯示錯誤
            printf("No such monster, please enter 1 to 4 to choose the monster.\n");
            printf("Do you want to go on your adventure (1: Yes; 0: No) ?:");               
            scanf("%d", &i);

            if (i==0){                                                                      //輸入0結束程式
                printf("We will miss you. Bye!\n");
                break;
            }

            else{ 
                continue;
            }
        }
        else{
            printf("You are fighting Monster %d!\n", num);                                  //攻擊
            if (strength>num){                                                              //攻擊力大於怪物，則勝利，且攻擊力+1    
                printf("You Win!\n");
                strength++;
            }
            else{
                printf("You Lose!\n");                                                      //攻擊力小於怪物，則失敗，血量-怪物攻擊力
                blood -= num;
            }
            printf("Do you want to go on your adventure (1: Yes; 0: No) ?:");               //詢問是否繼續遊玩
            scanf("%d", &i);
            if (i==0){                                                                      //輸入0結束程式
                printf("We will miss you. Bye!\n");
                break;}
        if (blood<=0){                                                                      //血量歸零則結束遊戲
            printf("You Dead. Bye!\n");
            break;
        }
        }
        }
        return 0;
}