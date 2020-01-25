#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int alpha['Z' - 'A' + 1][2] = {
    -1,
};

// DLR
void preorder(int current) {
  cout << (static_cast<char>(current + 'A'));
  if (alpha[current][0] != -1) preorder(alpha[current][0]);
  if (alpha[current][1] != -1) preorder(alpha[current][1]);
};

// LDR
void inorder(int current) {
  if (alpha[current][0] != -1) inorder(alpha[current][0]);
  cout << (static_cast<char>(current + 'A'));
  if (alpha[current][1] != -1) inorder(alpha[current][1]);
};

// LRD
void postorder(int current) {
  if (alpha[current][0] != -1) postorder(alpha[current][0]);
  if (alpha[current][1] != -1) postorder(alpha[current][1]);
  cout << (static_cast<char>(current + 'A'));
};

void solution() {
  int N;
  cin >> N;
  char parent, child1, child2;

  for (int i = 0; i < N; i++) {
    cin >> parent >> child1 >> child2;

    if (child1 != '.') {
      alpha[parent - 'A'][0] = child1 - 'A';
    } else {
      alpha[parent - 'A'][0] = -1;
    }
    if (child2 != '.') {
      alpha[parent - 'A'][1] = child2 - 'A';
    } else {
      alpha[parent - 'A'][1] = -1;
    }
  }

  preorder(0);
  cout << "\n";
  inorder(0);
  cout << "\n";
  postorder(0);
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}