#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// use brute force & overlap

class MyCalendarTwo {
 private:
  struct Data {
    int start, end;
  };
  vector<Data> books;
  vector<Data> overlaps;

 public:
  bool book(int start, int end) {
    for (Data data : overlaps) {
      if (data.start < end && data.end > start) return false;
    }
    for (Data data : books) {
      // find overlapped range
      if (data.start < end && data.end > start) {
        overlaps.push_back({max(start, data.start), min(end, data.end)});
      }
    }

    books.push_back({start, end});
    return true;
  }
};

// use boundary count

class MyCalendarTwo {
 private:
  map<int, int> m;  // time, +1 if start, -1 if end

 public:
  bool book(int start, int end) {
    m[start]++;
    m[end]--;
    int booked = 0;

    for (auto it = m.begin(); it != m.end(); it++) {
      booked += it->second;
      if (booked == 3) {
        m[start]--;
        m[end]++;
        return false;
      }
    }

    return true;
  }
};