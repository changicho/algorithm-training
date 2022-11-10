echo "Algospot solved count"
DIR="$(cd "$(dirname "$0")" && pwd -P)"

shopt -s dotglob
shopt -s nullglob

count=$(ls | wc -l)

echo
echo "total : $count"
