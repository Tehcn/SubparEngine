PROJECT_INCLUDE_PATH=libs/include
PROJECT_LIB_PATH=libs/lib
CC=g++

all: compile run

compile:
	echo "compiling..."
	rm -r dist/
	mkdir dist
	$(CC) -I$(PROJECT_INCLUDE_PATH) -L$(PROJECT_LIB_PATH) -o dist/main.exe src/*.cpp src/engine/*.cpp src/render/*.cpp -lglew32 -lglfw3 -lopengl32 -pthread -libstdc++
	cp libs/lib/glew32.dll dist/glew32.dll 
	cp libs/lib/glfw3.dll dist/glfw3.dll
	cp -r shaders/ dist/shaders
	echo "compiled to dist/main.exe"

run:
	echo "running..."
	./dist/main.exe
