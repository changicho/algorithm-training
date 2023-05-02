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

struct Range {
  int start, end;
};

long long solution(vector<long> &pancakes, Range &alice, Range &bob) {
  int size = pancakes.size();
  long long answer = 0;

  vector<long long> prefixes(size, 0), suffixes(size, 0);
  prefixes[0] = pancakes[0];
  suffixes[size - 1] = pancakes[size - 1];

  for (int i = 1; i < size; i++) {
    prefixes[i] = prefixes[i - 1] + pancakes[i];
    suffixes[size - 1 - i] = suffixes[size - i] + pancakes[size - 1 - i];
  }
  long long allSum = prefixes[size - 1];

  for (int choose = alice.start; choose <= alice.end; choose++) {
    long long bobMaximum = 0;

    // left block case
    int leftBlock = choose - 1;
    if (leftBlock >= 0) {
      if (bob.start <= leftBlock && leftBlock <= bob.end) {
        // bob block (choose - 1)
        long long bobSum = prefixes[choose - 1];
        long long aliceSum = suffixes[choose];

        bobMaximum = max(bobMaximum, bobSum);
      } else if (bob.end < leftBlock) {
        // bob block his most right
        int diff = leftBlock - bob.end;

        int bobRight = bob.end + (diff) / 2;
        int aliceLeft = choose - (diff) / 2;
        if (bobRight == aliceLeft) bobRight--;

        long long bobSum = prefixes[bobRight];
        long long aliceSum = suffixes[aliceLeft];

        bobMaximum = max(bobMaximum, bobSum);
      }
    }

    int rightBlock = choose + 1;
    if (rightBlock < size) {
      if (bob.start <= rightBlock && rightBlock <= bob.end) {
        // bob block (choose + 1)
        long long bobSum = suffixes[choose + 1];
        long long aliceSum = prefixes[choose];

        bobMaximum = max(bobMaximum, bobSum);
      } else if (rightBlock < bob.start) {
        // bob block his most left
        int diff = bob.start - rightBlock;

        int bobLeft = bob.start - (diff) / 2;
        int aliceRight = choose + (diff) / 2;
        if (bobLeft == aliceRight) bobLeft++;

        long long bobSum = suffixes[bobLeft];
        long long aliceSum = prefixes[aliceRight];

        bobMaximum = max(bobMaximum, bobSum);
      }
    }

    answer = max(answer, allSum - bobMaximum);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<long> pancakes(N);
    for (int i = 0; i < N; i++) {
      cin >> pancakes[i];
    }

    Range alice, bob;
    cin >> alice.start >> alice.end >> bob.start >> bob.end;
    alice.start--, alice.end--, bob.start--, bob.end--;

    auto answer = solution(pancakes, alice, bob);

    cout << "Case #" << testCase << ": ";

    // cout << (answer ? "YES" : "NO") << endl;
    cout << answer << endl;
    // for (int num : answer) {
    //   cout << num << " ";
    // }
    // cout << endl;
  }

  return 0;
}