# 3005. Count Elements With Maximum Frequency

[링크](https://leetcode.com/problems/count-elements-with-maximum-frequency/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 수를 count 한 뒤 가장 많이 나온 count와 같은 갯수를 찾아야 한다.

이를 위해 count를 구하는데 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

각 수의 범위는 1 ~ 100까지이다. 이를 위해 배열을 선언할 경우 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

각 수를 순회하며 count를 증가시킨다.

이 때 maximum이 갱신될 때 정답을 갱신한다.

만약 현재 count가 maximum과 같다면 정답을 증가시킨다.

```cpp
int maxFrequencyElements(vector<int>& nums) {
  int answer = 0;
  int maxFreq = 0;
  int counts[101] = {
      0,
  };

  for (int& num : nums) {
    counts[num]++;

    int count = counts[num];
    if (count > maxFreq) {
      answer = count;
      maxFreq = count;
    } else if (count == maxFreq) {
      answer += count;
    }
  }

  return answer;
}
```

## 고생한 점
