CC = g++
AR = ar
SWIGEXEC = swig
SWIGLD = $(CC)

SRC = src
INC = inc
OBJ = obj
BIN = bin
LIB = lib
SWIG = swig
TOOLS = tools
SCRIPTS = scripts
WAVESLIB = $(LIB)/libvrend.a

ARFLAGS=rvs
CFLAGS+=-g -Wall -I$(INC) -std=c++0x -c -fPIC
TOOL_CFLAGS += -Wall -I$(INC) -std=c++0x -L$(LIB)

LDFLAGS+=-lfftw3
TOOL_LDFLAGS += -lrt -lwaves -lpng -lfftw3 -lGL -lGLU -lglut

SWIGCFLAGS += -c -I$(INC) -I/usr/include/python2.7
SWIGLDFLAGS += -L$(LIB) -lpython2.7 -lwaves -lpng -lfftw3
SWIGFLAGS+=-c++ -python -shadow -I$(INC) -outdir $(LIB)

SOURCES=$(wildcard $(SRC)/*.cpp)
TOOL_SOURCES=$(wildcard $(TOOLS)/*.cpp)
OBJECTS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))
SWIGI = $(wildcard $(SWIG)/*.i)
SWIGROOTS = $(SWIG)/vrend.i
TOOL_EXECUTABLES = $(patsubst $(TOOLS)/%.cpp, $(BIN)/%, $(TOOL_SOURCES))

SWIGWRAPS = $(patsubst $(SWIG)/%.i, $(SWIG)/%_wrap.cxx, $(SWIGROOTS))
SWIGSOS = $(patsubst $(SWIG)/%.i, $(LIB)/_%.so, $(SWIGROOTS))
SWIGPYS = $(patsubst $(SWIG)/%.i, $(LIB)/%.py, $(SWIGROOTS))
SWIGPYLINKS = $(patsubst $(LIB)/%.py, $(SCRIPTS)/%.py, $(SWIGPYS))
SWIGSOLINKS = $(patsubst $(LIB)/%.so, $(SCRIPTS)/%.so, $(SWIGSOS))

-include custom.mk

all: debug

## 'make release' to not print debug info.
release: setreleaseflag everything

setreleaseflag:
	$(eval CFLAGS += -DRELEASE)

debug: everything

everything: directories $(SOURCES) $(WAVESLIB) $(TOOL_EXECUTABLES) genswig

## generate swig interfaces and softlinks in scripts/ directory.
genswig: $(SWIGSOS) $(SWIGPYLINKS) $(SWIGSOLINKS)

## clean up base code, swig, and pyc's
clean: cleanbase cleanswig cleanpyc

cleanbase:
	rm -f $(OBJ)/*.o
	rm -f $(TOOL_EXECUTABLES)
	rm -f $(WAVESLIB)
	
cleanswig:
	rm -f $(SWIGSOS) $(SWIGPYS) $(SWIGPYLINKS) $(SWIGSOLINKS)

cleanpyc:
	rm -f $(LIB)/*.pyc
	rm -f $(SCRIPTS)/*.pyc
  
directories: $(LIB) $(OBJ) $(BIN)

## generates static library
$(WAVESLIB): $(OBJECTS)
	$(AR) $(ARFLAGS) $(WAVESLIB) $(OBJECTS)

## generates tool executables
bin/%: $(TOOLS)/%.cpp $(WAVESLIB)
	$(CC) $(TOOL_CFLAGS) $< -o $@ $(TOOL_LDFLAGS)

## generates object files from library
$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

$(LIB):
	mkdir -p $(LIB)

$(OBJ):
	mkdir -p $(OBJ)

$(BIN):
	mkdir -p $(BIN)

## generates softlinks to swig python libraries
$(SCRIPTS)/%.py: $(SWIGSOS)
	ln -sf ../$(LIB)/$*.py $@

## generates softlinks to swig shared libraries
$(SCRIPTS)/%.so: $(SWIGSOS)
	ln -sf ../$< $@

## generates swig wrapper code
$(SWIG)/%_wrap.cxx: $(SWIG)/%.i
	$(SWIGEXEC) $(SWIGFLAGS) $<

$(LIB)/%.py: $(SWIG)/%_wrap.o

## generates swig wrapper object
$(SWIG)/%_wrap.o: $(SWIG)/%_wrap.cxx
	$(CC) -fPIC $(SWIGCFLAGS) $< -o $@

## generates swig shared library
$(LIB)/_%.so: $(SWIG)/%_wrap.o
	$(SWIGLD) -fPIC -g -shared  $< -o $@ $(SWIGLDFLAGS)
