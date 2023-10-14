# Problem A1: Cheeseburger Corollary 1

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2023/practice-round/problems/A1)

| 난이도 |
| :----: |
|  8 pt  |

## 설계

### 시간 복잡도

입력받은 싱글패티, 더블패티의 수를 각각 S, D라 하자.

위 값을 이용해 K데커를 만들 수 있는지 판단해야 한다.

이는 가지고 있는 재료의 수를 세서 판별하면 되므로 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

가지고 있는 재료를 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 수학

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(1)     |    O(1)     |

S와 D를 이용해 가진 재료의 수를 모두 구한다.

K데크 버거를 만들기 위해 필요한 재료의 수는 다음과 같다.

- K+1개의 빵
- K개의 치즈와 번

이를 이용해 판별한다.

```cpp
bool solution(int s, int d, int k) {
  int bun = 0;
  int cheese = 0;
  int patty = 0;

  bun += s * 2;
  bun += d * 2;

  cheese += s;
  cheese += d * 2;

  patty += s;
  patty += d * 2;

  int needB = k + 1, needC = k, needP = k;

  if (bun >= needB && cheese >= needC && patty >= needP) return true;
  return false;
}
```

## 고생한 점
