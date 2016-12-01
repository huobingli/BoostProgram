CC = g++
XX = g++
CFLAGS = -Wall -D_REENTRANT -g -std=c++11
INCLUDE = ../../boost/boost/lib
#STDLIB = -stdlib=libc++

LIBS = -lpthread -lrt -lboost_system -lboost_filesystem
OBJS = boost_socket.cpp
TEST = boost_socket

%.o: %.c
	$(CC)  $(CFLAGS) $(INCLUDE) -c $< -o $@
%.o: %.cpp
	$(CC)  $(CFLAGS) $(STDLIB) $(INCLUDE) -c $< -o $@

all: $(TEST)

$(TEST): $(OBJS)
	$(XX) $(STDLIB) -o $(TEST) $(OBJS) $(LIBS)

clean:
	rm -f *.o
