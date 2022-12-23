#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use vector
// time : O(N)
// space : O(N)
class Allocator {
 private:
  vector<int> memory;

  int getFirstEmpty(int need) {
    int size = memory.size();
    for (int i = 0; i < size; i++) {
      if (memory[i] != -1) continue;
      int length = 0;
      int start = i;
      while (i < size && memory[i] == -1) {
        length++;
        i++;
      }

      if (length >= need) {
        return start;
      }
    }
    return -1;
  }

 public:
  Allocator(int n) { memory.resize(n, -1); }

  int allocate(int size, int mID) {
    int first = getFirstEmpty(size);
    if (first == -1) return -1;
    for (int i = first; i < first + size; i++) {
      memory[i] = mID;
    }
    return first;
  }

  int free(int mID) {
    int size = memory.size();
    int count = 0;
    for (int i = 0; i < size; i++) {
      if (memory[i] != mID) continue;
      count++;
      memory[i] = -1;
    }
    return count;
  }
};
