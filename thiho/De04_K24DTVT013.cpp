#include <stdio.h>


char to_uppercase(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}


char to_lowercase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        return 1;
    }

    char str[1000]; 
    if (fgets(str, sizeof(str), file) == NULL) {
        fclose(file);
        return 1;
    }
    fclose(file);

    
    int length = 0;
    while (str[length] != '\0') {
        if (str[length] == '\n') {
            str[length] = '\0';
            break;
        }
        length++;
    }

    
    char uppercase_str[1000];
    for (int i = 0; i <= length; i++) {
        uppercase_str[i] = to_uppercase(str[i]);
    }

    
    int n = 3; 
    char cut_part[4] = ""; 
    if (length > n) {
        for (int i = 0; i < n; i++) {
            cut_part[i] = to_lowercase(str[length - n + i]);
        }
        cut_part[n] = '\0'; 
        str[length - n] = '\0'; 
    }

    
    printf("%s\n", uppercase_str); 
    printf("%d %s\n", n, cut_part); 

    return 0;
}
