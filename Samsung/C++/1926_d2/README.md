# 1926. 간단한 369게임

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PTeo6AHUDFAUq&categoryId=AV5PTeo6AHUDFAUq&categoryType=CODE)

### 난이도 d2

## 정리

c++ 컴파일러 c++11 에서 제공하는 stoi(string), to_string(number)를 이용했다.

vscode에선 c++11에서 제공하는 method에서 오류메시지를 출력하는데 이유를 알기 어렵다.


extention으로 code runner를 사용하는데 shell script를 건드릴 수 있어 좋다

```json
  "code-runner.executorMap": {
    "c": "cd $dirWithoutTrailingSlash gcc $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe",
    // input.txt로 바로 입력.
    "cpp": "cd $dirWithoutTrailingSlash && g++ $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe < input.txt cat thing > output_console.txt",
    // 직접 실행후 입력할때.
    //"cpp": "cd $dirWithoutTrailingSlash && g++ $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe",
  },
  "code-runner.runInTerminal": true,
```
terminal을 powershell에서 gitbash로 변경했다. 이로인해 answer.exe에서 input.txt을 바로 읽고 output_console.txt로 결과를 출력할 수 있게 했다.

