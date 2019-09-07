# .vs/settings.json

```json
{
  "code-runner.executorMap": {
    "c": "cd $dirWithoutTrailingSlash gcc $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe",
    "cpp": " cd $dirWithoutTrailingSlash && if [ ! -d 'bin' ]; then mkdir 'bin'; fi && g++ $fileName -g -o './bin/$fileNameWithoutExt' && if [ -e $'./data/input.txt' ]; then echo && echo '************************' && echo '**   From input.txt   **' && echo '************************' && echo &&  './bin/$fileNameWithoutExt.exe' < './data/input.txt' > './data/my_output.txt' ; else echo && echo '************************' && echo '**    Enter  Input    **' && echo '************************' && echo && './bin/$fileNameWithoutExt.exe' > './data/my_output.txt' ; fi && echo && echo '************************' && echo '**       Output       **' && echo '************************' && echo && cat './data/my_output.txt' ; if [ -e $'./data/output.txt' ]; then echo && echo '************************' && echo '**   Compare Result   **' && echo '** < : ans  yours : > **' && echo '************************' && echo && diff -w -B './data/output.txt' './data/my_output.txt' && echo '        CORRECT         ' ; fi ; cd '$workspaceRoot' && echo && echo 'currnt root is $workspaceRoot' "
  },
  "code-runner.runInTerminal": true,
  "files.associations": {
    "string": "cpp",
    "*.tcc": "cpp"
  }
}
```

## 작성중인 shell script

```shell
cd $dirWithoutTrailingSlash &&
if [ ! -d 'bin' ];
then mkdir 'bin';
fi &&
g++ $fileName -g -o './bin/$fileNameWithoutExt' &&
if [ -e $'./data/input.txt' ];
then echo &&
echo '************************' &&
echo '**   From input.txt   **' &&
echo '************************' &&
echo &&
'./bin/$fileNameWithoutExt.exe' < './data/input.txt' > './data/my_output.txt' ;
else echo &&
echo '************************' &&
echo '**    Enter  Input    **' &&
echo '************************' &&
echo &&
'./bin/$fileNameWithoutExt.exe' > './data/my_output.txt' ;
fi &&
echo &&
echo '************************' &&
echo '**       Output       **' &&
echo '************************' &&
echo &&
cat './data/my_output.txt' ;
if [ -e $'./data/output.txt' ];
then echo &&
echo '************************' &&
echo '**   Compare Result   **' &&
echo '** < : ans  yours : > **' &&
echo '************************' &&
echo &&
diff -w -B './data/output.txt' './data/my_output.txt' &&
echo '        CORRECT         ' ;
fi ;
cd '$workspaceRoot' &&
echo &&
echo 'currnt root is $workspaceRoot'
```
