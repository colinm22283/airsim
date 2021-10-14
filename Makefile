all:
	g++ -std=c++17 -I ./header -I ./scripts/header -o ./platformer ./source/*.cpp ./scripts/source/*.cpp -L"lib" -Wall -lSDL2main -lSDL2 -lSDL2_ttf -pthread
	./platformer
compile:
	g++ -std=c++17 -I ./header -I ./scripts/header -o ./platformer ./source/*.cpp ./scripts/source/*.cpp -L"lib" -Wall -lSDL2main -lSDL2 -lSDL2_ttf -pthread
run:
	./platformer
push:
	./push.sh
	# git add ./header/*.h ./header/SDL/*.h ./source/*.cpp ./scripts/header/*.h ./scripts/source/*.cpp ./fonts/* ./README.md ./Makefile ./push.sh
	# git commit -a -m "Added more console printing functions"
	# git push origin main
