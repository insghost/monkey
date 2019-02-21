monkey :
	g++ -std=c++11 main.cpp -o monkey

clean :
	rm monkey

test : test19 test18 testBadArgs

test19 :
	./monkey 19 > output.txt
	diff tests/test19.txt output.txt

test18 :
	./monkey 18 > output.txt
	diff tests/test18.txt output.txt

testBadArgs :
	./monkey > output.txt
	diff tests/testBadArgs.txt output.txt