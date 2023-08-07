#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "Student.h"
#include "LinkList.h"

// ��������, "\033[������ɫ; ������ɫm �ַ��� \033[0m", ����������\033[��ͷ����m��β
// �ն� �ֺ�6 ��171 ��100 �ɿ�����������
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

// ������
void ProgressBar()
{
    // ���100%ʱ�������ʽ
    const char* LastStr = "[####################] 100%";
    const char ICON = '#';
    // ÿ����5%��ӡһ��ICON
    const int STEP = 5;
    // ICON�ĸ���
    const int MAXNUMICON = 20;
    // ÿ��10ms���ý��ȼ�1%
    const int PrintInterval = 10;

    printf("\n\t\t\t\t\t\t\t\t\t������: ");
    for (int i = 0; i <= 100; ++i)
    {
        printf("[");
        // ÿ����5%��ӡһ��ICON
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
        // ��ɾ�ַ��������ֺͽ�����ԭ�ر仯
        for (int j = 0; j < strlen(LastStr); j++)
            printf("\b");
    }
    system("cls");
}

// ��ӡ��ͷ
void ListHead_Print()
{
    printf("\t���\t����\t�Ա�\t����\tѧ��\t\t����\n");
    printf("-------------------------------------------------------------------\n");
}

// �˵�
void Menu()
{
    LinkList L;
    LinkList_Create(&L);
    char Idx[MAXSIZE] = {0};
    char fn[MAXSIZE] = "fp";
    while (1)
    {
        printf("\033[36m-------------------------------------------------------------------------\n");
        printf("                         ��ӭʹ��ѧ����Ϣ����ϵͳ               \n");
        printf("-------------------------------------------------------------------------\n");
        printf("                             ��ѡ��ϵͳ����                     \n");
        printf("-------------------------------------------------------------------------\n");
        printf("                             0.�˳�ϵͳ                          \n");
        printf("                             1.ѧ����Ϣ��¼��                    \n");
        printf("                             2.ѧ����Ϣ��ɾ��                    \n");
        printf("                             3.ѧ����Ϣ���޸�                    \n");
        printf("                             4.ѧ����Ϣ�Ĳ���                    \n");
        printf("                             5.ѧ����Ϣ����ʾ                    \n");
        printf("                             6.����ѧ����Ϣ�ļ�                  \n");
        printf("                             7.��ȡѧ����Ϣ�ļ�                  \n");
        printf("                             8.�������ѧ����Ϣ                  \n");
        printf("-------------------------------------------------------------------------\033[0m\n");
        printf("��ѡ�����(0-8)��");
        scanf_s(" %c", Idx, MAXSIZE);
        system("cls");

        // scanf()ƥ�䵽��Ҫ�����ݺ�,�Ὣƥ�䵽�����ݴӻ�������ɾ��,��û��ƥ�䵽��������Ȼ�����ڻ�������,���ǵ�����Ľ�׳��,������switch case
        if (strcmp(Idx, "0") == 0)
        {
            printf("��лʹ�ã��´��ټ���\n");
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
            printf("�����������������룡\n");
    }
}