all:
	g++ -O3 -std=c++17 -I ./header -I ./scripts/header -o ./engine ./source/*.cpp ./scripts/source/*.cpp ./source/3D/*.cpp -L"lib" -Wall -lSDL2main -lSDL2 -lSDL2_ttf -pthread
	./engine
compile:
	g++ -O3 -std=c++17 -I ./header -I ./scripts/header -o ./engine ./source/*.cpp ./scripts/source/*.cpp ./source/3D/*.cpp -L"lib" -Wall -lSDL2main -lSDL2 -lSDL2_ttf -pthread
run:
	./engine
push:
	./tools/push.sh
release:
	g++ -std=c++17 -I ./header -I ./scripts/header -o ./engine ./source/*.cpp ./scripts/source/*.cpp ./source/3D/*.cpp -L"lib" -Wall -lSDL2main -lSDL2 -lSDL2_ttf -pthread
	./tools/push.sh
	./tools/release.sh
