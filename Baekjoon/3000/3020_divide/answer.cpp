#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, H;
vector<int> odd, even;

int caclul(int height) {
  int count = 0;

  int oddCount =
      odd.size() - (upper_bound(odd.begin(), odd.end(), height) - odd.begin());
  int evenCount =
      (upper_bound(even.begin(), even.end(), height) - even.begin());

  count += oddCount;
  count += evenCount;

  return count;
}

void solution() {
  cin >> N >> H;

  int level;
  for (int i = 0; i < N / 2; i++) {
    cin >> level;
    odd.push_back(level);
    cin >> level;
    even.push_back(H - level);
  }

  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());

  int minHeight = N;
  int minCount = 1;
  for (int height = 0; height < H; height++) {
    int count = caclul(height);

    if (count < minHeight) {
      minHeight = count;
      minCount = 1;
    } else if (count == minHeight) {
      minCount++;
    }
  }

  cout << minHeight << " " << minCount << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("./data/input.txt", "r", stdin);
  solution();

  return 0;
}