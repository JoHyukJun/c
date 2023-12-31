#include <stdio.h>


enum sex { Male, Female };
enum season { Spring, Summer, Autumn, Winter };

void print_sex(enum sex sex) {
    switch (sex)
    {
    case Male:
        printf("Male");
        break;
    case Female:
        printf("Female");
        break;
    }
}

void print_season(enum season season) {
    switch (season)
    {
    case Spring:
        printf("Spring");
        break;
    case Summer:
        printf("Summer");
        break;
    case Autumn:
        printf("Autumn");
        break;
    case Winter:
        printf("Winter");
        break;
    }
}

enum sex select_sex(void) {
    int tmp;

    do {
        printf("0_Male      1_Female: ");
        scanf("%d", &tmp);
    } while (tmp < Male || tmp > Female);

    return tmp;
}

enum season select_season(void) {
    int tmp;

    do {
        printf("0_Spring    1_Summer    2_Autumn    3_Winter: ");
        scanf("%d", &tmp);
    } while (tmp < Spring || tmp > Winter);

    return tmp;
}

int main(void) {
    enum sex your_sex;
    enum season your_season;

    printf("Sex: ");
    your_sex = select_sex();
    printf("Season: ");
    your_season = select_season();

    print_sex(your_sex);
    print_season(your_season);

    return 0;
}