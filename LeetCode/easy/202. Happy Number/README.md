# 202. Happy Number

[링크](https://leetcode.com/problems/happy-number/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

숫자의 범위는 2^31 - 1 까지이다. 이는 2,147,483,647 이며 10자리 숫자이다.

10자리 숫자에 대해서 이전에 나온 값이 나오지 않을 때 까지의 연산의 최대 횟수는 16이다.

연산 중에 이전에 나온 값이 다시 나올 수 있으며 이 경우에는 무한 사이클에 빠지게 된다.

이를 별도로 처리할 경우 시간 복잡도는 O(1) 이다.

### 공간 복잡도

각 연산마다 최악의 경우도 int형의 범위를 넘지 않는다. 이는 10자리 숫자에서 모두 9로 채워진 최악의 경우도 연산을 수행하면 1000 이하이기 때문이다.

이전에 나온 값이 다시 나올 수 있기 때문에 이를 저장해야 한다.

이 연산의 횟수는 최대 16번 이므로 필요한 공간 복잡도는 O(1)이다.

### 시뮬레이션

> 0ms

- 시간 복잡도 : O(1)
- 공간 복잡도 : O(1)

이전에 방문한 숫자가 나올때 까지, 혹은 1이 될 때까지 연산을 반복한다.

```cpp
bool isHappy(int n) {
  unordered_set<int> s;

  while (s.find(n) == s.end()) {
    if (n == 1) {
      return true;
    }
    s.insert(n);

    int cur = 0;
    while (n) {
      int target = n % 10;
      cur += target * target;
      n /= 10;
    }
    n = cur;
  }

  return false;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
