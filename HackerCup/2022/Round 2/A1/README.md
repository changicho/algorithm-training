# Problem A1: Perfectly Balanced - Chapter 1

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2022/round-2/problems/A1)

| 난이도 |
| :----: |
| 10 pt  |

## 설계

### 시간 복잡도

문자열의 길이를 N, 쿼리의 갯수를 Q라 하자.

특정 범위의 문자열이 almost palindrome인지 판단하기 위해 중앙점을 기준으로 왼쪽, 오른쪽에 대해 글자들의 count의 차이가 1인지 비교한다.

이 때 범위를 모두 탐색할 경우 O(N)의 시간 복잡도를 사용한다.

이 때 글자의 범위는 O(1)이므로 별도로 생각하지 않는다.

이를 모든 쿼리에 대해 반복할 경우 O(N \* Q)의 시간 복잡도를 사용한다.

prefixSum을 이용할 경우 미리 탐색해놓고 이를 O(1)의 시간 복잡도로 구할 수 있다.

이 경우 O(N + Q)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefixSum을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### prefixSum

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(N + Q)   |    O(N)     |

길이가 홀수인 특정 문자열이 almost palindrome일 경우 이는 다음 두 경우중 하나이다.

- 중앙값을 포함해 왼쪽에서 수 하나를 제거한 경우
- 중앙값을 포함하지 않고 오른쪽에서 수 하나를 제거한 경우

즉 다음 두가지 경우에 대해서 글자들의 수를 왼쪽 부분, 오른쪽 부분을 count하고 이 차이의 합이 1인 경우면 almost palindrome으로 판단할 수 있다.

여기서 매 쿼리마다 해당 범위의 글자들의 count를 모두 구하면 O(N)의 시간 복잡도가 매번 사용된다.

이를 prefixSum을 이용해 미리 구해놓는다.

이후 각 쿼리마다, 쿼리의 범위가 길이가 짝수인 문자열인 경우 무시하고 (짝수는 불가능), 그 외의 경우는 중앙값을 기준으로 두 경우를 탐색한다.

- 왼쪽 부분이 중앙값을 포함하지 않는 경우
- 왼쪾 부분이 중앙값을 포함하는 경우

이를 구현하면 다음과 같다.

```cpp
bool isAlmostPalin(vector<vector<int>> &subArraySums, int left, int mid,
                   int right) {
  vector<int> leftCount(256, 0), rightCount(256, 0);

  leftCount = subArraySums[mid];
  for (int i = 0; i < 26; i++) {
    leftCount[i] -= subArraySums[left - 1][i];
  }

  rightCount = subArraySums[right];
  for (int i = 0; i < 26; i++) {
    rightCount[i] -= subArraySums[mid][i];
  }

  int diffCount = 0;
  for (int i = 0; i < 26; i++) {
    diffCount += abs(leftCount[i] - rightCount[i]);
  }
  if (diffCount == 1) return true;
  return false;
}

int solution(string &s, vector<pair<int, int>> queries) {
  int size = s.size();
  vector<vector<int>> subArraySums(size + 1, vector<int>(26, 0));

  for (int i = 0; i < size; i++) {
    subArraySums[i + 1] = subArraySums[i];
    subArraySums[i + 1][s[i] - 'a']++;
  }

  int answer = 0;
  for (pair<int, int> &query : queries) {
    int left = query.first, right = query.second;

    if ((right - left + 1) % 2 == 0) continue;

    int mid = (left + right) / 2;

    if (isAlmostPalin(subArraySums, left, mid - 1, right) ||
        isAlmostPalin(subArraySums, left, mid, right)) {
      answer++;
    }
  }

  return answer;
}
```

## 고생한 점
