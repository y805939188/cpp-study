#include "ding.h"

int func(int a){
  return a;
}

int func(double a){
  return int(a);
}

int func(int a, double b){
  return a + int(b);
}
