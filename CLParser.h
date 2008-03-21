// 
// File:   CLParser.h
// Author: gerry
//
// Created on 08 March 2008, 21:13
//

#ifndef _CLPARSER_H
#define	_CLPARSER_H

namespace mamafs
{
    class CLParser
    {
    private:
        // args
        char * mountpoint;
        char * middleware;
        char * source;
        char * tport;
        bool foreground;
        bool debug;
        
        bool compare(char * s1, char * s2);
        
    public:
        CLParser(int argc, char ** argv);
        ~CLParser();
        
        int getFuseArgs(char ** arg_ar);
        void printFuseArgs();
        
        char * getMountpoint();
        char * getTransport();
        char * getSource();
        char * getMiddleware();
        // etc
    };
}


#endif	/* _CLPARSER_H */
