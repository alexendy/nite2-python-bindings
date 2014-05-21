# location of the Python header files
 
PYTHON_VERSION = 2.7
PYTHON_INCLUDE = /usr/include/python$(PYTHON_VERSION)
PYTHON_LIB=/usr/lib/python$(PYTHON_VERSION)/config

# location of the Boost Python include files and library

BOOST_INC = /usr/include
BOOST_LIB = /usr/lib

CC=g++


CFLAGS=-c -fPIC -std=c++0x -Wall -I$(OPENNI2_INCLUDE) -I$(NITE2_INCLUDE) -I$(PYTHON_INCLUDE) -I$(BOOST_INC)
LDFLAGS=-fPIC -shared -std=c++0x -L$(NITE2_REDIST) -L$(OPENNI2_REDIST) -L$(BOOST_LIB) -L$(PYTHON_LIB) -lNiTE2 -lOpenNI2 -lpthread -lpython$(PYTHON_VERSION) -lboost_python-py27
SRC=nite_b.cpp usertrackerframeref_b.cpp usertracker_b.cpp userdata_b.cpp skeleton_b.cpp skeletonjoint_b.cpp bindings.cpp
OBJ=$(SRC:.cpp=.o)
NAME=nite2.so



# compile mesh classes
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $< $(CFLAGS) -o $@



clean:
	rm -f $(OBJ) $(NAME)
#TARGET = hello_ext
 
#$(TARGET).so: $(TARGET).o
#	g++ -shared -Wl,--export-dynamic $(TARGET).o -L$(BOOST_LIB) -lboost_python-py27 -L/usr/lib/python$(PYTHON_VERSION)/config -lpython$(PYTHON_VERSION) -o $(TARGET).so
 
#$(TARGET).o: $(TARGET).C
#	g++ -I$(PYTHON_INCLUDE) -I$(BOOST_INC) -fPIC -c $(TARGET).C
