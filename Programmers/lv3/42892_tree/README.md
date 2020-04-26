# 42892. 길 찾기 게임

[링크](https://programmers.co.kr/learn/courses/30/lessons/42892)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
|  lv3   |             |

## 설계

### 정렬

입력받는 좌표에는 index 정보가 포함되어 있지 않으므로 구조체를 이용해 index를 포함해준다.

```cpp
struct info {
  int index, x, y;
};
```

무작위로 입력받는 좌표를 높이 별로 정렬하면 root노드를 바로 찾을 수 있다.

트리를 만들 경우 높이가 높은 순으로 트리를 만들어야 하므로 우선 y가 높은 순으로 정렬한다.

이후 x가 작은 점이 좌표상 앞에 있으므로 x가 작은 순으로 정렬한다.

```cpp
bool compare(info a, info b) {
  if (a.y != b.y) {
    return a.y > b.y;
  }
  return a.x < b.x;
}
```

### 트리 생성

정렬된 좌표 정보를 이용해 트리를 만든다.

root는 정렬 이후 제일 앞에있는 좌표이므로 nodes[0]으로 선언한다.

index는 1부터 증가시키며 nodes를 순회하고 트리를 생성한다.

트리의 노드 구조는 다음과 같다.

```cpp
struct node {
  int value;
  struct node *left;
  struct node *right;
};
```

추가할 노드의 생성은 다음 순서로 진행한다.

```cpp
// 메모리 할당으로 노드 생성
newNode = (node *)malloc(sizeof(node));

// 값 선언
newNode->value = value;

// 연결관계 초기화
newNode->left = NULL;
newNode->right = NULL;
```

노드를 삽입하는것은 다음과 같이 구현한다.

```cpp
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

// 사용방법

insert(root, newNode);
```

### 전위, 중위, 후위 순회

각 순회의 순서는 다음과 같다

전위 순회

1. value
2. left
3. right

중위 순회

1. left
2. value
3. right

후위 순회

1. left
2. right
3. value

## 고생한 점

트리를 직접 구현하는것이 어려웠다.
