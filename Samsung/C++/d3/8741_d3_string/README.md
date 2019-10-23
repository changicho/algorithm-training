# 8741. 두문자어

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW2y6n3qPXQDFATy&categoryId=AW2y6n3qPXQDFATy&categoryType=CODE)

난이도\_d3_59%

## 정리

내 코드 : 6 ms;
빠른 코드 : 5 ms;

문자열의 갯수가 3개로 정해져 있는 쉬운 문제.
toupper 메소드를 이용해 대문자로 치환했다.

만약 문자열의 갯수가 정해지지 않는다면? 한 라인별로 통째로 입력받고 나눠야한다.

```cpp
string str;

getline(cin, str);  // getline(cin, str, '\n')과 같음
cout << str;
```

이 방법을 통해 한 줄을 통째로 입력 받을 수 있다.


### split

```cpp
#include "stdafx.h"
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
 
using namespace std;
 
template<typename Out>
void split(const string &s, char delim, Out result) 
{
    stringstream ss(s);
    string item;
 
    while (getline(ss, item, delim)) 
        *(result++) = item;
}
 
vector<string> split(const string &s, const char delim)
{
    vector<string> elems;
    split(s, delim, back_inserter(elems));
 
    return elems;
}
 
int main()
{
    vector<string> x = split("one:two::three", ':');
 
    return 0;
}

```

[stack overflow](https://stackoverflow.com/questions/236129/how-do-i-iterate-over-the-words-of-a-string)

위 링크에서 찾은 방법 (두 번째)
cpp은 이런 부분에서 너무 불편하다.
