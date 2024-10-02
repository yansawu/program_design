#include<stdio.h>
#include<stdbool.h>

void push(int *pointer,int *current_number_pointer);
void pop(int *pointer,int *current_number_pointer);
void display(int str[],int current_number);

int main(){
    bool flag = true;           //determine the time to end
    int size, choose;
    int current_number = 0;     //determine the current location in array
    int *current_number_addr = &current_number;     
    printf("Enter the size of the stack : ");       
    scanf("%d", &size);
    int stack[size];
    int *stack_addr = &stack[current_number];
    while(flag){
        printf("1.Push 2.Pop 3.Display 4.Exit:");
        scanf("%d", &choose);
        switch(choose){                             
            case(1)://push
                if(current_number>size-1){
                    printf("Stack overflow\n");
                    break;
                }
                push(stack_addr, current_number_addr);
                display(stack,current_number);
                break;
            case(2)://pop
                if(current_number==0){
                    printf("Stack underflow\n");
                    break;
                }
                pop(stack_addr, current_number_addr);
                display(stack,current_number);
                break;
            case(3)://display
                display(stack,current_number);
                break;
            case(4)://exit
                flag = false;
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
}

//add a new element in the stack
void push(int *pointer,int *current_number_pointer){    //pointer will be stack
    int input;
    printf("Enter the item to be pushed :");
    scanf("%d", &input);
    pointer[*current_number_pointer] = input;
    *current_number_pointer+=1;
}

//pop the lastest element in the stack
void pop(int *pointer,int *current_number_pointer){     //pointer will be stack
    printf("Element %d has been popped from the stack\n", pointer[*current_number_pointer-1]);
    *current_number_pointer -= 1;
}

//show the elements in the stack
void display(int str[],int current_number){
    if(current_number==0){
        printf("Stack is empty\n");
    }
    else{
        for (int i = current_number-1; i >= 0;i--){
            printf("-> %d\n", str[i]);
        }
    }
}