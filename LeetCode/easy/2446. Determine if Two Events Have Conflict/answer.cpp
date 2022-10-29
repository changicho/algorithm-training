#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use interval overlapped
// time : O(1)
// space : O(1)
class Solution {
 private:
  int convert(string& time) {
    int minutes = (time[3] - '0') * 10 + (time[4] - '0');
    int hours = (time[0] - '0') * 10 + (time[1] - '0');
    return hours * 60 + minutes;
  }

 public:
  bool haveConflict(vector<string>& event1, vector<string>& event2) {
    return convert(event1.back()) >= convert(event2.front()) &&
           convert(event2.back()) >= convert(event1.front());
  }
};

// use interval overlapped
// time : O(1)
// space : O(1)
class Solution {
 public:
  bool haveConflict(vector<string>& event1, vector<string>& event2) {
    return (event1.back() >= event2.front()) &&
           (event2.back() >= event1.front());
  }
};