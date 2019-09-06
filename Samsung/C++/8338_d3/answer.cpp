#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solution() {
    long long int answer = 0, number_add, number_multiple;
    int N, input_number;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &input_number);
        
        number_add = answer + input_number;
        number_multiple = answer*input_number;

        if(number_add > number_multiple){
            answer = number_add;
        }else{
            answer = number_multiple;
        }
    }
    printf("%lld", answer);
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        printf("#%d ",i+1);
        solution();
        printf("\n");
    }

    return 0;
}