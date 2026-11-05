all: testProgramacionDinamica

testProgramacionDinamica: main.o ProgramacionDinamica.o
	g++ main.o ProgramacionDinamica.o -o testProgramacionDinamica

main.o: main.cpp ProgramacionDinamica.h
	g++ -c main.cpp

ProgramacionDinamica.o: ProgramacionDinamica.cpp ProgramacionDinamica.h
	g++ -c ProgramacionDinamica.cpp

test: all
	./testProgramacionDinamica

clean:
	rm main.o ProgramacionDinamica.o testProgramacionDinamica
