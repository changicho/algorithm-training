# 988. Smallest String Starting From Leaf

[링크](https://leetcode.com/problems/smallest-string-starting-from-leaf/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

DFS를 이용해 부모노드에서 리프노드 까지의 path를 탐색한 뒤 이를 이용해 정답을 구할 수 있다.

이 경우 탐색에 O(N)의 시간 복잡도를 사용한다.

이후 정답 문자열을 구하는데 O(N)의 시간 복잡도가 필요하다.

따라서 총 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

DFS에 O(N)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      6       |   O(N^2)    |    O(N)     |

루트노드에서부터 리프노드까지 탐색하며 path를 저장한다.

이후 해당 path를 역순으로 순회해 단어를 구한 뒤 정답을 갱신한다.

이 떄 리프에서만 정답을 갱신하며 이 경우 path를 순회하며 정답을 생성해야 하므로 순회에 O(N)의 시간 복잡도를 사용한다.

```cpp
string answer = "";

void recursive(TreeNode *node, vector<int> &path) {
  path.push_back(node->val);
  bool isLeaf = true;

  if (node->left) {
    isLeaf = false;
    recursive(node->left, path);
  }
  if (node->right) {
    isLeaf = false;
    recursive(node->right, path);
  }

  if (isLeaf) {
    string word = "";
    for (int &p : path) {
      word += p + 'a';
    }
    reverse(word.begin(), word.end());

    if (answer == "") {
      answer = word;
    } else {
      answer = min(answer, word);
    }
  }

  path.pop_back();
}

string smallestFromLeaf(TreeNode *root) {
  vector<int> path;

  recursive(root, path);

  return answer;
}
```

## 고생한 점
