#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use heap
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  struct Data {
    int index, rating;

    bool operator<(const Data &b) const { return rating > b.rating; }
  };

 public:
  int candy(vector<int> &ratings) {
    int size = ratings.size();
    vector<int> candies(size, 1);

    priority_queue<Data> pq;

    for (int i = 0; i < size; i++) {
      pq.push({i, ratings[i]});
    }

    while (!pq.empty()) {
      Data cur = pq.top();
      pq.pop();

      int left = cur.index - 1, right = cur.index + 1;

      if (0 <= left) {
        if (ratings[left] < cur.rating && candies[left] >= candies[cur.index]) {
          candies[cur.index] = candies[left] + 1;
        }
      }
      if (right < size) {
        if (ratings[right] < cur.rating &&
            candies[right] >= candies[cur.index]) {
          candies[cur.index] = candies[right] + 1;
        }
      }
    }

    int count = 0;
    for (int &c : candies) {
      count += c;
    }

    return count;
  }
};

// use two array
// time : O(N)
// space : O(N)
class Solution {
 public:
  int candy(vector<int> &ratings) {
    int size = ratings.size();

    vector<int> fromLeft(size, 1), fromRight(size, 1);
    for (int i = 0; i < size; i++) {
      int rIdx = size - 1 - i;

      if (0 <= i - 1 && ratings[i - 1] < ratings[i]) {
        fromLeft[i] = fromLeft[i - 1] + 1;
      }
      if (rIdx + 1 < size && ratings[rIdx] > ratings[rIdx + 1]) {
        fromRight[rIdx] = fromRight[rIdx + 1] + 1;
      }
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
      count += max(fromLeft[i], fromRight[i]);
    }
    return count;
  }
};

// use constant space
// time : O(N)
// space : O(1)
class Solution {
 public:
  int candy(vector<int> &ratings) {
    int size = ratings.size();
    int count = 1;
    if (size == 1) return count;

    int i, pPos, peak = 1;
    bool isDes = false;
    for (i = 1; i < size; i++) {
      if (ratings[i] >= ratings[i - 1]) {  // it is increasing
        if (isDes) {
          count -= (peak - 1) * (i - pPos - (peak > 0));
          peak = 1;
          isDes = false;
        }
        // update child i candy number, if equal, set to 1
        peak = (ratings[i] == ratings[i - 1]) ? 1 : peak + 1;
        count += peak;
      } else {
        if (!isDes) {
          pPos = i - 1;
          isDes = true;
        }
        peak--;
        count += peak;
      }
    }

    return !isDes ? count : count - (peak - 1) * (i - pPos - (peak > 0));
  }
};