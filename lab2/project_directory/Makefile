output: src/course.o src/student.o src/teacher.o src/main.o
	g++ src/course.o src/student.o src/teacher.o src/main.o -o output.out

src/course.o: src/course.cpp include/course.h
	g++ -Wall -c src/course.cpp -o src/course.o -Iinclude

src/student.o: src/student.cpp include/student.h
	g++ -Wall -c src/student.cpp -o src/student.o -Iinclude

src/teacher.o: src/teacher.cpp include/teacher.h
	g++ -Wall -c src/teacher.cpp -o src/teacher.o -Iinclude

src/main.o: src/main.cpp include/student.h include/teacher.h include/course.h
	g++ -Wall -c src/main.cpp -o src/main.o -Iinclude

clean:
	rm src/*.o output.out
