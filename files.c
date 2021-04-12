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

void check(struct strings* string, int n, FILE* tff, FILE* tf1) {
    int len;
    for (int i = 0; i < n; i++) {
        len = strlen(string[i].line) - 1;
        if (len >= 20)
        {
            for (int j = 0; j < 20; j++) {
                fprintf(tff, "%c", string[i].line[j]);
            }
            fprintf(tff, "\n");
        }
        else {
            char line2[22];
            for (int j = 0; j < 20; j++) {
                line2[j] = '*';
            }
            line2[20] = '\n';
            line2[21] = '\0';
            for (int k = 0; k < (strlen(string[i].line))-1; k++) {
                line2[k] = string[i].line[k];
            }
            fprintf(tf1, "%s", line2);
        }
    }

}

int main() {
    srand(time(NULL));
    FILE* tf = fopen("test.txt", "w");
    FILE* tf1 = fopen("test2.txt", "w");
    FILE* tff = fopen("tf2.txt", "w");
    int number, c, length, i, j, k, m;
    struct strings* string;

    printf("enter number\n");
    scanf("%d", &number);
    string = malloc(sizeof(struct strings) * number);

    for (i = 0; i < number; i++) {
        length = rand() % 36;
        for (j = 0; j < length; j++) {
            fprintf(tf, "%c", random());
        }
        fprintf(tf, "\n");
    }
    fclose(tf);
    FILE* tf2 = fopen("test.txt", "r");

    for (i = 0; i < number; i++) {
        fgets(string[i].line, 100, tf2);
    }
    for (i = 0; i < number; i++) {
        printf("%s", string[i].line);
    }

    check(string, number, tff, tf1);
    
    fclose(tf2);
    fclose(tf1);
    fclose(tff);
    return 0;
}