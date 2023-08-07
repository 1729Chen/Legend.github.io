#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "Student.h"
#include "LinkList.h"

// 启动动画, "\033[字体颜色; 背景颜色m 字符串 \033[0m", 控制命令以\033[开头，以m结尾
// 终端 字号6 宽171 高100 可看到完整封面
void Cover()
{
    printf("\033[31;47m"
        "                                                                                I]fYLZ0Jn1>,                                                                               \n"
        "                                                                 ^ QOZZZZZZZZZZZZZZZZZZZZZOZZZZZZZZZZZZZ)                                                                  \n"
        "                                                           !ZZZZmZZZm>                                rOZmZmZZZL  ^                                                        \n"
        "                                                     ^ZOZZZOO-                                              ^^QZZZZZOi                                                     \n"
        "                                                 -ZZZZZY           ^QO                                      ZZ      mZmZZZ ^                                               \n"
        "                                            ~mZZZ0                 Z ^                                    :wn          {ZZZZm,                                             \n"
        "                                        ^ mZZmO                         ^ ,                           ZZmZZ-                }OmZm-^                                        \n"
        "                                       ZZZZ_                 0^       ZZOZ                            ^ mZ^?^:OZZ               ZOZOU                                      \n"
        "                                   ,ZZmZ                        ^jZZO,                                 ,ZO    ,                    ZmmZ(                                   \n"
        "                                ^mOZZ^          C     ^xOZZ^ OOZJ^                                  ru Z+^ZZ0C                        ZZOO                                 \n"
        "                               ZmZZ           m ZQ    ^^ZZZm                                    ^OwxO OZIO, Z                            OZZQ                              \n"
        "                            <ZZZ^^        XmZ  Z 0Q:OOm{                    ^^ ^  ;<][]_i             ^     ^                       ^^     ZZZO,                           \n"
        "                        ^ zZZO            ] } ^^Z,        m1          ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ}                            ^ ^Zm^    ^+mZm ^                        \n"
        "                       ^cmZZ               :Z,0Om:             lZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZO                    ^^Z  0f,        ZZm^                       \n"
        "                      iZZZ     ^  ,     ^LmmOx            ^ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZx           ^ZmwmO^mu ZO^Zm_    ^,ZZZ                      \n"
        "                   ^ ZZO       Z1w<^                  :ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZmZZmZZZZZZZZZZZZZZZZZZZZZZZZZZZZ?       ^m;Z0OmmZmZ            /ZZO                    \n"
        "                  ,OZZ^        ZL^ ^Z               ZZZZZZZZZZZZZZZZZZZZZZZOZ}                OZZZZZZZZZZZZZZZZZZZZZZZZZ      ZZY-Zw                 ZZZ^^                 \n"
        "                 lZZZ       XZ^   [ZZ            mZZZZZZZZZZZZZZZZZZZZZZZZ                      ^^mZZZZZZZZZZZZZZZZZZZZZZZZ       mZz^                 ZmZ                 \n"
        "                ZZZ     ^ ^  O^ZZmZ         ^ ZZZZZZZZZZZZZZZZZZZZZZZZZ,                            ZOZZZZZZZZZZZZZZZZZZZZZZZ^^                         0OZ                \n"
        "               Zmm       f+^Z-^,O O         mZZZZZZZZZZZZZZZZZZZZZZZO!^                               OZZZZZZZZZZZZZZZZZZZZZZZOO                         :OZZ              \n"
        "             nZZ           ^ ZZ   O     ^ ZZZZZZZZZZZZZZZZZZZZZZZZZO                                   <ZZZZZZZZZZZZZZZZZZZZZZZZZZ                         ZZZ^            \n"
        "            ZZZ           ^IOZ  ^L      ZZZZZZZZZZZZZZZZZZZZZZZZZZQ^                                     0ZZZZZZZZZZZZZZZZZZZZZZZZZO                       ^zZZ^           \n"
        "           mOm^   !O!Z   ^Z         ^,ZZZZZZZZZZZZZZZZZZZZZZZZZZZm^                                      :ZZZZZZZZZZZZZZZZZZZZZZZZZZZ0              11      ^mZI           \n"
        "          mZO      OZ,OO0m^        ^ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ^                                        ZZZZZZZZZZZZZZZZZZZZZZZZZZZZO^              11   ,0  ^ZZ}        \n"
        "         ZZZ       u ,OZJZ         ZZZZZZZZZZZZZmOJ           uOO^                     ^ZZ                 ZZ           ;ZZZZZZZZZZZZZZZZ      Lm 0Z ^^-ZZZ     ZZ)        \n"
        "        ZZO         ^Q  ^Z       OZZZZZZZZZZ0m^                                        LZZZZ                                 ]ZZZZZZZZZZZZ          Qmm^^ 11     ^ZZi      \n"
        "      ^OZZ        ^Zm,^ Z       ZZZZZZZZZmO                                           ZZZZZZZ  ZZ^                              vmZZZZZZZZZ(      Z?       11     ^ZZ^     \n"
        "      ZZZ        ^ O 0^O      :ZZZZZZZZZ0                                            mZZx^^wZZZZZZ^                               +ZZZZZZZZZZ^   YZ               _ZO      \n"
        "     ,ZZ          ^(_         ZZZZZZZZO^                                     ;^^   >ZZZ^    OZZZmZZ-                                OZZZZZZZZO                     ZZZ     \n"
        "     OZ>          ^0        ^mZZZZZZZZ                                     ^ZZZZZlZZZZ      ^ ^  mZZZ^                              ^cZZZZZZZZZ                     ZZO    \n"
        "   ,ZZZ                     ZZZZZZZZw                                   ^?Z0OZZZZZZZ              ^ZZZ,                               vZZZZZZZZm                     ZZ    \n"
        "    ZZ                     ZZZZZZZZZ                                  ^OZZ0     mm,                ^ ZZ                                0ZZZZZZZZc^                   OZO   \n"
        "   Zm0        Qm          mZZZZZZZZO                               ^iOZZ                              ^ZO^                             ^ZZZZZZZZm                     ZZ,  \n"
        "  ,ZZ         Z,         }ZZZZZZZZZ]                            , mZ~                mZ^                ^t^                             ZZZZZZZZZZ                    QZm^ \n"
        "  OZZ        tZ         ^ZZZZZZZZZZ^                                                 ;Z                                                 ZZZZZZZZZZL                    ZZ  \n"
        " ^ZZ         ZZ         ZmZZZZZZZZZ^                                                 ;Z                                                 ZZZZZZZZZZZ     ,Zm  0Q nm     ZZZ \n"
        " uZm        |0         ^ZZZZZZZZZZZZ                                                 ;Z                                                ,ZZZZZZZZZZZJ   ZZ^OO  ZZZZOZO^ IZZ \n"
        " OZL   Z   ^ZZ         {ZZZZZZZZZZZm                                       ZZZZZZZZZZZmZZZZZZZZZZZ                                     QZZZZZZZZZZZm   Z Z_ O^mm^ mr    ZZ \n"
        " ZZ^  ^    ,Z,         ZZZZZZZZZZZZZm                                      ZZZZZZZZZZZZZZZZZZZZZZZ                                    ^ZZZZZZZZZZZZZ   Oz0^ZC ?ZZ      ^ZZJ\n"
        " ZZ       ^ZZ          ZZZZZZZZZZZZZZZ^                                    ZZZZZZZZZZZZZZZZZZZZZZZ                                   ^mZZZZZZZZZZZZZC       :  ^^       ZZm\n"
        "IZm       ^O Z Z       ZZZZZZZZZZZZZZZZ                            (ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                          ^^OZZZZZZZZZZZZZZZ                   1ZO\n"
        "fZZ  L^   ZZ >^^      ;ZZZZZZZZZZZZZZZZO ^                         (ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                         ^OZZZZZZZZZZZZZZZZO                   :ZZ\n"
        "QmO       Z           ]ZZZZZZZZZZZZZZZZZZZ^                        -nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn^                      ^mZZZZZZZZZZZZZZZZZZZ                    ZZ\n"
        "0ZO      mZ           ]ZZZZZZZZZZZZZZZZZZZm                  mZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ^               ^ ZZZZZZZZZZZZZZZZZZZZ                    ZZ\n"
        "uZZ      ,ZZc         iZZZZZZZZZZZZZZZZZZ^                   ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                   ^ZZZZZZZZZZZZZZZZZZ                    ZZ\n"
        ">ZZ         fi         ZZZZZZZZZZZZZZZO                      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                     ZZZZZZZZZZZZZZZZZ                   ?Zm\n"
        " ZZ      -:;Z          ZZZZZZZZZZZZZmZ^                      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                      lZZZZZZZZZZZZZZZ                  ^OZO\n"
        " ZZ       ^            OZZZZZZZZZZZZZ  ZZZZZZZZZZZZZZZZZZZZZ )))))))))))))))))))))))))))))))))))))))))))))))))) vZZZZZZZZZZZZZZZZZZZZ ~ZZZZZZZZZZZZZ,                   ZZZ\n"
        " mZn                   YZZZZZZZZZZZO  ^ZZZZZZZZZZZZZZZZZZZZZ ZZZZZZZZZZZZZZZZZZZZZZOZZZZZZZZmZZZZZZOZZZZZZZZZZZ^cZZZZZZZZZZZZZZZZZZZZO ZZZZZZZZZZZZZ                    ZZ^\n"
        " ZZO                   ^ZZZZZZZZZZZZ  ZZZZZZZZZZZZZZZZZZZZZZ ZZZZZZZZZZZZ>,i,!!ZZZZ      ZZZmui^>^>IZZZZZZZZZZZ^cZZZZZZZZZZZZZZZZZZZZZ  ZZZZZZZZZZZZ                    ZZ \n"
        " ^Om    ,,  ^       ZZm ZOZZZZZZZZZ~ ^ZZZZZZZZZZZZZZZZZZZZZZ ZZZZZZZZZZZZZ!Z<ZZZZZZ      ZZZZZZ Z ZZZZZZZZZZZZZ^cZZZZZZZZZZZZZZZZZZZZZY ZZZZZZZZZZZ   ^                ZZm \n"
        "  Omx    ^ZZmOOf^0ZZZ:   mZZZZZZZZZ  ^ZZZZZZZZZZZZZZZZZZZZZZ ZZZZZZZZZZZZZ!Z<ZZZZZZ      ZZZZZZ Z ZZZZZZZZZZZZZ^cZZZZZZZZZZZZZZZZZZZZZO ZZZZZZZZZZZ   0O?^             ZZl \n"
        "  (ZZ        ^ ZZZZOm]^^ OZZZZZZZZZl^>JUUUUUUUUUUUUUUUUUUUUU CUUUUUUUUUUUUIJ>UUUUUU      UUUUUU,U YUUUUUUUUUUUU^xUUUUUUUUUUUUUUUUUUUUUY ZZZZZZZZZZ      ZOO           {Zm  \n"
        "   ZZ-     ;mmZZ    ^ _Z, ZZZZZZZZZZ                                                                                                   ^ZZZZZZZZm]      ^]OZmOZ/      ZZf  \n"
        "   [ZZ     ZO            ^ ZZZZZZZZm                                                                                                   OZZZZZZZZm  ^ZZZZOZ:   >ZZZ  ^|Z0   \n"
        "    ZZ0            -mmZZZZ lZZZZZZZZZ^                                   ,0^    ZZOx    mZmO       m                                  ^ZZZZZZZZZ     ^              ^ZZ,   \n"
        "     OZ     mOZZZZZQ        x0ZZZZZZZO^                                 mrZ    O    O^ Z    Z   ^O Z                                  ZZZZZZZZZ    ZO              ^ZZZ    \n"
        "     CZZ    ^^^          um^ vZZZZZZZZm                                   Z    O|  vZ     ,Z^  ^Z  Z                                _OZZZZZZZZ   ,OmY              1ZZ     \n"
        "      ZZm          OZZZZZZZl  -ZZZZZZZZZ/                                 Z         Z^  ^O     ZOOZZO                              ZZZZZZZZmZ    ZO!ZZmZZZZv  ^   ^ZZ      \n"
        "       mZQ^   fZmOi   LZZj      ZZZZZZZZZZ1                               Z    /m _O,  ZOOZZZ^     Z                            ^ZZZZZZZZZZO    ZZ^     ^ iOZO{  ^Zmn,     \n"
        "       ^ZZ1        ^)ZZO^    v^  ZmZZZZZZZZZm^                                                                                LZZZZZZZZZZmx   ^ZZ^               ZZZ       \n"
        "         ZZ+      :ZZZ^ZZZZO<^    ZZZZZZZZZZZZZZO:^            ^Z                                         ^n              CZZZZZZZZZZZZZm^      JZZZm0,         ZZZ        \n"
        "         ^ZZ{    XmmZZ^         ^^  ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ^                                        mZZZZZZZZZZZZZZZZZZZZZZZZZZZOZ             CZZZZC,   ZZO         \n"
        "          ^ZZL                ^ZZZ   nOZZZZZZZZZZZZZZZZZZZZZZZZZZO                                        ZZZZZZZZZZZZZZZZZZZZZZZZZZZO     ZOmZ         ^,   ,OZm^         \n"
        "            ZOO^    ZZ    iOZZZZ       OZZZZZZZZZZZZZZZZZZZZZZZZZZX                                    ^ ZZZZZZZZZZZZZZZZZZZZZZZZZZO     YZv    ZZZOZZ^     ^OZc           \n"
        "            ^0ZZ    ,0ZZZZZ]      ,ZZ    OZZZZZZZZZZZZZZZZZZZZZZZZZ0                                   ,ZZZZZZZZZZZZZZZZZZZZZZZZZZ       OZZlZZZO,  ^OZ    )ZZ^            \n"
        "              zZm              }mOOZ       mZZZZZZZZZZZZZZZZZZZZZZZZO ^                               tZZZZZZZZZZZZZZZZZZZZZZZmO           fZZu     ZO/   ZZZ              \n"
        "                ZZZ         OmZm            ^_OZZZZZZZZZZZZZZZZZZZZZZZm^                           ^ ZZZZZZZZZZZZZZZZZZZZZZZmZ     :UmZZZZL      OZZO    mZm               \n"
        "                 ZZZ    ^:ZOO^         ZOOZ     ZZZZZZZZZZZZZZZZZZZZZZZZm^                       ,UZZZZZZZZZZZZZZZZZZZZZZmZ<      mmO    OZi           ZmO^                \n"
        "                  :wZC          :ZZOmZ^,OZO       ^0ZZZZZZZZZZZZZZZZZZZZZZZZ!                  0ZZZZZZZZZZZZZZZZZZZZZZZOx       ZOZw,  ^0ZZZZZZ1     ^OZm,                 \n"
        "                    QZZX     OmZ^jZZ  ,ZO}     ,      mOZZZZZZZZZZZZZZZZZZZZZZZZZZX;   ^}OZZZZZZZZZZZZZZZZZZZZZZZZZZZ,     ^  ZZ^ ,ZmZZmZ^     v    ZZO                    \n"
        "                      ZZm:^        !mZZm^^    ZZOr        ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZOv^       ,ZZO^^      OZwZ      ^,OZZ                      \n"
        "                        ZZZ       ^^ZmU   ^^Zm;ZZ   ^^^       vZZmZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZmZm          ^ mZZ     0L      OmO    ZZZv                       \n"
        "                        ^^ZZm!    ,lZ,  ^;ZZ?,0ZZ   ~mO^            CZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZO!^^            Zm  ^OOmOZm            ,ZZmU                         \n"
        "                            mZZQ ^     ^ZZf   ZmU IZZ  ^ 1ZZZ ^^             <CZZOZZZZZZZZZZZ|,                 C     ^ZZ    OZZ    ZOm+   ^ZZZ]                           \n"
        "                             ^OZZm^    ^      ZZ OO^  Xm0m:  )mm                                          ^[Z  ,0mZ-   LZ      OZZZm?^  ^vOZO^                             \n"
        "                                ^mOZO^       cZmO^   OZZ      ?ZZ^                                    mm   ZZZ^   ]ZZZ,^ZZ      ^1    ^ZZOm                                \n"
        "                                   OZZZ1      :^     Zm   YZZ,                     !ZZ^    ZZ YZmm^    ZZ^  uZZ,    ^OOZ0Z~        ^OmZZ                                   \n"
        "                                      ZZZZc ^        mZ ^  :ZZZ                    iZZ     ZZ ^ZZZZZO  !Zn^  iOO ^     ^Zm[      0ZZZI                                     \n"
        "                                       ^^ZmZ0Z^        ZZZZZOZ^                    iZZ     ZZ   ZZ^^ZZO ZZ    ,ZZ,           jOZOQ^                                        \n"
        "                                            ;ZmZZZ^        ^}                      iZZ     Zm   ZZ    ZZZZO    ,Z>      ^_ZZZZm                                            \n"
        "                                                (OZZZZ-                             ZZ    ,ZZ    OO     /mO:       ^ mZZZZO                                                \n"
        "                                                    ^ZOZZZZQ                        ,ZZZZZZc     i            ^lZZO0Jc}                                                    \n"
        "                                                          ZOZZZZZOL  ^                                  }ZOZZZZZZi                                                         \n"
        "                                                                ,ZmZZZZZZZZZZZZX)>:      !?rOZZZZZZZZZZZmZf                                                                \n"
        "                                                                           _UZZOZZZZZZZmZZZZ0mOr^  ^                                                                       \n"
        "\033[0m"
    );
}

