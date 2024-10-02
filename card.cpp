#include<iostream>
using namespace std;

void createCards(int cards[],int numOfCards){
	for(int i=0;i<numOfCards;i++){
    	cards[i]=i;
	}
}
void shuffleCards(int cards[],int numOfCards){
    for(int i=0;i<numOfCards;i++){
        int pos_1=rand()%52;
        int pos_2=rand()%52;
        int temp = cards[pos_1];
        cards[pos_1]=cards[pos_2];
        cards[pos_2]=temp;
    } 
}
int dealCard(int cards[],int &remainCards){
    int returnCard=cards[remainCards-1];
  	remainCards--;
  	return returnCard;
}
const int NUM_OF_CARDS=52;

void printCard(int x){
  	int cardFace=x/13+1;
  	int cardNum=x%13+1;

  	if(cardFace==1) cout<<"S";
  	else if(cardFace==2) cout<<"H";
  	else if(cardFace==3) cout<<"D";
  	else if(cardFace==4) cout<<"C";

  	if(cardNum==11) cout<<"J"<<" ";
  	else if(cardNum==12) cout<<"Q"<<" ";
  	else if(cardNum==13) cout<<"K"<<" ";
  	else if(cardNum==1) cout<<"A"<<" ";
  	else cout<<cardNum<<" ";
}
int main(){
  	int s;
  	cin>>s;
  	srand(s);
  	int cards[NUM_OF_CARDS];
  	int totalCards=NUM_OF_CARDS;
  	createCards(cards,totalCards);
  	shuffleCards(cards,totalCards);
	
	int player[4][13];
	int a;

    for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			player[i][j]= dealCard(cards,totalCards);
           printCard(player[i][j]);
			cout<<" ";
		}
	    cout<<endl;
	}
    for (int i = 0; i < 4; i++){
        for (int k = 0; k < 12;k++){
            for (int j = 0; j < 12-k; j++){
				if(player[i][j]>player[i][j+1]){
		    	a=player[i][j];
			    player[i][j]=player[i][j+1];
			    player[i][j+1]=a;
                }
			}
		}
    }
    for (int i = 0; i < 4;i++){
        for (int j = 0; j < 13;j++){
            printf("%d ", player[i][j]);
        }
        printf("\n");
    }
}