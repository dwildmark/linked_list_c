
CC = gcc

CFLAGS = -Wall -Werror

INCLUDES = -I./include

SRCS = src/linked_list.c \
        src/unity.c \
        src/test.c

OBJS = $(SRCS:.c=.o)

MAIN = list_test

.PHONY: depend clean

all:    $(MAIN)

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE
