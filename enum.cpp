#include <iostream>

enum Test
{
    dnnl_format_tag_undef = 0,
    /// Undefined memory format tag.
    /// The primitive selects a format automatically.
    dnnl_format_tag_any,
    // Plain formats
    dnnl_a, ///< plain 1D tensor
    dnnl_ab, ///< plain 2D tensor
    dnnl_abc, ///< plain 3D tensor
    dnnl_abcd, ///< plain 4D tensor
    dnnl_acbd, ///< plain 4D tensor
    dnnl_abcde, ///< plain 5D tensor
    dnnl_abcdef, ///< plain 6D tensor
    dnnl_abcdefg, ///< plain 7D tensor
    dnnl_abcdefgh, ///< plain 8D tensor
    dnnl_abcdefghi, ///< plain 9D tensor
    dnnl_abcdefghij, ///< plain 10D tensor
    dnnl_abcdefghijk, ///< plain 11D tensor
    dnnl_abcdefghijkl, ///< plain 12D tensor
};

enum class format_tag {
    a = dnnl_a,
    ab = dnnl_ab,
    abc = dnnl_abc,
    abcd = dnnl_abcd,
    abcde = dnnl_abcde,
    abcdef = dnnl_abcdef,
};

void test_func(Test type)
{
    std::cout << type << std::endl;
}

void test_class_enum(format_tag type)
{
    std::cout << static_cast<int>(type) << std::endl;
}
int main()
{
    int dim = 3;   // dnnl_abc

    // Test type = dnnl_format_tag_undef + dim;

    test_func(static_cast<Test>(dim+1));  // test_func(dnnl_abc)
    test_class_enum(static_cast<format_tag>(dim+1));  // test_func(dnnl_abc)
    return 0;
}