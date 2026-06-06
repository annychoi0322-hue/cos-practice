CC=g++                                 // 사용 컴파일러 지정
SRCS=$(wildcard *.cpp)                 // 현재 디렉토리의 모든 .cpp 파일 목록
DATA_SRCS=$(wildcard data/*.cpp)       // data 폴더 안의 모든 .cpp 파일 목록
OBJS=$(SRCS:.cpp=.o)                   // SRCS에 대응되는 .o 파일 목록
DATA_OBJS=$(DATA_SRCS:.cpp=.o)         // DATA_SRCS에 대응되는 .o 파일 목록

all: edge      // 기본 실행 타켓 (make 입력 시 실행)

edge: $(OBJS) $(DATA_OBJS)     // 최종 실행 파일 생성 규칙
	$(CC) -o $@ $^

%.o: %.cpp                     // 일반 cpp 파일을 object 파일로 컴파일하는 규칙
	$(CC) -c $< -o $@          // $< : 첫 번째 dependency, $@ : target

data/%.o: data/%.cpp           // data 폴더 안 cpp 파일을 object 파일로 컴파일하는 규칙
	$(CC) -c $< -o $@        

clean:                                // 빌드 결과 삭제
	$(RM) edge $(OBJS) $(DATA_OBJS)   // edge 실행파일 + 모든 .o 파일 제거
