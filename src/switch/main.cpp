#include <QApplication>
#include <QDebug>
#include <QWidget>
#include "switch.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget w;

    Switch switch_widget(SimpleSwitchOption(), &w);
    switch_widget.setChecked(true);
    QObject::connect(&switch_widget, &Switch::clicked, [](bool status){
                     qDebug()<<"Clicked " << status;
                     });
    Switch switch_disable(SimpleSwitchOption());
    switch_disable.setEnabled(false);

    QHBoxLayout layout(&w);
    w.setLayout(&layout);
    layout.addWidget(&switch_widget);
    layout.addWidget(&switch_disable);

    w.show();
    return a.exec();
}
