CC=g++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lX11
SRCS=src/main.cpp src/button.cpp src/buttonListener.cpp src/buttonEvent.cpp
HEADERS=src/button.h src/buttonListener.h src/buttonEvent.h
EXEDIR=bin
OUTFILE=main

exec : $(EXEDIR)
	$(CC) -o $(EXEDIR)/$(OUTFILE) $(HEADERS) $(SRCS) $(CFLAGS)
	$(EXEDIR)/$(OUTFILE)


$(EXEDIR):
	mkdir $(EXEDIR)


.PHONY : clean
clean : $(OBJS)
		find . -name "*~" -exec rm {} \;
		find . -name "#*#" -exec rm {} \;
