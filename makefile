# Example SDL21V2
EXE=final

# Main target
all: $(EXE)

#  MinGW
ifeq "$(OS)" "Windows_NT"
CFLG=-O3 -Wall
LIBS=-lglut32cu -lglu32 -lopengl32
CLEAN=del *.exe *.o *.a
else
#  OSX
ifeq "$(shell uname)" "Darwin"
CFLG=-O3 -Wall -Wno-deprecated-declarations
LIBS=-framework OpenGL
#  Linux/Unix/Solaris
else
CFLG=-O3 -Wall
LIBS=-lGLU -lGL -lm
endif
#  OSX/Linux/Unix/Solaris
CLEAN=rm -f $(EXE) *.o *.a
endif

# Dependencies
tree.o: tree.cpp tree.hpp time.hpp
object.o: object.cpp object.hpp
renderer.o: renderer.cpp renderer.hpp
input.o: input.cpp input.hpp
error.o: error.cpp error.hpp
camera.o: camera.cpp camera.hpp
main.o: main.cpp main.hpp util.hpp

# Compile rules
.cpp.o:
	g++ -c -std=c++11 $(CFLG) $<

#  Link
final: main.o camera.o error.o input.o renderer.o object.o tree.o
	g++ -O3 -o $@ $^ $(LIBS) -lSDL2 -lSDL2_mixer

#  Clean
clean:
	$(CLEAN)
