# 4071. Minimum Rotations to Dial a Number II

[링크](https://leetcode.com/problems/minimum-rotations-to-dial-a-number-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

가장 유리한 위치를 순회를 통해 구할 수 있다. 이에 O(N)의 시간 복잡도를 사용한다.

이후 해당 위치부터 suffix를 reverse한 점수를 구하는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

점수를 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |    O(N)     |    O(1)     |

특정 위치 i번째부터 suffix를 뒤집었을 때 변화하는 비용은 다음과 같다.

- i-1과 맨 마지막 문자의 shift비용
- i-1과 i번째 문자의 shift비용

해당 비용이 변경되었을 때 최소 비용을 계산할 수 있고, 이를 이용해 정답을 구한다.

이 때 변화하는 비용의 최소값을 구하고, 아무것도 변화가 없을 때 비용을 알고 있으면 두 값을 이용해 정답을 구할 수 있다.

```cpp
int getCount(char a, char b) {
  int aa = min(a, b) - '0', bb = max(a, b) - '0';

  return min(bb - aa, aa + 10 - bb);
}

int minRotations(int n, string s) {
  int diff = INT_MAX;
  int answer = 0;

  for (int i = n - 1; i >= 0; i--) {
    char before = i == 0 ? '0' : s[i - 1];
    int beforeDiff = getCount(s[i], before);
    int curDiff = getCount(s[n - 1], before) - beforeDiff;

    answer += beforeDiff;
    if (curDiff < diff) {
      diff = curDiff;
    }
  }

  return answer + diff;
}
```

## 고생한 점
