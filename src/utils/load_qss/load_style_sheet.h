/* Copyright (©) 2017 zgzf1001@gmail.com */

#ifndef SRC_UTILS_LOAD_STYLE_SHEET_H_
#define SRC_UTILS_LOAD_STYLE_SHEET_H_

#include <QString>
#include <QWidget>

namespace utils {

/**
 * 读取QSS文件并设置到widget上
 *
 * @param qss_file_name QSS文件名
 * @param widget    要设置QSS的widget
 */
void LoadStyleSheet(const QString &qss_file_name, QWidget *widget);

}  // namespace utils

#endif  // SRC_UTILS_LOAD_STYLE_SHEET_H_
