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
#include "fsutils.h"

using namespace std;
using namespace Wombat;
using namespace mamafs;

int main(int argc, char** argv) 
{
    fuse_operations mamafs_ops;
    
    memset(&mamafs_ops, 0, sizeof(fuse_operations));
    
    mamafs_ops.init = mamafs_init;
    mamafs_ops.destroy = mamafs_destroy;
    mamafs_ops.readdir = mamafs_readdir;
    mamafs_ops.getattr = mamafs_getattr;
    mamafs_ops.open = mamafs_open;
    
    MamaRunner * mr = MamaRunner::getInstance();
    mr->init();
    
    return fuse_main (argc, argv, &mamafs_ops, NULL);

}

