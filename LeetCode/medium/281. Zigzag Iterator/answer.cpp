#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use index

class ZigzagIterator {
 private:
  vector<int> indexes = {0, 0};
  vector<int> sizes;
  int vIndex = 0;

  vector<vector<int>> array;

 public:
  bool canCurIndex(int index) {
    if (indexes[index] == sizes[index]) return false;
    return true;
  }

  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    sizes.emplace_back(v1.size());
    array.emplace_back(v1);

    sizes.emplace_back(v2.size());
    array.emplace_back(v2);

    if (canCurIndex(0)) {
      vIndex = 0;
    } else if (canCurIndex(1)) {
      vIndex = 1;
    }
  }

  int next() {
    int ret;
    int before = vIndex;

    ret = array[vIndex][indexes[vIndex]];
    indexes[vIndex]++;
    vIndex = (vIndex + 1) % 2;

    if (!canCurIndex(vIndex)) vIndex = (vIndex + 1) % 2;

    return ret;
  }

  bool hasNext() {
    if (!canCurIndex(0) && !canCurIndex(1)) return false;
    return true;
  }
};

// use queue

class ZigzagIterator {
 private:
  queue<int> q;

 public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    int index1 = 0, index2 = 0;
    int size1 = v1.size(), size2 = v2.size();

    while (index1 < size1 || index2 < size2) {
      if (index1 < size1) {
        q.push(v1[index1]);
        index1 += 1;
      }
      if (index2 < size2) {
        q.push(v2[index2]);
        index2 += 1;
      }
    }
  }

  int next() {
    int cur = q.front();
    q.pop();
    return cur;
  }

  bool hasNext() {
    return !q.empty();
  }
};

// use iterator queue

class ZigzagIterator {
 private:
  queue<pair<vector<int>::iterator, vector<int>::iterator>> q;

 public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    if (v1.size() != 0) {
      q.push(make_pair(v1.begin(), v1.end()));
    }
    if (v2.size() != 0) {
      q.push(make_pair(v2.begin(), v2.end()));
    }
  }

  int next() {
    auto beginIt = q.front().first;
    auto endIt = q.front().second;
    q.pop();

    if (beginIt + 1 != endIt) {
      q.push(make_pair(beginIt + 1, endIt));
    }

    return *beginIt;
  }

  bool hasNext() {
    return !q.empty();
  }
};