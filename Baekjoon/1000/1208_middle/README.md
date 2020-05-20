# 1208. 부분수열의 합 2

[링크](https://www.acmicpc.net/problem/1208)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold II |   21.659    |

## 설계

### 시간 복잡도

부분 수열은 N개의 수 중에서 만들 수 있는 조합의 경우이므로 2^N 만큼의 시간복잡도가 소요된다.

이 경우 N은 최대 40이며 2^40은 1,099,511,627,776 이므로 시간 내에 풀이가 불가능하다.

따라서 수열을 두 부분으로 나눠서 풀이해야 한다.

- Meet in the middle

수열의 합을 왼쪽 수열의 합 + 오른쪽 수열의 합 으로 분리해 생각해보자.

한쪽 수열의 합의 갯수를 구하는 데에는 2^20 번이 소요되며 이는 1,048,576 번 이므로 제한 시간 내에 가능하다.

이를 왼쪽, 오른쪽 두번 구하더라도 O(2,097,152‬) 이므로 시간 내에 충분하다.

### 공간복잡도

정답 answer의 범위에 대해 생각해보자.

왼쪽 수열과 오른쪽 수열의 수들이 모두 절대 값은 같고 부호만 반대일 경우 가능한 정답의 수는 다음과 같다.

```cpp
[1, 1, 1, 1, .... , -1, -1, -1, ...];
```

1,099,511,627,776

이는 int형의 범위를 초과하므로 long long 형태를 선언한다.

### 나누어 생각하기

하나의 수열은 왼쪽 수열과 오른쪽 수열로 나누어 생각할 수 있다.

이 때 나누는 기준점은 N/2 이다.

따라서 수열의 합은 다음과 같다.

왼쪽 수열의 합 + 오른쪽 수열의 합

따라서 수열의 합이 S가 되는 경우를 구하면 된다.

DFS로 왼쪽 수열로 가능한 합의 경우의 수를 모두 구한다.

DFS로 오른쪽 수열로 가능한 합의 경우를 구하고 S - (현재 합)인 수가 왼쪽 수열로 만든 합에 존재하는 지 찾는다.

존재하는 경우 그 수만큼 정답을 증가시킨다.

여기서 S가 0인 경우는 정답에서 1을 감소시켜야하는데, 이는 왼쪽과 오른쪽에서 가능한 조합에 아무것도 택하지 않는 0인 경우가 포함되기 때문이다.

DFS탐색은 다음과 같다.

```cpp
void make_part_first(int index, int sum) {
  if (index == N / 2) {
    // 왼쪽 수열에서 나올 수 있는 합 sum을 저장
    return;
  }

  make_part_first(index + 1, sum);
  make_part_first(index + 1, sum + arr[index]);
}

void make_part_second(int index, int sum) {
  if (index == N) {
    // 오른쪽 수열에서 나올 수 있는 sum
    // S - sum 이 왼쪽수열에서 나올 수 있는지 확인 후 answer 를 증가
    return;
  }

  make_part_second(index + 1, sum);
  make_part_second(index + 1, sum + arr[index]);
}
```

여기서 왼쪽 경우의 수를 Map 혹은 vector에 저장 가능하다.

```cpp
// Map을 이용한 방법
if (index == N / 2) {
  first[sum] += 1;
  return;
}

if (index == N) {
  answer += first[S - sum];
  return;
}
```

```cpp
// upper_bound, lower_bound를 이용한 방법
if (index == N / 2) {
  first.push_back(sum);
  return;
}

if (index == N) {
  answer += upper_bound(first.begin(), first.end(), S - sum) -
            lower_bound(first.begin(), first.end(), S - sum);
  return;
}
```

여기서 upper_bound를 이용하는 경우가 시간과 메모리가 더 적게든다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     336      |       8        |

## 고생한 점
