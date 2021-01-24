# Visual Studio Code settings

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
