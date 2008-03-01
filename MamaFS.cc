// 
// File:   MamaFS.cc
// Author: gerry
//
// Created on 29 February 2008, 15:22
//

#include <stdlib.h>
#include <iostream>
#include <fuse.h>
#include "time.h"

#include <mama/mamacpp.h>

#include "MamaRunnner.h"

using namespace std;
using namespace Wombat;
using namespace mamafs;

int main(int argc, char** argv) 
{
    
    MamaRunner * mr = MamaRunner::getInstance();
    mr->init();
    // should have dictionary by now
    mr->startMamaInBackground();
    sleep(5);
    mr->stopMama();
    
    return (EXIT_SUCCESS);
}

