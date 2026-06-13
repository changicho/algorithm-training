# 3751. Total Waviness of Numbers in Range I

[링크](https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 숫자중 큰값을 N이라 하자.

완전 탐색을 수행할 경우 O(N \* log_10(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

완전 탐색에 문자열 변환에 O(log_10(N))의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도  |
| :----------: | :---------------: | :----------: |
|      54      | O(N \* log_10(N)) | O(log_10(N)) |

범위에 속하는 수를 직접 순회하며 정답을 센다.

```cpp
int count(int num) {
  int ret = 0;

  string s = to_string(num);
  int size = s.size();

  for (int i = 1; i < size - 1; i++) {
    if (s[i - 1] < s[i] && s[i] > s[i + 1]) {
      ret++;
    } else if (s[i - 1] > s[i] && s[i] < s[i + 1]) {
      ret++;
    }
  }
  return ret;
}

int totalWaviness(int num1, int num2) {
  int answer = 0;
  for (int num = num1; num <= num2; num++) {
    answer += count(num);
  }
  return answer;
}
```

## 고생한 점
