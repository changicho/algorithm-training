#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use Manber Myers algorithm by STL sort
// time : O(N * log_2^2(N))
// space : O(N)
vector<int> getSuffixArray(string &s) {
  int size = s.size();
  vector<int> suffixArray(size), rank(2 * size);

  for (int i = 0; i < size; ++i) {
    suffixArray[i] = i, rank[i] = s[i];
  }

  for (int d = 1; d < size; d *= 2) {
    auto compare = [&](const int &a, const int &b) {
      return rank[a] < rank[b] ||
             (rank[a] == rank[b] && rank[a + d] < rank[b + d]);
    };
    sort(suffixArray.begin(), suffixArray.end(), compare);

    vector<int> newRank(2 * size, 0);
    newRank[suffixArray[0]] = 1;
    for (int i = 1; i < size; i++) {
      newRank[suffixArray[i]] = newRank[suffixArray[i - 1]];

      if (compare(suffixArray[i - 1], suffixArray[i])) {
        newRank[suffixArray[i]]++;
      }
    }
    rank = newRank;
  }
  return suffixArray;
}

// use Manber Myers algorithm by counting sort
// time : O(N * log_2(N))
// space : O(N)
vector<int> getSuffixArrayByCount(string &s) {
  int size = s.size();
  int maximum = max(256, size) + 1;

  vector<int> suffixArray(size), rank(2 * size);
  vector<int> count(maximum), idx(size);
  // initialize
  for (int i = 0; i < size; ++i) {
    suffixArray[i] = i, rank[i] = s[i];
  }
  for (int d = 1; d < size; d *= 2) {
    vector<int> newRank(2 * size);
    auto compare = [&](const int &a, const int &b) {
      return rank[a] < rank[b] ||
             (rank[a] == rank[b] && rank[a + d] < rank[b + d]);
    };

    for (int i = 0; i < maximum; ++i) count[i] = 0;
    for (int i = 0; i < size; ++i) count[rank[i + d]]++;
    for (int i = 1; i < maximum; ++i) count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; --i) idx[--count[rank[i + d]]] = i;

    for (int i = 0; i < maximum; ++i) count[i] = 0;
    for (int i = 0; i < size; ++i) count[rank[i]]++;
    for (int i = 1; i < maximum; ++i) count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; --i)
      suffixArray[--count[rank[idx[i]]]] = idx[i];

    newRank[suffixArray[0]] = 1;
    for (int i = 1; i < size; i++) {
      newRank[suffixArray[i]] = newRank[suffixArray[i - 1]];

      if (compare(suffixArray[i - 1], suffixArray[i])) {
        newRank[suffixArray[i]]++;
      }
    }
    rank = newRank;

    // reduce running time
    if (rank[suffixArray[size - 1]] == size) break;
  }
  return suffixArray;
}

// use Kasai algorithm
// time : O(N)
// space : O(N)
vector<int> getLCP(string &s, vector<int> &suffixArray) {
  int size = s.size();
  vector<int> LCPArray(size), idxOfSuffixArray(size);
  for (int i = 0; i < size; i++) {
    idxOfSuffixArray[suffixArray[i]] = i;
  }
  for (int k = 0, i = 0; i < size; ++i) {
    if (idxOfSuffixArray[i] > 0) {
      int j = suffixArray[idxOfSuffixArray[i] - 1];
      while (s[i + k] == s[j + k]) {
        k++;
      }

      LCPArray[idxOfSuffixArray[i]] = (k ? k-- : 0);
    }
  }
  LCPArray[0] = -1;

  return LCPArray;
}

void solution(string &line) {
  vector<int> suffixArray = getSuffixArrayByCount(line);
  vector<int> lcp = getLCP(line, suffixArray);

  for (int &index : suffixArray) {
    cout << index + 1 << " ";
  }
  cout << "\n";

  for (int &index : lcp) {
    if (index == -1) {
      cout << 'x' << " ";
    } else {
      cout << index << " ";
    }
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  string S;
  cin >> S;

  solution(S);

  return 0;
}