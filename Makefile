build: *.cpp *.h
	g++ -g -o drum.out *.cpp -lSDL2 -lSDL2_mixer
