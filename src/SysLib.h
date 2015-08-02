/*-------------------------------------------------------------------
* Purpose:
*         system library
* Time:
*         2012��3��2�� 12:24:11
* Author:
*         ������
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
 * ����һ��C���������ݹؼ��֣��鿴�ùؼ����Ƿ���ϵͳ�����ؼ���
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
