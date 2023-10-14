#include "mainwindow.h"
#include <QPixmap>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow win;
    win.resize(800,500);
    win.move(100,100);
    QPalette pal;
    pal.setBrush(QPalette::Active, QPalette::Window, QBrush(QPixmap("C:/Qt/projects/main_menu_2/main_menu_background.png")));
    win.setPalette(pal);
    win.show();
    return app.exec();
}
