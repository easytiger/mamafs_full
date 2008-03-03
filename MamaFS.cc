// 
// File:   MamaFS.cc
// Author: gerry
//
// Created on 29 February 2008, 15:22
//

#include <stdlib.h>
#include <iostream>
#include <fuse.h>
#include <ctime>
#include <map>

#include <mama/mamacpp.h>

#include "SubscriptionStore.h"
#include "SubscriptionEntity.h"
#include "MamaRunnner.h"
#include "fsutils.h"

using namespace std;
using namespace Wombat;
using namespace mamafs;

int main(int argc, char** argv) 
{
    fuse_operations mamafs_ops;
    memset(&mamafs_ops, 0, sizeof(fuse_operations));
    
    mamafs_ops.init     = mamafs_init;
    mamafs_ops.destroy  = mamafs_destroy;
    mamafs_ops.readdir  = mamafs_readdir;
    mamafs_ops.getattr  = mamafs_getattr;
    mamafs_ops.open     = mamafs_open;
    mamafs_ops.read     = mamafs_read;
    mamafs_ops.mkdir    = mamafs_mkdir;
    mamafs_ops.create   = mamafs_create;
    mamafs_ops.setxattr = mamafs_setxattr;
    mamafs_ops.fgetattr = mamafs_fgetattr;
    
    return fuse_main (argc, argv, &mamafs_ops, NULL);
}
