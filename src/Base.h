/*-------------------------------------------------------------------
 * Purpose:
 *         this is the super father object
 * Time:
 *         2011年11月13日 13:35:45
 * Author:
 *         张彦升
 --------------------------------------------------------------------*/
#ifndef _Base_h__
#define _Base_h__

#include "Util.h"

EF_NAMESPACE_BEGIN

/**
 * abstract class,not for initialize
 *
 **/
class Base
{
public:
protected:
    Base();
    virtual ~Base() = 0;
private:
};

EF_NAMESPACE_END

#endif /*!_Base_h__*/