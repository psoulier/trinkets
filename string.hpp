#include <assert.h>
#include <stdio.h>

class String {

    template<size_t U> friend class StringN;

    const char* s;

    static bool compare_cstr(const char* a, const char* b)
    {
        if (a == b) {
            return true;
        }
        else if (a == nullptr || b == nullptr) {
            return false;
        }

        while (*a != '\0' && *a == *b) {
            a++;
            b++;
        }

        return *a == *b;
    }


    public:

        static constexpr size_t npos = static_cast<size_t>(-1);

        constexpr String() : s(nullptr)
        {
        }

        constexpr String(const char* s) : s(s)
        {
        }

        constexpr String(const String& s) : s(s.s)
        {
        }

        String& operator = (const String& a)
        {
            this->s = a.s;

            return *this;
        }

        friend bool operator == (const String& a, const char* cstr)
        {
            return compare_cstr(a.s, cstr);
        }

        friend bool operator == (const char* cstr, const String& a)
        {
            return compare_cstr(cstr, a.s);
        }

        friend bool operator == (const String& a, const String& b)
        {
            return compare_cstr(a.s, b.s);
        }

        friend bool operator != (const String& a, const char* cstr)
        {
            return !compare_cstr(a.s, cstr);
        }

        friend bool operator != (const char* cstr, const String& a)
        {
            return !compare_cstr(cstr, a.s);
        }

        friend bool operator != (const String& a, const String& b)
        {
            return !compare_cstr(a.s, b.s);
        }

        const char* c_str() const
        {
            return s;
        }

        size_t length() const
        {
            if (s == nullptr) {
                return 0;
            }

            auto c = s;
            size_t len = 0;
            while (*c != '\0') {
                c++;
                len++;
            }

            return len;
        }

        size_t find(const String& s)
        {
            size_t pos = 0;

            while (s[pos] != '\0') {
                size_t j = 0;
                while (s.s[j] != '\0' && s.s[j] == s[pos + j]) {
                    j++;
                }

                if (s.s[j] == '\0') {
                    return pos;
                }

                pos++;
            }

            return npos;
        }
};

template <size_t N>
class StringN : public String {
    char        arr[N];

    public:

        StringN() :
            String(arr)
        {
            arr[0] = '\0';
        }

        StringN(const char* cstr) :
            String(arr)
        {
            size_t  i = 0;

            while (cstr[i] != '\0') {
                arr[i] = cstr[i];
                i++;

                assert(i < N);
            }

            arr[i] = '\0';
        }

        StringN(const StringN& a) :
            StringN(a.arr)
        {
        }

        template <size_t L>
        StringN& operator = (const StringN<L>& str)
        {
            return operator = (str.s);
        }

        StringN& operator = (const char* cstr)
        {
            size_t  i = 0;

            while (cstr[i] != '\0') {
                arr[i] = cstr[i];
                i++;

                assert(i < N);
            }

            arr[i] = '\0';

            return *this;
        }

        void append(const char* cstr)
        {
            auto len = length();
            size_t i = 0;

            while (cstr[i] != '\0') {
                assert(len < N);

                arr[len + i] = cstr[i];
                i++;
            }

            arr[len + i] = '\0';
        }

        template <size_t L>
        void append(const StringN<L>& str)
        {
            append(str.s);
        }

        template <size_t L>
        StringN& operator += (const StringN<L>& str)
        {
            append(str.s);
            return *this;
        }

        template <size_t L>
        StringN& operator += (const char* cstr)
        {
            append(cstr);
            return *this;
        }

        friend StringN operator + (const StringN& a, const StringN& b)
        {
            StringN s = a;

            s += b;

            return s;
        }
};




