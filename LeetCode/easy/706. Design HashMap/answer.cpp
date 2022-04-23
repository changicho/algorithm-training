#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use array

class MyHashMap {
 public:
  int data[1000001];
  MyHashMap() { fill(data, data + 1000000, -1); }

  void put(int key, int value) { data[key] = value; }

  int get(int key) { return data[key]; }

  void remove(int key) { data[key] = -1; }
};

// use linked list hash map

class MyHashMap {
 private:
  struct Node {
    int key, val;
    Node* next;

    Node(int k, int v, Node* n) {
      key = k;
      val = v;
      next = n;
    }
  };

  const static int size = 19997;
  const static int mult = 12582917;

  Node* data[size];

  int hashFunction(int key) { return (int)((long)key * mult % size); }

 public:
  void put(int key, int val) {
    remove(key);
    int hashValue = hashFunction(key);
    Node* node = new Node(key, val, data[hashValue]);

    data[hashValue] = node;
  }

  int get(int key) {
    int hashValue = hashFunction(key);
    Node* node = data[hashValue];

    while (node) {
      if (node->key == key) return node->val;
      node = node->next;
    }

    return -1;
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

// use STL

class MyHashMap {
 public:
  unordered_map<int, int> um;

  void put(int key, int value) { um[key] = value; }

  int get(int key) {
    if (um.count(key) > 0) return um[key];
    return -1;
  }

  void remove(int key) { um.erase(key); }
};

// use linked list hash map
// time : O(N / K)
// space : O(K + M)
class MyHashMap {
 private:
  const static int size = 19997;
  const int mult = 12582917;

  list<pair<int, int>> data[size];

  int hashFunction(int key) { return (int)((long)key * mult % size); }

 public:
  void put(int key, int val) {
    if (get(key) != -1) {
      remove(key);
    }

    int hashValue = hashFunction(key);
    data[hashValue].push_back({key, val});
  }

  int get(int key) {
    int hashValue = hashFunction(key);
    auto it = data[hashValue].begin();

    while (it != data[hashValue].end()) {
      if (it->first == key) return it->second;
      it++;
    }

    return -1;
  }

  void remove(int key) {
    int hashValue = hashFunction(key);
    auto it = data[hashValue].begin();

    while (it != data[hashValue].end()) {
      if (it->first == key) {
        data[hashValue].erase(it);
        break;
      }
      it++;
    }
  }
};