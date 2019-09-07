#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

long long VALUE[1000000];

long long solution() {
    long long answer = 0;

    int N, target;
    vector<int> array;

    cin >> N;
    array.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    reverse(array.begin(), array.end());

    target = array[0];
    for (int i = 1; i < N; i++) {
        if(array[i]>target){
            target = array[i];
            continue;
        }
        answer += target - array[i];
    }

    return answer;
}

int main() {
    int T;

    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cout<<"#"<<i+1<<" "<<solution()<<endl;
    }

    return 0;
}