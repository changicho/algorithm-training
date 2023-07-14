# 49995. 쿠키 구입

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/49995)

| 난이도 |
| :----: |
|  lv4   |

## 설계

### 시간 복잡도

cookie의 크기를 N이라 하자.

연속된 범위에서 두 합이 같아야 한다. 중앙점을 이동시키며 각 경우마다 투 포인터를 사용할 경우 정답을 구할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

투 포인터를 사용할 경우 O(1)의 공간 복잡도가 필요하다.

### 투 포인터

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|   O(N^2)    |    O(1)     |

정답 범위를 l ~ r이고 이를 두 영역으로 쪼갰을 때 중앙점을 mid라 하자.

- l ~ mid
- mid+1 ~ r

이 때 두 영역의 합이 같아야 한다.

mid, mid+1을 기준점으로 투 포인터 알고리즘을 사용해 두 영역의 합을 갱신하며 탐색한다.

이 때 합이 적은 쪽영역에 수를 추가해 더해나가며 탐색하며, 만약 더이상 탐색 불가능한 경우 탐색을 중지한다.

이를 이용해 각 mid를 순회하며 투 포인터 알고리즘을 사용할 수 있다.

이를 구현하면 다음과 같다.

```cpp
int solution(vector<int> cookie) {
  int size = cookie.size();

  int answer = 0;
  for (int mid = 0; mid < size - 1; mid++) {
    int leftI = mid, rightI = mid + 1;
    int leftSum = cookie[leftI], rightSum = cookie[rightI];

    while (true) {
      if (leftSum == rightSum) {
        answer = max(answer, leftSum);
      }

      if (leftSum < rightSum) {
        leftI--;
        if (leftI < 0) break;
        leftSum += cookie[leftI];
      } else {
        rightI++;
        if (rightI >= size) break;
        rightSum += cookie[rightI];
      }
    }
  }

  return answer;
}
```

## 고생한 점
