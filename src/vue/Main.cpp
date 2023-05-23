#include"../utile/Date.h"
#include<iostream>
int main(){
    Date date1(1,2,2022);
    Date date2(1,2,2022);
    printf("date1 < date 2 : %s\n", date1 == date2 ? "true" : "false");
    return 0;
}