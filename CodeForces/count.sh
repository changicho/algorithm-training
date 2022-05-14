echo "========================"
echo "CodeForces solved count"
echo

DIR="$( cd "$( dirname "$0" )" && pwd -P )"
# echo "path : $DIR"
# echo

count=0

shopt -s dotglob
shopt -s nullglob
array=(*/)
for dir in "${array[@]}"; 
do 
  cd $DIR/$dir
  RoundArray=(*/)
  for round in "${RoundArray[@]}"; 
  do
    cd "$DIR/$dir/$round"
    num=`ls -d */ | wc -l`
    echo "$dir$round : `expr $num`"
    count=`expr $count + $num`
  done
done

echo
echo "total : $count"
echo "========================"