#include <stdio.h>
int foo (int x);
int jupiter(int x);
int mercury(int x, int y);
int main(void){
 int x = 20, y = 30, z = 10;
 y = foo(x++);
 y = jupiter(z/x);
 printf("The values at point 4 of x y and z are %d %d %d\n", x,y,z);
 return 0;
}
int mercury(int x, int y) {
 int z;
 z = x + 2 * y;
 printf("The values at point 2 of x y and z are %d %d %d\n", x,y,z);
 return z;
}
int jupiter(int x){
 int y = mercury(3 % 4, ++x);
 printf("The values at point 3 of x and y are %d %d \n", x,y);
 return y++;
}
int foo(int x){
 printf("The value at point 1 of x is %d\n", x);
 return ++x;
}