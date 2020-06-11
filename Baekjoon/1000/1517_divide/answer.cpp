#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
long long answer = 0;
vector<int> arr;
vector<int> temp;

void merge(int start, int end) {
  int mid = (end + start) / 2;
  int idx = start;
  int left = start;
  int right = mid + 1;

  while (left <= mid && right <= end) {
    if (arr[left] <= arr[right]) {  // 앞에있는 덩어리에서 채움
      temp[idx++] = arr[left++];
    } else {  // 뒤에있는 덩어리에서 채움
      temp[idx++] = arr[right++];

      answer += (mid - left + 1);
    }
  }

  while (left <= mid) {
    temp[idx++] = arr[left++];
  }
  while (right <= end) {
    temp[idx++] = arr[right++];
  }

  for (int i = start; i <= end; i++) {
    arr[i] = temp[i];
  }
}

void mergeSort(int start, int end) {
  int mid = (start + end) / 2;

  if (start >= end) return;

  mergeSort(start, mid);
  mergeSort(mid + 1, end);
  merge(start, end);
}

void solution() {
  cin >> N;

  arr.resize(N);
  temp.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  mergeSort(0, N - 1);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}