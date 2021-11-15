#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() { FILE *inp; char c; inp = fopen("input.txt", "r"); int count = 0; char buf[10000]; int *arr = (int*)calloc(1000, sizeof(int)); while (fscanf(inp, "%s", buf) != EOF) {arr[strlen(buf)]++;} fclose(inp); FILE *out = fopen("output.txt", "w"); for (int i = 1; i < 1000; i++) { if (arr[i]) {fprintf(inp, "%d - %d\n", i, arr[i]);} } free(arr); fclose(out); return 0; }