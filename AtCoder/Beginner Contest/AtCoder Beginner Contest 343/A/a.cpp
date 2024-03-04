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
  int sum = a + b;

  for (int i = 0; i <= 9; i++) {
    if (i != sum) return i;
  }

  return -1;
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