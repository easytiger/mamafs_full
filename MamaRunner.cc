
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

MamaRunner * mamafs::MamaRunner::getInstance()
{
    if ( !instFlag)
    {
        inst = new MamaRunner();
        instFlag = true;

        return inst;
    }
    else
    {
        return inst;
    }
}

void mamafs::MamaRunner::startMama()
{
    Mama::start(mBridge);
}

void mamafs::MamaRunner::stopMama()
{
    Mama::stop(mBridge);
}

void mamafs::MamaRunner::startMamaInBackground()
{
    StartCallback * msc = new StartCallback;
    Mama::startBackground(mBridge,  msc);
}

mamafs::MamaRunner::~MamaRunner()
{
    instFlag = false;
    delete inst;
}

void mamafs::MamaRunner::init()
{
    // todo: extract all settings to be command line params
    
    mBridge = Mama::loadBridge("wmw");
    Mama::open();
    mDefQueue = Mama::getDefaultEventQueue(mBridge);

    mTransport = new MamaTransport();
    mTransport->create("gerry_utp", mBridge);
    
    
    mSource = new Wombat::MamaSource("GERRY", mTransport, "WOMBAT");

    fetchDataDictionary();    
}



