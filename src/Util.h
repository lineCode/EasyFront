/*-------------------------------------------------------------------
 * Purpose:
 *         some utility information will defined at here
 * Time:
 *         2011年11月13日 10:30:17
 * Author:
 *         张彦升
 --------------------------------------------------------------------*/
#ifndef _Util_h__
#define _Util_h__
 
#ifdef _DEBUG
#define EF_DEBUG
#endif

#define EF_NAMESPACE_BEGIN namespace EF {
#define EF_NAMESPACE_END    }

#ifdef EF_DEBUG

#define EF_DEBUG_MESSAGE_POSITION(message) {std::cout << message << "\n\tIn File:" << \
        __FILE__ << "\n\tAt Line:" << __LINE__ << std::endl;}
#define EF_DEBUG_MESSAGE(message) {std::cout << message << std::endl;}
#else
#define EF_DEBUG_MESSAGE(message)
#define EF_DEBUG_MESSAGE_POSITION(message)
#endif //EF_DEBUG

#endif /*!_Util_h__*/