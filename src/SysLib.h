/*-------------------------------------------------------------------
* Purpose:
*         system library
* Time:
*         2012年3月2日 12:24:11
* Author:
*         张彦升
--------------------------------------------------------------------*/
#ifndef _SysLib_h__
#define _SysLib_h__

#include "Util.h"
#include "object.h"

#include <iostream>
#include <string>

EF_NAMESPACE_BEGIN

static CoutObject* cout_handler = new CoutObject();

/**
 * 这是一个C函数，根据关键字，查看该关键字是否是系统保留关键字
 */
inline Object* reserver(std::string name)
{
    if (name == "cout")
    {
        return cout_handler;
    }
    else
    {
        return NULL;
    }
}

EF_NAMESPACE_END

#endif /*!_SysLib_h__*/
