# 알고리즘 문제풀이

백준, 삼성, 프로그래머스

### 폴더의 경로 설명 :
문제출처/사용언어/문제번호/소스+문제풀이정리

### 문제 폴더의 양식 : 
문제번호_난이도_공부내용

### C++ 설정
c_cpp의 경우 컴파일러 버전 c++11에 맞춤.
vscode의 오류 발견은 c++17 버전으로 설정 (c_cpp_properties.json 설정 필요)

위 방법 대신 setting.json에 아래 코드 추가로 해결 가능
```json
"C_Cpp.default.intelliSenseMode": "clang-x64",
// 이쪽이 더 정확함
"C_Cpp.intelliSenseEngine": "Tag Parser",
```

to_string 메소드를 사용하는 경우 multiple definition of `vsnprintf' 에러 발생
 - download mingw-w64-install.exe
 - setup to Version: 6.3.0, Architecture: i686, Threads: posix, Exception: dwarf and Build revision: 2.
 - 환경변수 설정 (바꿔주면 됨)
이렇게 해결함.

CodeRunner Shell Script 추가
```json
  "code-runner.executorMap": {
    "c": "cd $dirWithoutTrailingSlash gcc $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe",
     // input.txt로 바로 입력, 없으면 콘솔로 입력. 결과를 output_console.txt로 출력, output.txt와 비교.
    "cpp": " clear && echo ' ' && echo '************************' && echo '****     Output     ****' && echo '************************' && echo ' ' && cd $dirWithoutTrailingSlash && g++ $fileName -g -o $fileNameWithoutExt && if [ -e $'input.txt' ]; then ./$fileNameWithoutExt.exe < input.txt | tee output_console.txt; else ./$fileNameWithoutExt.exe | tee output_console.txt; fi && echo ' ' && echo '************************' && echo '****     Result     ****' && echo '************************' && echo ' ' && if [ -e $'output.txt' ]; then diff -w -B output.txt output_console.txt; else cat output_console.txt; fi && cd '$workspaceRoot' ",
  },
```
쉘 스크립트를 이용

프로그램 실행 시 이전 콘솔 기록 초기화
프로그램 실행 결과와 output.txt와 비교
- 비교 구문을 comm 에서 diff로 변경, 공백과 newline을 무시하는 옵션을 추가했다.
input.txt가 있는경우 읽어오고, 없는경우 콘솔에서 입력
실행이 끝난 후 workspace 경로로 다시 돌아옴