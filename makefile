all:
	g++ -std=c++0x TwoOpt.cpp TwoOptMain.cpp -o TwoOptMain
clean:
	rm -rf a.out *.o TwoOptMain