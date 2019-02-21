monkey :
	g++ -std=c++11 main.cpp -o monkey

clean :
	rm monkey

test :
	./monkey < input.txt > output.txt
	diff correct.txt output.txt