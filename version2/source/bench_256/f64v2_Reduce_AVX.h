/* f64v2_Reduce_AVX.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 06/05/2017
 * Last Modified    : 06/05/2017
 * 
 */

#ifndef _flops_f64v2_Reduce_AVX_H
#define _flops_f64v2_Reduce_AVX_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <immintrin.h>
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
inline double reduce(__m256d y){
    __m128d x = _mm_add_pd(_mm256_castpd256_pd128(y), _mm256_extractf128_pd(y, 1));
    x = _mm_add_pd(x, _mm_unpackhi_pd(x, x));
    return _mm_cvtsd_f64(x);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
