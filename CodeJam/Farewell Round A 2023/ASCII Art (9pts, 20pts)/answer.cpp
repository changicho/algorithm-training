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

vector<long long> boundaryEnds;
vector<long long> loops;

char solution(long long num) {
  int idx = lower_bound(boundaryEnds.begin(), boundaryEnds.end(), num) -
            boundaryEnds.begin();

  long long boundaryEnd = boundaryEnds[idx - 1];
  long long loop = loops[idx - 1];

  long long target = num - boundaryEnd;

  int move = ceil((double)target / loop);
  return (move - 1) + 'A';
}

void init() {
  long long boundaryEnd = 0;
  long long loop = 1;

  boundaryEnds.push_back(boundaryEnd);
  loops.push_back(loop);

  while (boundaryEnd <= 1e12) {
    loop++;
    boundaryEnd += (loop - 1) * 26;

    boundaryEnds.push_back(boundaryEnd);
    loops.push_back(loop);
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  init();

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    long long N;
    cin >> N;

    char answer = solution(N);

    cout << "Case #" << testCase << ": " << answer << endl;
  }

  return 0;
}