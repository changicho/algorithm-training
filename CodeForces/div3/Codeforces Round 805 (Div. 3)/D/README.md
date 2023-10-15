# D. Not a Cheap String

[링크](https://codeforces.com/contest/1702/problem/D)

| 난이도 |
| :----: |
| \*1000 |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

각 글자중 'z'가 가장 값이 크고 'a'가 가장 값이 작다.

따라서 'z'부터 'a'까지 순회하며 문자열에서 이를 제거했을 때 P보다 총 합이 작아지는지 판단한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 문자가 삭제되었는지 위치를 판단할 O(N)크기의 배열을 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      31      |    O(N)     |    O(N)     |

각 문자마다의 score를 계산하고 총 합을 구한다.

이후 'z'부터 'a'까지 순회하며 문자열에서 해당 문자를 없앴을 때 점수가 P이하가 될때까지 이를 반복한다.

여기서 'z'부터 순회하는 이유는 같은 한 글자를 제거했을 때 가장 cost를 크게 줄일 수 있는 곳부터 순회하기 위함이다.

```cpp
string solution(string &w, int p) {
  vector<int> indexes[27];
  vector<bool> isDeleted(w.size(), false);

  int scoreSum = 0;
  for (int i = 0; i < w.size(); i++) {
    char c = w[i];
    indexes[c - 'a'].push_back(i);
    scoreSum += (c - 'a' + 1);
  }

  for (char c = 'z'; c >= 'a'; c--) {
    while (scoreSum > p && indexes[c - 'a'].size() > 0) {
      int target = indexes[c - 'a'].back();
      indexes[c - 'a'].pop_back();

      isDeleted[target] = true;
      scoreSum -= (c - 'a' + 1);
    }
  }

  string ret = "";
  for (int i = 0; i < w.size(); i++) {
    if (isDeleted[i]) continue;
    ret += w[i];
  }
  return ret;
}
```

## 고생한 점
