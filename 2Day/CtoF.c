/*
프로그램 명: CtoF

섭씨 온도를 화씨 온도로 변환하는 프로그램을 작성하세요.

화씨 온도 = 9 / 5 * 섭씨온도 + 32

입력
1 에서 100 사이의 자연수가 입력으로 주어진다.

출력
소수점 둘째자리까지 출력한다.

입출력 예
-----------------------------------------------------------
50

122.0  

--------------------------------------
36

96.8
/*


#include <stdio.h> 

int main() 
{ 
    int a; 
    double f; 

    scanf("%d", &a); 
    f = (9 / 5.0 *a) + 32; 
    printf("%.1f \n", f); 

    return 0; 
}
