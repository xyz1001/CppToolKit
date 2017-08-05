#include <QEventLoop>
#include <QDialog>

#include "xswitch/xswitch.h"

void XSwitchRun() {
    QDialog widget;

    XSwitchOption option{20,
                        0,
                        40,
                        20,
                        QBrush(QColor("#000000")),
                        QBrush(QColor("#0000ff")),
                        QBrush(QColor(0, 255, 255, 50)),
                        QBrush(QColor("#ff00ff")),
                        QBrush(QColor("#ffff00"))};

    XSwitch xswitch(option);
    XSwitch xswitch_disable(option);
    xswitch_disable.setEnabled(false);

    QHBoxLayout layout;
    widget.setLayout(&layout);
    layout.addWidget(&xswitch);
    layout.addWidget(&xswitch_disable);
    widget.exec();
}
