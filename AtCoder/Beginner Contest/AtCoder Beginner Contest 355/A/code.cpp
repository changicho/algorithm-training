#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(int a, int b) {
  if (a == b) return -1;

  unordered_set<int> us;
  us.insert(1);
  us.insert(2);
  us.insert(3);

  us.erase(a);
  us.erase(b);

  return *us.begin();
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int A, B;
  cin >> A >> B;

  int answer = solution(A, B);

  cout << answer << endl;

  return 0;
}