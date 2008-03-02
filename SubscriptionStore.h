// 
// File:   SubscriptionStore.h
// Author: gerry
//
// Created on 01 March 2008, 21:16
//

#ifndef _SUBSCRIPTIONSTORE_H
#define	_SUBSCRIPTIONSTORE_H

#include "SubscriptionEntity.h"
#include <mama/mamacpp.h>
#include <map>

using namespace std;

namespace mamafs
{
    
    class SubscriptionStore
    {
    private:
        static bool instFlag;
        static SubscriptionStore *inst;
        SubscriptionStore();
        
        
        map<string, SubscriptionEntity*> subs;
    public:
        static SubscriptionStore * getInstance();
        ~SubscriptionStore();
        
        void printStoreContents(void);
        bool addEntity(string symName);
        SubscriptionEntity * getSubscriptionEntityBySym(string sym_name);
        
    };
}

#endif	/* _SUBSCRIPTIONSTORE_H */

