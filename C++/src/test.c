#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>



void testProductSet() {
    int randomData = open("/dev/urandom", O_RDONLY);
    
    unsigned int n;
    
    read(randomData, &n, sizeof(n));
    n = n % 20 + 1;
    printf("%d\n", n);
    int i;
    for (i = 0; i < n; i++) {
        unsigned int k;
        int x;
        read(randomData, &k, sizeof(k));
        x = k % 1000 - 500;
        printf("%d ", x);
    }
    printf("\n");
    
    unsigned int n1;
    read(randomData, &n1, sizeof(n1));
    n1 = n1 % 20 + 1;
    printf("%d\n", n1);
    for (i = 0; i < n1; i++) {
        unsigned int k;
        int x;
        read(randomData, &k, sizeof(k));
        x = k % 1000 - 500;
        printf("%d ", x);
    }
    printf("\n");
    close(randomData);
}

void testBooleanMatrix() {
    int randomData = open("/dev/urandom", O_RDONLY);
    
    unsigned int r, c;
    read(randomData, &r, sizeof(r));
    r = r % 10 + 1;
    read(randomData, &c, sizeof(c));
    c = c % 10 + 1;
    printf("%d %d\n", r, c);
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            unsigned int b;
            read(randomData, &b, sizeof(b));
            b = b % 2;
            printf("%d ", b);
        }
    }
    printf("\n");

    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            unsigned int b;
            read(randomData, &b, sizeof(b));
            b = b % 2;
            printf("%d ", b);
        }
    }
    printf("\n");

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            unsigned int b;
            read(randomData, &b, sizeof(b));
            b = b % 2;
            printf("%d ", b);
        }
    }
    printf("\n");

    close(randomData);
}

void testDigraph() {
    int randomData = open("/dev/urandom", O_RDONLY);
    
    unsigned int r;
    read(randomData, &r, sizeof(r));
    r = r % 10 + 1;
    printf("%d\n", r);
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            unsigned int b;
            read(randomData, &b, sizeof(b));
            b = b % 2;
            printf("%d ", b);
        }
    }
    printf("\n");
    
    for (i = 0; i < r; i++) {
        unsigned int b;
        int ele;
        read(randomData, &b, sizeof(b));
        ele = b % 400 - 200;
        printf("%d ", ele);
    }
    printf("\n");
    
    unsigned int n;
    read(randomData, &n, sizeof(n));
    n = n % r;
    printf("%d\n", n);
    
    read(randomData, &n, sizeof(n));
    n = n % r;
    printf("%d\n", n);
    
    read(randomData, &n, sizeof(n));
    n = n % r;
    printf("%d\n", n);
    
    close(randomData);
}

void testRelation() {
    int randomData = open("/dev/urandom", O_RDONLY);
    
    unsigned int r, c;
    read(randomData, &r, sizeof(r));
    r = r % 10 + 1;
    read(randomData, &c, sizeof(c));
    c = c % 10 + 1;
    printf("%d %d\n", r, c);
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            unsigned int b;
            read(randomData, &b, sizeof(b));
            b = b % 2;
            printf("%d ", b);
        }
    }
    printf("\n");

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            unsigned int b;
            read(randomData, &b, sizeof(b));
            b = b % 2;
            printf("%d ", b);
        }
    }
    printf("\n");
}

int main(void) {
    testBooleanMatrix();
    testDigraph();
    testRelation();
    return 0;
}