// 进度条
void ProgressBar()
{
    // 最后100%时的输出形式
    const char* LastStr = "[####################] 100%";
    const char ICON = '#';
    // 每加载5%打印一个ICON
    const int STEP = 5;
    // ICON的个数
    const int MAXNUMICON = 20;
    // 每隔10ms会让进度加1%
    const int PrintInterval = 10;

    printf("\n\t\t\t\t\t\t\t\t\t加载中: ");
    for (int i = 0; i <= 100; ++i)
    {
        printf("[");
        // 每加载5%打印一个ICON
        int Index = i / STEP; 
        for (int j = 0; j < MAXNUMICON; j++)
        {
            if (j < Index)
                printf("%c", ICON);
            else
                printf(" ");
        }
        printf("] ");
        printf("%3d%%", i);
        Sleep(PrintInterval);
        // 回删字符，让数字和进度条原地变化
        for (int j = 0; j < strlen(LastStr); j++)
            printf("\b");
    }
    system("cls");
}

// 打印表头
void ListHead_Print()
{
    printf("\t序号\t姓名\t性别\t年龄\t学号\t\t分数\n");
    printf("-------------------------------------------------------------------\n");
}

// 菜单
void Menu()
{
    LinkList L;
    LinkList_Create(&L);
    char Idx[MAXSIZE] = {0};
    char fn[MAXSIZE] = "fp";
    while (1)
    {
        printf("\033[36m-------------------------------------------------------------------------\n");
        printf("                         欢迎使用学生信息管理系统               \n");
        printf("-------------------------------------------------------------------------\n");
        printf("                             请选择系统功能                     \n");
        printf("-------------------------------------------------------------------------\n");
        printf("                             0.退出系统                          \n");
        printf("                             1.学生信息的录入                    \n");
        printf("                             2.学生信息的删除                    \n");
        printf("                             3.学生信息的修改                    \n");
        printf("                             4.学生信息的查找                    \n");
        printf("                             5.学生信息的显示                    \n");
        printf("                             6.生成学生信息文件                  \n");
        printf("                             7.读取学生信息文件                  \n");
        printf("                             8.清除所有学生信息                  \n");
        printf("-------------------------------------------------------------------------\033[0m\n");
        printf("请选择操作(0-8)：");
        scanf_s(" %c", Idx, MAXSIZE);
        system("cls");

        // scanf()匹配到想要的数据后,会将匹配到的数据从缓冲区中删除,而没有匹配到的数据仍然会留在缓冲区中,考虑到程序的健壮性,故弃用switch case
        if (strcmp(Idx, "0") == 0)
        {
            printf("感谢使用，下次再见！\n");
            exit(0);
        }
        else if (strcmp(Idx, "1") == 0)
            LinkList_Insert2(&L);
        else if (strcmp(Idx, "2") == 0)
            LinkList_Delete(&L);
        else if (strcmp(Idx, "3") == 0)
            LinkList_Rewrite(&L);
        else if (strcmp(Idx, "4") == 0)
            LinkList_SearchById(&L);
        else if (strcmp(Idx, "5") == 0)
            LinkList_Print(&L);
        else if (strcmp(Idx, "6") == 0)
            LinkList_SaveToFile(&L, fn);
        else if (strcmp(Idx, "7") == 0)
            LinkList_LoadFromFile(&L, fn);
        else if (strcmp(Idx, "8") == 0)
            LinkList_Destroy(&L);
        else
            printf("参数错误，请重新输入！\n");
    }
}