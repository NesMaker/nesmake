all: main

main:
	@g++ src/compstr/*.cpp -c -o compstr.o
	@g++ src/stdnes/*.cpp -c -o stdnes.o
	@g++ src/*.cpp -c -o main.o
	@g++ -o main main.o compstr.o stdnes.o
	@rm *.o

clean:
	@rm main
