#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int key) {
    char *ptr = message;
    while (*ptr != '\0') {
        *ptr = *ptr ^ (short)key;
        ptr++;
    }
}

void decrypt(char *message, int key) {
    encrypt(message, key); // XOR 연산은 자기 자신에 대해 두 번 하면 원래 값을 되돌릴 수 있음
}

int main() {
    char message[100];
    int key;

    printf("암호화할 메시지를 입력하세요: ");
    fgets(message, sizeof(message), stdin);

    printf("암호화 키를 입력하세요 (0 이상의 정수): ");
    scanf("%d", &key);

    // 개행 문자 제거
    char *pos;
    if ((pos = strchr(message, '\n')) != NULL)
        *pos = '\0';

    //initRandomGenerator(); 이제 안쓰임
    encrypt(message, key);

    printf("암호화된 메시지: %s\n", message);

    decrypt(message, key);
    printf("복호화된 메시지: %s\n", message);

    return 0;
}