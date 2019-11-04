#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(long long a, long long b) { return a > b; }

int toDec(int hexa) {
  if (hexa - '0' < 10) {
    return hexa - '0';
  }
  return hexa - 'A' + 10;
}

long long hexToDec(string hex) {
  long long answer = 0;
  long long pow = 1;

  reverse(hex.begin(), hex.end());

  for (int i = 0; i < hex.length(); i++) {
    long long dec = toDec(hex[i]);
    answer += dec * pow;
    pow *= 16;
  }
  return answer;
}

void solution(int test_case) {
  int N, K;
  string numbers_str;
  vector<long long> max;

  cin >> N >> K;
  cin >> numbers_str;

  // 회전은 N/4번
  for (int rotation = 0; rotation < N / 4; rotation++) {
    int size = N / 4;

    int count = 0;
    string hex = "";

    for (int i = 0; i < N; i++) {
      hex += numbers_str[i];
      count++;
      if (count == size) {
        max.push_back(hexToDec(hex));
        hex = "";
        count = 0;
      }
    }

    // 시계방향으로 회전
    string new_numbers_str = "";
    new_numbers_str += numbers_str[numbers_str.length() - 1];
    for (int i = 0; i < numbers_str.length() - 1; i++) {
      new_numbers_str += numbers_str[i];
    }
    numbers_str = new_numbers_str;
  }

  sort(max.begin(), max.end());
  max.erase(unique(max.begin(), max.end()), max.end());
  sort(max.begin(), max.end(), compare);

  cout << "#" << test_case << " " << max[K - 1] << "\n";
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