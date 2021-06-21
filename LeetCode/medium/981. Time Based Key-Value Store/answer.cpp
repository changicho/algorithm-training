#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use binary search

class TimeMap {
 public:
  struct Data {
    int timestamp;
    string value;
  };

  unordered_map<string, vector<Data>> m;

  void set(string key, string value, int timestamp) {
    m[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {
    vector<Data>& array = m[key];
    if (array.size() == 0) return "";

    int left = 0, right = array.size();
    Data ret = array[left];
    if (ret.timestamp > timestamp) return "";

    while (left < right - 1) {
      int mid = (left + right) / 2;

      if (array[mid].timestamp <= timestamp) {
        ret = array[mid];
        left = mid;
      } else {
        right = mid;
      }
    }

    return ret.value;
  }
};

// use STL

class TimeMap {
  unordered_map<string, map<int, string>> m;

 public:
  void set(string key, string value, int timestamp) {
    m[key][timestamp] = value;
  }

  string get(string key, int timestamp) {
    auto it = m[key].upper_bound(timestamp);

    if (it == m[key].begin()) return "";

    // it--;
    // return it->second;
    return prev(it)->second;
  }
};
