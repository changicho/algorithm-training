# E. Beautiful Palindromes

[링크](https://codeforces.com/contest/2162/problem/E)

| 난이도 |
| :----: |
|  1600  |

## 설계

### 시간 복잡도

입력받은 배열의 길이를 N, 수를 K라 하자.

각 숫자별로 나타나는 위치에 따라 (조건을 만족하는) 우선순위를 부여할 수 있다.

이후 우선순위가 낮은 K개의 숫자를 선택한다.

이에 O(N \* log_2(K))의 시간 복잡도가 소요된다.

카운팅 정렬을 사용할 경우 O(N)의 시간 복잡도로도 해결할 수 있다.

### 공간 복잡도

우선순위를 관리하는데 O(N)의 공간 복잡도가 소요된다.

우선순위 큐를 이용해 K개의 숫자를 관리한다.

이에 O(K)의 공간 복잡도가 소요된다.

카운팅 정렬에 O(N)의 공간 복잡도를 사용한다.

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     140      |    O(N)     |    O(N)     |

K개의 숫자를 뒤에 추가했을 때 최대한 조건을 만족하지 않도록 추가하는편이 유리하다.

다음과 같은 형태의 배열을 생각해보자.

```javascript
A B C D E
```

이 경우 E 이후에 현재 배열을 뒤집은 형태를 추가할 경우 가장 prefix, suffix 양 방향으로 읽었을 때 조건을 만족하는 경우가 많아진다.

따라서 배열에 없는 숫자나 최대한 앞에 위치한 숫자를 먼저 선택하는편이 유리하다.

각 숫자의 우선순위를 기록한 뒤 카운팅 정렬을 이용해 우선순위가 낮은 K개의 숫자를 선택한다.

```cpp
auto solution(int size, int k, vector<int>& nums) {
  vector<int> priority(size + 1, -1);
  for (int i = 0; i < size; i++) {
    priority[nums[i]] = i;
  }

  vector<vector<int>> candidates(size + 1);
  for (int num = 1; num <= size; num++) {
    candidates[priority[num] + 1].push_back(num);
  }

  vector<int> answer;
  for (int i = 0; i <= size && answer.size() < k; i++) {
    for (int& candidate : candidates[i]) {
      answer.push_back(candidate);
      if (answer.size() == k) {
        break;
      }
    }
  }

  return answer;
}
```

### 우선순위 큐

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     140      | O(N \* log_2(K)) |  O(N + K)   |

각 숫자마다 나타나는 마지막 위치를 기록한 뒤, 이 중 K개의 숫자를 우선순위 큐로 뽑는다.

이후 우선순위 큐에 있는 숫자들을 역순으로 정답에 추가해 반환한다.

```cpp
auto solution(int size, int k, vector<int>& nums) {
  vector<int> priority(size + 1, -1);
  for (int i = 0; i < size; i++) {
    priority[nums[i]] = i;
  }

  priority_queue<pair<int, int>> pq;
  for (int i = 1; i <= size; i++) {
    pq.push({priority[i], i});
    if (pq.size() > k) {
      pq.pop();
    }
  }

  vector<int> answer;
  for (int i = 0; i < k; i++) {
    answer.push_back(pq.top().second);
    pq.pop();
  }
  reverse(answer.begin(), answer.end());

  return answer;
}
```

## 고생한 점
