#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
  int left, right;
  char value;
};
node nodes[101];
string answer = "";

void req(int index) {
  if (nodes[index].left != -1) {
    req(nodes[index].left);
  }
  answer += nodes[index].value;
  if (nodes[index].right != -1) {
    req(nodes[index].right);
  }
}

void clear() { answer = ""; }

void solution(int test_case) {
  clear();
  int N;

  cin >> N;

  for (int i = 1; i <= N; i++) {
    int index, left = -1, right = -1;
    char value;

    cin >> index >> value;
    if (i * 2 <= N) {
      cin >> left;
    }
    if (i * 2 + 1 <= N) {
      cin >> right;
    }
    node current = {left, right, value};
    nodes[index] = current;
  }

  req(1);

  cout << "#" << test_case << " " << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 10;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}