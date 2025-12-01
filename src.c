#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void line() {
    printf("\n-----------------------------------------------------------\n");
}

int main() {
    char name[50];
    int answer, correct = 0;
    int used5050 = 0, usedSkip = 0;

    long prizeMoney[] = {0, 1000, 5000, 10000, 20000, 40000, 80000,
                         160000, 320000, 640000, 1250000, 2500000,
                         5000000};

    printf("\n********** CHALO KHELE KAUN BANEGA CROREPATI **********\n");
    printf("Enter your Name: ");
    scanf("%s", name);

    line();
    printf("Hello %s! You have 2 lifelines:\n", name);
    printf("1️. 50-50 (Removes 2 wrong options)\n");
    printf("2️. Skip Question (No loss, move to next question)\n");
    line();

    // 12 Questions of the game 
    char *questions[] = {
        "Which planet is known as the Red Planet?",
        "Who is the father of C Language?",
        "Which device measures temperature?",
        "Who wrote the National Anthem of India?",
        "Which is the largest mammal?",
        "What is the capital of Australia?",
        "Which gas is used by plants during photosynthesis?",
        "Who discovered gravity?",
        "Which is the fastest animal on land?",
        "Who invented the telephone?",
        "What is the national currency of Japan?",
        "Which is the longest river in the world?"
    };

    // Options for each question
    char *options[][4] = {
        {"1. Earth", "2. Mars", "3. Jupiter", "4. Venus"},
        {"1. Dennis Ritchie", "2. Bill Gates", "3. Bjarne Stroustrup", "4. Charles Babbage"},
        {"1. Barometer", "2. Thermometer", "3. Ammeter", "4. Speedometer"},
        {"1. Bankim Chandra", "2. Rabindranath Tagore", "3. Gandhi Ji", "4. Nehru Ji"},
        {"1. Blue Whale", "2. Elephant", "3. Giraffe", "4. Shark"},
        {"1. Sydney", "2. Canberra", "3. Melbourne", "4. Perth"},
        {"1. Oxygen", "2. Carbon Dioxide", "3. Nitrogen", "4. Hydrogen"},
        {"1. Newton", "2. Einstein", "3. Galileo", "4. Edison"},
        {"1. Cheetah", "2. Tiger", "3. Lion", "4. Leopard"},
        {"1. Alexander Graham Bell", "2. Edison", "3. Einstein", "4. Tesla"},
        {"1. Yen", "2. Won", "3. Dollar", "4. Euro"},
        {"1. Nile", "2. Amazon", "3. Ganga", "4. Yangtze"}
    };

    // Correct Answers of each question
    int correctOption[] = {2, 1, 2, 2, 1, 2, 2, 1, 1, 1, 1, 1};

    // 50-50 lifeline all the wrong sets
    int fifty1[] = {1, 2, 1, 1, 2, 1, 1, 2, 2, 2, 2, 2};
    int fifty2[] = {3, 4, 3, 4, 4, 3, 4, 3, 4, 4, 4, 3};

    int totalQuestions = 12;

    for (int i = 0; i < totalQuestions; i++) {
        line();
        printf("\nQ%d: %s\n", i + 1, questions[i]);

        for (int j = 0; j < 4; j++)
            printf("%s\n", options[i][j]);

        printf("\nYour Lifelines:\n");
        printf("50-50: %s\n", used5050 ? "USED" : "AVAILABLE");
        printf("Skip : %s\n", usedSkip ? "USED" : "AVAILABLE");

        time_t start = time(NULL);

        printf("\nEnter (1-4), 55 for 50-50, 99 to Skip: ");
        scanf("%d", &answer);

        time_t end = time(NULL);
        int timeTaken = (int)difftime(end, start);

        //condition for fifty fifty lifeline
        if (answer == 55) {
            if (used5050 == 1) {
                printf("\n You already used 50-50!\n");
                i--;
                continue;
            }
            used5050 = 1;

            printf("\n 50-50 Lifeline Activated!\nRemaining Options:\n");
            printf("%s\n", options[i][fifty1[i] - 1]);
            printf("%s\n", options[i][fifty2[i] - 1]);

            printf("\nEnter your answer: ");
            scanf("%d", &answer);
        }

        // Skip Lifeline condition
        if (answer == 99) {
            if (usedSkip == 1) {
                printf("\n Skip already used!\n");
                i--;
                continue;
            }

            usedSkip = 1;
            printf("\n Question Skipped! Moving to next...\n");
            continue;
        }

        //conditions for the right answer
        if (answer == correctOption[i]) {
            correct++;
            printf("\n Correct Answer!\n");
            printf(" Time taken: %d seconds\n", timeTaken);
            printf(" Money Won: %ld\n", prizeMoney[correct]);
        } else {
            printf("\n Wrong Answer!\n");
            printf("Correct Answer was: %d\n", correctOption[i]);
            break;
        }
    }

    line();
    printf("\nGAME OVER!\n");
    printf("Total Correct Answers: %d\n", correct);
    printf("Total Money Won: %ld\n", prizeMoney[correct]);
    line();

    printf("\nThank you for playing KBC, %s!\n", name);

    return 0;
}
