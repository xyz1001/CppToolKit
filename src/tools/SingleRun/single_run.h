/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef SINGLERUN_SINGLE_RUN_H_
#define SINGLERUN_SINGLE_RUN_H_

#define APPNAME "your_app_name"

#ifndef APPNAME
#warning You should define APPNAME above
#endif /* ifndef  */

namespace utils {

bool IsSingleRun();

}  // namespace utils

#endif  // SINGLERUN_SINGLE_RUN_H_
