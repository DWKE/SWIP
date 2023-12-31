// 8_배열2.c
#include <stdio.h>
#include <stdlib.h>

// 5과목의 점수를 입력받고 싶습니다.
// 3명의 5과목의 점수를 입력 받기 위해서는 어떻게 코드를 작성해야 할까요?
// 1) 5개짜리 배열을 3개 사용합니다.
//   > 사람마다 배열의 이름이 다르기 때문에,
//     사람이 추가될때마다 새로운 변수가 추가되어야 합니다.

// 2) 5과목 * 3명
//   > 15개짜리 배열을 이용합니다.

//     [0][1][2][3][4] [5][6][7][8][9] [10][11][12][13][14]
//     |  첫번째 사람   | |    두번째 사람 | |    세번째 사람      |
// i/5        0               1                 2
// i%5  0  1  2  3  4   0  1  2  3  4   0    1   2   3   4
#if 0
int main(void)
{
    int score[3 * 5];
    for (int i = 0; i < 15; i++) {
        printf("%d번째 사람, %d번째 과목\n", (i / 5) + 1, (i % 5) + 1);

        scanf("%d", &score[i]);
    }

    // 두번째 사람의 세번째 과목을 출력하고 싶습니다.
    int i = 1;
    int j = 2;
    printf("score: %d\n", score[i * 5 + j]);

    return 0;
}
#endif

#if 0
int main(void)
{
    // int score[3 * 5];
    int score[3][5];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d번째 사람, %d번째 과목\n", i + 1, j + 1);
            scanf("%d", &score[i][j]);
        }
    }

    // 두번째 사람의 세번째 과목을 출력하고 싶습니다.
    printf("score: %d\n", score[1][2]);

    return 0;
}
#endif

// int score[3][5]
//     |  첫번째 사람   | |    두번째 사람 | |  세번째 사람   |
//     |     [0]     | |     [1]     | |     [2]     |
//     [0][1][2][3][4] [0][1][2][3][4] [0][1][2][3][4]
//         int[5]            int[5]         int[5]
#if 0
int main(void)
{
    int x[2][3];
    // [ int[3] ][ int[3] ]
    // x의 길이는 얼마인가요? 2

    // 배열의 길이를 구하는 연산
    // sizeof(x) / sizeof(x[0])
    printf("%zu\n", sizeof(x) / sizeof(x[0]));

    return 0;
}
#endif

// 2차원 배열의 활용
//  => 테트리스
//  **
//   **
#if 0
int main(void)
{
    //           y  x
    int block[4][4][4] = {
        {
            { 0, 0, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 1, 1 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 1, 0 },
        },
        {
            { 0, 0, 0, 0 },
            { 0, 1, 1, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 },
        },
        {
            { 0, 0, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 1, 0 },
        },
    };

    int i = 0;
    while (1) {

        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                if (block[i][y][x]) {
                    printf("◼︎");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        getchar();
        system("clear"); // system("cls");
        i = (i + 1) % 4;
    }

    return 0;
}
#endif