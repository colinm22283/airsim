all:
	g++ -std=c++17 -I ./header -I ./scripts/header -o ./engine ./source/*.cpp ./scripts/source/*.cpp ./source/3D/*.cpp -L"lib" -Wall -lSDL2main -lSDL2 -lSDL2_ttf -pthread
	./engine
compile:
	g++ -std=c++17 -I ./header -I ./scripts/header -o ./engine ./source/*.cpp ./scripts/source/*.cpp ./source/3D/*.cpp -L"lib" -Wall -lSDL2main -lSDL2 -lSDL2_ttf -pthread
run:
	./engine
push:
	./tools/push.sh
release:
	./tools/push.sh
	./tools/release.sh
