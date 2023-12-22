#ifndef  __sm4_H__
#define  __sm4_H__

#include <stdint.h>
/* SM4算法
 *分组长度为128位（即16字节，4字）
 *密钥长度也为128位（即16字节，4字）
 *加解密过程采用了32轮迭代机制每一轮需要一个轮密钥
 */

// 定义一些常量
#define SM4_BLOCK_SIZE 16 // 分组长度
#define SM4_KEY_SIZE 16 // 密钥长度
#define SM4_IV_SIZE 16 // 初始向量长度
#define SM4_KEY_SCHEDULE_SIZE 32 // 轮密钥长度
// 32位循环左移
#define SM4_ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

#define GET_ULONG_BE(n,b,i)                             \
{                                                       \
    (n) = ( (uint32_t) (b)[(i)    ] << 24 )        \
        | ( (uint32_t) (b)[(i) + 1] << 16 )        \
        | ( (uint32_t) (b)[(i) + 2] <<  8 )        \
        | ( (uint32_t) (b)[(i) + 3]       );       \
}

#define PUT_ULONG_BE(n,b,i)                             \
{                                                       \
    (b)[(i)    ] = (uint8_t) ( (n) >> 24 );       \
    (b)[(i) + 1] = (uint8_t) ( (n) >> 16 );       \
    (b)[(i) + 2] = (uint8_t) ( (n) >>  8 );       \
    (b)[(i) + 3] = (uint8_t) ( (n)       );       \
}

void sm4_key_expand(uint8_t *key, uint32_t *rk);

void sm4_ecb_encrypt(const uint8_t *in, uint8_t *out, uint32_t *rk);

void sm4_ecb_decrypt(const uint8_t *in, uint8_t *out, uint32_t *rk);


#endif
/* sm4 */