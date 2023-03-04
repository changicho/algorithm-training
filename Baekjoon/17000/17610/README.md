# 17610. 양팔저울

[링크](https://www.acmicpc.net/problem/17610)

| 난이도 |
| :----: |
| 실버 I |

## 설계

### 시간 복잡도

무게추의 갯수를 N이라 하자.

왼쪽, 오른쪽 양팔저울에 무게추를 올리는 경우의 수는 2가지이다. 또한 아무곳에도 올리지 않는 경우를 포함해 총 3가지의 경우가 존재한다.

따라서 경우의 수는 3^N이다.

모든 경우의 수를 탐색하며 저울의 무게를 계산하면 시간 복잡도는 O(3^N)이다.

### 공간 복잡도

재귀호출을 이용해 구현할 경우 call stack에 N개의 함수가 쌓이게 된다.

이 경우 공간 복잡도는 O(N)이다.

또한 무게추의 무게를 저장할 공간이 필요하다.

무게추의 최대 크기는 200,000 이다. 이것이 총 13개 존재할 수 있으므로 최대 2,600,000의 무게를 저장할 수 있다.

이 경우 공간 복잡도는 O(2,600,000)이다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     268      |   O(3^N)    |    O(N)     |

재귀호출을 이용해 완전 탐색을 수행한다.

이 과정에서 만들 수 있는 수에 대한 정보를 저장한다.

- 왼쪽의 무게
- 오른쪽의 무게
- 왼쪽과 오른쪽의 무게의 차이

이를 모두 저장한 뒤 전체 무게에서 만들 수 있는 무게의 갯수를 빼면 답이 된다.

```cpp
unordered_set<int> visited;
void recursive(int index, vector<int> &grams, int leftSum, int rightSum) {
  visited.insert(leftSum);
  visited.insert(rightSum);
  visited.insert(abs(leftSum - rightSum));

  if (index == grams.size()) return;

  recursive(index + 1, grams, leftSum, rightSum);
  recursive(index + 1, grams, leftSum + grams[index], rightSum);
  recursive(index + 1, grams, leftSum, rightSum + grams[index]);
}

int solution(vector<int> grams) {
  int size = grams.size();
  int sum = 0;
  for (int &g : grams) {
    sum += g;
  }

  visited.insert(0);
  recursive(0, grams, 0, 0);

  int answer = sum - visited.size() + 1;
  return answer;
}
```

## 고생한 점
