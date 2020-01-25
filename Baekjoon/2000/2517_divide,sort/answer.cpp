#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct runner {
  int power, rank;
};

vector<runner> arr;
vector<runner> temp;
vector<int> counts;

void merge(int start, int mid, int end) {
  int p1 = start;
  int p2 = mid + 1;

  int k = start;
  int p1_count = 0;

  while (p1 <= mid && p2 <= end) {
    if (arr[p1].power <= arr[p2].power) {
      // 앞에 있는 것이 앞으로 오는 경우
      temp[k] = arr[p1];
      p1 += 1;
      p1_count += 1;
    } else {
      // 뒤에 있는 것이 앞으로 오는 경우
      temp[k] = arr[p2];

      counts[temp[k].rank] += p1_count;

      p2 += 1;
    }
    k += 1;
  }

  while (p1 <= mid) {
    temp[k] = arr[p1];
    k += 1;
    p1 += 1;
  }

  while (p2 <= end) {
    temp[k] = arr[p2];

    counts[temp[k].rank] += p1_count;

    k += 1;
    p2 += 1;
  }

  for (int i = start; i <= end; i++) {
    arr[i] = temp[i];
  }
}

void merge_sort(int start, int end) {
  int mid = (start + end) / 2;

  if (start < end) {
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, mid, end);
  }
}

void solution() {
  int N;
  cin >> N;

  arr.resize(N);
  temp.resize(N);
  counts.resize(N, 0);

  vector<int> origin;

  for (int i = 0; i < N; i++) {
    cin >> arr[i].power;
    arr[i].rank = i;

    origin.push_back(arr[i].power);
  }

  merge_sort(0, N - 1);

  for (int i = 0; i < N; i++) {
    cout << i + 1 - counts[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}