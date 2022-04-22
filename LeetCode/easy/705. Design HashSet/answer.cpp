#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

// use STL
// time : O(1)
// space : O(N)
class MyHashSet {
 private:
  unordered_set<int> us;

 public:
  MyHashSet() {}

  void add(int key) { us.insert(key); }

  void remove(int key) { us.erase(key); }

  bool contains(int key) { return us.count(key) > 0; }
};

// use array
// time : O(1)
// space : O(1e6)
class MyHashSet {
 private:
  bool us[1000001] = {
      false,
  };

 public:
  MyHashSet() {}

  void add(int key) { us[key] = true; }

  void remove(int key) { us[key] = false; }

  bool contains(int key) { return us[key]; }
};

// use linked list with bucket
// time : O(N / K)
// space : O(K + M)
class MyHashSet {
 private:
  struct Node {
    int key;
    Node* next;

    Node(int k, Node* n) {
      key = k;
      next = n;
    }
  };

  const static int size = 19997;
  const static int mult = 12582917;

  Node* data[size];

  int hashFunction(int key) { return (int)((long)key * mult % size); }

 public:
  void add(int key) {
    remove(key);
    int hashValue = hashFunction(key);
    Node* node = new Node(key, data[hashValue]);

    data[hashValue] = node;
  }

  bool contains(int key) {
    int hashValue = hashFunction(key);
    Node* node = data[hashValue];

    while (node) {
      if (node->key == key) return true;
      node = node->next;
    }

    return false;
  }

  void remove(int key) {
    int hashValue = hashFunction(key);
    Node* node = data[hashValue];

    if (node == NULL) return;
    if (node->key == key) {
      Node* target = node;
      data[hashValue] = node->next;
      delete target;

      return;
    }

    while (node->next) {
      if (node->next->key == key) {
        node->next = node->next->next;
        return;
      }
      node = node->next;
    }
  }
};

// use linked list with bucket
// time : O(N / K)
// space : O(K + M)
class MyHashSet {
 private:
  const static int size = 19997;
  const int mult = 12582917;

  list<int> data[size];

  int hashFunction(int key) { return (int)((long)key * mult % size); }

 public:
  void add(int key) {
    if (contains(key)) return;

    int hashValue = hashFunction(key);
    data[hashValue].push_back(key);
  }

  bool contains(int key) {
    int hashValue = hashFunction(key);
    auto it = data[hashValue].begin();

    while (it != data[hashValue].end()) {
      if (*it == key) return true;
      it++;
    }

    return false;
  }

  void remove(int key) {
    int hashValue = hashFunction(key);
    auto it = data[hashValue].begin();

    while (it != data[hashValue].end()) {
      if (*it == key) {
        data[hashValue].erase(it);
        break;
      }
      it++;
    }
  }
};