# 9660. 번호 붙이기

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXCjuQl6J5UDFAX0)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
|   D6   |    8.09     |

## 설계

> 파스칼의 삼각형 (조합) + 포함 배제의 원리

입력받은 hate에서 불필요한 부분 (범위를 넘어서는 부분)은 무시한다.

이후 싫어하는 색들의 count를 이용해 포함 배제의 원리를 이용한다.

만약 싫어하는 색이 없다면 가능한 경우의 수는 N!이 된다.

싫어하는 색이 있는 경우를 생각해보자.

싫어하는 색이 A, B, C가 있다고 하자.

가능한 모든 경우의 수(N!)에서 ∣A∪B∪C∣ 인 경우의 수를 빼면 정답을 구할 수 있다.

여기서 포함 배제의 원리를 이용해 ∣A∪B∪C∣=∣A∣+∣B∣+∣C∣−∣A∩B∣−∣B∩C∣−∣C∩A∣+∣A∩B∩C∣ 로 생각할 수 있다.

위 식에서 각 경우는 아래와 같이 대입할 수 있다.

- ∣A∣,∣B∣,∣C∣ : combination(N, 1)
- ∣A∩B∣,∣B∩C∣,∣C∩A∣ : combination(N, 2)
- ∣A∩B∩C∣ : combination(N, 3)

여기서 combination을 구하기 위해 파스칼의 삼각형을 이용한다.

이 때 파스칼의 삼각형을 구할 때 싫어하는 색의 횟수(가중치)를 부여해 구한다.

이때 각 연산에 overflow가 발생하지 않도록 MOD 연산을 수행한다.

이를 구현하면 다음과 같다.

```cpp
long long solution(int n, vector<int> hate) {
  unordered_map<int, int> hateCount;
  for (int &target : hate) {
    // ignore useless case
    if (target > n) continue;
    hateCount[target]++;
  }

  // edge case
  if (hateCount.size() == 0) return factorials[n];

  vector<long long> uniqueHate;
  for (auto &it : hateCount) {
    uniqueHate.push_back(it.second);
  }

  // nC1, nC2, ... , nCn
  vector<long long> pascalTriangle = {1};
  for (long long count : uniqueHate) {
    vector<long long> currentLine;

    long long prev = 0;
    for (long long number : pascalTriangle) {
      // fill weight of current nCr
      long long cur = (prev * count) % MOD;

      cur += number;
      cur %= MOD;

      currentLine.push_back(cur);
      prev = number;
    }

    currentLine.push_back((prev * count) % MOD);

    pascalTriangle = currentLine;
  }

  long long answer = 0;
  for (int i = 0; i < pascalTriangle.size(); i++) {
    long long cur = pascalTriangle[i];
    cur *= factorials[n - i];
    cur %= MOD;

    if (i % 2 == 0) {
      answer += cur;
    } else {
      answer -= cur;
    }
  }

  answer %= MOD;
  if (answer < 0) answer += MOD;

  return answer;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     518      |      133       |

## 고생한 점
