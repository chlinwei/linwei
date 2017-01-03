PROJ = server
OBJS = main.o server.o serversocket.o \
	   logthread.o clientthread.o storethread.o \
	   logqueue.o filedao.o oracledao.o
CXX  = g++
RM   = rm -rf
CFLAGS = -c -Wall -I. -D_DEBUG
LIBS = -lpthread -lclntsh
$(PROJ): $(OBJS)
	$(CXX) $^ $(LIBS) -o $@
.cpp.o:
	$(CXX) $(CFLAGS) $^
clean:
	$(RM) $(PROJ) $(OBJS) *.gch
