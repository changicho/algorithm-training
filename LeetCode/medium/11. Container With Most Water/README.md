# 11. Container With Most Water

[링크](https://leetcode.com/problems/container-with-most-water/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

N은 최대 10^5 이다.

브루트 포스 방법을 사용할 경우 시간 복잡도는 O(N^2)가 되므로 제한시간 내에 불가능하다.

따라서 투 포인터를 이용해 O(N) 이내에 풀이한다.

### 공간 복잡도

높이는 최대 10^4이다.

### 투 포인터

물을 채우려는 범위의 시작점과 끝점을 left, right라고 하자.

left = 0, right = height.size() - 1로 설정한다. (각 맨 끝 index로 설정함)

그리고 가장 큰 답을 찾기 위해 left와 right를 이동시킨다. (left는 right보다 작아야함)

- 현재 left, right에 위치한 막대 중 left가 작은 경우 : left를 오른쪽으로 이동.
- 현재 left, right에 위치한 막대 중 right가 작은 경우 : right를 왼쪽으로 이동.
- 같은 경우 : 어느쪽도 가능

이 때 두 막대의 크기가 같은 경우 어느쪽도 이동이 가능한 이유는 다음과 같다.

- left ~ right 범위 안에 정답이 존재하는 경우, 두 막대는 left, right에 위치한 막대보다 길이가 긴것이 보장된다.
- left ~ right 가 같은 경우 위 조건을 제외한 경우 left ~ right 범위일때가 최대이다.

```cpp
int maxArea(vector<int>& height) {
  int answer = 0;

  int left = 0;
  int right = height.size() - 1;

  while (left < right) {
    int curAnswer = (right - left) * min(height[left], height[right]);
    answer = max(curAnswer, answer);

    if (height[left] <= height[right]) {
      left += 1;
    } else {
      right -= 1;
    }
  }

  return answer;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      80      |

## 고생한 점
