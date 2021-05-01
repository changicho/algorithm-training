#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// use map

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    map<int, int> m;
    vector<int> answer;
    int size = numbers.size();

    for (int i = 0; i < size; i++) {
      int number = numbers[i];
      m[number] = i + 1;
    }

    for (int i = 0; i < size; i++) {
      int number = numbers[i];
      if (m[target - number] != 0) {
        answer = {i + 1, m[target - number]};
        return answer;
      }
    }
    return answer;
  }
};

// use two pointer

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> answer;
    int size = numbers.size();

    int first = 0;
    int second = numbers.size() - 1;

    while (first < second) {
      if (numbers[first] + numbers[second] == target) {
        answer = {first + 1, second + 1};
        return answer;
      } else if (numbers[first] + numbers[second] > target) {
        second--;
      } else {
        first++;
      }
    }

    return answer;
  }
};