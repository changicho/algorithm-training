#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  long long T;
  int N, M;
  int arr_A[1000], arr_B[1000];

  long long count = 0;

  vector<long long> sum_A, sum_B;

  cin >> T;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr_A[i];
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> arr_B[i];
  }

  for (int i = 0; i < N; i++) {
    long long sum = 0;
    for (int j = i; j < N; j++) {
      sum += arr_A[j];
      sum_A.push_back(sum);
    }
  }

  for (int i = 0; i < M; i++) {
    long long sum = 0;
    for (int j = i; j < M; j++) {
      sum += arr_B[j];
      sum_B.push_back(sum);
    }
  }

  sort(sum_A.begin(), sum_A.end());
  sort(sum_B.begin(), sum_B.end());

  for (long long a : sum_A) {
    int low = lower_bound(sum_B.begin(), sum_B.end(), T - a) - sum_B.begin();
    int high = upper_bound(sum_B.begin(), sum_B.end(), T - a) - sum_B.begin();

    count += high - low;
  }

  cout << count << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}