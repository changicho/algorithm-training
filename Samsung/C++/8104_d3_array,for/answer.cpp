#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N, K;
    cin >> N >> K;

    int start = 1;
    int end = N * K;

    vector<int> classes(K);

    for (int i = 1; i <= N; i++) {
        if (i % 2 == 1) {
            for (int j = 1; j <= K; j++) {
                classes[j-1] += j+(i-1)*K;
                cout<< j+(i-1)*K<<" ";
            }
            cout<<endl;
        }else{
            for (int j = 1; j <= K; j++) {
                classes[K-j] += j+(i-1)*K;
                cout<< j+(i-1)*K<<" ";
            }
            cout<<endl;
        }
    }

    cout << "#" << test_case << " ";
    for(int S : classes){
        cout<<S<<" ";
    }
    cout<<endl;
}

int main() {
    int T;

    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        solution(test_case);
    }

    return 0;
}