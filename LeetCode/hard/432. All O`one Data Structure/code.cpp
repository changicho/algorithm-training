#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use linked list with hash map
// time : O(1)
// space : O(N)
class AllOne {
 private:
  struct Node {
    int count;
    Node* prev;
    Node* next;
    unordered_set<string> keys;

    Node(int count) : count(count), prev(nullptr), next(nullptr) {}
  };

  Node* head = new Node(0);
  Node* tail = new Node(0);
  unordered_map<string, Node*> um;

  Node* makeNode(int count, Node* prevNode, Node* nextNode) {
    Node* newNode = new Node(count);
    newNode->prev = prevNode;
    newNode->next = nextNode;
    prevNode->next = newNode;
    nextNode->prev = newNode;
    return newNode;
  }

  void removeNode(Node* node) {
    Node* prevNode = node->prev;
    Node* nextNode = node->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete node;
  }

 public:
  AllOne() {
    head->next = tail;
    tail->prev = head;
  }

  void inc(string key) {
    if (um.count(key) == 0) {
      Node* firstNode = head->next;

      if (firstNode == tail || firstNode->count > 1) {
        Node* newNode = makeNode(1, head, firstNode);
        firstNode = newNode;
      }

      firstNode->keys.insert(key);
      um[key] = firstNode;
      return;
    }

    Node* node = um[key];
    int count = node->count;
    node->keys.erase(key);

    Node* nextNode = node->next;
    if (nextNode == tail || nextNode->count != count + 1) {
      Node* newNode = makeNode(count + 1, node, nextNode);

      nextNode = newNode;
    }

    nextNode->keys.insert(key);
    um[key] = nextNode;

    if (node->keys.empty()) removeNode(node);
  }

  void dec(string key) {
    if (um.count(key) == 0) return;

    Node* node = um[key];
    node->keys.erase(key);
    int count = node->count;

    if (count == 1) {
      um.erase(key);
    } else {
      Node* prevNode = node->prev;

      if (prevNode == head || prevNode->count != count - 1) {
        Node* newNode = makeNode(count - 1, prevNode, node);
        prevNode = newNode;
      }

      prevNode->keys.insert(key);
      um[key] = prevNode;
    }

    if (node->keys.empty()) removeNode(node);
  }

  string getMaxKey() {
    if (tail->prev == head) return "";

    return *(tail->prev->keys.begin());
  }

  string getMinKey() {
    if (head->next == tail) return "";

    return *(head->next->keys.begin());
  }
};