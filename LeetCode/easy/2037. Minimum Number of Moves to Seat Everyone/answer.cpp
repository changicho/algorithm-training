#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());

    int size = seats.size();
    int answer = 0;
    for (int i = 0; i < size; i++) {
      answer += abs(seats[i] - students[i]);
    }
    return answer;
  }
};