/*
 * Contains implementations of Callbacks For:
 *
 * # MamafsMessageCallback -> MamaSubscriptionCallback
 * # DictionaryCallback    -> MamaDictionaryCallback
 * # StartCallback         -> MamaStartCallback
 *
 */

/*
 * MamaSubscriptionCallback Implementation
 */

#include "mama_callbacks.h"
#include <mama/mamacpp.h>


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

}

void mamafs::MamafsMessageCallback::onGap (MamaSubscription* subscription)
{
    
}

void mamafs::MamafsMessageCallback::onRecapRequest (MamaSubscription* subscription)
{
    
}

