# 2766. Relocate Marbles

[링크](https://leetcode.com/problems/relocate-marbles/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N, move의 크기를 M이라 하자.

각 경우마다 nums의 원소에서 move해야 하며 이에 대한 순서를 보장해야 한다.

이 때마다 중간에 있는 원소들의 순서가 변경될 수 있다.

hash set을 이용해 원소들의 변경을 진행 후 정렬을 이용하 수 있다.

이 경우 nums의 순회에 O(N), move의 순회에 O(M), 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* log_2(N) + M) 이다.

### 공간 복잡도

hash set에 원소를 저장해야 하므로 O(N)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|     350      | O(N \* log_2(N) + M) |    O(N)     |

nums에 현재 돌들이 존재하는 위치가 주어진다.

moveFrom과 moveTo에는 각각 돌이 이동할 위치와 이동될 위치가 주어진다.

각 과정마다 nums의 moveFrom에 있는 값들을 모두 moveTo로 변경해야 한다.

hash set을 이용해 각 원소들이 존재하는 위치를 관리할 경우 O(1)의 시간 복잡도로 접근이 가능하다.

moveFrom에 있는 값을 삭제 후 moveTo에 있는 값을 insert한다.

이를 구현하면 다음과 같다.

```cpp
vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
  unordered_set<int> us;

  for (int& num : nums) {
    us.insert(num);
  }

  int size = moveFrom.size();
  for (int i = 0; i < size; i++) {
    int from = moveFrom[i], to = moveTo[i];

    if (us.count(from) == 0) continue;

    us.erase(from);
    us.insert(to);
  }

  vector<int> answer(us.begin(), us.end());
  sort(answer.begin(), answer.end());
  return answer;
}
```

## 고생한 점
