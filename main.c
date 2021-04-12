#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char random() {
    return 33 + rand() % (126 - 33 + 1);
}

struct strings {
    char line[100];
};

void check(struct strings* string, int n, int *count, FILE* tf9_2, FILE* tf9_1) {
    int len;
    for (int i = 0; i < n; i++) {
        len = strlen(string[i].line) - 1;
        if (len >= 20)
        {
            (*count)++;
            for (int j = 0; j < 20; j++) {
                fprintf(tf9_2, "%c", string[i].line[j]);
            }
            fprintf(tf9_2, "\n");
        }
        else {
            char line2[22];
            for (int j = len; j < 20; j++) {
                line2[j] = '*';
            }
            line2[20] = '\n';
            line2[21] = '\0';
            for (int k = 0; k < (strlen(string[i].line)) - 1; k++) {
                line2[k] = string[i].line[k];
            }
            fprintf(tf9_1, "%s", line2);
        }
    }
}

int main() {
    srand(time(NULL));
    FILE* tf9_1; 
    FILE* tf9_2; 
    int number, c, length, i, j, k, m, count = 0;
    struct strings* string;

    printf("enter number\n");
    scanf("%d", &number);
    string = malloc(sizeof(struct strings) * number);
    tf9_1 = fopen("TF9_1.txt", "w");
    for (i = 0; i < number; i++) {
        length = rand() % 36;
        for (j = 0; j < length; j++) {
            fprintf(tf9_1, "%c", random());
        }
        fprintf(tf9_1, "\n");
    }
    fclose(tf9_1);
    tf9_1 = fopen("TF9_1.txt", "r");
    for (i = 0; i < number; i++) {
        fgets(string[i].line, 100, tf9_1);
    }
    for (i = 0; i < number; i++) {
        printf("%s", string[i].line);
    }
    fclose(tf9_1);
    
    tf9_1 = fopen("TF9_1.txt", "w");
    tf9_2 = fopen("TF9_2.txt", "w");
    check(string, number, &count, tf9_2, tf9_1);
    fclose(tf9_2);
    fclose(tf9_1);
    
    tf9_2 = fopen("TF9_2.txt", "r");
    printf("\n\nTF9_2:\n");
    for (i = 0; i < count; i++) {
        fgets(string[i].line, 100, tf9_2);
    }
    for (i = 0; i < count; i++) {
        printf("%s", string[i].line);
    }

    fclose(tf9_2);
    return 0;
}