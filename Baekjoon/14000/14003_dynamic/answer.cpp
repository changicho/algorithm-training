#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct table {
  int index, value;
};

int arr[1000001];
int lis[1000001];
table ans[1000001];

void solution() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) cin >> arr[i];

  int idxLis = 0, idxArr = 1;

  lis[idxLis] = arr[0];
  ans[0].index = 0;
  ans[0].value = arr[0];

  while (idxArr < N) {
    if (lis[idxLis] < arr[idxArr]) {
      idxLis++;
      lis[idxLis] = arr[idxArr];

      ans[idxArr].index = idxLis;
      ans[idxArr].value = arr[idxArr];
    }

    else {
      int pos = lower_bound(lis, lis + idxLis, arr[idxArr]) - lis + 1;

      lis[pos - 1] = arr[idxArr];
      ans[idxArr].index = pos - 1;
      ans[idxArr].value = arr[idxArr];
    }

    idxArr++;
  }

  cout << idxLis + 1 << "\n";

  stack<int> s;
  for (int i = N - 1; i >= 0; i--) {
    if (ans[i].index == idxLis) {
      idxLis--;

      s.push(ans[i].value);
    }
  }

  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}