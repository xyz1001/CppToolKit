#include <QApplication>
#include <QWidget>
#include <QSize>
#include <QPushButton>
#include <QLabel>

#include "scale.h"

using utils::Scale;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget w;
    w.resize(Scale<QSize>(200, 200));

    QPushButton btn("Button", &w);
    btn.resize(Scale<QSize>(60, 30));

    QLabel label("Label", &w);
    label.move(Scale<QPoint>(10, 30));

    QWidget widget(&w);
    widget.setStyleSheet(Scale("QWidget{background-color: #00FF00;"
                          " margin: 10px 20px 10px 20px;}"));
    widget.setGeometry(Scale<QRect>(0, 60, 50, 50));

    w.show();
    return a.exec();
}
