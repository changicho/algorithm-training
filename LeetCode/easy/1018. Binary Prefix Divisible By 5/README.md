# 1018. Binary Prefix Divisible By 5

[링크](https://leetcode.com/problems/binary-prefix-divisible-by-5/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

순회와 나머지를 이용해 풀이할 경우 O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

매번 prefix를 직접 계산할 경우 N이 10^5 이므로 자료형을 벗어난다.

따라서 나머지 연산을 이용해 풀이할 경우 O(1)의 공간 복잡도를 가진다.

정답에 O(N)의 공간 복잡도가 추가로 필요하다.

### 순회 & 나머지

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

prefix를 매번 계산한다. 이 때 5로 나눈 나머지 값만을 사용한다.

```cpp
vector<bool> prefixesDivBy5(vector<int>& nums) {
  vector<bool> answer;

  long long cur = 0;
  for (int& num : nums) {
    cur += num;

    answer.push_back(cur % 5 == 0);

    cur *= 2;
    cur %= 5;
  }
  return answer;
}
```

## 고생한 점
