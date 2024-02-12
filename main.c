#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <dos.h> // delay()

typedef struct Automobil{
    char model[50];
    char nume_companie[50];
    char culoare[50];
    char stare[50]; //nou, utilizat, stricat
    int an_productie;
    double pret;
} automobil;

void addElement_front(automobil * avto, int n);
void addElement_back(automobil * avto, int n);
void addElement_index(automobil * avto, int index, int n);
void delete_element(automobil * avto, int index, int n);
void show_avto(automobil * avto, int n);
void sortare(int n, automobil * avto);
void quick_sort(int i, int min_i, automobil * avto);

void introducereAvto(int n, automobil * avto);
void cautareAvto(int *n, automobil * avto);

int main(){
    int n;
    printf("Numarul de elemente: ");
    scanf("%d", &n);

    automobil *avto = (automobil *)malloc(sizeof(automobil) * n);
    introducereAvto(n, avto);
    show_avto(avto, n);
    printf("\n");
    printf("**********************************************************\n");

    cautareAvto(&n, avto);
    printf("\n");
    printf("Noile automobile:\n");
    show_avto(avto, n);

    printf("\n");
    free(avto);
    getch();
    return 0;
}


void Model(int n, automobil * avto){
    char op_select[50];
    printf("Modelul: ");
    scanf(" %[^\n]s", op_select);
    for(int j = 0; j < n; j++){
        if(strcmp(op_select, avto[j].model) == 0){
            printf("Pozitia unde se afla primul element: %d\n\n", j+1);
            return;
        }
    }
}
void NumeCompanie(int n, automobil * avto){
    char op_select[50];
    printf("Numele companiei: ");
    scanf(" %[^\n]s", op_select);
    for(int j = 0; j < n; j++){
        if(strcmp(op_select, avto[j].nume_companie) == 0){
            printf("Pozitia unde se afla primul element: %d\n\n", j+1);
            return;
        }
    }
};
void Culoare(int n, automobil * avto){
    char op_select[50];
    printf("Culoare: ");
    scanf(" %[^\n]s", op_select);
    for(int j = 0; j < n; j++){
        if(strcmp(op_select, avto[j].culoare) == 0){
            printf("Pozitia unde se afla primul element: %d\n\n", j+1);
            return;
        }
    }
};
void AnProductie(int n, automobil * avto){
    int op_select_int;
    printf("Anul productiei: ");
    scanf( "%d", &op_select_int);
    for(int j = 0; j < n; j++){
        if(op_select_int == avto[j].an_productie){
            printf("Pozitia unde se afla primul element: %d\n\n", j+1);
            return;
        }
    }
};
void Stare(int n, automobil * avto){
    char op_select[50];
    printf("Starea: ");
    scanf(" %[^\n]s", op_select);
    for(int j = 0; j < n; j++){
        if(strcmp(op_select, avto[j].stare) == 0){
            printf("Pozitia unde se afla primul element: %d\n\n", j+1);
            return;
        }
    }
};
void Pret(int n, automobil * avto){
    double op_select_dbl;
    printf("Pretul: ");
    scanf(" %lf", &op_select_dbl);
    for(int j = 0; j < n; j++){
        if(op_select_dbl == avto[j].pret){
            printf("Pozitia unde se afla primul element: %d\n\n", j+1);
            break;
        }
    }
};

void addElement_front(automobil * avto, int n){
    avto = realloc(avto, sizeof(automobil) * (n+1));
    for(int i = n; i > 0; i--){
        strcpy((avto+i)->nume_companie, (avto+i-1)->nume_companie);
        strcpy((avto+i)->nume_companie, (avto+i-1)->nume_companie);
        strcpy((avto+i)->model, (avto+i-1)->model);
        strcpy((avto+i)->culoare, (avto+i-1)->culoare);
        (avto+i)->an_productie = (avto+i-1)->an_productie;
        strcpy((avto+i)->stare, (avto+i-1)->stare);
        (avto+i)->pret = (avto+i-1)->pret;
    }

    printf("Denumirea companiei: ");
    scanf(" %[^\n]s", avto->nume_companie);
    printf("Model: ");
    scanf(" %[^\n]s", avto->model);
    printf("Culoare: ");
    scanf(" %[^\n]s", avto->culoare);
    printf("Anul productiei: ");
    scanf(" %d", &avto->an_productie);
    printf("Starea automobilului: ");
    scanf(" %[^\n]s", avto->stare);
    printf("Pretul automobilului: ");
    scanf(" %lf", &avto->pret);
    printf("\n");
}

