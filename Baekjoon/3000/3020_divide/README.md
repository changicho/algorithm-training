# 3020. 개똥벌레

[링크](https://www.acmicpc.net/problem/3020)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   40.018    |

## 설계

### 시간 복잡도

기둥의 갯수 N은 200,000, 기둥의 높이 H는 500,000 까지이다.

이를 전부 탐색할 경우 NH 이고 이는 제한 시간 내에 불가능하다.

기둥의 갯수를 정렬하고 이분탐색해 부셔야 하는 기둥의 갯수를 찾아 풀이할 경우 시간복잡도는

```cpp
logN * H = log(200,000) * 500,000 = 9,000,000
```

이므로 제한 시간 내에 충분하다.

### 공간 복잡도

N과 H 모두 int 형으로 충분하다.

### 이분 탐색

석순과 종유석이 순서대로 번갈아 나오므로, 이를 각각 vector에 저장한다.

이 때 종유석의 경우는 높이 H - 입력받은 높이 로 저장한다. (탐색을 편리하게 하기 위함);

석순과 종유석을 각각 오름차순으로 정렬한다.

높이 H를 0부터 H-1 까지 높이 h를 탐색한다.

최소 지점은 0으로 두고, 최대 지점을 H-1로 두었기 때문에 upper_bound를 사용한다.

석순에서는 현재 높이 h를 초과하는 종유석이 있는지 count한다.

종유석의 경우 현재 높이 h 미만의 종유석이 존재하는지 count한다.

```cpp
int caclul(int height) {
  int count = 0;

  int oddCount =
      odd.size() - (upper_bound(odd.begin(), odd.end(), height) - odd.begin());
  int evenCount =
      (upper_bound(even.begin(), even.end(), height) - even.begin());

  count += oddCount;
  count += evenCount;

  return count;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      60      |       4        |

## 고생한 점
