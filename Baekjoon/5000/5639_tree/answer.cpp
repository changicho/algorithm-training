#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> nums;

void divide(int start, int end) {
  if (start > end) return;

  int root = start;
  int cur_start = start;
  int cur_end = end;

  while (cur_start < nums.size() && nums[cur_start] >= nums[root]) {
    cur_start += 1;
  }
  while (cur_end >= 0 && nums[cur_end] > nums[root]) {
    cur_end -= 1;
  }

  divide(cur_start, cur_end);
  divide(cur_end + 1, end);

  cout << nums[root] << "\n";
}

void solution() {
  string line;

  while (cin >> line) {
    // in window, EOF is ctrl + z
    if (line[0] == EOF) break;

    nums.push_back(stoi(line));
  }

  divide(0, nums.size() - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}