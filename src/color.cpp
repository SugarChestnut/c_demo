/*
    void e()
    {
        // using enum Color;
        // auto a = red;
        auto c = Color::green;
        std::cout << int(c) << std::endl;
        std::cout << static_cast<int>(c) << std::endl;
        // 创建一个Color类型的对象d，值为10
        Color d{10};
        std::cout << int(d) << std::endl;
        // 输出
        std::cout << (++c == Color::red) << std::endl;
    }
*/
enum class Color : short
{
    red,
    blue,
    green
};

Color &operator++(Color &c)
{
    switch (c)
    {
    case Color::red:
        return c = Color::blue;
    case Color::blue:
        return c = Color::green;
    case Color::green:
        return c = Color::red;
    }
}