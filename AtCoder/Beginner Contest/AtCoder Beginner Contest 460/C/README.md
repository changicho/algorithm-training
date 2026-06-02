# C - Sushi

[링크](https://atcoder.jp/contests/abc460/tasks/abc460_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

두 배열의 크기를 각각 N, M이라 하자.

정렬 후 투 포인터를 사용할 경우 O(N \* log_2(N) + M \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 최대 O(N + M)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) |           시간 복잡도            | 공간 복잡도 |
| :----------: | :------------------------------: | :---------: |
|      41      | O(N \* log_2(N) + M \* log_2(M)) |  O(N + M)   |

두 배열을 정렬 후 조건에 맞춰 가장 작은 shari 부터 순회하며 현재 선택 가능한 가장 작은 neta를 선택한다.

만약 조건을 충족할 수 있는 경우 정답에 추가하고 포인터를 증가시킨다.

```cpp
int solution(vector<int>& shari, vector<int>& neta) {
  int sSize = shari.size();
  int nSize = neta.size();

  int answer = 0;

  // the weight of the neta must be at most twice the weight of the shari
  sort(shari.begin(), shari.end());
  sort(neta.begin(), neta.end());

  int index = 0;
  for (int& s : shari) {
    if (s * 2 >= neta[index]) {
      index++;
      answer++;
    }

    if (index == nSize) break;
  }

  return answer;
}
```

## 고생한 점
