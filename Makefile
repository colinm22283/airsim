all:
	g++ -std=c++17 -I ./header -I ./scripts/header -o ./platformer ./source/*.cpp ./scripts/source/*.cpp -L"lib" -Wall -lSDL2main -lSDL2 -lSDL2_ttf -pthread
	./platformer
compile:
	g++ -std=c++17 -I ./header -I ./scripts/header -o ./platformer ./source/*.cpp ./scripts/source/*.cpp -L"lib" -Wall -lSDL2main -lSDL2 -lSDL2_ttf -pthread
run:
	./platformer
push:
	./tools/push.sh
release:
	./tools/release.sh