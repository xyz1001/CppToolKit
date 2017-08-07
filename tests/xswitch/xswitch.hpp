#include <QEventLoop>
#include <QDialog>
#include <QDebug>

#include "xswitch/xswitch.h"

void XSwitchRun() {
    QDialog widget;

    using xwidget::xswitch::XSwitchOption;
    using xwidget::xswitch::XSwitch;

    XSwitch xswitch(xwidget::xswitch::SimpleSwitchOption());
    xswitch.setChecked(true);
    QObject::connect(&xswitch, &XSwitch::clicked, &widget, [](bool status){
                     qDebug()<<"Clicked " << status;
                     });
    XSwitch xswitch_disable(xwidget::xswitch::SimpleSwitchOption());
    xswitch_disable.setEnabled(false);

    QHBoxLayout layout;
    widget.setLayout(&layout);
    layout.addWidget(&xswitch);
    layout.addWidget(&xswitch_disable);
    widget.exec();
}
