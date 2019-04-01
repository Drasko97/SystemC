all: loto_d

loto_d: loto.cpp main.cpp
	g++ -std=c++11 -I ${SYSTEMC}/include -L${SYSTEMC}/lib-linux64 -lsystemc -o loto_d main.cpp loto.cpp

.PHONY: clean
clean:
	rm loto_*
