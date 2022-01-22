#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class LFUCache {
 private:
  int capacity, size;
  int lfu = 0;                                    // minimum freq
  unordered_map<int, list<int>> keys;             // freq : keys
  unordered_map<int, pair<int, int>> values;      // key : {value,freq}
  unordered_map<int, list<int>::iterator> iters;  // key : list iterator

  void update(int key) {
    int freq = values[key].second;
    auto iter = iters[key];

    values[key].second++;    // increase freq
    keys[freq].erase(iter);  // remove cur iter from before freq
    keys[freq + 1].push_back(key);

    iters[key] = prev(keys[freq + 1].end());

    // trim minimum freq
    while (keys[lfu].empty()) lfu++;
  }

 public:
  LFUCache(int capacity) {
    this->capacity = capacity;
    size = 0;
  }

  int get(int key) {
    if (values.find(key) == values.end()) return -1;

    update(key);
    return values[key].first;
  }

  void put(int key, int value) {
    // do nothing if there are no capacity
    if (capacity == 0) return;

    if (values.find(key) != values.end()) {
      values[key].first = value;
      update(key);
      return;
    }

    if (size == capacity) {
      int remove = keys[lfu].front();
      keys[lfu].pop_front();
      values.erase(remove);
      iters.erase(remove);
    } else {
      size++;
    }

    // put new value. freq is 1
    values[key] = {value, 1};
    keys[1].push_back(key);
    iters[key] = prev(keys[1].end());
    lfu = 1;
  }
};