monkey :
	g++ -std=c++11 main.cpp -o monkey

clean :
	rm monkey

test :
	./monkey > output.txt
	diff correct.txt output.txt