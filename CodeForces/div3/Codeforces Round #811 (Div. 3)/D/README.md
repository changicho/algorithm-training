# D. Color with Occurrences

[링크](https://codeforces.com/contest/1714/problem/D)

| 난이도 |
| :----: |
| \*1600 |

## 설계

### 시간 복잡도

문자열 T의 길이를 M, S의 크기를 N이라 하자.

직전에 색칠된 영역중 새로채워진 영역을 순회하며 시작점으로 설정한다.

이 탐색에 O(M \* N)의 시간 복잡도를 사용한다.

여기서 현재 시작점을 설정했을 때 S의 문자열중 하나와 같은 지 판별한다.

내부적으로 해당 에 O(N)의 시간 복잡도를 사용한다.

이 때 찾을 수 있는경우 색칠할 수 있는 영역을 갱신한다.

이 중 가장 멀리까지 색칠할 수 있는 영역을 찾고 이후 다음에 해당 영역에 대해 탐색을 계속한다.

이를 모든 index에 대해서 반복하므로 최종적으로 O(M)의 시간 복잡도를 사용한다.

총 시간 복잡도는 O(M^2 \* N^2)이다.

### 공간 복잡도

정답에 최대 O(M)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|      15      | O(M^2 \* N^2) |    O(M)     |

직전에 색칠한 영역을 탐색해 이 중 가장 멀리까지 색칠할 수 있는 영역을 찾고 이후 다음에 새로 채워진 영역에 대해 탐색을 계속한다.

즉 각 상황에서 가장 멀리까지 색칠할 수 있는 경우만 선택해 탐색한다.

이는 각 경우마다 가장 멀리까지 색칠할 수 있는 경우를 선택해야 가장 적게 단어를 선택할 수 있기 때문이다.

```cpp
vector<pair<int, int>> solution(string &t, vector<string> &s) {
  int length = t.length();

  vector<pair<int, int>> answer;

  int left = -1, right = 0, index = 0;
  while (index < length) {
    int tempR = -1, tempL = -1, sIndex = 0;

    for (int from = left + 1; from <= right; from++) {
      for (int i = 0; i < s.size(); i++) {
        if (t.substr(from, s[i].size()) != s[i]) continue;

        int to = from + s[i].size();
        if (tempR < to) {
          tempL = from, tempR = to;
          sIndex = i;
        }
      }
    }
    if (tempR == -1) return {};

    answer.push_back({sIndex, tempL});
    left = tempL, right = tempR;
    index = right;
  }

  return answer;
}
```

## 고생한 점
