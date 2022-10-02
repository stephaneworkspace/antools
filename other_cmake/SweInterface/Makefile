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

SWEOBJ = angle.o aspect.o astre.o draw.o draw_aspect_line.o draw_bodie_astre.o draw_bodie_line.o\
draw_zodiac_circle.o draw_zodiac_line.o draw_zodiac_sign.o draw_house_angle.o draw_house_line.o draw_house_number.o\
swe02.o swe03.o swe08.o swe14.o swe17.o house.o sign.o timezone.o SweInterface.o

# create an archive and a dynamic link libary fro SwissEph
# a user of this library will inlcude swephexp.h  and link with -lswe

libSweInterface.a: $(SWEOBJ)
	ar r libSweInterface.a	$(SWEOBJ)

clean:
	rm -f *.o libSweInterface* *.a

###
angle.o:
	c++ $(FLAGO) -c angle.cpp
aspect.o:
	c++ $(FLAGO) -c aspect.cpp
astre.o:
	c++ $(FLAGO) -c astre.cpp
draw.o:
	c++ $(FLAGO) -c draw.cpp
draw_aspect_line.o:
	c++ $(FLAGO) -c draw_aspect_line.cpp
draw_bodie_astre.o:
	c++ $(FLAGO) -c draw_bodie_astre.cpp
draw_bodie_line.o:
	c++ $(FLAGO) -c draw_bodie_line.cpp
draw_house_angle.o:
	c++ $(FLAGO) -c draw_house_angle.cpp
draw_house_line.o:
	c++ $(FLAGO) -c draw_house_line.cpp
draw_house_number.o:
	c++ $(FLAGO) -c draw_house_number.cpp
draw_zodiac_circle.o:
	c++ $(FLAGO) -c draw_zodiac_circle.cpp
draw_zodiac_line.o:
	c++ $(FLAGO) -c draw_zodiac_line.cpp
draw_zodiac_sign.o:
	c++ $(FLAGO) -c draw_zodiac_sign.cpp
swe02.o:
	c++ $(FLAGO) -c swe02.cpp
swe03.o:
	c++ $(FLAGO) -c swe03.cpp
swe08.o:
	c++ $(FLAGO) -c swe08.cpp
swe14.o:
	c++ $(FLAGO) -c swe14.cpp
swe17.o:
	c++ $(FLAGO) -c swe17.cpp
house.o:
	c++ $(FLAGO) -c house.cpp
sign.o:
	c++ $(FLAGO) -c sign.cpp
timezone.o:
	c++ $(FLAGO) -c timezone.cpp
SweInterface.o:
	c++ $(FLAGO) -c SweInterface.cpp