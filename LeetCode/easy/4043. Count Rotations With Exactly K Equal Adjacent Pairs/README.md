# 4043. Count Rotations With Exactly K Equal Adjacent Pairs

[링크](https://leetcode.com/problems/count-rotations-with-exactly-k-equal-adjacent-pairs/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

완전 탐색을 사용할 경우 O(N^2)의 시간 복잡도를 사용한다.

shift하는 만큼만 갱신하며 탐색할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 수를 세는데 O(1)의 공간 복잡도를 사용한다.

### shift 이동

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

한번도 shift하지 않은 경우의 점수를 구한다.

이후 한칸씩 shift해가며 변화하는 점수를 구하고 이를 N번 반복하며 정답을 갱신한다.

```cpp
int countRotations(string s, int k) {
  int size = s.size();

  int answer = 0;
  int same = 0;
  for (int i = 0; i < size - 1; i++) {
    if (s[i] == s[i + 1]) {
      same++;
    }
  }

  for (int start = 0; start < size; start++) {
    if (same == k) answer++;

    if (s[start] == s[start + 1]) {
      same--;
    }
    if (s[(start + size - 1) % size] == s[(start + size) % size]) {
      same++;
    }
  }

  return answer;
}
```

## 고생한 점
