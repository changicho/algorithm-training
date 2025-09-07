# 3516. Find Closest Person

[링크](https://leetcode.com/problems/find-closest-person/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 세 좌표에서 가장 가까운 사람을 구한다.

이에 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

O(1)의 공간 복잡도를 사용한다.

### 대소비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

```cpp
int findClosest(int x, int y, int z) {
  int diffX = abs(z - x);
  int diffY = abs(z - y);

  if (diffX < diffY) {
    return 1;
  } else if (diffX > diffY) {
    return 2;
  } else {
    return 0;
  }
}
```

## 고생한 점
