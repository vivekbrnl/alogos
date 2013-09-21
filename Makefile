CXXFLAGS =	-O2 -g -Wall -fmessage-length=0
FILENAME = heapSort
OBJS =	$(FILENAME).o

LIBS =

DIR = src

TARGET =	Main.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

$(FILENAME).o: $(DIR)/$(FILENAME).c
	gcc -c $(DIR)/$(FILENAME).c -o $(FILENAME).o

run:
	make all
	Main.exe
	make clean

clean:
	del -f $(OBJS) $(TARGET)
