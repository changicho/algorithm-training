# 2025 프로그래머스 코드챌린지 1차 예선 - 비밀 코드 해독

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/388352)

| 난이도 |
| :----: |
|  lv2   |

## 설계

### 시간 복잡도

입력받은 수를 N, 쿼리의 수를 Q라 하자.

최대 5개의 숫자를 사용가능하며 이를 모두 탐색했을 때 O(N^5)의 시간 복잡도가 필요하다.

이후 각 경우마다 쿼리를 순회하며 적절한지 판단하는데 O(Q)의 시간 복잡도를 사용한다.

따라서 O(N^5 \* Q)의 시간 복잡도를 사용한다.

### 공간 복잡도

재귀호출로 탐색할 경우 O(1)의 공간복잡도를 사용한다.

### 백트래킹

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
| O(N^5 \* Q) |    O(1)     |

재귀호출로 가능한 모든 숫자 조합 쌍을 탐색한다.

이 때 수는 오름차순으로 되어있어야 하므로 이전에 사용한 수보다 큰 수만 사용한다.

이후 각 숫자조합이 쿼리를 모두 만족하는지 판단한다.

```cpp
bool check(vector<int> &target, vector<vector<int>> &q, vector<int> &ans) {
  int size = q.size();

  unordered_set<int> us(target.begin(), target.end());

  for (int i = 0; i < size; i++) {
    vector<int> query = q[i];
    int a = ans[i];

    int count = 0;
    for (int &num : query) {
      if (us.count(num)) count++;
    }

    if (count != a) return false;
  }
  return true;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
  int answer = 0;

  vector<int> temp;

  function<void(void)> recursive = [&]() {
    if (temp.size() == 5) {
      if (check(temp, q, ans)) answer++;
      return;
    }

    int start = temp.empty() ? 1 : temp.back() + 1;

    for (int num = start; num <= n; num++) {
      temp.push_back(num);
      recursive();
      temp.pop_back();
    }
  };

  recursive();

  return answer;
}
```

## 고생한 점
