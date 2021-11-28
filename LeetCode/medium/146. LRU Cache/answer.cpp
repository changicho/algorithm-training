#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hash map with Linked list

class LRUCache {
 private:
  struct Node {
    int key, val;
    Node *prev, *next;

    Node() {}
    Node(int key, int val) {
      this->key = key;
      this->val = val;
    }
  };

  unordered_map<int, Node*> hashMapToNode;
  Node *head = new Node(), *tail = new Node();
  int capacity;

  void cutTarget(Node* target) {
    Node *prev = target->prev, *next = target->next;
    prev->next = next;
    next->prev = prev;
  }

  void insertFront(Node* target) {
    Node* next = head->next;
    head->next = target;

    target->prev = head;
    target->next = next;

    next->prev = target;
  }

  void moveFirst(Node* target) {
    cutTarget(target);
    insertFront(target);
  }

 public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (hashMapToNode.find(key) == hashMapToNode.end()) return -1;

    Node* target = hashMapToNode[key];
    int ret = target->val;

    moveFirst(target);
    return ret;
  }

  void put(int key, int value) {
    if (hashMapToNode[key]) {
      Node* target = hashMapToNode[key];
      cutTarget(target);
      hashMapToNode.erase(key);
      delete target;
    }

    Node* node = new Node(key, value);
    hashMapToNode[key] = node;
    insertFront(node);

    // delete part
    if (hashMapToNode.size() > capacity) {
      // delete tail
      Node* target = tail->prev;
      cutTarget(target);
      hashMapToNode.erase(target->key);
      delete target;
    }
  }
};