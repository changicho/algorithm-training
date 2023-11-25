#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<int> &heights) {
  // 100,000
  int size = heights.size();

  vector<bool> underwater(size, false);

  map<int, vector<int>> orderedX;

  for (int x = 0; x < size; x++) {
    orderedX[heights[x]].push_back(x);
  }

  int numIslands = 1;
  int maxIslands = 1;

  for (auto &[h, xs] : orderedX) {
    for (int &x : xs) {
      underwater[x] = true;
      bool landToLeft = (x > 0 && !underwater[x - 1]);
      bool landToRight = (x < size - 1 && !underwater[x + 1]);

      if (landToLeft && landToRight) {
        numIslands++;
      } else if (!landToLeft && !landToRight) {
        numIslands--;
      }
    }
    maxIslands = max(maxIslands, numIslands);
  }

  return maxIslands;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }

  int answer = solution(H);
  cout << answer << "\n";

  return 0;
}