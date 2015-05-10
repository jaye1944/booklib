MAIN = bin/mycc
OUT = lib/alib.a
CC = gcc
ODIR = obj
SDIR = src
INC = -I include
CFLAGS = -Wall -g
LFLAGS = -L../lib
LIBS = -lsqlite3

_OBJS = main.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))


$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -c $(INC) -o $@ $< $(CFLAGS) 

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(MAIN)
