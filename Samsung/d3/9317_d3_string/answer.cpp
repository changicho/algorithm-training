#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  string ans, in;
  int count;

  cin >> count;
  cin >> ans >> in;

  for (int i = 0; i < ans.length(); i++) {
    if (ans[i] != in[i]) {
      count -= 1;
    }
  }

  cout << "#" << test_case << " " << count << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}