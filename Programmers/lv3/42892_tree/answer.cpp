#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
struct info {
  int index, x, y;
};

struct node {
  int index;
  int val;
  struct node *left;
  struct node *right;
};

node *root;
vector<vector<int>> answer(2);

void insert(node *cur, node *newNode) {
  // 왼쪽에  삽입
  if (cur->val > newNode->val) {
    if (cur->left != NULL) {
      insert(cur->left, newNode);
    } else {
      cur->left = newNode;
    }
  }
  // 오른쪽에 삽입
  if (cur->val < newNode->val) {
    if (cur->right != NULL) {
      insert(cur->right, newNode);
    } else {
      cur->right = newNode;
    }
  }
}

void preorder(node *cur) {
  if (cur == NULL) {
    return;
  }
  answer[0].push_back(cur->index);
  preorder(cur->left);
  preorder(cur->right);
}

void postorder(node *cur) {
  if (cur == NULL) {
    return;
  }
  postorder(cur->left);
  postorder(cur->right);
  answer[1].push_back(cur->index);
}

bool compare(info a, info b) {
  if (a.y != b.y) {
    return a.y > b.y;
  }
  return a.x < b.x;
}

struct node *makeNode(int index, int x) {
  node *rootNode = new node;

  rootNode->index = index;
  rootNode->val = x;
  rootNode->left = rootNode->right = NULL;

  return rootNode;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
  vector<info> nodes;

  for (int i = 0; i < nodeinfo.size(); i++) {
    info temp;

    temp.index = i + 1;
    temp.x = nodeinfo[i][0];
    temp.y = nodeinfo[i][1];

    nodes.push_back(temp);
  }

  sort(nodes.begin(), nodes.end(), compare);

  info first = nodes.front();
  nodes.erase(nodes.begin());

  root = makeNode(first.index, first.x);

  for (info cur : nodes) {
    node *nextNode = makeNode(cur.index, cur.x);

    insert(root, nextNode);
  }

  preorder(root);
  postorder(root);

  return answer;
}

int main() {
  vector<vector<int>> nodeinfo = {{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1},
                                  {1, 3}, {8, 6},  {7, 2},  {2, 2}};
  vector<vector<int>> result = {{7, 4, 6, 9, 1, 8, 5, 2, 3},
                                {9, 6, 5, 8, 1, 4, 3, 2, 7}};

  vector<vector<int>> myresult = solution(nodeinfo);

  cout << "answer : " << endl;
  for (vector<int> r : result) {
    for (int a : r) {
      cout << a << " ";
    }
    cout << endl;
  }

  cout << "myanswer : " << endl;
  for (vector<int> r : myresult) {
    for (int a : r) {
      cout << a << " ";
    }
    cout << endl;
  }

  return 0;
}