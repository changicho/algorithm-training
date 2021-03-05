# 14725. 개미굴

[링크](https://www.acmicpc.net/problem/14725)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold II |   69.231    |       1       |

## 설계

### 시간 복잡도

노드의 총 개수는 1,000개 이다.

### 공간 복잡도

노드의 개수는 1,000개이며 각 경우마다 문자열을 출력하므로 string을 이용한다.

### 트라이

트라이는 문자열을 효율적으로 저장하고 탐색할 수 있는 K진 트리의 자료구조이다.

원하는 문자열을 찾는 데 들어가는 시간 복잡도는 O(N)이다.

각 단계마다 문자열들을 key로 설정하고 이후 탐색을 진행하는 방식으로 탐색을 최적화한다.

이때 중복된 단계에서 문자열이 어떨때는 마지막 문자열일수도, 아닐수도 있기 때문에 boolean으로 이 단계가 끝인지 여부또한 저장한다.

루트 노드의 경우 key값이 없음에 유의한다.

```cpp
struct Node {
  map<string, Node*> child;
  string key = "";
  bool isEnd = false;

  void insert(vector<string> words, int depth) {
    if (isEnd) {
      return;
    }
    string target = words[depth];

    if (child.find(target) != child.end()) {
      child.find(target)->second->insert(words, depth + 1);
    } else {
      Node* next = new Node;

      next->key = target;
      next->isEnd = depth + 1 == words.size();
      next->insert(words, depth + 1);

      child[target] = next;
    }
  }

  void print(int depth) {
    if (depth != 0) {
      for (int i = 0; i < depth - 1; i++) {
        cout << "--";
      }
      cout << key << '\n';
    }

    if (isEnd) {
      return;
    }

    for (auto it : child) {
      it.second->print(depth + 1);
    }
  }
};
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
