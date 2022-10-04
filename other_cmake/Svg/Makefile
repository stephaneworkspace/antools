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

SWEOBJ = svg_data.o

# create an archive

libSVG.a: $(SWEOBJ)
	ar r libSvg.a	$(SWEOBJ)

clean:
	rm -f *.o libSvg *.a

###
svg_data.o:
	c++ $(FLAGO) -c svg_data.cpp