# [PCCP 기출문제] 4번 / 수식 복원하기

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/340210)

| 난이도 |
| :----: |
|  LV3   |

## 설계

### 시간 복잡도

배열 expressions의 크기를 N이라 하자.

각 진수별로 모두 수행한 뒤 빈 부분을 채울 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답 배열에 최대 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

2진수부터 9진수까지 모든 경우에 대해 수식을 수행한다.

이 때 연산 결과가 지워진 경우는 무시하고 연산의 결과가 동일한 경우 해당 진수를 valid한 목록에 추가한다.

이후 연산 결과가 지워진 경우에대해서 valid한 진수로 연산을 모두 수행해 본 뒤 정답을 채운다.

이 떄 연산 결과가 2개 이상 나오는 경우는 ?을 붙인다.

```cpp
vector<string> split(string &s) {
  vector<string> ret;
  stringstream ss(s);
  string temp;
  while (ss >> temp) {
    ret.push_back(temp);
  }
  return ret;
}

// change to 10digit
int change(int num, int digit) {
  int ret = 0;
  int cur = 1;

  while (num > 0) {
    ret += (num % 10) * cur;
    cur *= digit;
    num /= 10;
  }
  return ret;
}

int calc(string &a, string &operation, string &b, int digit) {
  for (char &c : a) {
    if (c >= (digit + '0')) return -1;
  }
  for (char &c : b) {
    if (c >= (digit + '0')) return -1;
  }

  int numA = change(stoi(a), digit), numB = change(stoi(b), digit);

  int sum = operation == "+" ? numA + numB : numA - numB;
  if (sum == 0) return 0;
  if (sum < 0) return -1;

  string ret = "";
  while (sum > 0) {
    ret += (sum % digit + '0');
    sum /= digit;
  }
  reverse(ret.begin(), ret.end());

  return stoi(ret);
}

bool isCorrect(string s, int digit) {
  vector<string> tokens = split(s);

  int result = calc(tokens[0], tokens[1], tokens[2], digit);

  if (result == -1) return false;

  if (tokens.back() == "X") return true;
  int target = stoi(tokens.back());
  return result == target;
}

string getResult(string &s, int digit) {
  vector<string> tokens = split(s);

  int result = calc(tokens[0], tokens[1], tokens[2], digit);

  return to_string(result);
}

vector<string> solution(vector<string> expressions) {
  vector<string> answer;

  vector<int> validDigits;
  for (int digit = 2; digit <= 9; digit++) {
    bool isFine = true;
    for (string &e : expressions) {
      if (!isCorrect(e, digit)) {
        isFine = false;
        break;
      }
    }

    if (!isFine) continue;
    validDigits.push_back(digit);
  }

  for (string &e : expressions) {
    if (e.back() != 'X') continue;

    unordered_set<string> results;
    for (int &digit : validDigits) {
      results.insert(getResult(e, digit));
    }

    if (results.size() >= 2) {
      e.pop_back();
      e.push_back('?');
    } else {
      e.pop_back();
      string result = *results.begin();
      e += result;
    }
    answer.push_back(e);
  }
  return answer;
}
```

## 고생한 점
