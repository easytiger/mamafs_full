#include <iostream>

#include "CLParser.h"
#include "MamaRunnner.h"

#include <cstring>

using namespace std;

mamafs::CLParser::CLParser(int argc, char **argv)
{
    int i = 1; // args 
    
    //default values
    foreground = false;
    debug = false;
    middleware = strdup("wmw");
    
    MamaRunner * mr = MamaRunner::getInstance();
    
    mr->middlware_str = middleware;
    
    while (i < argc)
    {
       cout << "Arg " << i << " " << argv[i] << endl;

        if (compare(argv[i], "-M")){
            mountpoint = strdup(argv[++i]);
            cout << "Mountpoint encountered\n" ;
        }
       
        if (compare(argv[i], "-tport")){
            tport = strdup(argv[++i]);
            mr->tport_str = tport;
            
        }
        else if (compare(argv[i], "-S")){
            source = strdup(argv[++i]);
            mr->source_str = source;
            
        }
       else if (compare(argv[i], "-m")){
            middleware = strdup(argv[++i]);
            mr->middlware_str = middleware;
        }
       else if ( (compare(argv[++i], "-F") || (compare(argv[i], "--foreground")) ) ){
            foreground = true;

        }
       else if ( compare(argv[++i], "--debug")  ){
            debug = true;
            cout << "SETTING DEBUG TO TRUE" << endl;
        }
       
        ++i;
    }//end while
}

mamafs::CLParser::~CLParser()
{
    
}

bool mamafs::CLParser::compare(char * s1, char * s2)
{
    if (strcmp(s1, s2) != 0)
        return false;
    else
        return true;
}

/*
 * arg_ar - array to be modified
 */
int mamafs::CLParser::getFuseArgs(char ** arg_ar)
{
    
    int num = 0;
    
    arg_ar[num] = new char[12]; 
    arg_ar[num] = strdup("mamafs_full");
    num++;
    
    arg_ar[num] = new char[strlen(mountpoint)]; 
    arg_ar[num] = mountpoint;
    
    num++;
    arg_ar[num] = new char[3]; arg_ar[num] = "-f";
//    
//    // set -f
//    if (foreground)
//        arg_ar[++num] = new char[num]; arg_ar[num] = "-f";
//
//    if (debug)
//        arg_ar[++num] = new char[num]; arg_ar[num] = "-d";

    return num + 1;
    
}

