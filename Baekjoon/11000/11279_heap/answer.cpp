#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long heap[100002];
int heap_size = 0;

void heap_delete() {
  int current, left, right;

  heap[1] = heap[heap_size];
  heap[heap_size] = 0;
  heap_size -= 1;

  if (heap_size == 0) {
    return;
  }

  current = 1;
  while (true) {
    left = current * 2;
    right = current * 2 + 1;

    if (left > heap_size) {
      break;
    }

    // if it has only left node
    if (right > heap_size) {
      if (heap[left] > heap[current]) {
        swap(heap[left], heap[current]);
        current = left;
        continue;
      }
    }
    // if it has two node
    else {
      if (heap[left] >= heap[right]) {
        if (heap[left] > heap[current]) {
          swap(heap[left], heap[current]);
          current = left;
          continue;
        }
      } else {
        if (heap[right] > heap[current]) {
          swap(heap[right], heap[current]);
          current = right;
          continue;
        }
      }
    }

    if (current == left / 2) {
      break;
    }
  }

  return;
}

void heap_push(int input) {
  heap_size += 1;
  heap[heap_size] = input;

  int current = heap_size, parent;

  while (true) {
    if (current == 1) break;

    parent = current / 2;

    if (heap[current] > heap[parent]) {
      swap(heap[parent], heap[current]);
    } else {
      break;
    }
    current = parent;
  }
}

void solution() {
  int N, input;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> input;
    if (input == 0) {
      // cout << "out: ";
      if (heap_size == 0) {
        cout << "0\n";
      } else {
        cout << heap[1] << "\n";
        heap_delete();
      }
    } else {
      heap_push(input);
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}