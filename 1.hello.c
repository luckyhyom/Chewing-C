#include <stdio.h>
/*
    1. include : 외부 파일의 내용을 해당 파일에 복사해온다.
    2. stdio.h : 입/출력에 대한 메시지를 전달하는 코드. (CPU -> 운영체제 -> 하드웨어)
    3. main의 첫번째 명령어는 프로그램의 진입점이다. (시작 명령어를 레지스터에 등록한다.)
 */

int main(void)
{
    printf("hello world \n");
    return 0;
}