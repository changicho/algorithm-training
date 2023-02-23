#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass with compare neighbor

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    // we iterate all index of nums
    int size = nums.size();
    int answer = nums.front();

    // (int i=0; i<nums.size();i++)
    for (int i = 0; i < size; i++) {
      // we check the left part (even i-1 < 0)
      bool isLeftOk = i - 1 >= 0 ? nums[i - 1] == nums[i] : false;
      // we check the right part (even i+1 >= nums.size())
      bool isRightOk = i + 1 < size ? nums[i] == nums[i + 1] : false;
      // we have two boolean value leftOk, rightOk

      // if leftOk == false && rightOk == false
      if (!isLeftOk && !isRightOk) {
        // i is the answer's index
        answer = nums[i];
        break;
      }
      // else i is not a single element
    }

    // return answer
    return answer;
  }
};

// use one pass

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    // first we start index = 0
    int index = 0;
    int size = nums.size();
    // and do while iteration until index < size - 1
    while (index < size - 1) {
      // we just compare index, index + 1 (is the same or not)
      if (nums[index] == nums[index + 1]) {
        // if same, we move index += 2
        index += 2;
      } else {
        // if not, index is the single element
        // and break
        break;
      }
    }
    // if the last element is the answer index == size - 1 and break the while
    // so index is the answer;
    return nums[index];
  }
};

// use binary search

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int size = nums.size();
    int left = 0, right = size - 1;

    // compare leftSubarray, rightSubarray size is odd or not
    // if some subarray is odd that means there are answer in that subarray

    int answer = nums.front();
    while (left <= right) {
      int mid = left + (right - left) / 2;

      // check there are same value next each other
      bool isLeftSame = mid - 1 >= 0 && nums[mid] == nums[mid - 1];
      bool isRightSame = mid + 1 < size && nums[mid] == nums[mid + 1];

      // the case that current value is single
      if (!isLeftSame && !isRightSame) {
        answer = nums[mid];
        break;
      }

      // make next range's edge
      int nextRight = isLeftSame ? mid - 2 : mid - 1;
      int nextLeft = isLeftSame ? mid + 1 : mid + 2;

      // there are answer in left Part
      if ((nextRight - left + 1) % 2 == 1) {
        right = nextRight;
      } else {  // there are answer in right part
        left = nextLeft;
      }
    }

    return answer;
  }
};

// use binary search only even index

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int size = nums.size();
    int left = 0, right = size - 1;

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (mid % 2 == 1) mid--;

      // there are answer in right part
      if (nums[mid] == nums[mid + 1]) {
        left = mid + 2;
      } else {  // there are answer in left part
        right = mid;
      }
    }

    return nums[left];
  }
};

// use binary search
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int size = nums.size();
    int left = 0, right = size;
    // if(size==1) return nums[0];
    while (left < right) {
      int mid = left + (right - left) / 2;
      bool isOdd = mid % 2 == 1;
      int target = isOdd ? mid - 1 : mid + 1;

      if (target < 0 || target >= size) {
        right = mid;
        continue;
      }

      // odd & mid-1 == mid || even & mid == mid+1
      // pick right
      // even & mid != mid+1 || odd & mid-1 != mid
      // pick left
      if (nums[mid] == nums[target]) {
        // pick right part
        left = mid + 1;
      } else {
        // pick left part;
        right = mid;
      }
    }

    return nums[left];
  }
};