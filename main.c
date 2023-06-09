#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 63
#define N 4

int next(int arr[]) {
    int j = N;
    while (j > 0 && arr[j] == SIZE) arr[j--] = 1;
    if (j > 0) {
        arr[j]++;
        return 1;
    }
    return 0;
}

void main() {
    char abc[SIZE] = {0};
    int i = 0, *arr;
    for (char c = '0'; c <= 'z';) {
        if (c == ':' ||  c == '[' ||  c == ']' ||  c == '^' ||
            c == '<' ||  c == '>' ||  c == '@' ||  c == '`' ||
            c == ';' ||  c == '=' ||  c == '?' ||  c == '\\') {
            c++;
            continue;
        }
        abc[i++] = c++;
    }
    arr = (int *) calloc(N, sizeof(int));
    for (i = 1; i <= N; i++) arr[i] = 1;
    do {
        for (i = 1; i <= N; i++) printf("%c", abc[ arr[i] - 1 ]);
        printf("\n");
    } while (next(arr) != 0);
}
