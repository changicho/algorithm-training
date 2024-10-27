# 2938. Separate Black and White Balls

[링크](https://leetcode.com/problems/separate-black-and-white-balls/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이므로 제한시간 내에 불가능하다.

투 포인터를 사용해 이동 위치를 최적화한다. 이 경우 시간 복잡도는 O(N)이다.

한번의 순회로 이동하는 횟수를 구할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

투 포인터를 사용할 경우 O(1)의 공간 복잡도가 필요하다.

순회로 풀이할 경우 O(1)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      39      |    O(N)     |    O(1)     |

현재 흰색과 검은색을 교환해야 하는 위치를 각각 wI, bI라고 하자.

맨 오른쪽부터 이를 탐색하며 현재 바꿔야 하는 위치를 찾고 이를 교환한다.

이를 두 index를 못 찾을때 까지 반복한다.

```cpp
long long minimumSteps(string s) {
  int size = s.size();

  int wI = size - 1, bI = size - 1;

  long long answer = 0;
  while (bI > 0 && wI > 0) {
    while (wI > 0 && s[wI] != '0') {
      wI--;
    }
    while ((wI < bI) || (bI >= 0 && s[bI] != '1')) {
      bI--;
    }
    if (bI == -1) break;

    swap(s[wI], s[bI]);
    answer += (wI - bI);
  }

  return answer;
}
```

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      32      |    O(N)     |    O(1)     |

왼쪽부터 순회하며 현재 위치에서 0을 만난 경우 이는 이전까지 나온 black이 결국 이동해야 하는 횟수이다.

따라서 현재 마주친 0에 대해 black이 해당 0을 이동하는 횟수를 구한다.

현재까지 나온 black의 개수를 세고, 이를 이용해 이동해야 하는 횟수를 계산한다.

```cpp
long long minimumSteps(string s) {
  int size = s.size();

  long long answer = 0;
  int blackBallCount = 0;
  for (char &c : s) {
    if (c == '0') {
      answer += blackBallCount;
    } else {
      blackBallCount++;
    }
  }

  return answer;
}
```

## 고생한 점
