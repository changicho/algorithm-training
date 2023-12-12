# 5874. 소를 찾아라

[링크](https://www.acmicpc.net/problem/5874)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| 실버 3 |   61.723    |       1       |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자.

뒷발이 존재하는 index들과 앞발이 존재하는 index들을 한번의 순회로 구할 수 있다. 이에 O(N)의 시간 복잡도가 소요된다.

현재 뒷발을 선택할 때 선택 가능한 앞발들이 존재한다. 해당 경우쌍들을 모두 더하면 정답을 구할 수 있다.

이에 투 포인터를 이용해 O(N)의 시간 복잡도로 풀이할 수 있다.

### 공간 복잡도

각 index들을 저장하는데 O(N)의 공간 복잡도를 사용한다.

## 투 포인터

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

앞발이 존재할 수 있는 index, 뒷발이 존재할 수 있는 index들을 각각 배열에 저장한다.

현재 뒷발을 선택할 때 해당 값보다 큰 앞발들의 갯수를 구할 수 있다. 해당 갯수를 정답에 대한다.

이를 모든 뒷발에 대해 반복한다.

두 index 배열이 정렬되어 있는 경우 현재 뒷발보다 작은 뒷발들은 이전 순회에서 탐색했다.

따라서 직전에 선택 했던 앞발의 범위를 좁혀 탐색할 수 있다.

따라서 투 포인터 알고리즘을 사용할 수 있다.

```cpp
long long solution(string s) {
  int size = s.size();

  vector<int> lefts;
  vector<int> rights;

  for (int i = 1; i < size; i++) {
    if (s[i] == '(' && s[i - 1] == '(') {
      lefts.push_back(i);
    }
  }
  for (int i = 0; i < size - 1; i++) {
    if (s[i] == ')' && s[i + 1] == ')') {
      rights.push_back(i);
    }
  }

  long long answer = 0;
  int rightI = 0;
  for (int leftI = 0; leftI < lefts.size(); leftI++) {
    while (rightI < rights.size() && rights[rightI] < lefts[leftI]) {
      rightI++;
    }

    long long rightCount = rights.size() - rightI;

    long long count = rightCount;
    answer += count;
  }

  return answer;
}
```

## 고생한 점
