# 알고리즘 문제풀이

> 알고리즘 문제 풀이 저장소입니다.

백준, 삼성, 프로그래머스 등등

README.md 에 문제를 풀며 정리한 내용과 정답률 퍼센트, 원본 링크 등을 기록했습니다.

## 폴더 구조

폴더명에 문제 번호와 문제 종류 태그로 구성 되어있습니다

```sh
번호_태그
```

data : input.txt, output.txt, data.txt

description : 문제 내용을 명시한 README.md

## 문제 태그

다음 표에 나와있는 태그 외에도 다양한 태그들이 존재합니다.

| 태그명       | 의미                    |
| ------------ | ----------------------- |
| backtracking | 백트래킹                |
| bfs          | 너비 우선 탐색          |
| big          | 매우 큰 수              |
| brute        | 부르트 포스 (전부 대입) |
| combination  | 조합                    |
| dfs          | 깊이 우선 탐색          |
| divide       | 분할 정복 기법          |
| dynamic      | 동적계획법              |
| extreme      | 최대 최소 값 찾기       |
| find         | 검색                    |
| graph        | 그래프                  |
| greedy       | 탐욕 알고리즘           |
| iteration    | 반복문                  |
| list         | 큐, 스택, 리스트        |
| mod          | 나머지                  |
| notation     | 진법 문제               |
| number       | 정수론 (소수...)        |
| recusive     | 재귀                    |
| sequence     | 순열                    |
| simulation   | 시뮬레이션              |
| sort         | 정렬                    |
| string       | 문자열                  |
| table        | key, value 구조         |
| tree         | 트리 구조               |
| unique       | 유일한 값들의 집합      |

## C++ 설정

### 컴파일러

c_cpp의 경우 컴파일러 버전 c++14를 사용합니다.

g++를 사용할 때 다음 옵션을 추가합니다.

```bash
-std=c++14
```

vscode의 오류 발견은 c++14 버전으로 설정합니다.

(c_cpp_properties.json 설정 필요)

### input 읽어오기

PowerShell

```bash
cd $dir && g++ -std=c++14 $fileName -o $fileNameWithoutExt  && Get-Content ./data/input.txt | $dir$fileNameWithoutExt
```

bash

```bash
cd $dir && g++ -std=c++14 $fileName -o $fileNameWithoutExt  && $dir$fileNameWithoutExt < ./data/input.txt
```

## C_Cpp extention 설정

setting.json에 아래 코드 추가로 to_string 등 method 관련 오류 제거

```json
"C_Cpp.default.intelliSenseMode": "clang-x64",
// "C_Cpp.intelliSenseEngine": "Tag Parser", // 이방법은 사용 안하는것이 좋다.
```

to_string 메소드를 사용하는 경우 multiple definition of `vsnprintf' 에러 발생

- download mingw-w64-install.exe
- setup to Version: 6.3.0, Architecture: i686, Threads: posix, Exception: dwarf and Build revision: 2.
- 환경변수 설정 (바꿔주면 됨)

이렇게 해결함.
