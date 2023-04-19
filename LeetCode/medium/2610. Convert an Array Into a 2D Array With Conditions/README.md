# 2610. Convert an Array Into a 2D Array With Conditions

[링크](https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

각 원소를 순차적으로 순회하며 새로운 배열을 생성한다.

이 때 각 순회마다 O(N)의 시간 복잡도를 사용하며 중복이 반복될 경우 총 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

새로운 배열에 들어가는 원소의 수는 원본과 동일하다.

따라서 O(N)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |   O(N^2)    |    O(N)     |

각 원소를 큐에 넣는다.

큐를 순회하며 hash set에 중복되는 원소가 없는 경우 새로운 vector에 추가한다. 이후 hash set에 해당 원소를 저장한다.

hash set에 존재하는 원소는 다시 큐에 넣는다.

이를 각 과정마다 큐의 기존 크기만큼만 반복한다.

```cpp
vector<vector<int>> findMatrix(vector<int>& nums) {
  vector<vector<int>> answer;

  queue<int> q;
  for (int& n : nums) {
    q.push(n);
  }

  while (!q.empty()) {
    unordered_set<int> us;

    int size = q.size();
    while (size--) {
      int cur = q.front();
      q.pop();

      if (us.count(cur) == 0) {
        us.insert(cur);
      } else {
        q.push(cur);
      }
    }

    vector<int> line;
    for (int n : us) {
      line.push_back(n);
    }
    answer.push_back(line);
  }
  return answer;
}
```

## 고생한 점
