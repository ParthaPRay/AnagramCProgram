// The code is curated by Partha Pratim Ray as on 12/08/2023

#include <stdio.h>
#include <string.h>
#include <time.h>

void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void generate_anagrams(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str);
    } else {
        for (int i = l; i <= r; i++) {
            swap((str + l), (str + i));
            generate_anagrams(str, l + 1, r);
            swap((str + l), (str + i)); // backtrack
        }
    }
}

int main() {
    char str[100];  // Assuming the maximum length of input string is 100
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character added by fgets at the end of the string
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
    
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    printf("Anagrams for %s are:\n", str);
    generate_anagrams(str, 0, strlen(str) - 1);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    return 0;
}
