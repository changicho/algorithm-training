# 2214. Minimum Health to Beat Game

[링크](https://leetcode.com/problems/minimum-health-to-beat-game/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 damage의 크기를 N이라 하자.

damage중 가장 큰 값에 armor를 적용할 경우 총 합이 가장 작게 된다.

가장 큰 값을 검색하는데 O(N), sum을 구하는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

입력받은 damage를 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     113      |    O(N)     |    O(1)     |

가장 큰 damage에 armor를 적용하는 쪽이 가장 damage의 합을 줄일 수 있다.

```cpp
long long minimumHealth(vector<int>& damage, int armor) {
  int size = damage.size();

  long long health = 0;

  int maxI = 0;
  for (int i = 0; i < size; i++) {
    if (damage[i] > damage[maxI]) {
      maxI = i;
    }
  }

  damage[maxI] = max(0, damage[maxI] - armor);

  for (int& d : damage) {
    health += d;
  }

  return health + 1;
}
```

## 고생한 점
