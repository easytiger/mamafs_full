
#include "SubscriptionStore.h"
#include "SubscriptionEntity.h"
#include "MamaRunnner.h"

#include <map>
#include <mama/mamacpp.h>
#include <iostream>

using namespace mamafs;
using namespace std;

bool SubscriptionStore::instFlag = false;
SubscriptionStore * SubscriptionStore::inst = NULL;

SubscriptionStore * 
mamafs::SubscriptionStore::getInstance()
{
    if (!instFlag)
    {
        inst = new SubscriptionStore();
        instFlag = true;
        return inst;
    }
    else
    {
        return inst;
    }
}

mamafs::SubscriptionStore::SubscriptionStore()
{
    
}

mamafs::SubscriptionStore::~SubscriptionStore()
{
    std::map<string, SubscriptionEntity*>::iterator iter;
    for (iter = subs.begin(); iter != subs.end(); iter++)
    {
        delete (*iter).second;
        subs.erase(iter);
    }
}

void 
mamafs::SubscriptionStore::printStoreContents()
{
    std::map<string, SubscriptionEntity*>::iterator iter;
    for (iter = subs.begin(); iter != subs.end(); iter++)
    {
        cout << "Entry : " << (*iter).first << " Msg: "
             << (*iter).second->getMessage() << endl;
    }
}


bool 
mamafs::SubscriptionStore::addEntity(string symName)
{
    MamaRunner * mr = MamaRunner::getInstance();
    
    std::map<string, SubscriptionEntity*>::iterator iter;
    if ( (iter = subs.find(symName)) == subs.end())
    {    
        SubscriptionEntity * se = new SubscriptionEntity(symName);
        se->setMessage("New Entity");
        subs[symName] = se;
        
        se->mamaSub.create( mr->mTransport, 
                            mr->mDefQueue, 
                            mr->msgCbs, 
                            "UTP_WMW", 
                            symName.c_str(), 
                            NULL);
        cout << "Symbol " << symName << " added" << endl;
    }
    else
    {
        cout << "Not adding.. already in store" << endl;
    }
    
    

}

SubscriptionEntity * 
mamafs::SubscriptionStore::getSubscriptionEntityBySym(string symName)
{
    
    
    SubscriptionEntity * subEnt = NULL;
    std::map<string, SubscriptionEntity*>::iterator iter;
    
    if ( ! ((iter = subs.find(symName)) == subs.end()) ) 
    {
        subEnt = (*iter).second;
        cout << "foudn symbol" << endl;
    }
    
    return subEnt;
    
}

void
mamafs::SubscriptionStore::removeBySymName(string symName)
{
    std::map<string, SubscriptionEntity*>::iterator iter;
    
    iter = subs.find(symName);
    
    if (iter != subs.end())
    {
        delete (*iter).second;
        subs.erase(iter);
    }
    
}
