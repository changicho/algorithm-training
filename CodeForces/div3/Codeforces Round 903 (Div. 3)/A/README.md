# A. Don't Try to Count

[링크](https://codeforces.com/contest/1881/problem/A)

## 설계

### 시간 복잡도

입력받은 두 문자열의 길이를 N, M이라 하자.

증가시킬 수 있는 문자열 X는 반복되는 패턴이므로 X를 M보다 크게 만들 수 있다.

이 때 M이상이 되는 최소횟수만큼 증가시키고 해당 문자열에서 S가 존재하는지 검색한다.

이에 O(N)의 시간 복잡도를 사용한다. 이후 탐색에 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

문자열이 증가할 수 있으므로 O(N + M)의 공간 복잡도를 사용한다.

### 완전 탐색

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(N + M)   |  O(N + M)   |

찾고자 하는 문자열이 등장할 수 있도록 X를 증가시킨다.

이후 증가시킨 문자열에서 찾고자하는 문자열이 존재하는지 확인한다.

```cpp
int solution(string x, string s) {
  int count = 0;
  while (x.size() < s.size()) {
    x += x;
    count++;
  }

  if (x.find(s) == string::npos) {
    x += x;
    count++;
  }

  if (x.find(s) == string::npos) {
    return -1;
  }

  return count;
}
```

## 고생한 점
