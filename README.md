# 알고리즘 문제풀이

백준, 삼성, 프로그래머스

## repository의 구조 설명

### 폴더의 경로 설명

문제출처/사용언어/문제/

### 문제 폴더

폴더명 : 번호*난이도*태그 의 구조로 되어있다.

내부 폴더

- data : input.txt, output.txt
- description : 문제 내용을 명시한 README.md

## C++ 설정

### 컴파일러

c_cpp의 경우 컴파일러 버전 c++11에 맞춤.
vscode의 오류 발견은 c++17 버전으로 설정 (c_cpp_properties.json 설정 필요)

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

## CodeRunner Shell Script 추가

아래 내용들은 git bash에서 사용하는것을 전재로 한다.

### code-runnder 실행 명령

```json
  "code-runner.executorMap": {
    "c": "cd $dirWithoutTrailingSlash gcc $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe",
    "cpp": " clear && echo ' ' && echo '************************' && echo '****     Output     ****' && echo '************************' && echo ' ' && cd $dirWithoutTrailingSlash && g++ $fileName -g -o $fileNameWithoutExt && if [ -e $'./data/input.txt' ]; then ./$fileNameWithoutExt.exe < './data/input.txt' | tee './data/my_output.txt' ; else ./$fileNameWithoutExt.exe | tee './data/my_output.txt' ; fi && if [ -e $'./data/output.txt' ]; then echo ' ' && echo '************************' && echo '****     Result     ****' && echo '************************' && echo ' ' && diff -w -B './data/output.txt' './data/my_output.txt' ; fi && cd '$workspaceRoot' ",
  },
```

프로그램 실행 시 이전 콘솔 기록 초기화
프로그램 실행 결과와 output.txt와 비교

- 비교 구문을 comm 에서 diff로 변경, 공백과 newline을 무시하는 옵션을 추가했다.

data 폴더에 input.txt가 있는경우 읽어오고, 없는경우 콘솔에서 입력
프로그램 실행 후, 결과를 콘솔과 my_output.txt에 출력한다.
data 폴더에 output.txt가 있는 경우, my_output.txt와 비교, 없는경우 콘솔에 결과 출력
실행이 끝난 후 workspace 경로로 다시 돌아옴
