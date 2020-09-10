# 17684. [3차] 압축

[링크](https://programmers.co.kr/learn/courses/30/lessons/17684)

| 난이도 | 완료 (명) |
| :----: | :-------: |
|  lv2   |   1753    |

## 설계

### 시간 복잡도

글자의 수는 최대 1000 이다.

현재 index에서 증가시키며 단어를 비교하므로 시간 복잡도는 O(1,000)

### 공간 복잡도

각 단어마다의 index를 쉽게 찾기 위해 map을 이용한다.

key : string, value : int

### 문자 조합

현재 단어가 map에 있는 경우 현재 단어에서 다음 문자를 계속 더해간다.

이를 map에 없는 단어가 나올 때 까지 반복

```cpp
string cur = "";

for (int index = 0; index < msg.length(); index++) {
  cur += msg[index];

  if (m[cur] == 0) {
    m[cur] = m.size();
    cur.erase(cur.length() - 1, 1);
    answer.push_back(m[cur]);
    cur = "";
    index--;
  }
}

if (cur.length() > 0) {
  answer.push_back(m[cur]);
}
```

```cpp
int index = 0;
while (index < msg.length()) {
  string cur = "";
  int end;

  for (end = index; end < msg.length(); end++) {
    cur += msg[end];

    if (m[cur] == 0) {
      m[cur] = m.size();
      cur.erase(cur.length() - 1, 1);
      break;
    }
  }

  answer.push_back(m[cur]);
  index = end;
}
```

## 고생한 점

초기 알파벳 A-Z 배열을 만드는데 실수해 계속 틀렸다.

A-Z 한 글자짜리는 char이라서 for문으로 만들 경우 다음과 같이 사용해야함

```cpp
for (char alpha = 'A'; alpha <= 'Z'; alpha++) {
  string temp = "";
  m[temp + alpha] = m.size() + 1;
}

// 혹은
vector<string> mapping = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
```
