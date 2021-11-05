echo "Enter push name: "
read push_name

git add ./header/*.h ./header/3D/*.h ./header/SDL/*.h ./source/*.cpp ./source/3D/*.cpp ./scripts/header/*.h ./scripts/source/*.cpp ./fonts/* ./tools/* ./README.md ./Makefile
git commit -m "$push_name"
git push origin main