# 17683. [3차] 방금그곡

[링크](https://programmers.co.kr/learn/courses/30/lessons/17683)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv2   |   1413   |

## 설계

### 시간 복잡도

문자열을 순회하는 문제이다.

악보의 최대 길이는 1439 이다.

최악의 경우 음악의 길이는 1500 까지이다.

곡의 정보는 100 개 까지이다.

하나의 곡에서 음악 정보를 찾아내는데 제일 빠른 경우 KMP 알고리즘을 사용해 2N번의 시간이 소요된다고 하면,

최악의 경우 시간복잡도는

```cpp
100 * 1500 * 2 = 300,000
```

문자열을 검색 할 때 직접 하는 경우의 시간 복잡도는 225,000,000 이므로 KMP 알고리즘을 사용해야 한다.

### 공간 복잡도

숫자 정보는 1500을 넘지 않으므로 int형으로 선언하고, 나머지는 문자열로 선언한다.

### split

C++에서 split을 다음과 같이 구현한다.

```cpp
vector<string> split(string str, char target) {
  vector<string> result;
  string temp = "";

  for (char c : str) {
    if (c == target) {
      result.push_back(temp);
      temp = "";
    } else {
      temp += c;
    }
  }
  if (temp != "") {
    result.push_back(temp);
  }
  return result;
}
```

### 반올림 음계 치환

'#'이 들어가있는 음계의 경우 치환해야 한다.

입력은 대문자 알파벳으로 주어지므로, 이를 소문자 알파벳으로 치환하자.

올림 음계밖에 없으므로 N번만에 치환이 가능하다.

```cpp
string transform(string melody) {
  string result = "";

  for (int i = 0; i < melody.length(); i++) {
    if (i + 1 < melody.length() && melody[i + 1] == '#') {
      result += tolower(melody[i]);
      i++;
    } else {
      result += melody[i];
    }
  }

  return result;
}
```

모든 음악 패턴을 치환해 줘야 함에 유의한다.

### 시간 치환

HH:MM으로 되어있는 정보를 치환할 때 시간에 60을 곱하고 서로의 차를 이용해 계산한다.

```cpp
int parseTime(string time) {
  string temp = "";
  vector<string> times = split(time, ':');

  return stoi(times[0]) * 60 + stoi(times[1]);
}
```

### 패턴 검색

string의 find 메소드를 사용한다.

```cpp
if (str.played.find(patern) != string::npos) {
  // str에서 patern을 찾음
}else{
  // str에서 patern을 찾지 못함
}
```

## 고생한 점

정답이 없는 경우 출력할 문자열은 "(NONE)" 이다.

이를 문제에선 다음과 같이 표기함

```text
"`(NONE)`"
```
