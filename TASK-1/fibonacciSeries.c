#include <stdio.h>

int fibonacci(int n){
    int x = 0;
    int y = 1;
    int next;

    for(int i = 1; i <= n; i++){
        printf("%d ", x);
        next = x + y;
        x = y;
        y = next;
    }

    return 0;
}

int main(){
    int n;

    printf("enter a value for n:");
    scanf("%d", &n);

    printf("the fibonacci series is : ");
    fibonacci(n);

    printf("\n");

    return 0;
}