# 2951. Find the Peaks

[링크](https://leetcode.com/problems/find-the-peaks/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 mountain의 크기를 N이라 하자.

모든 index를 순회하며 peak인지 판별할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

정답의 공간에 O(N)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |    O(N)     |    O(N)     |

index를 1부터 N-1까지 순회하며 peak인지 판별한다.

```cpp
vector<int> findPeaks(vector<int>& mountain) {
  int size = mountain.size();

  vector<int> answer;
  for (int i = 1; i < size - 1; i++) {
    if (mountain[i - 1] < mountain[i] && mountain[i] > mountain[i + 1]) {
      answer.push_back(i);
    }
  }
  return answer;
}
```

## 고생한 점
