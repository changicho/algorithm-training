#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash map
// time :
//  - add : O(1)
//  - delete : O(1)
//  - has : O(1)
// space : O(N)
class FrequencyTracker {
 private:
  unordered_map<int, int> counts;
  unordered_map<int, unordered_set<int>> keyByFreq;

 public:
  void add(int number) {
    int before = counts[number];
    counts[number]++;

    keyByFreq[before].erase(number);
    keyByFreq[counts[number]].insert(number);
  }

  void deleteOne(int number) {
    if (counts[number] == 0) return;

    int before = counts[number];
    counts[number]--;

    keyByFreq[before].erase(number);
    keyByFreq[counts[number]].insert(number);
  }

  bool hasFrequency(int frequency) { return keyByFreq[frequency].size() > 0; }
};