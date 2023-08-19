// macro

#define ARRAY_SIZE(x) ( sizeof((x))/sizeof((x)[0]) ) // 배열의 길이
#define ABS(x)        ( ((x)<0)?-(x):(x) ) // 절대값
#define SQUARE(x)     ( (x)*(x) ) // 제곱근
#define UPCASE(c)     ( ((c)>='a'&&(c)<='z')?(c)-('a'-'A'):(c) ) // 소문자 -> 대문자
#define LOWCASE(c)    ( ((c)>='A'&&(c)<='z')?(c)+('a'-'A'):(c) ) // 대문자 -> 소문자
#define MAX(x,y)      ( (x)>(y)?(x):(y) ) // 최대 값
#define MIN(x,y)      ( (x)<(y)?(x):(y) ) // 최소 값