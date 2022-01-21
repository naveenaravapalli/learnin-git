#include<stdio.h>
#include<string.h>

int main(){
    char colorName[128];
    printf(" What color is the light: ");
    scanf("%s", colorName);

    if ( strcmp(colorName, "red") == 0 ){
         printf(" Stop!\n");
    }else  if ( strcmp(colorName, "green") == 0 ){
         printf("cross the road\n");
    }else {
         printf("is %s even a color?\n", colorName);
    }
    return 0;
}
