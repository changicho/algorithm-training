# 929. Unique Email Addresses

[링크](https://leetcode.com/problems/unique-email-addresses/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

이메일의 갯수를 N, 이메일의 최대 길이를 L이라 하자.

이메일을 convert 하는 데, O(L)의 시간 복잡도가 소요되며 이를 모든 이메일에 반복한다.

이후 unique한 이메일의 갯수를 세기 위해 hash set을 이용한다.

이 경우 시간 복잡도는 O(N \* L)이다.

### 공간 복잡도

hash set에 사용하는 공간 복잡도는 O(N \* L)이다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |  O(N \* L)  |  O(N \* L)  |

입력받은 이메일을 다음 규칙에 따라서 변형한다.

- local, domain 두 부분으로 나눈다. (처음 나온 '@' 문자를 기준)
- local에서 '.' 문자를 전부 삭제한다.
- local에서 처음 '+'문자가 나오는 부분부터 이후의 모든 문자열을 삭제한다.

이후 각 이메일들을 변형한 이메일의 unique한 갯수를 세기 위해 hash set에 저장한다.

마지막으로 hash set의 크기를 반환한다.

```cpp
string removeDots(string email) {
  string ret = "";
  for (char &c : email) {
    if (c == '.') continue;
    ret += c;
  }
  return ret;
}

string removeFirstPlus(string email) {
  return email.substr(0, email.find('+'));
}

string convert(string email) {
  int target = email.find('@');
  string local = email.substr(0, target), domain = email.substr(target);

  // first. remove all dots in local
  // second. remove all string start from first + in local
  local = removeFirstPlus(removeDots(local));

  return local + domain;
}

int numUniqueEmails(vector<string> &emails) {
  unordered_set<string> uniqueEmails;

  for (string &email : emails) {
    string converted = convert(email);
    uniqueEmails.insert(converted);
  }

  return uniqueEmails.size();
}
```

## 고생한 점
