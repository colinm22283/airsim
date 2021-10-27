all:
	g++ -std=c++17 -I ./header -I ./scripts/header -o ./airsim ./source/*.cpp ./scripts/source/*.cpp -L"lib" -Wall -lSDL2main -lSDL2 -lSDL2_ttf -pthread
	./airsim
compile:
	g++ -std=c++17 -I ./header -I ./scripts/header -o ./airsim ./source/*.cpp ./scripts/source/*.cpp -L"lib" -Wall -lSDL2main -lSDL2 -lSDL2_ttf -pthread
run:
	./airsim
push:
	./tools/push.sh
release:
	./tools/push.sh
	./tools/release.sh
