#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct info {
  int index, x, y;
};

bool compare(info a, info b) {
  if (a.y != b.y) {
    return a.y > b.y;
  }
  return a.x < b.x;
}

struct node {
  int index;
  int x;
  struct node *left;
  struct node *right;
};

node *root;
vector<vector<int>> answer(2);

void insert(node *cur, node *newNode) {
  if (cur->x > newNode->x) {
    if (cur->left != NULL) {
      insert(cur->left, newNode);
    } else {
      cur->left = newNode;
    }
  } else if (cur->x < newNode->x) {
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

  node *newNode;
  newNode = (node *)malloc(sizeof(node));
  info cur_root = nodes[0];

  newNode->index = cur_root.index;
  newNode->x = cur_root.x;
  newNode->left = NULL;
  newNode->right = NULL;

  root = newNode;

  for (int i = 1; i < nodes.size(); i++) {
    info cur = nodes[i];

    newNode = (node *)malloc(sizeof(node));
    newNode->index = cur.index;
    newNode->x = cur.x;
    newNode->left = newNode->right = NULL;
    insert(root, newNode);
  }

  preorder(root);
  postorder(root);

  return answer;
}