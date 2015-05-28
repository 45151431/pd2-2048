#ifndef GTWO
#define GTWO

#include<QKeyEvent>
#include<QLabel>
#include<QPalette>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>

class gTwo
{
    public:
        gTwo(QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*);
        void begin();
        void run_Up();
        void run_Down();
        void run_Left();
        void run_Right();
        void create_new();
        void check();
        bool IsUp();
        bool IsDown();
        bool IsLeft();
        bool IsRight();
        bool IsStop;
    private:
        bool flag[5][5];
        int save[5][5];
        int Score, Best, max;
        char str[4];
        char empt[4];
        QLabel *label[5][5];
        QPalette block_palette, result_palette;
};

#endif // GTWO
