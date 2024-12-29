#include <stdio.h>
#include <string.h>

void countCharacters(char *str) {
    int count[256] = {0};  
    
    for (int i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            printf("chu '%c' co %d lan\n", i, count[i]);
        }
    }
}

void printFirstThreeChars(char *str) {
    printf("Cat 3 ky tu dau la: %.3s\n", str);
}

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
    countCharacters(str);
    printFirstThreeChars(str);
    return 0;
}
