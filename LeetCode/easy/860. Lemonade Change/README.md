# 860. Lemonade Change

[링크](https://leetcode.com/problems/lemonade-change/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 bills의 크기를 N이라 하자.

각 주문 별로 거스름돈의 갯수를 센 뒤 불가능한 경우를 찾는다.

이 경우 순회에 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

거스름돈의 종류는 3가지 이므로 공간 복잡도는 O(1)이다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      81      |    O(N)     |    O(1)     |

각 주문 별로 거스름돈을 계산하며, 불가능한 경우를 찾는다.

이 때 20원을 받은 경우 15원을 거슬러줘야 하며 이는 다음과 같은 2가지 경우가 가능하다.

- 10 + 5
- 5 + 5 + 5

여기서 5원을 많이 가지는 경우가 유리하므로 최대한 10원을 사용한다.

```cpp
bool lemonadeChange(vector<int>& bills) {
  int five = 0, ten = 0, twenty = 0;

  for (int& bill : bills) {
    switch (bill) {
      case 5: {
        five++;
        break;
      }
      case 10: {
        five--;
        ten++;
        break;
      }
      case 20: {
        if (ten >= 1 && five >= 1) {
          ten--;
          five--;
          twenty++;
        } else {
          five -= 3;
          twenty++;
        }

        break;
      }
    }

    if (five < 0 || ten < 0) return false;
  }
  return true;
}
```

## 고생한 점
