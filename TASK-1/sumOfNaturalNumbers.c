#include <stdio.h>

int sum_of_first_n_natural_numbers(int n){
    int sum = 0;

    for(int i = 1; i <= n; i++){
        sum = sum + i;
    }

    return sum;
}

int main(){
    int n;

    printf("enter a value for n :");
    scanf("%d", &n);

    printf("The sum of first %d natural numbers %d ", n, sum_of_first_n_natural_numbers(n));
    printf("\n");

    return 0;
}