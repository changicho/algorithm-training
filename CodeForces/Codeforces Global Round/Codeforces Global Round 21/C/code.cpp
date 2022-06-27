#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Data {
  long long num, count;

  bool operator==(const Data& b) const {
    return num == b.num && count == b.count;
  }
};

Data divide(int num, int& m) {
  Data ret = {num, 1};

  while (ret.num > 0 && ret.num % m == 0) {
    ret.num /= m;
    ret.count *= m;
  }

  return ret;
}

void fillStack(int m, vector<int>& a, stack<Data>& stk) {
  for (int& num : a) {
    Data cur = {0, 0};

    if (num % m == 0) {
      cur = divide(num, m);
    } else {
      cur.num = num;
      cur.count = 1;
    }

    while (!stk.empty() && stk.top().num == cur.num) {
      cur.count += stk.top().count;
      stk.pop();
    }

    stk.push(cur);
  }
}

bool solution(int m, vector<int>& a, vector<int>& b) {
  int n = a.size(), k = b.size();

  stack<Data> stk;
  fillStack(m, a, stk);
  vector<Data> tempA, tempB;
  while (!stk.empty()) {
    tempA.push_back(stk.top());
    stk.pop();
  }

  fillStack(m, b, stk);
  while (!stk.empty()) {
    tempB.push_back(stk.top());
    stk.pop();
  }

  return tempA == tempB;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int n, m, k;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; i++) {
      cin >> b[i];
    }

    bool ret = solution(m, a, b);

    if (ret) {
      cout << "Yes";
    } else {
      cout << "No";
    }

    cout << "\n";
  }

  return 0;
}