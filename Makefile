all:
	g++ -fno-elide-constructors myInt.cpp main.cpp -o run.exe
dot:
	dot -Tpng grvz.dot -o output4.png