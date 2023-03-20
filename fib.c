//Marcos Gómez Tejón---------------------m.tejon
//Iván Álvarez Fernández--ivan.alvarez.fernandez
//Práctica 1, grupo 1.4


#include <stdio.h>
#include <sys/time.h>
#include <math.h>

int fib1(int n);
int fib2(int n);
int fib3(int n);
double microsegundos();
void printer1();
void printer2();
void printer3();
void test();

int main(){
    printer1();
    printer2();
    printer3();
    test();
}

int fib1(int n){
    if(n<2){
        return n;
    } else{
        return fib1(n-1)+ fib1(n-2);
    }
}

int fib2(int n){
    int i=1, j=0,k;

    for(k=1; k<=n; k++){
        j=i+j;
        i=j-i;
    }
    return j;
}

int fib3(int n){
    int i=1, j=0, k=0, h=1, t;
    while(n>0){
        if(n%2!=0){
            t=j*h;
            j=i*h+j*k+t;
            i=i*k+t;
        }
        t=h*h;
        h=2*k*h+t;
        k=k*k+t;
        n=n/2;
    }
    return j;
}

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0)
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

void printer1(){
    int n,i;
    double t1, t2, x, y, z, t;
    for(n=2;n<=32;n=n*2){
        t1 = microsegundos();
        fib1(n);
        t2 = microsegundos();
        t = t2-t1;
        if(t<500){
            t1=microsegundos();
            for(i=0;i<100000;i++){
                fib1(n);
            }
            t2=microsegundos();
            t=(t2-t1)/100000;
            x = t / pow(1.1,n);
            y = t / pow((((1+sqrt(5))/2)),n);
            z = t / pow(2,n);
            printf("(*)%12d%15.5lf%15.9lf%15.9lf%15.9lf\n", n, t, x, y, z);
        } else{
            x = t / pow(1.1,n);
            y = t / pow((((1+sqrt(5))/2)),n);
            z = t / pow(2,n);
            printf("   %12d%15.5lf%15.9lf%15.9lf%15.9lf\n", n, t, x, y, z);
        }
        
    }
    printf("\n");
}

void printer2(){
    int n,i;
    double t1, t2, x, y, z, t;
    for(n=1000;n<=10000000;n=n*10){
        t1 = microsegundos();
        fib2(n);
        t2 = microsegundos();
        t = t2-t1;
        if(t<500){
            t1=microsegundos();
            for(i=0;i<1000;i++){
                fib2(n);
            }
            t2=microsegundos();
            t=(t2-t1)/1000;
            x = t / pow(n,0.8);
            y = t / n;
            z = t / (n*log(n));
            printf("(*)%12d%15.5lf%15.9lf%15.9lf%15.9lf\n", n, t, x, y, z);
        } else{
            x = t / pow(n,0.8);
            y = t / n;
            z = t / (n*log(n));
            printf("   %12d%15.5lf%15.9lf%15.9lf%15.9lf\n", n, t, x, y, z);
        }     
    }
    printf("\n");
}

void printer3(){
    int n,i;
    double t1, t2, x, y, z, t;
    for(n=1000;n<=10000000;n=n*10){
        t1 = microsegundos();
        fib3(n);
        t2 = microsegundos();
        t = t2-t1;
        if(t<500){
            t1=microsegundos();
            for(i=0;i<10000;i++){
                fib3(n);
            }
            t2=microsegundos();
            t=(t2-t1)/10000;
            x = t / sqrt(log(n));
            y = t / log(n);
            z = t / pow(n, 0.5);
        printf("(*)%12d%15.5lf%15.9lf%15.9lf%15.9lf\n", n, t, x, y, z);
        } else{
        x = t / sqrt(log(n));
        y = t / log(n);
        z = t / pow(n, 0.5);
        printf("%12d%15.5lf%15.9lf%15.9lf%15.9lf\n", n, t, x, y, z);
        }
    }
    printf("\n");
}

void test(){
    printf("\n\tFIB1\tFIB2\tFIB3\n");
    for(int i=1;i<15;i++){
        printf("n=%i\t%i\t", i, fib1(i));
        printf("%i\t",fib2(i));
        printf("%i\n",fib3(i));
        printf("\n");
    }
}