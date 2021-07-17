#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#include <stdlib.h>

uint32_t readint(char* filename)
{
    FILE* file = fopen(filename,"rb");
    uint32_t f;
    size_t readlen = fread(&f,1,sizeof(uint32_t),file);
    if(readlen != sizeof(uint32_t)){
        printf("fread return %lu\n",readlen);
        exit(-1);
    }
    f=ntohl(f);
    fclose(file);
    return f;
}
int main(int argc, char* argv[])
{
    if(argc!=3){
        return -1;
    }
    uint32_t f1 = readint(argv[1]);
    uint32_t f2 = readint(argv[2]);

    return (f1 + f2);
}
/*
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
*/
