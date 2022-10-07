all: main

main:
	@gcc src/*.cpp -o main

clean:
	@rm main
