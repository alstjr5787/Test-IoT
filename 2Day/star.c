/*
﻿제약 : 50 이하의 정수가 입력됨을 가정합니다.﻿ 


1단계 
--------
N? 5
*
**
***
****
*****

2단계
N? 5
*****
****
***
**
*

3단계
N? 5
    *
   **
  ***
 ****
*****

4단계
N? 5
 *****
  ****
   ***
    **
     *

5단계 - 마름모
(홀수만가능)
N? 5
   *
  ***
 *****
  ***
   *
*/

#include <stdio.h>

int main()
{
    for(int i=0;i<5,i=i++;)
    {
        for(int j=0;j<=5,j=i++;)
        printf("*");
        printf("\n");
    }
    
}
