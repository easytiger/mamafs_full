
#include "SubscriptionStore.h"
#include "SubscriptionEntity.h"
#include <map>
#include <mama/mamacpp.h>
#include <iostream>

using namespace mamafs;
using namespace std;

bool SubscriptionStore::instFlag = false;
SubscriptionStore * SubscriptionStore::inst = NULL;

SubscriptionStore * mamafs::SubscriptionStore::getInstance()
{
    if (!instFlag)
    {
        inst = new SubscriptionStore();
        instFlag = true;
        cout << "Returning the new instance" << endl;
        return inst;
    }
    else
    {
        cout << "Returning the existing instance" << endl;
        return inst;
    }
}
