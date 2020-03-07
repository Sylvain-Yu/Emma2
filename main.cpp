#include "emma2.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Emma2 w;
    w.setWindowIcon(QIcon(":/icon/Image/main.png"));
    w.show();
    return a.exec();
}
