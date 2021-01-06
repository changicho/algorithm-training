#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int postOrder[100001];
int inOrder[100001];
int indexTable[100001];

void recursive(int inBegin, int inEnd, int postBegin, int postEnd) {
  if (inBegin > inEnd || postBegin > postEnd) return;

  int root = postOrder[postEnd];
  cout << root << " ";

  recursive(inBegin, indexTable[root] - 1, postBegin, postBegin + (indexTable[root] - inBegin) - 1);
  recursive(indexTable[root] + 1, inEnd, postBegin + (indexTable[root] - inBegin), postEnd - 1);
}

void solution() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> inOrder[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> postOrder[i];
  }
  for (int i = 0; i < N; i++) {
    indexTable[inOrder[i]] = i;
  }

  recursive(0, N - 1, 0, N - 1);
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}