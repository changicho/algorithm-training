#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use brute force

class RandomizedSet {
 private:
  unordered_set<int> us;

 public:
  bool insert(int val) {
    if (us.count(val) > 0) return false;
    us.insert(val);
    return true;
  }

  bool remove(int val) {
    if (us.count(val) == 0) return false;
    us.erase(val);
    return true;
  }

  int getRandom() {
    int count = rand() % us.size();
    auto it = next(us.begin(), count);

    return *it;
  }
};

// use array to get index

class RandomizedSet {
 private:
  vector<int> numberList;
  unordered_map<int, int> hashTable;

 public:
  bool insert(int val) {
    if (hashTable.find(val) != hashTable.end()) {
      return false;
    }
    hashTable[val] = numberList.size();
    numberList.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (hashTable.find(val) == hashTable.end()) {
      return false;
    }

    swap(numberList[hashTable[val]], numberList[numberList.size() - 1]);
    numberList.pop_back();

    hashTable[numberList[hashTable[val]]] = hashTable[val];
    hashTable.erase(val);

    return true;
  }

  int getRandom() {
    return numberList[rand() % numberList.size()];
  }
};