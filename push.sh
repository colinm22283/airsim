echo "Enter push name: "
read push_name

git add ./header/*.h ./header/SDL/*.h ./source/*.cpp ./scripts/header/*.h ./scripts/source/*.cpp ./fonts/* ./README.md ./Makefile ./push.sh
git commit -m $push_name
git push origin main