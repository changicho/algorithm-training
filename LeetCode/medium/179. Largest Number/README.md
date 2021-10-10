# 179. Largest Number

[링크](https://leetcode.com/problems/largest-number/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

모든 경우에 대해서 탐색할 경우 N!만큼의 시간 복잡도가 소요되며 이는 제한시간 내에 불가능하다.

따라서 탐욕 알고리즘과 정렬을 사용해 O(N \* log_2(N)) 이내에 풀이한다.

### 공간 복잡도

각 숫자들을 문자로 변환한 배열을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

정답 문자열을 생성하는데 O(N) 크기가 필요하다.

### 그리디 알고리즘 & 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(N \* log_2(N)) |    O(N)     |

특정 수들을 이어 붙여 가장 큰 수를 만들 수 있는 방법은

이어붙였을 때 가장 큰 숫자가 되는 순서대로 정렬한 뒤 이어붙이는 것이다.

여기서 앞자리 숫자가 클수록 이어붙였을 때 큰 수가 되기 위해선 다음 조건을 충족해야 한다.

- 이어붙였을 때 앞자리가 큰 숫자가 유리하다.
- 만약 같은 앞자리로 시작하는 경우 이어붙였을 때 유리한쪽에 우선한다.

이런 우선순위로 정렬한다고 하자.

우선도를 판단하는 방법은 다음과 같다.

```cpp
bool compare(string &a, string &b){
  string order1 = a + b;
  string order2 = b + a;

  return order2 < order1;
}
```

이를 이용해 모든 숫자를 정렬한 후 순서대로 정답에 이어붙인다.

```cpp
string largestNumber(vector<int> &nums) {
  vector<string> numStrings;

  for (int &num : nums) {
    string numString = to_string(num);

    numStrings.emplace_back(numString);
  }

  sort(numStrings.begin(), numStrings.end(),
        [](const string &a, const string &b) { return (a + b) > (b + a); });

  if (numStrings.front() == "0") return "0";

  string answer = "";
  for (string num : numStrings) {
    answer += num;
  }
  return answer;
}
```

## 고생한 점
