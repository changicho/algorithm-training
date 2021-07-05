#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// brute force

class MyCalendar {
 private:
  struct Data {
    int start, end;
  };
  vector<Data> array;

 public:
  bool book(int start, int end) {
    for (Data data : array) {
      // overlapped
      if (data.start < end && data.end > start) return false;
    }

    array.push_back({start, end});
    return true;
  }
};

// use heap

class MyCalendar {
 private:
  // start, end
  map<int, int> data;

 public:
  bool book(int start, int end) {
    auto it = data.lower_bound(start);

    if (it != data.end() && it->first < end) return false;
    if (it != data.begin() && start < prev(it)->second) return false;
    data[start] = end;

    return true;
  }
};

class MyCalendar {
 private:
  // end, start
  map<int, int> data;

 public:
  bool book(int start, int end) {
    auto it = data.upper_bound(start);

    if (it != data.end() && it->second < end) return false;

    data[end] = start;
    return true;
  }
};

class MyCalendar {
  // start, end
  set<pair<int, int>> data;

 public:
  bool book(int start, int end) {
    auto it = data.lower_bound({start, end});

    if (it != data.end() && it->first < end) return false;
    if (it != data.begin() && start < prev(it)->second) return false;

    data.insert({start, end});
    return true;
  }
};

class MyCalendar {
  // end, start
  set<pair<int, int>> data;

 public:
  bool book(int start, int end) {
    auto it = data.upper_bound({start, end});

    if (it != data.end() && it->second < end) return false;

    data.insert({end, start});
    return true;
  }
};