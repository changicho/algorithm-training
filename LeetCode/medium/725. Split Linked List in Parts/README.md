# 725. Split Linked List in Parts

[링크](https://leetcode.com/problems/split-linked-list-in-parts/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

연결 리스트의 길이를 N, 나눌 개수를 k라 하자.

우선 연결리스트의 길이를 측정해야 하므로 O(N)의 시간 복잡도를 사용한다.

이후 연결 리스트를 나누는데 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

나눌 연결 리스트의 길이를 저장할 배열이 필요하다. 이에 O(K)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(K)     |

정답으로 반환할 배열에 O(K)의 공간 복잡도를 사용한다.

연결 리스트의 길이를 측정하고 이를 N이라 하자.

나눌 연결 리스트의 최소 길이는 N / K 이며, N % K 만큼 앞에서부터 1씩 더 길어진다.

따라서 앞에서부터 나눌 길이를 바로 구할 수 있으므로, 해당 길이만큼 이동 후 연결 리스트를 나눈다.

이 때 현재 노드와 직전 노드 사이를 잘라야 하므로 이전 노드를 저장해놓는다.

또한 현재 노드와 이전 노드가 빈 값일 수 있음에 유의한다.

```cpp
int getLength(ListNode* node) {
  int length = 0;
  while (node) {
    length++;
    node = node->next;
  }
  return length;
}

vector<ListNode*> splitListToParts(ListNode* head, int k) {
  vector<ListNode*> answer(k);

  int length = getLength(head);

  int mods = length % k;
  int remain = length / k;

  ListNode* cur = head;
  ListNode* before = NULL;
  for (int i = 0; i < k; i++) {
    answer[i] = cur;

    int size = remain + (mods > 0);
    mods--;

    while (size--) {
      before = cur;
      if (cur) cur = cur->next;
    }

    if (before) before->next = NULL;
  }
  return answer;
}
```

## 고생한 점
