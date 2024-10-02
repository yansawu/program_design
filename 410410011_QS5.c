#include<stdio.h>

int main(){
    int blood = 10, strength = 2, num, start = 1, village = 1, item=1, sword=0;               
    printf("Welcome, Adventurer!\n");

    while (start){                                                                      //start為1執行,為0跳出
            printf("Do you want to go to our village first (1: Yes; 0: No)? ");
            scanf("%d", &village);

            if (village){                                                               //village為1進入村莊
                while(1){
                    printf("What do you want to do in our village (1:buy a magical sword; 2: go to the bar; 3:leave the village)?");
                    scanf("%d", &item);
                    switch (item){                                                      //item=1買劍, 攻擊力+1
                        case 1:                                                             //item=2買藥, 血量+1
                            if (sword == 0){                                                //item=3出村莊
                                strength++;
                                printf("Nice sword! Now you have %d strength!\n", strength);
                                sword++;                                                    //sword!=0就不能買劍
                                break;
                            }
                            
                            else{
                                printf("You already brought a sword.\n");
                                break;
                            }

                        case 2 :
                            if (blood<10){
                                blood++;
                                printf("Nice beer! Now you have %d blood!\n", blood);
                                break;
                            }

                            else{
                                printf("Your blood is full. You don't need a beer.\n");
                                break;
                            }
                        case 3 :
                            printf("You are welcome to come back anytime!\n");
                            sword = 0;                                                       //把sword歸零,下一次就可以再買
                            break;

                        default :
                            printf("Invalid action! 1: buy a magical sword; 2: go to the bar; 3: leave the village");
                            break;
                    }
                    if(item==3)
                        break;
                }
            }
        printf("You have %d blood and %d strength.\n", blood, strength);                    //顯示血量及攻擊力
        printf("Please choose which monster (1 to 4) you want to fight:");
        scanf("%d",&num);

        if (num<1 || num>4){                                                                //輸入1~4以外的數字會顯示錯誤
            printf("No such monster, please enter 1 to 4 to choose the monster.\n");
            printf("Do you want to go on your adventure (1: Yes; 0: No) ?:");               
            scanf("%d", &start);

            if (start==0){                                                                      //輸入0結束程式
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
            scanf("%d", &start);
            if (start==0){                                                                      //輸入0結束程式
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