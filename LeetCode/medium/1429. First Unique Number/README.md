# 1429. First Unique Number

[링크](https://leetcode.com/problems/first-unique-number/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

초기 배열의 길이를 N이라 하자. 이후 더해지는 값의 갯수를 K라 하자.

큐와 해시맵을 이용해 구현할 경우 다음과 같은 시간 복잡도가 소요된다.

이 때 더하는 경우 unique한 값을 갱신할 때 index를 이동하는 경우 모든 연산에 총 O(K)의 시간 복잡도가 소요된다.

- 생성 : O(N)
- showFirstUnique : O(1)
- add : O(1) (총 O(K))

### 공간 복잡도

hash map과 queue에 O(N + K)의 공간 복잡도를 사용한다.

### hash map & queue

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     228      | O(1), O(1)  |  O(N + K)   |

처음 배열을 순회하며 count를 증가시키고, 1개만 존재하는 값을 queue에 넣는다.

이후 add연산을 수행할 때 들어오는 값의 count를 증가시키고 1개만 존재하는 경우 queue에 넣는다.

현재 queue의 front가 1개만 존재하는 값이 아닌 경우 pop을 수행한다.

따라서 showFirstUnique는 큐의 front값이 된다. 만약 큐가 비어있는 경우 -1을 반환한다.

```cpp
class FirstUnique {
 private:
  unordered_map<int, int> counts;
  queue<int> q;

 public:
  FirstUnique(vector<int> &nums) {
    for (int &num : nums) {
      counts[num]++;
    }

    for (int &num : nums) {
      if (counts[num] == 1) {
        q.push(num);
      }
    }
  }

  int showFirstUnique() {
    if (q.empty()) return -1;
    return q.front();
  }

  void add(int value) {
    counts[value]++;
    if (counts[value] == 1) {
      q.push(value);
    }

    while (!q.empty() && counts[q.front()] > 1) {
      q.pop();
    }
  }
};
```

## 고생한 점
