# 4021. Minimum Operations to Make a Rotated Palindrome I

[링크](https://leetcode.com/problems/minimum-operations-to-make-a-rotated-palindrome-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

rotate연산에 따라 매번 최소 비용을 계산할 수 있다. 이 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

완전 탐색에 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     199      |   O(N^2)    |    O(1)     |

모든 rotate 횟수에 대해서 탐색을 시작하며, 이 경우 palindrome이 되기 위해 비교해야 하는 쌍들을 비교 후 최소 변환 횟수를 더한다.

이 중 각 rotate에 따른 최소 변환 횟수의 합을 정답으로 갱신한다.

```cpp
int minOperations(string s) {
  int size = s.size();
  int answer = INT_MAX;

  for (int rotate = 0; rotate < size; rotate++) {
    int curDiff = 0;
    for (int i = 0; i < size / 2; i++) {
      char left = s[(rotate + i) % size];
      char right = s[(size - 1 + rotate - i + size) % size];

      if (left != right) {
        int diff = max(left, right) - min(left, right);

        diff = min(diff, 26 - diff);
        curDiff += diff;
      }
    }

    answer = min(answer, curDiff + rotate);
  }

  return answer;
}
```

## 고생한 점
