CFLAGS= -g -Wall -fPIC
OP=$(CFLAGS)
#-target arm64-apple-ios
FLAGO=$(ARGUMENTS) -std=c++2a -stdlib=libc++
CC=clang++ $(ARGUMENTS)

# compilation rule for general cases
.o :
	$(CC) $(OP) -o $@ $? -lm
.c.o:
	$(CC) -c $(OP) $<

SWEOBJ = circle.o data.o

# create an archive

libSVG.a: $(SWEOBJ)
	ar r libSvg.a	$(SWEOBJ)

clean:
	rm -f *.o libSvg *.a

###
circle.o:
	c++ $(FLAGO) -c circle.cpp
data.o:
	c++ $(FLAGO) -c data.cpp