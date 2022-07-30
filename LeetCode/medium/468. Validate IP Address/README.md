# 468. Validate IP Address

[링크](https://leetcode.com/problems/validate-ip-address/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 queryIP의 길이를 N이라 하자.

각 숫자부분을 쪼개는 데 한번 순회해야 하므로 O(N)의 시간 복잡도를 사용한다.

각 쪼개진 부분을 순회하며 규칙에 맞는지 판별하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 문자열부분을 쪼갠 vector를 관리하는데 O(N)의 공간 복잡도를 사용한다.

### 구현

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

':', '.'에 대해서 문자열을 tokenize한다. 이 때 IPv4, IPv6의 token이 다르므로 두 경우가 동시에 존재하는 경우 유효하지 않다.

이후 각 token에 대해서 IPv4일때와 IPv6일때 유효성검사를 실행한다.

이 경우 token의 갯수에 따라 (4개 혹은 8개) 분기 처리 후 판단한다.

이를 구현하면 다음과 같다.

```cpp
bool isValidTokenizer(string &query){
  bool hasSemi = false;
  bool hasDot = false;

  for(char &c : query){
    if(c == ':') hasSemi = true;
    if(c == '.') hasDot = true;
  }

  if(hasSemi == hasDot) return false;
  return true;
}

vector<string> split(string &query) {
  vector<string> ret;
  string temp = "";
  for (char &c : query) {
    if (c == ':' || c == '.') {
      ret.push_back(temp);
      temp = "";
      continue;
    }
    temp += c;
  }
  ret.push_back(temp);
  return ret;
}

bool isValidIPv4(vector<string> &tokens) {
  if (tokens.size() != 4) return false;

  for (string &t : tokens) {
    if (t.length() >= 4 || t.length() == 0) return false;
    if (t.length() >= 2 && t.front() == '0') return false;
    for (char &c : t) {
      if (!isdigit(c)) return false;
    }
    if (stoi(t) < 0 || 256 <= stoi(t)) return false;
    continue;
  }
  return true;
}

bool isValidIPv6(vector<string> &tokens) {
  if (tokens.size() != 8) return false;

  for (string &t : tokens) {
    if (t.length() > 4 || t.length() == 0) return false;
    for (char &c : t) {
      if (islower(c) && c > 'f') return false;
      if (isupper(c) && c > 'F') return false;
      if (!isdigit(c) && !isupper(c) && !islower(c)) return false;
    }
  }
  return true;
}

string validIPAddress(string queryIP) {
  if (!isValidTokenizer(queryIP)) return "Neither";
  vector<string> tokens = split(queryIP);

  if (isValidIPv4(tokens)) {
    return "IPv4";
  } else if (isValidIPv6(tokens)) {
    return "IPv6";
  }

  return "Neither";
}
```

## 고생한 점
