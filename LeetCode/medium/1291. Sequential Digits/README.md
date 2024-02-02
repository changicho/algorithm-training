# 1291. Sequential Digits

[링크](https://leetcode.com/problems/sequential-digits/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 두 수 low, high의 범위를 N이라 하자. (N <= 10^9)

각 자리수별로 valid한 경우를 판별해야 한다.

최대 9자리까지 가능하며 이를 모든 수를 탐색할 경우 O(N)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

자리에 따른 만들 수 있는 수들이 정해져 있으므로 이를 이용해 풀이할 수 있다.

이 경우 모든 가능한 갯수는 100개 미만임이 보장된다.

따라서 시간 복잡도는 O(1)이다.

### 공간 복잡도

정답에 들어가는 수의 최대 자리수는 10 이하이다. 따라서 각 경우 문자열로 구성해도 O(1)의 공간 복잡도를 사용한다.

가능한 경우들만 탐색할 경우 정답에 O(1)의 공간 복잡도를 사용한다.

### 자리수 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(1)     |    O(1)     |

low와 high의 자리 수를 구한 뒤 해당 자리수로 만들 수 있는 모든 수를 탐색한다.

```cpp
vector<int> sequentialDigits(int low, int high) {
  vector<int> answer;

  int lowLen = log10(low) + 1, highLen = log10(high) + 1;

  for (int length = lowLen; length <= highLen; length++) {
    for (int start = 1; start <= 9 - length + 1; start++) {
      string cur = string(length, start + '0');
      for (int i = 1; i < length; i++) {
        cur[i] = cur[i - 1] + 1;
      }

      int num = stoi(cur);
      if (low <= num && num <= high) {
        answer.push_back(num);
      }
    }
  }
  return answer;
}
```

## 고생한 점
