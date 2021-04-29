#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int data;
  struct Node* next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int getLength(Node* head) {
  int count = 0;
  while (head) {
    head = head->next;
    count += 1;
  }
  return count;
}

int intersectPoint(Node* head1, Node* head2) {
  int length1 = getLength(head1);
  int length2 = getLength(head2);

  if (length2 > length1) {
    swap(head1, head2);
    swap(length1, length2);
  }

  int diff = length1 - length2;
  for (int i = 0; i < diff; i++) {
    head1 = head1->next;
  }

  while (head1 != head2) {
    head1 = head1->next;
    head2 = head2->next;
  }

  if (!head1) {
    return -1;
  }

  return head1->data;
}