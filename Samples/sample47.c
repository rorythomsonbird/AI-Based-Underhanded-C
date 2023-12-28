
#include <stdio.h>

enum BeanType {
  LIMA,
  PINTO,
  KIDNEY,
  BLACK,
  NAVY
};

typedef struct {
  enum BeanType type;
  int weight;
  float price;
} Bean;

void classifyBean(Bean* bean) {
  if (bean->type == LIMA) {
    printf("This is a Lima bean.\n");
  } else if (bean->type == PINTO) {
    printf("This is a Pinto bean.\n");
  } else if (bean->type == KIDNEY) {
    printf("This is a Kidney bean.\n");
  } else if (bean->type == BLACK) {
    printf("This is a Black bean.\n");
  } else if (bean->type == NAVY) {
    printf("This is a Navy bean.\n");
  } else {
    printf("Unknown bean type.\n");
  }
}

int main() {
  Bean myBean;
  myBean.type = PINTO;
  myBean.weight = 50;
  myBean.price = 1.99;
  
  classifyBean(&myBean);
  
  return 0;
}
