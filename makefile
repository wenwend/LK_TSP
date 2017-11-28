all:
	g++ TwoOpt.cpp TwoOptMain.cpp -o TwoOptMain
clean:
	rm -rf a.out *.o TwoOptMain