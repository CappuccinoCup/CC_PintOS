#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

/**
 * Fixed-Point Real Arithmetic
 * 用于解决 PintOS 不支持浮点数的问题
 * 参考官方文档：http://www.scs.stanford.edu/10wi-cs140/pintos/pintos_7.html#SEC131
*/

#include <stdint.h>
#include <debug.h>

/* fixed-point 类型 */
typedef int32_t fp_t;
#define fp_size 32

/* fixed-point 类型格式为 p.q */
#define fp_p 17
#define fp_q 14

#if fp_p + fp_q + 1 != fp_size
#error fp_p + fp_q + 1 != fp_size
#endif

/* 令 f = 2**q */
#define fp_f (1 << fp_q)

/**
 * x 和 y 代表 fixed-point ，n 代表整数 
 * 以下关于 fixed-point 类型的运算均参考官方文档
*/

/* Convert n to fixed point */
#define i_to_fp(n) ((n) * fp_f)

/* Convert x to integer (rounding toward zero) */
#define fp_to_i_0(x) ((x) / fp_f)

/* Convert x to integer (rounding to nearest) */
#define fp_to_i(x) (((x) > 0) ? (fp_to_i_0((x) + fp_f / 2)) : (fp_to_i_0((x)-fp_f / 2)))

/* Add x and y */
#define fp_add_fp(x, y) ((x) + (y))

/* Subtract y from x */
#define fp_sub_fp(x, y) ((x) - (y))

/* Add x and n */
#define fp_add_i(x, n) (fp_add_fp((x), i_to_fp(n)))

/* Subtract n from x */
#define fp_sub_i(x, n) (fp_sub_fp((x), i_to_fp(n)))

/* Multiply x by y */
#define fp_mul_fp(x, y) ((fp_t)(((intmax_t)(x)) * (y) / fp_f))

/* Multiply x by n */
#define fp_mul_i(x, n) ((x) * (n))

/* Divide x by y */
#define fp_div_fp(x, y) ((fp_t)(((intmax_t)(x)) * fp_f / (y)))

/* Divide x by n */
#define fp_div_i(x, n) ((x) / (n))

#endif /* threads/fixed_point.h */
