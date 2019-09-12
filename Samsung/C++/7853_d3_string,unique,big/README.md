# 7853. 오타

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWttUKkq5hQDFASy&categoryId=AWttUKkq5hQDFASy&categoryType=CODE)

난이도\_d3

## 정리

_각 테스트 케이스마다 재경이가 칠 수 있는 단어의 종류를 10억7(=109+7) 로 나눈 나머지를 출력하라._

문제 출력 요구조건 중 위 부분이 매우 헷갈렸다.
answer 의 값을 갱신할 때마다 1e9+7 의 수로 나누어 주어야 했다.
cpp 에서 % 연산은 long, double 형을 지원하지 않기 때문에 직접 1000000007 로 나누어주었다.

index 번째 일때, (첫번째와 마지막 제외) index - 1 , index , index + 1 번째의 문자 중에서 중복을 제거한 종류의 수를 구한다.
모든 문자를 순회하면서 앞에서 구한 경우의 수를 곱해나가면 가능한 경우의 수가 나온다.

중복을 제거할 때 vector.erase method 를 이용했다.

```cpp
//사용법
sort(diff.begin(), diff.end());
diff.erase(unique(diff.begin(), diff.end()), diff.end());
```
먼저 정렬을 해야함에 유의한다.

정렬을 한 뒤 unique(vector.begin(), vector.end()) 를 수행하면
[uniqe 한 원소들의 배열, 중복 원소들로 구성된 배열] 의 형태가 된다.

위 연산의 반환값은, 쓰레기 값들의 시작 점이므로
unique 연산을 통해 unique 한 값이 끝나는 위치를 반환
그 위치부터 끝까지 erase 연산 수행

이를 통해 유일한 값들만 모인 배열을 생성할 수 있다.
