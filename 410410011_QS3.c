#include<stdio.h>

int main(){
    int a, b, c;
    scanf("(%d, %d)", &a, &b);
        c = a * a + b * b;
        if (a==0&&b!=0)
            printf("(%d,%d) is on the y-axis.\n The value of squared distance is %d", a, b, c);
        if (b==0&&a!=0)
            printf("(%d,%d) is on the x-axis.\n The value of squared distance is %d", a, b, c);
        if (a>0 && b>0)
            printf("(%d,%d)is in Quadrant I.\nThe value of squared distance is %d", a, b, c);
        if (a<0 && b>0)
            printf("(%d,%d)is in Quadrant II.\nThe value of squared distance is %d", a, b, c);
        if (a<0 && b<0)
            printf("(%d,%d)is in Quadrant III.\nThe value of squared distance is %d", a, b, c);
        if (a>0 && b<0)
            printf("(%d,%d)is in Quadrant IV.\nThe value of squared distance is %d", a, b, c);
        if (a==0&&b==0)
            printf("(%d,%d)is in origin.\nThe value of squared distance is 0", a, b);
    }