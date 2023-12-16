#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

struct Book {
  int h, w;
};

int solution(vector<Book> &books, int length) {
  int size = books.size();

  vector<int> dp(books.size(), INT_MAX);

  dp[0] = books[0].h;

  for (int i = 1; i < size; i++) {
    int curMaxH = books[i].h;
    int widthSum = books[i].w;

    for (int before = i - 1; before >= 0; before--) {
      if (widthSum > length) break;
      widthSum += books[before].w;

      dp[i] = min(dp[i], dp[before] + curMaxH);

      curMaxH = max(curMaxH, books[before].h);
    }

    if (widthSum <= length) {
      dp[i] = min(curMaxH, dp[i]);
    }
  }

  return dp.back();
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);

  int N;
  int L;
  cin >> N >> L;

  vector<Book> books(N);
  for (int i = 0; i < N; i++) {
    cin >> books[i].h >> books[i].w;
  }

  int answer = solution(books, L);

  cout << answer << "\n";

  return 0;
}