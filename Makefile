all :
	g++ *.cpp -w -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -o cyborg-battle.out

clean :
	rm cyborg-battle.out