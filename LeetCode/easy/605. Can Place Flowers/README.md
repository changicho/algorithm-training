# 605. Can Place Flowers

[링크](https://leetcode.com/problems/can-place-flowers/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

flowerbed의 크기를 N이라 하자. (N <= 2 \* 10^4)

가능한 모든 경우를 탐색할 경우 O(2^N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

탐욕 알고리즘을 이용해 가능한 가장 왼쪽에 꽃을 심으며 가능한지 판별한다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

입력받은 배열을 사용할 경우 별도의 추가 공간을 필요로 하지 않는다.

따라서 O(1)의 공간 복잡도를 사용한다.

### 그리디 & one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(1)     |

각 index를 왼쪽부터 순회하며 현재 위치에 꽃을 놓을 수 있는 경우 꽃을 놓는다.

```cpp
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
  int size = flowerbed.size();

  int planted = 0;
  for (int i = 0; i < size; i++) {
    if (flowerbed[i] == 1) continue;

    bool isPossible = true;
    if (i - 1 >= 0 && flowerbed[i - 1] == 1) isPossible = false;
    if (i + 1 < size && flowerbed[i + 1] == 1) isPossible = false;

    if (isPossible) {
      flowerbed[i] = 1;
      planted++;
    }
  }

  return planted >= n;
}
```

## 고생한 점

양 끝에 꽃을 놓아야 하는 경우, 놓아도 되는지 여부를 판별하는 로직에서 실수가 생김

(이미 꽃이 심어진 경우 건너뛰기)
