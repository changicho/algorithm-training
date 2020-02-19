#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  // make a is bigger than b
  if (b > a) {
    swap(a, b);
  }

  while (b != 0) {
    int temp = a % b;
    a = b;
    b = temp;
  }

  // return abs
  if (a < 0) {
    return -a;
  }
  return a;
}

void solution() {
  int N, temp;
  int max_index = -1, max_value = -1;
  cin >> N;

  vector<int> nums(N);

  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  vector<int> gcdFoward, gcdBackward;

  gcdFoward.push_back(nums.front());
  gcdBackward.push_back(nums.back());

  for (int i = 1; i < N; i++) {
    gcdFoward.push_back(gcd(gcdFoward[i - 1], nums[i]));
    gcdBackward.push_back(gcd(gcdBackward[i - 1], nums[N - i - 1]));
  }

  reverse(gcdBackward.begin(), gcdBackward.end());

  for (int i = 0; i < N; i++) {
    int current_gcd;
    if (i - 1 < 0) {
      current_gcd = gcdBackward[i + 1];
    } else if (i + 1 >= N) {
      current_gcd = gcdFoward[i - 1];
    } else {
      current_gcd = gcd(gcdFoward[i - 1], gcdBackward[i + 1]);
    }

    if (gcd(nums[i], current_gcd) == current_gcd) continue;

    if (max_value < current_gcd) {
      max_value = max(max_value, current_gcd);
      max_index = i;
    }
  }

  if (max_index == -1) {
    cout << "-1\n";
    return;
  }
  cout << max_value << " " << nums[max_index] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}