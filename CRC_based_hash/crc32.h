#ifndef _CIPHER_CRC32_H_
#define _CIPHER_CRC32_H_

#include <stdint.h>

namespace platform
{
namespace commlib
{
class CCrc32
{
public:
    CCrc32() : crc(0) {}

    /*
     *@brief 增量计算crc32的值
     *@ptr 待计算的数据
     *@len 待计算的数据长度
     *@return  = 0  成功
               < 0  失败
     */
    int Update(unsigned char *ptr, uint32_t len);
    /*
     *@brief 将Update的增量计算结果返回
     *@return  crc32的结果
     */
    uint32_t Final();

    /*
     *@brief 一次性计算crc32值
     *@ptr 待计算的数据
     *@len 待计算的数据长度
     *@return  crc32的结果
     */
    uint32_t Crc32(unsigned char *ptr, uint32_t len);

private:
    uint32_t crc;
};
}
}

#endif /* _CIPHER_CRC32_H_ */