void addElement_back(automobil * avto, int n){
    avto = realloc(avto, sizeof(automobil) * (n+1));
    printf("Denumirea companiei: ");
    scanf(" %[^\n]s", (avto + n)->nume_companie);
    printf("Model: ");
    scanf(" %[^\n]s", (avto + n)->model);
    printf("Culoare: ");
    scanf(" %[^\n]s", (avto + n)->culoare);
    printf("Anul productiei: ");
    scanf(" %d", &(avto + n)->an_productie);
    printf("Starea automobilului: ");
    scanf(" %[^\n]s", (avto + n)->stare);
    printf("Pretul automobilului: ");
    scanf(" %lf", &(avto + n)->pret);
    printf("\n");
}

void addElement_index(automobil * avto, int index, int n){
    if(index > n || index <= 0){
        printf("Indexul este gresit.\n");
    }
    avto = realloc(avto, sizeof(automobil) * (n + 1));

    for(int i = n; i >= index; i--){
        strcpy((avto+i)->nume_companie, (avto+i-1)->nume_companie);
        strcpy((avto+i)->model, (avto+i-1)->model);
        strcpy((avto+i)->culoare, (avto+i-1)->culoare);
        (avto+i)->an_productie = (avto+i-1)->an_productie;
        strcpy((avto+i)->stare, (avto+i-1)->stare);
        (avto+i)->pret = (avto+i-1)->pret;
    }

    printf("Denumirea companiei: ");
    scanf(" %[^\n]s", (avto + index - 1)->nume_companie);
    printf("Model: ");
    scanf(" %[^\n]s", (avto + index - 1)->model);
    printf("Culoare: ");
    scanf(" %[^\n]s", (avto + index - 1)->culoare);
    printf("Anul productiei: ");
    scanf(" %d", &(avto + index - 1)->an_productie);
    printf("Starea automobilului: ");
    scanf(" %[^\n]s", (avto + index - 1)->stare);
    printf("Pretul automobilului: ");
    scanf(" %lf", &(avto + index - 1)->pret);
    printf("\n");
}

void delete_element(automobil * avto, int index, int n){
    if(index > n || index <= 0){
        printf("Indexul este gresit.\n");
        return;
    }
    for(int i = index - 1; i < n; i++){
        strcpy((avto + i)->nume_companie, (avto + i + 1)->nume_companie);
        strcpy((avto + i)->model, (avto + i + 1)->model);
        strcpy((avto + i)->culoare, (avto + i + 1)->culoare);
        (avto + i)->an_productie = (avto + i + 1)->an_productie;
        strcpy((avto + i)->stare, (avto + i + 1)->stare);
        (avto + i)->pret = (avto + i + 1)->pret;
    }
     avto = realloc(avto, sizeof(automobil) * (n-1));
}

void introducereAvto(int n, automobil *avto){
    for(int i = 0; i < n; i++){
        printf("Denumirea companiei: ");
        scanf(" %[^\n]s", (avto + i)->nume_companie);
        printf("Model: ");
        scanf(" %[^\n]s", (avto + i)->model);
        printf("Culoare: ");
        scanf(" %[^\n]s", (avto+i)->culoare);
        printf("Anul productiei: ");
        scanf(" %d", &(avto + i)->an_productie);
        printf("Starea automobilului: ");
        scanf(" %[^\n]s", (avto + i)->stare);
        printf("Pretul automobilului: ");
        scanf(" %lf", &(avto + i)->pret);
        printf("\n");
    }
}

void quick_sort(int i, int min_i, automobil * avto){
    automobil temp = *(avto + i);
    *(avto + i) = *(avto + min_i);
    *(avto + min_i) = temp;
}

