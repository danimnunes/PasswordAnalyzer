CXX = g++
CXXFLAGS = -std=c++17 -Wall
LIBS = -lcurl -lssl -lcrypto

SRC = main.cpp APIClient.cpp PasswordAnalyzer.cpp
OBJ = $(SRC:.cpp=.o)
OUT = password_analyzer

$(OUT): $(OBJ)
	$(CXX) $(OBJ) -o $(OUT) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(OUT)
