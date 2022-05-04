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

// use two pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  int candy(vector<int> &ratings) {
    int size = ratings.size();

    vector<int> fromLeft(size, 1), fromRight(size, 1);
    for (int i = 1; i < size; i++) {
      if (ratings[i - 1] < ratings[i]) {
        fromLeft[i] = fromLeft[i - 1] + 1;
      }
    }
    for (int i = size - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        fromRight[i] = fromRight[i + 1] + 1;
      }
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
      count += max(fromLeft[i], fromRight[i]);
    }
    return count;
  }
};