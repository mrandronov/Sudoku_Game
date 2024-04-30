
build:
        @mkdir -p build
        cd build && cmake .. && make

exec:
        ./build/SudokuApp

clean:
        @rm -rf build

run: build exec

new: clean build exec
