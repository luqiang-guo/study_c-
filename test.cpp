#include <iostream>

// kBFloat16, kHalf, iter.dtype(), "add_cpu/sub_cpu",
#define AT_DISPATCH_ALL_TYPES_AND_COMPLEX_AND2(                             \
    SCALARTYPE1, SCALARTYPE2, TYPE, NAME, ...)                              \
  [&] {                                                                     \
    const auto& the_type = TYPE;                                            \
    /* don't use TYPE again in case it is an expensive or side-effect op*/  \
    at::ScalarType _st = ::detail::scalar_type(the_type);                   \
    RECORD_KERNEL_FUNCTION_DTYPE("add_cpu/sub_cpu", _st);                                \
    switch (_st) {                                                          \
      AT_PRIVATE_CASE_TYPE("add_cpu/sub_cpu", at::ScalarType::Byte, uint8_t, __VA_ARGS__)      \
      AT_PRIVATE_CASE_TYPE("add_cpu/sub_cpu", at::ScalarType::Char, int8_t, __VA_ARGS__)       \
      AT_PRIVATE_CASE_TYPE("add_cpu/sub_cpu", at::ScalarType::Double, double, __VA_ARGS__)     \
      AT_PRIVATE_CASE_TYPE("add_cpu/sub_cpu", at::ScalarType::Float, float, __VA_ARGS__)       \
      AT_PRIVATE_CASE_TYPE("add_cpu/sub_cpu", at::ScalarType::Int, int32_t, __VA_ARGS__)       \
      AT_PRIVATE_CASE_TYPE("add_cpu/sub_cpu", at::ScalarType::Long, int64_t, __VA_ARGS__)      \
      AT_PRIVATE_CASE_TYPE("add_cpu/sub_cpu", at::ScalarType::Short, int16_t, __VA_ARGS__)     \
      AT_PRIVATE_CASE_TYPE(                                                       \
          "add_cpu/sub_cpu", at::ScalarType::ComplexFloat, c10::complex<float>, __VA_ARGS__)   \
      AT_PRIVATE_CASE_TYPE(                                                       \
          "add_cpu/sub_cpu", at::ScalarType::ComplexDouble, c10::complex<double>, __VA_ARGS__) \
      AT_PRIVATE_CASE_TYPE(                                                 \
          "add_cpu/sub_cpu",                                                             \
          kBFloat16,                                                      \
          decltype(c10::impl::ScalarTypeToCPPType<kBFloat16>::t),         \
          __VA_ARGS__)                                                      \
      AT_PRIVATE_CASE_TYPE(                                                 \
          "add_cpu/sub_cpu",                                                             \
          kHalf,                                                      \
          decltype(c10::impl::ScalarTypeToCPPType<kHalf>::t),         \
          __VA_ARGS__)                                                      \
      default:                                                              \
        AT_ERROR(#NAME, " not implemented for '", toString(_st), "'");      \
    }                                                                       \
  }()




    AT_DISPATCH_ALL_TYPES_AND_COMPLEX_AND2(kBFloat16, kHalf, iter.dtype(), "add_cpu/sub_cpu", [&]() {
      auto alpha = alpha_scalar.to<scalar_t>();
      auto alpha_vec = Vectorized<scalar_t>(alpha);
      cpu_kernel_vec(iter,
        [=](scalar_t a, scalar_t b) __ubsan_ignore_undefined__ -> scalar_t { return a + alpha * b; },
        [=](Vectorized<scalar_t> a, Vectorized<scalar_t> b) __ubsan_ignore_undefined__ {
          return vec::fmadd(b, alpha_vec, a);
        });
      });

    