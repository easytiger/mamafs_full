#include <iostream>

#include "CLParser.h"
#include "MamaRunnner.h"

#include <cstring>

using namespace std;

mamafs::CLParser::CLParser(int argc, char **argv)
{
    MamaRunner * mr = mamafs::MamaRunner::getInstance();
    
    int i = 1;
    bool min_met = true;
    
    //defaul values
    foreground = false;
    debug = true;
    middleware = "wmw";
    
    while (i < argc)
    {
       cout << "Arg " << i << " " << argv[i] << endl;
        
        if (compare(argv[i], "-tport")){
            tport = strdup(argv[++i]);
            
        }
        else if (compare(argv[i], "-S")){
            source = strdup(argv[++i]);
            
        }
       else if (compare(argv[i], "-m")){
            middleware = strdup(argv[++i]);
            
        }
       else if ( (compare(argv[i], "-M") || (compare(argv[i], "--mount-point")) ) ){
            mountpoint = strdup(argv[++i]);
            
        }
       else if ( (compare(argv[i], "-F") || (compare(argv[i], "--foreground")) ) ){
            foreground = true;

        }
       else if ( compare(argv[i], "--debug")  ){
            debug = true;

        }
       
        ++i;
    }//end while

    //todo check on exit for required params and exit if not given
    cout << "TRANSPORT " << tport << endl;
    cout << "SOURCE " << source << endl;
    cout << "MIDDLEWARE " << middleware << endl;
    cout << "MOUNTPOUINT " << mountpoint << endl;
    
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
    
    // set exe name
    arg_ar[num] = new char[12]; 
    arg_ar[num] = "mamafs_full";

    arg_ar[++num] = new char[strlen(mountpoint)]; 
    arg_ar[num] = mountpoint;
    
    // set -f
    if (foreground)
        arg_ar[++num] = new char[num]; arg_ar[num] = "-f";

    if (debug)
        arg_ar[++num] = new char[num]; arg_ar[num] = "-d";

    return ++num;
    
}

