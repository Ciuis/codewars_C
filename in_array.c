#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 * @param array1
 * @param sz1 sz1: size of array1
 * @param array2
 * @param sz2 sz2: size of array2
 * @param lg lg: size of the returned array
 * @return
 */

int compare(const void* a, const void* b);
char** inArray(char* array1[], int sz1, char* array2[], int sz2, int* lg);

int main() {
    int lg;
    char* arr1[3] = { "arp", "live", "strong" };
    char* arr2[5] = { "lively", "alive", "harp", "sharp", "armstrong" };
    int sz1 = sizeof(arr1) / sizeof(arr1[0]);
    int sz2 = sizeof(arr2) / sizeof(arr1[0]);
    char** res = inArray(arr1, sz1, arr2, sz2, &lg);
    printf("%s", *res++);
}

int compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

char** inArray(char* array1[], int sz1, char* array2[], int sz2, int* lg) {
    char** result = (char **) malloc(0 * sizeof(char *));
    int cnt = 0;
    for (int i = 0; i < sz1; i++) {
        for (int j = 0; j < sz2; j++) {
            if (strstr(array2[j], array1[i])) {
                result = (char **) realloc(result, (cnt + 1) * sizeof(char *));
                result[cnt] = array1[i];
                cnt++;
                break;
            }
        }
    }
    *lg = cnt;
    qsort(result, cnt, sizeof(const char *), compare);
    return result;
}