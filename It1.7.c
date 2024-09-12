#include "object.h"
#include <stdio.h>

int check_collision() {
    // Проверка на столкновение
    printf("Проверка на столкновение\n");
        return 0; // Возвращаем 0, если столкновения нет
}

char get_user_input() {
    char input;
    printf("Введите команду (w/a/s/d для управления, q для выхода, a для автопилота): ");
    scanf(" %c", &input);
    return input;
}


