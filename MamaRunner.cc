
#include "MamaRunnner.h"


#include <string>
#include <iostream>
#include <mama/mamacpp.h>
#include <iostream>
#include <sstream>

using namespace mamafs;

bool  mamafs::MamaRunner::instFlag = false;
MamaRunner * mamafs::MamaRunner::inst = NULL;
MamafsMessageCallback  * mamafs::MamaRunner::msgCbs =  new MamafsMessageCallback;

