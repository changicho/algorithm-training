# 696. Count Binary Substrings

[링크](https://leetcode.com/problems/count-binary-substrings/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자. (N <= 1e5)

완전 탐색을 수행할 경우 O(N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

순회를 사용할 경우 O(N)의 시간 복잡도로 해결할 수 있다.


### 공간 복잡도

각 index마다 각각의 방향으로 연속된 0과 1의 개수를 저장할 경우 O(N)의 공간 복잡도를 사용한다.

순회하며 이전과 현재의 연속된 0과 1의 개수만 저장할 경우 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

직전 연속된 0 또는 1의 갯수와 현재 연속된 0 또는 1의 갯수를 저장한다.

각 경우마다 직전 연속된 0 또는 1의 갯수가 현재 연속된 0 또는 1의 갯수보다 크거나 같을 경우 answer를 증가시킨다.

```cpp
int countBinarySubstrings(string s) {
  int size = s.size();

  int before = 0;
  int cur = 1;
  int answer = 0;

  for (int i = 1; i < size; i++) {
    if (s[i] == s[i - 1]) {
      cur++;
    } else {
      before = cur;
      cur = 1;
    }

    if (before >= cur) answer++;
  }

  return answer;
}
```

## 고생한 점
