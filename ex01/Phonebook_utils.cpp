#include <Phonebook.hpp>

static size_t utf8_char_bytes(unsigned char c)
{
    if ((c & 0x80) == 0x00) return 1;         
    if ((c & 0xE0) == 0xC0) return 2;         
    if ((c & 0xF0) == 0xE0) return 3;         
    if ((c & 0xF8) == 0xF0) return 4;         
    return 1;
}

static size_t utf8_width(const std::string &s)
{
    size_t w = 0;
    for (size_t i = 0; i < s.size();)
    {
        size_t n = utf8_char_bytes((unsigned char)s[i]);
        if (i + n > s.size()) n = 1;
        i += n;
        ++w;
    }
    return w;
}

static std::string utf8_truncate_cols(const std::string &s, size_t max_cols)
{
    std::string out;
    size_t cols = 0;

    for (size_t i = 0; i < s.size() && cols < max_cols;)
    {
        size_t n = utf8_char_bytes((unsigned char)s[i]);
        if (i + n > s.size()) n = 1;
        out.append(s, i, n);
        i += n;
        ++cols;
    }
    return out;
}

std::string col10(const std::string &s)
{
    const size_t COLS = 10;
    size_t w = utf8_width(s);

    if (w > COLS)
    {
        std::string t = utf8_truncate_cols(s, COLS - 1);
        t += ".";
        return t;
    }
    return std::string(COLS - w, ' ') + s;
}
