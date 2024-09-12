/*
 * It1_1.c
 * 
 * Copyright 2024 Irina <Irina@DESKTOP-88UC3Q3>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "drone.h"
#include "map.h"
#include "autopilot.h"
#include "object.h"
#include <stdio.h>

int main() {
    initialize_map(20, 20); // Создаем поле размером 20x20

    while (1) {
        update_map();       // Обновляем карту, появление новых объектов
        display_map();      // Отображаем карту на экране

        char command = get_user_input(); // Получаем команду пользователя

        if (command == 'q') {
            break; // Выход из игры
        } else if (command == 'a') {
            autopilot_mode(); // Включаем автопилот
        } else {
            move_drone(command); // Управляем дроном вручную
        }

        if (check_collision()) {
            printf("Аварийная ситуация! Цепочка тележек столкнулась с дроном!\n");
            break;
        }
    }

    return 0;
}
