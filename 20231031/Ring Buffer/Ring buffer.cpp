#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BUFFER_SIZE 5

int main() {
    int ringBuffer[BUFFER_SIZE] = {0,  };
    int index = 0;

    while (1) {
        int value;
        printf("���� �Է� : ");
        scanf("%d", &value);

        if (value == 0) {
            printf("ERROR");
            break;
        }

        ringBuffer[index] = value;

        // ���� ���� ���
        for (int i = 0; i < BUFFER_SIZE; i++) {
            printf("%d ", ringBuffer[i]);
        }
        printf("\n");

        index = (index + 1) % BUFFER_SIZE; // ���� �ε����� �̵�
    }

    return 0;
}