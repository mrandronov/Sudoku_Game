
build:
        @mkdir -p build
        cd build && cmake .. && make

exec:
        ./build/GUITest

clean:
        @rm -rf build

run: build exec

new: clean build exec
