CPP=g++ -std=c++11 

build: build-debug

build-debug: CPP += -ggdb
build-debug: lib/libJson.a

build-release: lib/libJson.a

sample: lib/libJson.a
	$(CPP) -o sample sample.cpp lib/libJson.a

###############
##
##	clean
##
###############
clean:
	rm lib/* *.o  sample

###############
##
##	build
##
###############
lib/libJson.a: *.o
	ar ru lib/libJson.a *.o

###############
##
##	compile json
##
###############

*.o: *.cpp *.hpp
	$(CPP) -I/usr/include -c *.cpp

	


	

