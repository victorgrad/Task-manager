#include "gui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo{"tasks.txt"};
    Validator val;
    Service serv{ val,repo };
    Gui w{serv};
    w.show();
    w.Update();
    return a.exec();
}
