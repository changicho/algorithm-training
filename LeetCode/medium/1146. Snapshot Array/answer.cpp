#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// use binary search

class SnapshotArray {
 private:
  vector<map<int, int>> snapshots;
  int id = 0;

 public:
  SnapshotArray(int length) {
    snapshots.resize(length);

    for (int i = 0; i < length; i++) {
      snapshots[i][0] = 0;
    }
  }

  void set(int index, int val) { snapshots[index][id] = val; }

  int snap() {
    id++;
    return id - 1;
  }

  int get(int index, int snap_id) {
    auto it = snapshots[index].upper_bound(snap_id);
    // if(it == snapshots[index].begin()) return 0;
    return prev(it)->second;
  }
};