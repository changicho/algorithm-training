#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use prefix sum with hash string
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int countDistinct(vector<int>& nums, int k, int p) {
    int size = nums.size();

    unordered_set<string> subArrays;

    vector<int> prefixSums(size + 1, 0);
    for (int i = 0; i < size; i++) {
      prefixSums[i + 1] = prefixSums[i] + (nums[i] % p == 0 ? 1 : 0);
    }

    for (int left = 0; left < size; left++) {
      string subArr = "";

      for (int right = left; right < size; right++) {
        if (prefixSums[right + 1] - prefixSums[left] > k) break;

        subArr.push_back(nums[right]);

        subArrays.insert(subArr);
      }
    }

    return subArrays.size();
  }
};

// use prefix sum with rolling hash
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int countDistinct(vector<int>& nums, int k, int p) {
    int size = nums.size();

    unordered_set<int> rollingHash;

    vector<int> prefixSums(size + 1, 0);
    for (int i = 0; i < size; i++) {
      prefixSums[i + 1] = prefixSums[i] + (nums[i] % p == 0 ? 1 : 0);
    }

    for (int left = 0; left < size; left++) {
      int curHash = 0;

      for (int right = left; right < size; right++) {
        if (prefixSums[right + 1] - prefixSums[left] > k) break;

        curHash = ((long long)curHash * 200 + nums[right]) % 10000000007;

        rollingHash.insert(curHash);
      }
    }

    return rollingHash.size();
  }
};

// use trie
// time : O(N^2)
// space : O(N + 200^N)
class Solution {
 private:
  struct Trie {
    unordered_map<int, Trie*> ch;
    int count = 0;

    int insert(vector<int>& nums, int i, int k, int p) {
      if (i == nums.size() || k - (nums[i] % p == 0) < 0) return 0;
      if (!ch[nums[i]]) {
        ch[nums[i]] = new Trie();
      }

      int next = ch[nums[i]]->insert(nums, i + 1, k - (nums[i] % p == 0), p);
      ch[nums[i]]->count++;
      bool isFirst = ch[nums[i]]->count == 1;

      return isFirst ? next + 1 : next;
    }
  };

 public:
  int countDistinct(vector<int>& nums, int k, int p) {
    int size = nums.size();
    int count = 0;
    Trie trie;

    for (int i = 0; i < size; i++) {
      count += trie.insert(nums, i, k, p);
    }

    return count;
  }
};