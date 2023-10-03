# 1512. Number of Good Pairs

[링크](https://leetcode.com/problems/number-of-good-pairs/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 숫자별 갯수를 센 뒤 이를 이용해 정답을 구할 수 있다.

hash map을 이용해 셀 경우 O(N)의 시간 복잡도를 사용한다.

정렬을 이용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

정렬을 사용할 경우 최대 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

특정 숫자가 나타나는 index들의 집합을 I라 하자.

I에서 2개를 고르는 쌍의 갯수는 (I의 크기)C2이다.

따라서 이는 I \* (I-1) / 2 로 구할 수 있다.

hash map을 이용해 각 숫자들의 갯수를 세고 정답에 더한다.

```cpp
int numIdenticalPairs(vector<int> &nums) {
  int answer = 0;
  unordered_map<int, int> um;

  for (int &num : nums) {
    um[num]++;
  }

  for (auto &[key, val] : um) {
    answer += (val * (val - 1)) / 2;
  }
  return answer;
}
```

## 고생한 점
