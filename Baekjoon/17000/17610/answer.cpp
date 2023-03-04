#include <algorithm>
#include <climits>
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

const int MAX = 1e9 + 1;

unordered_set<int> visited;
void recursive(int index, vector<int> &grams, int leftSum, int rightSum) {
  visited.insert(leftSum);
  visited.insert(rightSum);
  visited.insert(abs(leftSum - rightSum));

  if (index == grams.size()) return;

  recursive(index + 1, grams, leftSum, rightSum);
  recursive(index + 1, grams, leftSum + grams[index], rightSum);
  recursive(index + 1, grams, leftSum, rightSum + grams[index]);
}

int solution(vector<int> grams) {
  int size = grams.size();
  int sum = 0;
  for (int &g : grams) {
    sum += g;
  }

  visited.insert(0);
  recursive(0, grams, 0, 0);

  int answer = sum - visited.size() + 1;
  return answer;
}

void init() {}

void clear() {}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  init();

  // freopen("./input.txt", "r", stdin);

  int K;
  cin >> K;

  vector<int> grams(K);
  for (int i = 0; i < K; i++) {
    cin >> grams[i];
  }

  int answer = solution(grams);
  cout << answer;
  cout << "\n";

  return 0;
}
