/*-------------------------------------------------------------------
 * Purpose:
 *         包含一些通用的函数
 * Time:
 *         2011年8月13日 10:26:16
 * Author:
 *         张彦升
 --------------------------------------------------------------------*/
#ifndef _Misc_h__
#define _Misc_h__

#include <stdint.h>
#include <string>
#include <ctime>
#include <cstring>
#include <cstdlib>
//#include <boost/regex.hpp>

#include "Util.h"

EF_NAMESPACE_BEGIN

template <typename T>
inline T get_min(T left, T right)
{
    return left > right ? right : left;
}

template <typename T>
inline T get_max(T left, T right)
{
    return left > right ? left : right;
}
template <typename T_left, typename T_right>
inline void invertMap(const T_left &source, T_right &target)
{
    typename T_left::const_iterator ipos = source.begin();
    for (; ipos != source.end(); ++ipos)
    {
        target.insert(std::make_pair(ipos->second, ipos->first));
    }
    return;
}
inline int32_t absoluteValue(const int num)
{
    return num < 0 ? (int32_t)-num : (int32_t)num;
}

inline const char *strstrCN(const char *string, const char *strCharSet)
{//这个函数的功能完成中文标点符号的查询
    const char *cp = strstr(string, strCharSet);
    if (cp != NULL && (cp - string) % 2 == 1)
    {//为奇数位
        return NULL;
    }
    return cp;
}

inline const time_t curTime()
{
    return time(NULL);
}

inline const char* curTimeBuffer()
{
    return "";
}

/**
 * description:    这个函数最终会被遗弃
 * parameter:
 * return:
 **/
/*inline void filter_unuse_ch(std::string &buffer)
{
std::string regex_expression("]");

//上述正则表达式过滤无用字符,准确的说这不是正则表达式，哪有这样的正则!
std::string regex_expression_to("");
boost::regex reg(regex_expression,boost::regex::icase|boost::regex::perl);
buffer = boost::regex_replace(buffer,reg,regex_expression_to,boost::match_default | boost::format_all);
}*/
/**
 * 判断是否是实型
 */
inline bool is_float(std::string str)
{
    int32_t pos = str.find('.');
    if (pos != std::string::npos)
    {
        return true;
    }
    return false;
}
/**
 * 判断是否是整型
 */
inline bool is_int(std::string str)
{
    int32_t pos = str.find('.');
    if (pos == std::string::npos)
    {
        return true;
    }
    return false;
}
/**
 * 下面是一些通用的哈希函数，将被MAP使用
 **/
inline unsigned int RSHash(const std::string& str)
{
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;

    for (std::size_t i = 0; i < str.length(); i++)
    {
        hash = hash * a + str[i];
        a = a * b;
    }

    return hash;
}
/* End Of RS Hash Function */


inline unsigned int JSHash(const std::string& str)
{
    unsigned int hash = 1315423911;

    for (std::size_t i = 0; i < str.length(); i++)
    {
        hash ^= ((hash << 5) + str[i] + (hash >> 2));
    }

    return hash;
}
/* End Of JS Hash Function */


inline unsigned int PJWHash(const std::string& str)
{
    unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
    unsigned int ThreeQuarters = (unsigned int)((BitsInUnsignedInt * 3) / 4);
    unsigned int OneEighth = (unsigned int)(BitsInUnsignedInt / 8);
    unsigned int HighBits = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
    unsigned int hash = 0;
    unsigned int test = 0;

    for (std::size_t i = 0; i < str.length(); i++)
    {
        hash = (hash << OneEighth) + str[i];

        if ((test = hash & HighBits) != 0)
        {
            hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
        }
    }

    return hash;
}
/* End Of  P. J. Weinberger Hash Function */


inline unsigned int ELFHash(const std::string& str)
{
    unsigned int hash = 0;
    unsigned int x = 0;

    for (std::size_t i = 0; i < str.length(); i++)
    {
        hash = (hash << 4) + str[i];
        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
        }
        hash &= ~x;
    }

    return hash;
}
/* End Of ELF Hash Function */


inline unsigned int BKDRHash(const std::string& str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    for (std::size_t i = 0; i < str.length(); i++)
    {
        hash = (hash * seed) + str[i];
    }

    return hash;
}
/* End Of BKDR Hash Function */


inline unsigned int SDBMHash(const std::string& str)
{
    unsigned int hash = 0;

    for (std::size_t i = 0; i < str.length(); i++)
    {
        hash = str[i] + (hash << 6) + (hash << 16) - hash;
    }

    return hash;
}
/* End Of SDBM Hash Function */


inline unsigned int DJBHash(const std::string& str)
{
    unsigned int hash = 5381;

    for (std::size_t i = 0; i < str.length(); i++)
    {
        hash = ((hash << 5) + hash) + str[i];
    }

    return hash;
}
/* End Of DJB Hash Function */


inline unsigned int DEKHash(const std::string& str)
{
    unsigned int hash = static_cast<unsigned int>(str.length());

    for (std::size_t i = 0; i < str.length(); i++)
    {
        hash = ((hash << 5) ^ (hash >> 27)) ^ str[i];
    }

    return hash;
}
/* End Of DEK Hash Function */


inline unsigned int BPHash(const std::string& str)
{
    unsigned int hash = 0;
    for (std::size_t i = 0; i < str.length(); i++)
    {
        hash = hash << 7 ^ str[i];
    }

    return hash;
}
/* End Of BP Hash Function */


inline unsigned int FNVHash(const std::string& str)
{
    const unsigned int fnv_prime = 0x811C9DC5;
    unsigned int hash = 0;
    for (std::size_t i = 0; i < str.length(); i++)
    {
        hash *= fnv_prime;
        hash ^= str[i];
    }

    return hash;
}
/* End Of FNV Hash Function */


inline unsigned int APHash(const std::string& str)
{
    unsigned int hash = 0xAAAAAAAA;

    for (std::size_t i = 0; i < str.length(); i++)
    {
        hash ^= ((i & 1) == 0) ? ((hash << 7) ^ str[i] * (hash >> 3)) :
            (~((hash << 11) + (str[i] ^ (hash >> 5))));
    }

    return hash;
}
/* End Of AP Hash Function */

EF_NAMESPACE_END
 
#endif /*!_Misc_h__*/
