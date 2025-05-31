FLEX := win_flex
BISON := win_bison
CC := g++
CXXFLAGS := -Wall \
			-g \
			-I.
TARGET := compiler.exe

all: lex.yy.cpp l25.tab.cpp
	$(CC) $(CXXFLAGS) *.cpp -o $(TARGET)

lex.yy.cpp: l25.lex
	$(FLEX) -o lex.yy.cpp l25.lex

l25.tab.cpp: l25.y
	$(BISON) -d -t -v l25.y -o l25.tab.cpp

