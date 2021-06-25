#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int n1, int n2) {
  return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
}

// use cyclic replacement & gcd

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    if (k == 0) return;
    int size = nums.size();

    int limit = gcd(k, size);

    for (int i = 0; i < limit; i++) {
      int index = i;
      int temp = nums[index];

      while ((index + k) % size != i) {
        int next = (index + k) % size;
        swap(nums[next], temp);
        index = next;
      }
      nums[i] = temp;
    }
  }
};

// use cyclic replacement

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    k %= size;
    int count = 0;

    for (int start = 0; count < size; start++) {
      int index = start;
      int temp = nums[index];

      while ((index + k) % size != start) {
        int next = (index + k) % size;
        swap(nums[next], temp);
        index = next;
        count++;
      }
      nums[start] = temp;
      count++;
    }
  }
};

// use reverse

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    if (k == 0) return;
    int size = nums.size();

    k %= size;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};
