# 247. Strobogrammatic Number II

[링크](https://leetcode.com/problems/strobogrammatic-number-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

만들어야 하는 글자 수를 N이라 하자.

만들어야 하는 수에 들어갈 수 있는 문자는 다음 5가지이다. ("0", "1", "6", "8", "9")

모든 경우를 탐색할 경우 시간 복잡도는 5^N이며 이를 모두 탐색할 경우 제한시간 내에 불가능하다.

따라서 백트래킹을 이용하거나 분할 정복을 이용한다.

백트래킹을 이용할 경우 (N / 2) 크기의 경우의 수를 만드는 경우, 이후에는 각 경우의 수을 반대로 뒤집는 경우에 대한 수들만 생성하면 된다.

따라서 5^(N / 2)가지 경우를 생성할 수 있다.

이후 나머지 절반을 채우는 경우와, 내부적으로 유효한지 판별하는 데 O(N)만큼 사용한다.

따라서 시간 복잡도는 O(N \* 5^(N/2))이다.

### 공간 복잡도

모든 경우에 대해서 vector에 저장해야 하므로 공간 복잡도는 O(N \* 5^(N/2)))이다.

### 백트래킹

| 내 코드 (ms) |   시간 복잡도   |   공간 복잡도   |
| :----------: | :-------------: | :-------------: |
|      64      | O(N \* 5^(N/2)) | O(N \* 5^(N/2)) |

유효한 숫자를 구성하는 각각 숫자들은 ("0", "1", "6", "8", "9") 이 5가지이다.

BFS를 이용해 N / 2크기의 문자열 모두를 만든다.

이후에는 중심을 기준으로 각 문자열들의 나머지 절반을 채워넣는다.

이 때 N이 홀수인 경우는 가운데 글자로 들어올 수 있는 글자는 3가지 경우만 존재한다.

- 0
- 1
- 8

따라서 N이 짝수, 홀수 여부에 따라서 별도로 정답에 삽입한다.

```cpp
unordered_map<char, char> table = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
vector<char> digits = {'0', '1', '6', '8', '9'};

// O(N)
string getReverse(string half, int n) {
  int length = half.length(), center = n / 2;

  for (int i = 0; i < center; i++) {
    char c = half[center - 1 - i];
    half += table[c];
  }
  return half;
}

vector<string> findStrobogrammatic(int n) {
  queue<string> q;
  q.push("");

  // make all half
  // O(N)
  for (int i = 0; i < n / 2; i++) {
    int size = q.size();
    // O(N^(N / 2))
    while (size--) {
      string before = q.front();
      q.pop();

      for (char &digit : digits) {
        string num = before + digit;

        if (num[0] == '0') continue;
        q.push(num);
      }
    }
  }

  // fill half and push to answer
  vector<string> answer;
  while (!q.empty()) {
    string num = q.front();
    q.pop();

    if (n % 2 == 1) {
      for (char c : {'0', '1', '8'}) {
        answer.emplace_back(getReverse(num + c, n));
      }
    } else {
      answer.emplace_back(getReverse(num, n));
    }
  }

  return answer;
}
```

### 분할 정복

| 내 코드 (ms) |   시간 복잡도   |   공간 복잡도   |
| :----------: | :-------------: | :-------------: |
|      32      | O(N \* 5^(N/2)) | O(N \* 5^(N/2)) |

뒤집어도 유효한 숫자 S가 존재할 때 S의 길이 + 2 크기의 뒤집어도 유효한 숫자는 다음과 같은 방법으로 생성한다.

- S의 앞 뒤에 두 문자를 붙이되, 각 문자는 뒤집었을 때 같고 유효해야 한다.

이를 일반식으로 나타내면 다음과 같다.

```cpp
for (string cur : part) {
  if (left != n) next.push_back("0" + cur + "0");
  next.push_back("1" + cur + "1");
  next.push_back("6" + cur + "9");
  next.push_back("8" + cur + "8");
  next.push_back("9" + cur + "6");
}
```

여기서 S의 길이가 1 혹은 0인 임계값의 경우는 다음을 return해야 한다.

```cpp
if (left == 0) return {""};
if (left == 1) return {"0", "1", "8"};
```

이를 이용해 모든 경우를 탐색한다.

```cpp
vector<string> makePart(int left, int n) {
  if (left == 0) return {""};
  if (left == 1) return {"0", "1", "8"};

  vector<string> part = makePart(left - 2, n);
  vector<string> ret;

  for (string cur : part) {
    if (left != n) ret.push_back("0" + cur + "0");
    ret.push_back("1" + cur + "1");
    ret.push_back("6" + cur + "9");
    ret.push_back("8" + cur + "8");
    ret.push_back("9" + cur + "6");
  }

  return ret;
}

vector<string> findStrobogrammatic(int n) {
  return makePart(n, n);
}
```

## 고생한 점
