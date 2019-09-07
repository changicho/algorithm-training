clear 
&& echo ' ' 
&& echo '************************' 
&& echo '****     Output     ****' 
&& echo '************************' 
&& echo ' ' 
&& cd $dirWithoutTrailingSlash 
&& if [ ! -d 'bin' ]; 
then mkdir 'bin';
fi
&& g++ $fileName -g -o './bin/$fileNameWithoutExt' 
&& if [ -e $'./data/input.txt' ]; 
then './bin/$fileNameWithoutExt.exe' < './data/input.txt' | tee './data/my_output.txt' ; 
else './bin/$fileNameWithoutExt.exe' | tee './data/my_output.txt' ; 
fi 
&& if [ -e $'./data/output.txt' ]; 
then echo ' ' 
&& echo '************************' 
&& echo '**** CompareResult  ****' 
&& echo '************************' 
&& echo ' ' 
&& diff -w -B './data/output.txt' './data/my_output.txt' ; 
fi 
&& cd '$workspaceRoot'