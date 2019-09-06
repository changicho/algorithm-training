# .vs/settings.json

```json
{
  "code-runner.executorMap": {
    "c": "cd $dirWithoutTrailingSlash gcc $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe",
    "cpp": " clear && echo ' ' && echo '************************' && echo '****     Output     ****' && echo '************************' && echo ' ' && cd $dirWithoutTrailingSlash && g++ $fileName -g -o $fileNameWithoutExt && if [ -e $'input.txt' ]; then ./$fileNameWithoutExt.exe < input.txt | tee output_console.txt; else ./$fileNameWithoutExt.exe | tee output_console.txt; fi && echo ' ' && echo '************************' && echo '****     Result     ****' && echo '************************' && echo ' ' && if [ -e $'output.txt' ]; then diff -w -B output.txt output_console.txt; else cat output_console.txt; fi && cd '$workspaceRoot' ",
  },
  "code-runner.runInTerminal": true,
}
```