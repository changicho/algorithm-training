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

string solution(int num) {
  string ret = string(num, 'o');

  for (int i = 2; i < num; i += 3) {
    ret[i] = 'x';
  }
  // do something
  return ret;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  string answer = solution(N);

  cout << answer << endl;

  return 0;
}