#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float max = 0;
int a, b;

struct dots{
    int x,y,z;
} *dot, *top;

//void test(struct dots);
void distance(int, int, int, int, int, int, int, int);

int main(){
    srand(time(NULL));
    int i, n; 
    printf("enter n\n");
    scanf("%d",&n);
    dot = malloc(n * sizeof(struct dots));
    top = dot;
    for (i=0;i<n;i++) {      
        dot->x = rand()%10;
        dot->y = rand()%10;
        dot->z = rand()%10;
        dot++;
    }
    dot = top;
    for (i = 0; i < n; i++)
    {
        printf("dot [%d]: %d %d %d \n", i+1, dot->x, dot->y, dot->z);
        dot++;
    }
    dot = top;
    
    
    /*
    for (i=0;i<n;i++) {      
        printf("dot [%d]: %d %d %d \n", i+1, dot[i].x, dot[i].y, dot[i].z);
    }*/
    
    for (int i = 0; i < n; i++){
        for (int  j = i+1; j < n; j++){
            distance(dot->x, dot->y, dot->z, dot->x, dot->y, dot->z, i, j);
            dot++;
        }
    }
    dot = top;
    if (max == 0){
        printf("error\n");
        return(1);
    }
    else{
        printf("\nmax = %f\ndots: %d & %d\n", max, a+1,b+1);
    }
    
    return 0;
}
/*
void test(dot){
    for (int i = 0; i < n; i++){
        for (int  j = i+1; j < n; j++){
            sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
            //distance(dot[i].x, dot[j].x, dot[i].y, dot[j].y, dot[i].z, dot[j].z, i, j);
        }
    }
}
*/ 

void distance(int x1, int y1, int z1, int x2, int y2, int z2, int i, int j){
    float d;
    d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
    if (d > max){
        max = d;
        a = i;
        b = j;
    } 
}