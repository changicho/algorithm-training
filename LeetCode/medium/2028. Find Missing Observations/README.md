# 2028. Find Missing Observations

[링크](https://leetcode.com/problems/find-missing-observations/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 rolls의 크기를 M, 굴려질 주사위의 횟수룰 N이라 하자.

평균값과 총 주사위를 굴리는 횟수를 이용해 나와야 하는 합과 이미 채워진 합을 구할 수 있다.

이후 N과 해당 차이값을 이용해 크기가 N인 주사위 눈 배열을 만들 수 있는지 확인한다.

이는 나머지와 몫을 이용할 경우 O(N)의 시간 복잡도로 구현 가능하다.

따라서 총 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

정답 배열에 O(N)의 공간 복잡도를 사용한다.

### 나머지

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      84      |  O(N + M)   |    O(N)     |

이미 굴려진 주사위의 눈 들의 합과 채워야 하는 합을 구한다.

만약 해당 차이가 유효하지 않다면 빈 배열을 반환한다.

유효한 경우라면 정답 배열을 만들 수 있는 경우이다.

해당 차이를 D라고 했을 때 채워야 하는 수들을 아래 2가지 부분으로 나눌 수 있다.

- N / D
- N % D

이를 위해 크기가 N인 배열의 값들을 N / D로 설정한 뒤 N % D개의 값을 1씩 증가시킨다.

```cpp
vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
  int m = rolls.size();
  int size = m + n;

  int diff = size * mean - accumulate(rolls.begin(), rolls.end(), 0);

  // invalid diff check
  if (diff > 6 * n || n > diff) return {};

  int q = diff / n, r = diff % n;

  vector<int> answer(n, q);
  for (int i = 0; i < r; i++) {
    answer[i]++;
  }
  return answer;
}
```

## 고생한 점
