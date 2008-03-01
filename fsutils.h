// 
// File:   fsutils.h
// Author: gerry
//
// Created on 01 March 2008, 13:45
//

#ifndef _FSUTILS_H
#define	_FSUTILS_H

#include <fuse.h>


int mamafs_getattr (const char *path, struct stat *stbuf);

int mamafs_readdir (const char *path, void *buf,
                         fuse_fill_dir_t filler, off_t offset,
                         struct fuse_file_info *fi);

int mamafs_mkdir (const char *path, mode_t mode);

int mamafs_open (const char *path, struct fuse_file_info *fi);

int mamafs_read (const char *path, char *buf, size_t size,
                      off_t offset, struct fuse_file_info *fi);

void *mamafs_init (struct fuse_conn_info *conn);

int mamafs_utimens (const char *path, const struct timespec ts[2]);

int mamafs_create (const char *path, mode_t mode,
                        struct fuse_file_info *fi);

int mamafs_fgetattr (const char *path, struct stat *stbuf,
                          struct fuse_file_info *fi);

int mamafs_setxattr (const char *path, const char *name,
                          const char *value, size_t size, int flags);

int mamafs_unlink (const char *path);

int mamafs_opendir (const char * path, struct fuse_file_info *fi);

void mamafs_destroy (void * ctx);

#endif	/* _FSUTILS_H */