void sortare(int n, automobil * avto){
    int op;
    printf("Introdu criteriul de sortare:\n");
    printf("model (1)\n");
    printf("nume companie (2)\n");
    printf("an productie (3)\n");
    printf("culoare (4)\n");
    printf("stare (5)\n");
    printf("pret (6)\n");
    printf("Enter: ");
    scanf(" %d", &op);

    if(op == 1){
        for(int i = 0; i < n; i++){
            int int_min = i;
            for(int j = i + 1; j < n; j++){
                if(strcmp((avto + int_min)->model, (avto + j)->model) > 0) int_min = j;
            }
            if(int_min != i) quick_sort(i, int_min, avto);
            show_avto(avto, n);
        }
    } else if(op == 2){
        for(int i = 0; i < n; i++){
            int int_min = i;
            for(int j = i + 1; j < n; j++){
                if(strcmp((avto + int_min)->nume_companie, (avto + j)->nume_companie) > 0) int_min = j;
            }
            if(int_min != i) quick_sort(i, int_min, avto);
            show_avto(avto, n);
        }
    } else if(op == 3){
        for(int i = 0; i < n; i++){
            int int_min = i;
            for(int j = i + 1; j < n; j++){
                if((avto + int_min)->an_productie > (avto + j)->an_productie) int_min = j;
            }
            if(int_min != i) quick_sort(i, int_min, avto);
            show_avto(avto, n);
        }
    } else if(op == 4){
        for(int i = 0; i < n; i++){
            int int_min = i;
            for(int j = i + 1; j < n; j++){
                if(strcmp((avto + int_min)->culoare, (avto + j)->culoare) > 0) int_min = j;
            }
            if(int_min != i) quick_sort(i, int_min, avto);
            show_avto(avto, n);
        }
    } else if(op == 5){
        for(int i = 0; i < n; i++){
            int int_min = i;
            for(int j = i + 1; j < n; j++){
                if(strcmp((avto + int_min)->stare, (avto + j)->stare) > 0) int_min = j;
            }
            if(int_min != i) quick_sort(i, int_min, avto);
            show_avto(avto, n);
        }
    } else if(op == 6){
        for(int i = 0; i < n; i++){
            int int_min = i;
            for(int j = i + 1; j < n; j++){
                if((avto + int_min)->pret > (avto + j)->pret) int_min = j;
            }
            if(int_min != i) quick_sort(i, int_min, avto);
            show_avto(avto, n);
        }
    } else printf("ati introdus ceva gresit");
}

void show_avto(automobil * avto, int n){
    for(int i = 0; i < n; i++){
        printf("Automobilul %d:\n", i+1);
        printf("Denumirea companiei: %s\n", (avto + i)->nume_companie);
        printf("Model: %s\n", (avto + i)->model);
        printf("Culoare: %s\n", (avto + i)->culoare);
        printf("Starea automobilului: %s\n", (avto + i)->stare);
        printf("Anul productiei: %d\n", (avto + i)->an_productie);
        printf("Pretul automobilului: %.2lf\n", (avto + i)->pret);
        printf("\n");
    }
}

void cautareAvto(int * n, automobil * avto){
    int i = 0;
    int optiune;
    printf("Cautare:\n");
    printf("model (1);\n");
    printf("nume companie(2);\n");
    printf("culoare (3);\n");
    printf("an productie (4);\n");
    printf("stare (5);\n");
    printf("pret (6);\n");
    printf("add element front (7);\n");
    printf("add element back (8);\n");
    printf("add element index (9);\n");
    printf("delete element (10);\n");
    printf("vizualizare (11);\n");
    printf("sortare (12);\n");
    printf("exit (13);\n");
    printf("\n");

        do{
        printf("Enter: ");
        scanf(" %d", &optiune);

        if(optiune == 1){
            Model(*n, avto);
            continue;
        } else if(optiune == 2){
            NumeCompanie(*n, avto);
            continue;
        } else if(optiune == 3){
            Culoare(*n, avto);
            continue;
        } else if(optiune == 4){
            AnProductie(*n, avto);
            continue;
        } else if(optiune == 5){
            Stare(*n, avto);
            continue;
        } else if(optiune == 6){
            Pret(*n, avto);
            continue;
        } else if(optiune == 7){
            addElement_front(avto, *n);
            (*n)+=1;
            continue;
        } else if(optiune == 8){
            addElement_back(avto, *n);
            *(n)+=1;
            continue;
        } else if(optiune == 9){
            int index;
            printf("Introdu pozitia: ");
            scanf("%d", &index);
            addElement_index(avto, index, *n);
            *(n)+=1;
            continue;
        } else if(optiune == 10){
            int index;
            printf("Introdu pozitia: ");
            scanf("%d", &index);
            delete_element(avto, index, *n);
            *(n)-=1;
            continue;
        } else if(optiune == 11){
            printf("\n");
            show_avto(avto, *n);
            continue;
        } else if(optiune == 12){
            sortare(*n, avto);
            continue;
        } else if(optiune == 13){
            i = 1;
            break;
        }
        printf("Ati introdus ceva gresit.\n\n");
    } while(i == 0);
}
