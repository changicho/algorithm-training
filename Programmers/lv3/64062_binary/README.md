# 64062. 징검다리 건너기

[링크](https://programmers.co.kr/learn/courses/30/lessons/64062)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv3   |   927    |

## 설계

### 시간복잡도

징검다리의 크기는 최대 200,000, 내구도의 최대 값은 200,000,000

이 내구도를 하나하나 감소시킬 경우 최악의 경우 시간복잡도는 200,000,000 이므로 제한시간 내에 불가능하다.

따라서 내구도를 이분탐색해 제한시간 내에 풀이한다.

이 경우 시간 복잡도는

- 유효한지 길을 검사하는 N (200,000)
- stone을 이분탐색한 log_2(M) (200,000,000)

```cpp
200,000 * log_2(200,000,000) = 200,000 * 28 = 5,600,000‬
```

이므로 제한시간 내에 충분하다.

### 공간복잡도

정답은 200,000,000 이내 이므로 int형으로 선언한다.

### 이분 탐색

통과할 수 있는 명 수는, stone의 내구도 이다. (이는 내구도가 0이 되어 stone이 사라지고 길도 없어지면 더이상 통과할 수 없기 때문)

따라서 정답은 입력받은 stone의 내구도 중에 하나이다.

stone의 범위는 1 ~ 200,000,000이며 이를 이분탐색 한다.

이분 탐색은 다음과 같이 수행한다.

```cpp
int answer = 0;
int left = 0, right = LIMIT;

while (left <= right) {
  int mid = (left + right) / 2;

  if (check(stones, k, mid)) {
    answer = max(answer, mid);

    left = mid + 1;
  } else {
    right = mid - 1;
  }
}
```

이분탐색 할 때 현재 정답이 유효한지 검사하기 위한 함수를 생성한다.

위 함수는 각 돌들이 정답 (지나가는 인원)을 버티는지 검사하며 연속 K개의 stone이 불가능 한 경우 현재 정답이 불가능함을 return 한다.

```cpp
bool check(vector<int> stones, int k, int m) {
  int count = 0;

  for (int i = 0; i < stones.size(); i++) {
    if (stones[i] < m) {
      count++;

      if (count == k) {
        return false;
      }
    } else {
      count = 0;
    }
  }
  return true;
}
```

## 고생한 점

### greedy 알고리즘

다음 코드를 이용하는 경우 효율성 검사 13번에서 시간초과가 발생했다.

이유는 index는 N번만 증가하지만, 최악의 경우 K번씩 계속 검사하기 때문이다.

따라서 시간복잡도는 O(NK) 이며, 200,000 X 200,000,000 이다.

```cpp
int solution(vector<int> stones, int k) {
  int answer = LIMIT;

  int size = stones.size();
  int count = 0;
  int index = 0;

  while (index < size) {
    int max_index = index;

    for (int new_index = index; new_index < index + k; new_index++) {
      if (new_index >= size) {
        break;
      }

      if (stones[max_index] <= stones[new_index]) {
        max_index = new_index;
      }
    }

    if (stones[max_index] == 0) {
      answer = 0;
      break;
    }

    answer = min(answer, stones[max_index]);

    if (max_index + k >= size) {
      break;
    }

    index = max_index;
    index++;
  }

  return answer;
}
```
