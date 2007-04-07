MAKE = make
QMAKE = qmake
MAKEFILE = Makefile

first: all

all: Makefile
	$(QMAKE) lib/lib.pro -o lib/$(MAKEFILE) && cd lib && $(MAKE)
clean:
	cd lib && $(QMAKE) && $(MAKE) clean
dummy:
