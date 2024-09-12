#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// Функция для проверки наличия нажатой клавиши
int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int main() {
    printf("Press 'p' to simulate button press. Press 'q' to quit.\n");

    while (1) {
        if (kbhit()) {
            char ch = getchar();
            if (ch == 'p') {
                printf("Button pressed!\n");
            } else if (ch == 'q') {
                printf("Exiting...\n");
                break;
            }
        }
        usleep(100000); // 100ms delay
    }

    return 0;
}
