#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* file1;
    FILE* file;

    file1 = fopen("test.txt", "r");
    if (file1 == NULL) {
        printf("File not found\n");
        getchar();
        return -1;
    }
    int i, ind_open_bracket = 0, ind_close_bracket = 0, ind_last_num_elm = 0,
           ind_first_num_elm = 0, ind_second_num_elm = 0;
    int l = 0, c = 0, e = 0, error = 0;

    while (1) {
        e = fgetc(file1);
        if (e == EOF) {
            if (feof(file1) != 0) {
                break;
            }
        }
        c++;
    }
    l = c;
    fclose(file1);

    char a[l], b[6] = "circle";
    file = fopen("test1.txt", "r");
    if (file == NULL) {
        printf("File not found\n");
        getchar();
        return -1;
    }
    while (fgets(a, l + 1, file)) {
        printf("%s", a);

        for (i = 0; i < 7; i++) {
            if (a[i] != b[i] && i < 6) {
                printf("Неправильное название объекта, "
                       "ожидалось'circle'\n");
                error = 1;
                break;
                ;
            }
            ind_open_bracket = i;
        }

        for (i = 0; i < l; i++) {
            if (a[i] == ')') {
                ind_close_bracket = i;
            } else {
                ind_close_bracket = l - 1;
            }
        }

        for (i = ind_open_bracket + 1; a[i] != ' '; i++) {
            if (error == 0) {
                if (a[i] == ',') {
                    error = 1;
                    printf("Ожидались '<space>' и '<double>'\n");
                    break;
                }
                if (isdigit(a[i]) == 0 && a[i] != '.') {
                    error = 1;
                    printf("Ожидалось'<double>'\n");
                    break;
                }
                ind_first_num_elm = i;
            } else {
                break;
            }
        }

        for (i = ind_first_num_elm + 2; a[i] != ','; i++) {
            if (error == 0) {
                if (a[i] == ')') {
                    error = 1;
                    printf("Ожидались ',' и '<double>'\n");
                    break;
                }
                if (isdigit(a[i]) == 0 && a[i] != '.') {
                    error = 1;
                    printf("Ожидалось '<double>'\n");
                    break;
                }
                ind_second_num_elm = i;
            } else {
                break;
            }
        }

        for (i = ind_second_num_elm + 3; i < ind_close_bracket; i++) {
            if (error == 0) {
                if ((isdigit(a[i]) == 0 && a[i] != '.') || a[i] == '0') {
                    if (a[i] == ')' || a[i] == '(' || a[i] == ' ') {
                        break;
                    }
                    error = 1;
                    printf("Ожидалось '<double>'\n");
                    break;
                }
                ind_last_num_elm = i;
            } else {
                break;
            }
        }

        for (i = ind_last_num_elm + 1; i < l; i++) {
            if (error == 0) {
                if (a[i] != ')') {
                    error = 1;
                    printf("Ожидалось')'\n");
                    break;
                } else {
                    ind_close_bracket = i;
                    break;
                }
            } else {
                break;
            }
        }

        for (i = ind_close_bracket + 1; i < l; i++) {
            if (error == 0) {
                if (a[i] == '\n') {
                    break;
                }

                if (a[i] != ' ') {
                    error = 1;
                    printf("???\n");
                    break;
                }
            } else {
                break;
            }
        }

        if (error == 0) {
            printf("Правильно\n");
        }

        error = 0;
    }
    return 0;
}