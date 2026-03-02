# 1461. Check If a String Contains All Binary Codes of Size K

[링크](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N, 입력받은 수를 K라 하자.

슬라이딩 윈도우를 사용해 각 K길이의 문자열을 확인할 수 있다.

이를 hash set을 이용할 경우 O(N \* K)의 시간 복잡도를 사용한다.

각 비트셋을 숫자로 변환해 저장할 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set, 비트셋에 O(2^K)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우 & 비트셋

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |   O(2^K)    |

길이가 K인 문자열을 숫자로 변환해 저장한다.

한칸씩 이동하므로 비트를 이동 후 현재 비트를 더한 숫자를 만든 뒤 2^K로 나눈 나머지를 이용해 윈도우를 저장한다.

각 윈도우마다 방문 여부를 별도 배열로 저장한다.

이후 방문한 윈도우의 종류가 2^K와 같은지 확인한다.

```cpp
bool hasAllCodes(string s, int k) {
  int size = s.size();
  if (size < k) return false;

  int limit = 1 << k;
  bool visited[1048576] = {false};
  int visitCount = 0;

  int temp = 0;
  for (int i = 0; i < k - 1; i++) {
    temp = temp * 2 + (s[i] - '0');
  }
  for (int i = k - 1; i < size; i++) {
    temp = temp * 2 + (s[i] - '0');

    temp %= limit;
    if (visited[temp] == false) visitCount++;
    visited[temp] = true;
  }

  return visitCount == limit;
}
```

## 고생한 점
