#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

// use hash map

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    vector<Node*> array;
    unordered_map<Node*, Node*> m;

    Node* dummy = new Node(0);
    Node* before = dummy;
    Node* cur = head;

    // deep copy with dummy, and store to array and map
    while (cur) {
      Node* node = new Node(cur->val);
      before->next = node;
      array.push_back(node);
      m[cur] = node;

      cur = cur->next;
      before = before->next;
    }

    // set random of nodes in array
    cur = head;
    for (Node* node : array) {
      if (cur->random) {
        node->random = m[cur->random];
      } else {
        node->random = NULL;
      }
      cur = cur->next;
    }

    return dummy->next;
  }
};

// use copy to next

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return NULL;

    Node *first, *second;
    for (first = head; first; first = first->next->next) {
      second = new Node(first->val);
      second->random = first->random;
      second->next = first->next;
      first->next = second;
    }

    Node* ret = head->next;
    for (first = head; first; first = first->next->next) {
      if (first->random) {
        first->next->random = first->random->next;
      }
    }

    for (first = head; first; first = first->next) {
      second = first->next;
      first->next = second->next;

      if (second->next) {
        second->next = second->next->next;
      }
    }

    return ret;
  }
};
