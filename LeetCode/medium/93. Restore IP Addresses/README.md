# 93. Restore IP Addresses

[링크](https://leetcode.com/problems/restore-ip-addresses/submissions/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이 N은 최대 3,000 까지이다. 우선 문제 조건에서 가능한 IP의 최대 길이는 12자리 이므로 이를 넘어갈 경우 절대 정답을 만들 수 없다.

IP로의 변환을 위해 탐색을 진행해야 한다. 숫자를 4개의 파트로 나눠야하므로 이는 각 숫자 사이에 .을 4번 넣는것과 같다.

여기서 숫자는 최대 3자리이므로 3자리씩 탐색을 이어나가면 된다.

각 숫자는 1자리에서 최대 3자리까지 가능하므로 이 자리를 4번 만든다고 했을 때 시간 복잡도는 O(3^4) 이다.

### 공간 복잡도

정답을 저장하는 공간 외에 현재 IP로 변환중인 상태를 저장할 배열이 필요하다.

이는 글자 수에 영향을 받으므로 공간 복잡도는 O(N)이다.

### 재귀호출 & 백트래킹

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(3^4)    |    O(N)     |

현재 index에서 최대 3자리까지 숫자를 생성한다.

각 경우마다 재귀호출을 반복해 정답일 경우 갱신한다.

이 때 정답이 불가능한 경우에는 탐색을 진행하지 않는다.

- 두자리 이상의 숫자인데 0으로 시작하는 경우
- 남은 글자수가 IP를 만들 수 있는 최대 경우보다 많은경우
- 숫자가 불가능한 경우

```cpp
vector<string> restoreIpAddresses(string s) {
  vector<string> answers;
  vector<string> array;

  recursive(answers, array, 0, s);

  return answers;
}

void recursive(vector<string> &answer, vector<string> &array, int index, string &s) {
  int length = s.length();
  if (array.size() == 4 && index == length) {
    answer.push_back(convertToIp(array));
    return;
  }
  if (length - index > (4 - array.size()) * 3) return;

  int limit = min(index + 3, length);
  string temp = "";
  int cur = 0;
  for (int i = index; i < limit; i++) {
    temp += s[i];
    cur = cur * 10 + s[i] - '0';

    if (i - index > 0 && temp.front() == '0') {
      break;
    }

    if (0 <= cur && cur <= 255) {
      array.push_back(temp);
      recursive(answer, array, i + 1, s);
      array.pop_back();
    }
  }
}

string convertToIp(vector<string> &v) {
  string ret = "";
  for (string s : v) {
    ret += s + ".";
  }
  ret.erase(ret.length() - 1, 1);
  return ret;
}
```

### 반복문

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(3^4)    |    O(N)     |

재귀호출을 4번까지밖에 호출하지 않으므로 반복문을 이용해 나타낼 수 있다.

```cpp
vector<string> restoreIpAddresses(string s) {
  vector<string> answers;

  for (int a = 1; a <= 3; a++) {
    for (int b = 1; b <= 3; b++) {
      for (int c = 1; c <= 3; c++) {
        for (int d = 1; d <= 3; d++) {
          if (a + b + c + d != s.length()) continue;

          int first = stoi(s.substr(0, a));
          int second = stoi(s.substr(a, b));
          int third = stoi(s.substr(a + b, c));
          int fourth = stoi(s.substr(a + b + c, d));

          if (first <= 255 && second <= 255 && third <= 255 && fourth <= 255) {
            string ans = to_string(first) + "." + to_string(second) + "." + to_string(third) + "." + to_string(fourth);

            if (ans.length() == s.length() + 3) {
              answers.push_back(ans);
            }
          }
        }
      }
    }
  }

  return answers;
}
```

## 고생한 점
