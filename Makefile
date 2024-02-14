all:
	g++ -fno-elide-constructors ./rsc/myInt.cpp ./src/main.cpp -o run.exe
dot:
	dot -Tpng ./logs/grvz.dot -o outputPics/output4.png