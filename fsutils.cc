/*
 * Contains the fuse api setup and callbacks code
 *
 */
#include <iostream>
#include <map>
#include <cstdlib>
#include <cerrno>

#include "MamaRunnner.h"
#include "SubscriptionStore.h"
#include "SubscriptionEntity.h"

#include <fuse.h>
#include "fsutils.h"

using namespace mamafs;
using namespace std;

/*
 * All the filesystem callbacks
 */


int mamafs_getattr (const char *path, struct stat *stbuf)
{
    memset(stbuf, 0, sizeof(struct stat));

    if (strcmp(path, "/") == 0) {
        stbuf->st_mode = S_IFDIR | 0755;
        stbuf->st_nlink = 2;
        stbuf->st_size = 4096;
    } else {
         SubscriptionStore *ss = SubscriptionStore::getInstance();
         std::map<string, SubscriptionEntity*>::iterator iter;
         iter = ss->subs.find(++path);
         if ( iter != NULL )
         {
            cout <<  "Found for getattr" << endl;
            stbuf->st_mode = S_IFREG | 0644 ;
            stbuf->st_nlink = 1;
            stbuf->st_size = (*iter).second->getMessage().length();

         } else {
             return -ENONET;
         }
    }

    return 0;
}

int mamafs_readdir ( const char *path, void *buf,
                     fuse_fill_dir_t filler, off_t offset,
                     struct fuse_file_info *fi)
{
    (void) offset;
    (void) fi;

    if (strcmp(path, "/") != 0)
        return -ENOENT;

    filler(buf, ".", NULL, 0);
    filler(buf, "..", NULL, 0);
    
    SubscriptionStore *ss = SubscriptionStore::getInstance();
    std::map<string, SubscriptionEntity*>::iterator iter;
    for (iter = ss->subs.begin(); iter != ss->subs.end(); iter++)
    {
        filler (buf, (*iter).second->getSymbolName().c_str(), NULL, 0);
    }

    return 0;
}

int mamafs_mkdir (const char *path, mode_t mode)
{
    return -EACCES;
}

int mamafs_open (const char *path, struct fuse_file_info *fi)
{
    return 0;
}

int mamafs_read (const char *path, char *buf, size_t size,
                 off_t offset, struct fuse_file_info *fi)
{
        return 0;

}

void *mamafs_init (struct fuse_conn_info *conn)
{
    MamaRunner * mr = MamaRunner::getInstance();
    mr->startMamaInBackground();
    
    return 0;
}

void mamafs_destroy (void * ctx){
    
    SubscriptionStore * ss = SubscriptionStore::getInstance();
    delete ss;
    
    MamaRunner * mr = MamaRunner::getInstance();
    mr->stopMama(); 
    
}

int mamafs_utimens (const char *path, const struct timespec ts[2])
{
    return 0;   
}

int mamafs_create (const char *path, mode_t mode,
                   struct fuse_file_info *fi)
{
    return 0;
}

int mamafs_fgetattr (const char *path, struct stat *stbuf,
                     struct fuse_file_info *fi)
{
    return 0;
}

int mamafs_setxattr (const char *path, const char *name,
                     const char *value, size_t size, int flags)
{
    return 0;  
}

int mamafs_unlink (const char *path)
{
    return 0;
}

int mamafs_opendir (const char * path, struct fuse_file_info *fi)
{
    return 0;
}
