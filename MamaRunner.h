// 
// File:   MamaRunnner.h
// Author: gerry
//
// Created on 29 February 2008, 16:30
//

#ifndef _MAMARUNNNER_H
#define	_MAMARUNNNER_H

#include <string>
#include <mama/mamacpp.h>
#include "mama_callbacks.h"

using namespace std;
using namespace Wombat;


namespace mamafs {
    
    class MamaRunner    // NB: singleton
    {

    private:
        static bool instFlag;
        static MamaRunner *inst;

    public:

        // it is of course bad to make these public like this
        // TODO: encapsulate all this crap
        mamaBridge              mBridge;
        string                  mWare;
        MamaQueue              *mDefQueue;
        MamaTransport          *mTransport;
        MamaSource             *mSource;
        MamaSource             *dSource;
        MamaDictionary         *mDictionary;

        char *middlware_str;
        char *tport_str;
        char *source_str;
        
        static MamafsMessageCallback  *msgCbs;
        static MamaRunner *getInstance();

        // MamaRunner();
        ~MamaRunner();

        void init();
        void fetchDataDictionary();
        void startMama();
        void startMamaInBackground();
        void stopMama();
    };

}

#endif	/* _MAMARUNNNER_H */

