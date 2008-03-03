// 
// File:   SubscriptionEntity.h
// Author: gerry
//
// Created on 01 March 2008, 20:47
//

/*
 * This class contains all the information we need a bout each file/subscription
 *
 */

#ifndef _SUBSCRIPTIONENTITY_H
#define	_SUBSCRIPTIONENTITY_H

#include <string>
#include <mama/mamacpp.h>

namespace mamafs
{
    class SubscriptionEntity
    {
    private:
        string symbolName;
        string message;
        time_t lastUpdateTime;
        
    public:
        //SubscriptionEntity();
        SubscriptionEntity(string sym_name);
        
        ~SubscriptionEntity();
        
        Wombat::MamaSubscription * mamaSub;   // public mamaSub
        
        string getSymbolName();
        void setSymbolName(string sym_name);
        
        string getFilePath();
        
        string getMessage();
        void setMessage(string msg);

        void setUpdateTimeToNow();
        time_t getUpdateTime();
    };  
}

#endif	/* _SUBSCRIPTIONENTITY_H */

