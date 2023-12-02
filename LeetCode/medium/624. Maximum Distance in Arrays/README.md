# 624. Maximum Distance in Arrays

[링크](https://leetcode.com/problems/maximum-distance-in-arrays/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열 arrays의 크기를 N이라 하자.

모든 경우를 순회할 경우 O(N^2)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

각 배열을 순회하며 최대값, 최소값을 갱신하며 정답을 갱신할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

최대값 최소값을 저장하는 데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     267      |    O(N)     |    O(1)     |

만약 현재까지의 maximum, minimum 값을 알고 있을 경우 현재 배열에서 정답의 후보는 다음과 같다.

- abs(back - minimum)
- abs(maximum - front)

이 때 같은 배열의 두 값을 선택할 수 없으므로 직전까지 순회한 값들 중에서 선택해야 한다.

즉 현재 배열의 front, back을 이용해 차이가 큰 값으로 정답을 갱신할 수 있다.

이후 현재까지 순회한 maximum, minimum 값을 갱신한다.

이 과정에서 정답에 포함되는 값 (front, back)중 하나는 maximum, minimum으로 갱신되므로 이후 순회시 정답에 포함된다.

```cpp
int maxDistance(vector<vector<int>>& arrays) {
  int size = arrays.size();

  int minimum = arrays[0].front();
  int maximum = arrays[0].back();

  int answer = 0;
  for (int i = 1; i < size; i++) {
    int fromBack = abs(arrays[i].back() - minimum);
    int fromFront = abs(maximum - arrays[i].front());

    answer = max(answer, fromBack);
    answer = max(answer, fromFront);

    minimum = min(minimum, arrays[i].front());
    maximum = max(maximum, arrays[i].back());
  }

  return answer;
}
```

## 고생한 점
