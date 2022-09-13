# Problem A: Second Hands

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2022/qualification-round/problems/A)

| 난이도 |
| :----: |
|  9 pt  |

## 설계

### 시간 복잡도

입럭된 숫자의 갯수를 N이라 하자.

우선 각 수를 순회하며 갯수를 센다. 이에 O(N)의 시간 복잡도를 사용한다.

이후 각 수를 중복되는것 없이 K개 이상 두 공간에 놓을 수 있는지 판단한다.

따라서 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

숫자의 갯수를 세기 위해 총 O(N)의 공간 복잡도를 사용한다.

### 브루트 포스

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

만약 입력받은 수가 2 \* K 보다 작은 경우 정답을 만족하지 않는다.

이후 N개의 수를 세며 3개 이상의 동일한 수가 나타나는 경우 정답을 생성할 수 없다.

```cpp
bool solution(int n, int k, vector<int>& s) {
  if (n > k * 2) return false;

  unordered_map<int, int> counts;
  for (int& num : s) {
    counts[num]++;

    if (counts[num] > 2) return false;
  }

  return true;
}
```

## 고생한 점
