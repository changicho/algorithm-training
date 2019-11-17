# 5658. [모의 SW 역량테스트] 보물상자 비밀번호

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo)

난이도\_60%

## 정리

내 코드 : 33 ms;

시뮬레이션 문제

뚜껑이 무조건 4각형 이므로, N/4의 길이를 갖는 16진수 문자열 4개가 생긴다. (한번 회전마다)
이 중 중복되는 수는 제외해야 하므로 unique함수를 이용했다.

```cpp
sort(max.begin(), max.end());
max.erase(unique(max.begin(), max.end()), max.end());
sort(max.begin(), max.end(), compare);
```

16진수 문자열의 회전은 새로운 문자열을 생성하고, 덧씌우는식으로 해결했다.

```cpp
// 시계방향으로 회전
string new_numbers_str = "";
new_numbers_str += numbers_str[numbers_str.length() - 1];
for (int i = 0; i < numbers_str.length() - 1; i++) {
  new_numbers_str += numbers_str[i];
}
numbers_str = new_numbers_str;
```

## 고생한점

회전하는 수가 4번으로 고정된 것이 아닌, N/4번을 회전한다.
4번만 회전한다고 생각해서 문제를 풀 수 없었다.
