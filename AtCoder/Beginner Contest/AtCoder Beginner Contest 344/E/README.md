# E - Insert or Erase

[링크](https://atcoder.jp/contests/abc344/tasks/abc344_e)

| 난이도 |
| :----: |
|  475   |

## 설계

### 시간 복잡도

배열 A의 숫자의 갯수를 N, 쿼리의 갯수를 Q라 하자.

직접 배열을 수정할 경우 O(N \* Q)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

연결 리스트를 사용할 경우 배열의 수정에 O(1)의 시간 복잡도를 사용하므로 O(N + Q)의 시간 복잡도를 사용한다.

### 공간 복잡도

연결 리스트에 O(N + Q)의 공간 복잡도가 필요하다.

### 연결 리스트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     475      |  O(N + Q)   |  O(N + Q)   |

배열 A를 순회하며 연결 리스트 구조를 생성한다.

이후 쿼리를 순회하며 연결 리스트를 수정한다.

마지막으로 연결 리스트의 시작점부터 순회하며 정답을 만든다.

```cpp
vector<int> solution(vector<int> &arr, vector<vector<int>> &queries) {
  int size = arr.size();
  unordered_map<int, int> nexts;
  unordered_map<int, int> prevs;

  for (int i = 0; i < arr.size(); i++) {
    nexts[arr[i]] = (i + 1) < size ? arr[i + 1] : -1;
    prevs[arr[i]] = (i - 1) >= 0 ? arr[i - 1] : -1;
  }

  for (vector<int> &q : queries) {
    if (q[0] == 1) {
      int x = q[1], y = q[2];

      int next = nexts[x];

      prevs[y] = x;
      nexts[y] = next;

      nexts[x] = y;
      prevs[next] = y;

    } else {
      int x = q[1];

      int prev = prevs[x];
      int next = nexts[x];

      prevs[next] = prev;
      nexts[prev] = next;

      prevs.erase(x);
      nexts.erase(x);
    }
  }

  int start = -1;
  for (auto &p : prevs) {
    if (p.second == -1) {
      start = p.first;
      break;
    }
  }

  vector<int> answer;
  int cur = start;
  while (cur != -1) {
    answer.push_back(cur);
    cur = nexts[cur];
  }

  return answer;
}
```

## 고생한 점
