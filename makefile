
CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time

OBJS = ant.o board.o main.o menu.o inputValidation.o

SRCS = ant.cpp board.cpp main.cpp menu.cpp inputValidation.cpp

HEADERS = ant.hpp board.hpp menu.hpp inputValidation.hpp

#target: dependencies
#	rule to build
#

matrix: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o ant

#${OBJS}: ${SRCS}
#	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
