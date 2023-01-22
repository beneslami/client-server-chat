#include<QApplication>
#include "ui.h"
int main(int argc, char **argv){
    QApplication app(argc, argv);
    ui ui;
    ui.show();
    return app.exec();
}
