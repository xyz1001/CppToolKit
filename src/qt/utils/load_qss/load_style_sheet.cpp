/* Copyright (©) 2017 zgzf1001@gmail.com */

#include "load_style_sheet.h"

#include <QDebug>
#include <QFile>
#include <QRegExp>


namespace utils {

void LoadStyleSheet(const QString &qss_file_name, QWidget *widget) {
    if (widget == nullptr) { return; }

    QFile file(":/qss/" + qss_file_path);
    file.open(QFile::ReadOnly);
    QString style_sheet = QString::fromLatin1(file.readAll());
    widget->setStyleSheet(style_sheet);
    file.close();
}

}  // namespace utils
