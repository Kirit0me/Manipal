#include <stdio.h>

int string_length(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void string_concatenate(char dest[], char src[]) {
    int dest_len = string_length(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    printf("%s", dest);
}

void string_compare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] > str2[i]) {
            printf("%s", str1);
        }
        else if(str1[i] < str2[i]){
            printf("%s", str2);
        }
        i++;
    }
}

void string_insert(char main_str[], char sub_str[], int position) {
    int main_len = string_length(main_str);
    int sub_len = string_length(sub_str);
    int i, j;

    for (i = main_len + sub_len; i >= position + sub_len; i--) {
        main_str[i] = main_str[i - sub_len];
    }

    for (j = 0; j < sub_len; j++) {
        main_str[position + j] = sub_str[j];
    }
    printf("%s", main_str);
}

void string_delete(char main_str[], char sub_str[]) {
    int main_len = string_length(main_str);
    int sub_len = string_length(sub_str);
    int i, j;

    for (i = 0; i < main_len; i++) {
        int found = 1;
        for (j = 0; j < sub_len; j++) {
            if (main_str[i + j] != sub_str[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            for (j = i; j < main_len - sub_len; j++) {
                main_str[j] = main_str[j + sub_len];
            }
            main_len -= sub_len;
            i -= 1;
        }
    }
    main_str[main_len] = '\0';
    printf("%s", main_str);
}

int main() {
    int c;
    scanf("%d", &c);
    char str[30]; char str2[30]; int i;
    switch (c){
        case 1:
            //char str[30];
            scanf("%s", str);
            printf("Length of string is %d", string_length(str));
            break;
        case 2:
            //char str[30]; char str2[30];
            scanf("%s", str); scanf("%s", str2);
            string_concatenate(str, str2);
        case 3:
            //char str[30]; char str2[30];
            scanf("%s", str); scanf("%s", str2);
            string_compare(str, str2);
        case 4:
            //char str[30]; char str2[30]; int i;
            scanf("%s", str); scanf("%s", str2); scanf("%d", &i);
            string_insert(str, str2, i);
        case 5:
            //char str[30]; char str2[30];
            scanf("%s", str); scanf("%s", str2);
            string_delete(str, str2);
    }
}
