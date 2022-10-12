all: main

main:
	@g++ src/*.cpp -o main

clean:
	@rm main
