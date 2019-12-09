#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  string s, n = "";
  int N, start = 0, end;

  cin >> N;

  for (int i = 0; i < N; i++) {
    char c;
    cin >> c;
    s += c;
  }

  end = s.length() - 1;

  while (start < end) {
    int temp_start = start, temp_end = end;
    bool flag = true;

    while (temp_start < temp_end) {
      if (s[temp_start] > s[temp_end]) {
        flag = true;
        break;
      } else if (s[temp_start] < s[temp_end]) {
        flag = false;
        break;
      }
      temp_start++;
      temp_end--;
    }

    if (flag) {
      n += s[end--];
    } else {
      n += s[start++];
    }
  }
  n += s[start];

  cout << "#" << test_case << " " << n << "\n";
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