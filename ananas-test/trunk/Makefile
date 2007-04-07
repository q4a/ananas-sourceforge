MAKE = make
MAKEFILE = Makefile

first: all

all: Makefile
	cd tests && $(MAKE)
clean:
	cd tests && $(MAKE) clean
dummy:

test: ananas.qpj tests-bin/libcoretest.so
	texttestrunner ananas.qpj

	
	
