#include <string>

enum class ErrorAction
{
    ingore,
    throwing,
    terminating,
    logging
};

constexpr ErrorAction defautl_error_action = ErrorAction::throwing;

enum class ErrorCode
{
    range_error,
    length_error,
};

std::string error_code_name[]{
    "range_error",
    "length_error",
};
/*
    通用的异常处理函数
    
    action为错误处理方式，
    C为匿名函数，返回值为bool类型
*/
template <ErrorAction action = defautl_error_action, class C>
constexpr void except(ErrorCode c, C cond)
{
    if constexpr (action == ErrorAction::logging)
    {
        if (!cond())
        {
            std::cerr << "Error: " << error_code_name[static_cast<int>(x)] << '\n';
        }
    }
    if constexpr (action == ErrorAction::throwing)
    {
        if (!cond())
        {
            throw x;
        }
    }
    if constexpr (action == ErrorAction::terminating)
    {
        if (!cond())
        {
            std::terminate();
        }
    }
}