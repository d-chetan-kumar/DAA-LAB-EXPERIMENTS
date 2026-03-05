#include <stdio.h>

int factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return n * factorial(n - 1);
    }
}

int main(){
    int n;

    printf("enter a value for n:");
    scanf("%d", &n);

    printf("the factorial of %d is %d", n, factorial(n));
    printf("\n");

    return 0;
}