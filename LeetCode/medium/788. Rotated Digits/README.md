# 788. Rotated Digits

[링크](https://leetcode.com/problems/rotated-digits/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

각 수를 순회하며 회전후 비교하는데 O(N \* log_10(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 수를 회전하는데 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도 |
| :----------: | :---------------: | :---------: |
|      0       | O(N \* log_10(N)) |    O(1)     |

각 수를 직접 회전시키며 비교 후 정답을 센다.

```cpp
int moveTo[10] = {
    0,
};

int rotate(int num) {
  int ret = 0;
  for (int d = 1; d <= num; d *= 10) {
    int cur = num % (d * 10) / d;
    if (moveTo[cur] == -1) return -1;

    ret += moveTo[cur] * d;
  }
  return ret;
}

int rotatedDigits(int n) {
  for (int i = 0; i <= 9; i++) {
    moveTo[i] = -1;
  }
  moveTo[0] = 0;
  moveTo[1] = 1;
  moveTo[2] = 5;
  moveTo[5] = 2;
  moveTo[6] = 9;
  moveTo[8] = 8;
  moveTo[9] = 6;

  int answer = 0;
  for (int i = 1; i <= n; i++) {
    int converted = rotate(i);

    if (converted == -1) continue;
    if (converted != i) {
      answer++;
    }
  }
  return answer;
}
```

## 고생한 점
