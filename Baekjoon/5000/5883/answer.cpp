#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count(vector<int> &arr, int skip) {
  int ret = 0;
  int count = 0;
  int before = -1;
  for (int &num : arr) {
    if (num == skip) continue;

    if (num == before) {
      count++;
    } else {
      before = num;
      count = 1;
    }
    ret = max(ret, count);
  }
  ret = max(ret, count);

  return ret;
}

int solution(vector<int> &arr) {
  int size = arr.size();
  int answer = 0;

  for (int &num : arr) {
    answer = max(answer, count(arr, num));
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int answer = solution(A);
  cout << answer << "\n";

  return 0;
}