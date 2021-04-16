# 25. Reverse Nodes in k-Group

[링크](https://leetcode.com/problems/reverse-nodes-in-k-group/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

연결 리스트의 노드의 개수는 최대 5000이다.

순회하며 특정 구간의 순서를 바꿔주면 되므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

노드의 연결관계를 뒤집을 때 배열을 이용하는 경우 공간 복잡도는 O(N)이다.

그러나 임시 노드를 만들고 순서대로 뒤집을 경우 공간 복잡도는 O(1)이다.

### Iterator

> 8ms

노드가 다음 순서로 연결되어있다고 하자

(편의상 A보다 앞에 있는 시작노드를 before라고 하자.)

before > A > B > C > D

이 노드에서 A~C 구간을 뒤집는다고 할 때 결과는 다음과 같을 것이다.

before > C > B > A > D

이 때 A를 이동시키며, A->next에 있던 노드를 before->next에 끼워넣는다.

즉 순서는 다음과 같다.

1. before > A > B > C > D
2. before > B > A > C > D
3. before > C > B > A > D

이 때 맨 마지막 구간이 k보다 작은 경우 뒤집지 말아야 하므로 뒤집을 구간이 몇개인지를 구하고, 그 구간들만 뒤집는다.

```cpp
int getLength(ListNode* head) {
  int length = 0;
  while (head) {
    length++;
    head = head->next;
  }
  return length;
}

ListNode* reverseKGroup(ListNode* head, int k) {
  ListNode* dummy = new ListNode();
  ListNode* before = dummy;
  ListNode* cur = head;
  dummy->next = head;

  int count = getLength(head) / k;
  for (int i = 0; i < count; i++) {
    for (int j = 1; j < k; j++) {
      ListNode* temp = before->next;
      before->next = cur->next;
      cur->next = cur->next->next;
      before->next->next = temp;
    }
    before = cur;
    cur = cur->next;
  }

  return dummy->next;
}
```

### 배열을 이용

> 16ms

뒤집을 구간의 노드를 배열에 담고 그 배열의 노드를 역순으로 방문하며 뒤집어도 된다.

```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
  ListNode* dummy = new ListNode();
  dummy->next = head;
  ListNode* before = dummy;
  ListNode* cur = head;

  vector<ListNode*> v(k);
  while (cur) {
    int count = 0;
    for (int i = 0; i < k; i++) {
      v[i] = cur;
      count += 1;
      cur = cur->next;

      if (!cur) break;
    }

    if (count != k) break;

    v.front()->next = v.back()->next;
    before->next = v.back();

    for (int i = k - 1; i >= 1; i--) {
      v[i]->next = v[i - 1];
    }

    before = v.front();
  }

  return dummy->next;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      8       |

## 고생한 점
