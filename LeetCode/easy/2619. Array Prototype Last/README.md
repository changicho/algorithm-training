# 2619. Array Prototype Last

[링크](https://leetcode.com/problems/array-prototype-last/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 길이 N을 this.length로 접근 가능하다.

또한 배열의 값 또한 this로 접근 가능하므로 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

배열의 값을 this로 접근 가능하므로 O(1)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      52      |    O(1)     |    O(1)     |

배열의 원소와 길이를 this로 접근 가능하므로 last() 함수를 구현한다.

```javascript
Array.prototype.last = function () {
  if (this.length === 0) return -1;
  return this[this.length - 1];
};
```

## 고생한 점
