// 
// File:   mama_callbacks.h
// Author: gerry
//
// Created on 29 February 2008, 16:38
//

/*
 * Contains definitions of Callback classes for:
 *
 * # MamafsMessageCallback -> MamaSubscriptionCallback
 * # DictionaryCallback    -> MamaDictionaryCallback
 * # StartCallback         -> MamaStartCallback
 *
 */

#ifndef _MAMA_CALLBACKS_H
#define	_MAMA_CALLBACKS_H

#include <mama/mamacpp.h>

using namespace Wombat;
using namespace std;

namespace mamafs 
{
    
    class MamafsMessageCallback : public MamaSubscriptionCallback
    {
    public:
        virtual ~MamafsMessageCallback   ();

        virtual void onCreate (MamaSubscription* subscription);


        virtual void onError(MamaSubscription* subscription,
                            const MamaStatus& status,
                            const char* symbol);


        virtual void    onQuality (MamaSubscription *subscription,
                                   mamaQuality quality,
                                   const char *symbol,
                                   short cause,
                                   const void *platformInfo);

        virtual void onMsg (MamaSubscription*  subscription,
                                   MamaMsg&     msg);

        virtual void onGap (MamaSubscription* subscription);

        virtual void onRecapRequest (MamaSubscription* subscription);

    };
    
}
#endif	/* _MAMA_CALLBACKS_H */

