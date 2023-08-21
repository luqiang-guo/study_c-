#include <cstdint>
#include <iostream>
#include <limits>

const double EXP_LIMIT = 708;
const double PX1exp = 1.26177193074810590878E-4;
const double PX2exp = 3.02994407707441961300E-2;
const double PX3exp = 9.99999999999999999910E-1;
const double QX1exp = 3.00198505138664455042E-6;
const double QX2exp = 2.52448340349684104192E-3;
const double QX3exp = 2.27265548208155028766E-1;
const double QX4exp = 2.00000000000000000009E0;
const double LOG2E = 1.4426950408889634073599; // 1/log(2)


union ieee754{
   ieee754 () {};
   ieee754 (double thed) {d=thed;};
   ieee754 (uint64_t thell) {ll=thell;};
   ieee754 (float thef) {f[0]=thef;};
   ieee754 (uint32_t thei) {i[0]=thei;};
  double d;
  float f[2];
  uint32_t i[2];
  uint64_t ll;
  uint16_t s[4];
};

inline uint32_t sp2uint32(float x) {
  ieee754 tmp;
  tmp.f[0]=x;
  return tmp.i[0];
}

inline float uint322sp(int x) {
  ieee754 tmp;
  tmp.i[0]=x;
  return tmp.f[0];
}

inline double uint642dp(uint64_t ll) {
  ieee754 tmp;
  tmp.ll=ll;
  return tmp.d;
}

inline double fpfloor(const double x){
  int32_t ret = int32_t (x);
  ret-=(sp2uint32(x)>>31);
  return ret;

}


inline float fpfloor(const float x){
  int32_t ret = int32_t (x);
  ret-=(sp2uint32(x)>>31);
  return ret;

}


/// Exponential Function double precision
inline double fast_exp(double initial_x){

    double x = initial_x;
    double px=fpfloor(LOG2E * x +0.5);

    const int32_t n = int32_t(px);

    x -= px * 6.93145751953125E-1;
    x -= px * 1.42860682030941723212E-6;

    const double xx = x * x;

    // px = x * P(x**2).
    px = PX1exp;
    px *= xx;
    px += PX2exp;
    px *= xx;
    px += PX3exp;
    px *= x;

    // Evaluate Q(x**2).
    double qx = QX1exp;
    qx *= xx;
    qx += QX2exp;
    qx *= xx;
    qx += QX3exp;
    qx *= xx;
    qx += QX4exp;

    // e**x = 1 + 2x P(x**2)/( Q(x**2) - P(x**2) )
    x = px / (qx - px);
    x = 1.0 + 2.0 * x;

    // Build 2^n in double.
    x *= uint642dp(( ((uint64_t)n) +1023)<<52);

    if (initial_x > EXP_LIMIT)
            x = std::numeric_limits<double>::infinity();
    if (initial_x < EXP_LIMIT)
            x = 0.;

    return x;

}

const float MAXLOGF = 88.72283905206835f;
const float MINLOGF = -88.f;
const float C1F =   0.693359375f;
const float C2F =  -2.12194440e-4f;
const float PX1expf = 1.9875691500E-4f;
const float PX2expf =1.3981999507E-3f;
const float PX3expf =8.3334519073E-3f;
const float PX4expf =4.1665795894E-2f;
const float PX5expf =1.6666665459E-1f;
const float PX6expf =5.0000001201E-1f;
const float LOG2EF = 1.44269504088896341f;

/// Exponential Function single precision
inline float fast_expf(float initial_x) {

    float x = initial_x;

    float z = fpfloor(LOG2EF * x +0.5f ); /* floor() truncates toward -infinity. */

    x -= z * C1F;
    x -= z * C2F;
    const int32_t n = int32_t ( z );

    const float x2 = x * x;

    // c0*f+c1
    z = x*PX1expf;
    z += PX2expf;

    // (c0*f+c1)*f+c2
    z *= x;
    z += PX3expf;

    // ((c0*f+c1)*f+c2)*f+c3
    z *= x;
    z += PX4expf;
    // (((c0*f+c1)*f+c2)*f+c3)*f+c4
    z *= x;
    z += PX5expf;

    z *= x;
    z += PX6expf;
    
    z *= x2;
    z += x + 1.0f;

    /* multiply by power of 2 */
    z *=  uint322sp((n+0x7f)<<23);

    if (initial_x > MAXLOGF) z=std::numeric_limits<float>::infinity();
    if (initial_x < MINLOGF) z=0.f;

    return z;

  }


// constexpr float EXP_HI = 88.3762626647949f;
// constexpr float EXP_LO = -88.3762626647949f;

// constexpr float LOG2EF = 1.44269504088896341;
// constexpr float EXP_C1 = 0.693359375;
// constexpr float EXP_C2 = -2.12194440e-4;

// constexpr float EXP_P0 = 1.9875691500E-4;
// constexpr float EXP_P1 = 1.3981999507E-3;
// constexpr float EXP_P2 = 8.3334519073E-3;
// constexpr float EXP_P3 = 4.1665795894E-2;
// constexpr float EXP_P4 = 1.6666665459E-1;
// constexpr float EXP_P5 = 5.0000001201E-1;


// float expNeonPs(float x) {
//   float one = 1.0f;
//   if(x > EXP_HI) {x = EXP_HI;}
//   if(x < EXP_LO) {x = EXP_LO;}

//   /* express exp(x) as exp(g + n*log(2)) */
//   float fx = LOG2EF * x +0.5f;

//   /* perform a floorf */
//   float tmp = float(int32_t(fx));

//   /* if greater, substract 1 */
//   mask = vcgtq_f32(_tmp, _fx);
//   mask = vandq_u32(mask, vreinterpretq_u32_f32(_one));

//   _fx = vsubq_f32(_tmp, vreinterpretq_f32_u32(mask));

//   _tmp = vmulq_f32(_fx, vdupq_n_f32(EXP_C1));
//   float _z = vmulq_f32(_fx, vdupq_n_f32(EXP_C2));
//   _x_0 = vsubq_f32(_x_0, _tmp);
//   _x_0 = vsubq_f32(_x_0, _z);

//   _z = vmulq_f32(_x_0, _x_0);

//   float _y = vdupq_n_f32(EXP_P0);
//   _y = vfmaq_f32(vdupq_n_f32(EXP_P1), _y, _x_0);
//   _y = vfmaq_f32(vdupq_n_f32(EXP_P2), _y, _x_0);
//   _y = vfmaq_f32(vdupq_n_f32(EXP_P3), _y, _x_0);
//   _y = vfmaq_f32(vdupq_n_f32(EXP_P4), _y, _x_0);
//   _y = vfmaq_f32(vdupq_n_f32(EXP_P5), _y, _x_0);

//   _y = vfmaq_f32(_x_0, _y, _z);
//   _y = vaddq_f32(_y, _one);

//   /* build 2^n */
//   int32x4_t _mm;
//   _mm = vcvtq_s32_f32(_fx);
//   _mm = vaddq_s32(_mm, vdupq_n_s32(0x7f));
//   _mm = vshlq_n_s32(_mm, 23);
//   float pow2n = vreinterpretq_f32_s32(_mm);

//   _y = vmulq_f32(_y, pow2n);
//   return _y;
// }