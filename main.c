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

int main(){
    int n;
    printf("Numarul de elemente: ");
    scanf("%d", &n);

    automobil *avto = (automobil *)malloc(sizeof(automobil) * n);

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
    printf("\n");
    printf("**********************************************************\n");

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
    printf("\n");

    int i = 0;
    char optiune[50];
    char op_select[50];
    int op_select_int;
    double op_select_dbl;
    printf("Cautare:\n");
    printf("Introdu una din optiuni: model, nume companie, culoare, an productie, stare, pret,\n add element front, add element back, add element index, delete element, vizualizare\n exit.\n");

        do{
        printf("Enter: ");
        scanf(" %[^\n]s", optiune);

        if(strcmp(optiune, "model") == 0){
            printf("Modelul: ");
            scanf(" %[^\n]s", op_select);
            for(int j = 0; j < n; j++){
                if(strcmp(op_select, (avto + j)->model) == 0){
                    printf("Pozitia unde se afla primul element: %d\n\n", j+1);
                    break;
                }
            }
            continue;
        } else if(strcmp(optiune, "nume companie") == 0){
            printf("Numele companiei: ");
            scanf(" %[^\n]s", op_select);
            for(int j = 0; j < n; j++){
                if(strcmp(op_select, (avto + j)->nume_companie) == 0){
                    printf("Pozitia unde se afla primul element: %d\n\n", j+1);
                    break;
                }
            }
            continue;
        } else if(strcmp(optiune, "culoare") == 0){
            printf("Culoare: ");
            scanf(" %[^\n]s", op_select);
            for(int j = 0; j < n; j++){
                if(strcmp(op_select, (avto + j)->culoare) == 0){
                    printf("Pozitia unde se afla primul element: %d\n\n", j+1);
                    break;
                }
            }
            continue;
        } else if(strcmp(optiune, "an productie") == 0){
            printf("Anul productiei: ");
            scanf( "%d", &op_select_int);
            for(int j = 0; j < n; j++){
                if(op_select_int == (avto + j)->an_productie){
                    printf("Pozitia unde se afla primul element: %d\n\n", j+1);
                    break;
                }
            }
            continue;
        } else if(strcmp(optiune, "stare") == 0){
            printf("Starea: ");
            scanf(" %[^\n]s", op_select);
            for(int j = 0; j < n; j++){
                if(strcmp(op_select, (avto + j)->stare) == 0){
                    printf("Pozitia unde se afla primul element: %d\n\n", j+1);
                    break;
                }
            }
            continue;
        } else if(strcmp(optiune, "pret") == 0){
            printf("Pretul: ");
            scanf(" %lf", &op_select_dbl);
            for(int j = 0; j < n; j++){
                if(op_select_dbl == (avto+i)->pret){
                    printf("Pozitia unde se afla primul element: %d\n\n", j+1);
                    break;
                }
            }
            continue;
        } else if(strcmp(optiune, "add element front") == 0){
            addElement_front(avto, n);
            n++;
            continue;
        } else if(strcmp(optiune, "add element back") == 0){
            addElement_back(avto, n);
            n++;
            continue;
        } else if(strcmp(optiune, "add element index") == 0){
            int index;
            printf("Introdu pozitia: ");
            scanf("%d", &index);
            addElement_index(avto, index, n);
            n++;
            continue;
        } else if(strcmp(optiune, "delete element") == 0){
            int index;
            printf("Introdu pozitia: ");
            scanf("%d", &index);
            delete_element(avto, index, n);
            n--;
            continue;
        } else if(strcmp(optiune, "vizualizare") == 0){
            printf("\n");
            show_avto(avto, n);
            continue;
        } else if(strcmp(optiune, "exit") == 0){
            i = 1;
            break;
        }
        printf("Ati introdus ceva gresit.\n\n");
    } while(i == 0);


    printf("\n");
    printf("Noile automobile:\n");
    show_avto(avto, n);
    printf("\n");
    getch();
    return 0;
}

void addElement_front(automobil * avto, int n){
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

void addElement_back(automobil * avto, int n){
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
    for(int i = index - 1; i < n-1; i++){
        strcpy((avto + i)->nume_companie, (avto + i + 1)->nume_companie);
        strcpy((avto + i)->model, (avto + i + 1)->model);
        strcpy((avto + i)->culoare, (avto + i + 1)->culoare);
        (avto + i)->an_productie = (avto + i + 1)->an_productie;
        strcpy((avto + i)->stare, (avto + i + 1)->stare);
        (avto + i)->pret = (avto + i + 1)->pret;
    }
     avto = realloc(avto, sizeof(automobil) * (n-1));
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
