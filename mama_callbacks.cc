/*
 * Contains implementations of Callbacks For:
 *
 * MamafsMessageCallback -> MamaSubscriptionCallback
 * DictionaryCallback    -> MamaDictionaryCallback
 * StartCallback         -> MamaStartCallback
 *
 */

/*
 * MamaSubscriptionCallback Implementation
 */

#include "mama_callbacks.h"
#include "MamaRunnner.h"

#include <mama/mamacpp.h>

#include <iostream>

using namespace mamafs;
using namespace std;

mamafs::MamafsMessageCallback::~MamafsMessageCallback ()
{
    
}

void mamafs::MamafsMessageCallback::onCreate (MamaSubscription* subscription)
{
    
}

void mamafs::MamafsMessageCallback::onError(MamaSubscription* subscription,
                                            const MamaStatus& status, 
                                            const char* symbol)
{

}

void mamafs::MamafsMessageCallback::onQuality (MamaSubscription *subscription, 
                                               mamaQuality quality, 
                                               const char *symbol, 
                                               short cause, 
                                               const void *platformInfo)
{

}

void mamafs::MamafsMessageCallback::onMsg(MamaSubscription*  subscription,
                                          MamaMsg&     msg)
{
    cout << "Message Recieved - " <<  msg.getMsgTypeName() << " recieved for " 
         << subscription->getSymbol() << endl;
}

void mamafs::MamafsMessageCallback::onGap (MamaSubscription* subscription)
{
    
}

void mamafs::MamafsMessageCallback::onRecapRequest (MamaSubscription* subscription)
{
    
}

/*
 * END OF MamaSubscriptionCallback Implementation
 */


/*
 * Dictionary Callbacks
 */
void mamafs::DictionaryCallback::onTimeout()
{
    std::cout << "Dictionary Timeout called" << std::endl;
    MamaRunner * mr = mamafs::MamaRunner::getInstance();
    mr->stopMama();

}

void mamafs::DictionaryCallback::onError(const char * errMsg)
{
    std::cout << "Dictionary Error Called" << std::endl;
    MamaRunner * mr = mamafs::MamaRunner::getInstance();
    mr->stopMama();
}

void mamafs::DictionaryCallback::onComplete()
{
    std::cout << "Dictionary received" << std::endl;
    MamaRunner * mr = mamafs::MamaRunner::getInstance();
    mr->stopMama();

}

void mamafs::MamaRunner::fetchDataDictionary()
{

    mDictionary = new MamaDictionary;
    DictionaryCallback dictCallbacks;
    
    dSource = new Wombat::MamaSource("WOMBAT", mTransport, "WOMBAT");
    
    mDictionary->create(mDefQueue,
                        &dictCallbacks,
                        dSource,
                        3,
                        10.0);
    
     MamaRunner * mr = mamafs::MamaRunner::getInstance();
     mr->startMama();     
}

void mamafs::StartCallback::onStartComplete(MamaStatus status)
{
    cout << "MamaStartCallback called with status " <<status.toString() << endl;
}
