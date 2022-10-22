#include <string>
#include <vector>

// exceptions
namespace csv
{
    typedef std::string Exception;
    const Exception TypeMismatchException = "csv::TypeMismatchException";
}

// value class
namespace csv
{
    class value
    {
    public:
        value() = delete;
        value(const csv::value &v)
        {
            m_val = v.m_val;
        }
        value(const std::string &s)
        {
            m_val = s;
        }
        std::string toString()
        {
            return m_val;
        }
        /**
         * @return bool
         * @throws csv::TypeMismatchException if data in CSV file can't be converted to bool
         */
        bool toBool()
        {
            if (m_val == "true" || (int) std::stoi(m_val) == 1)
                return true;
            else if (m_val == "false" || (int) std::stoi(m_val) == 0)
                return false;
            else throw csv::TypeMismatchException;
        }
        char toChar()
        {
            return (char) m_val[0];
        }
        short toShort()
        {
            return (short) std::stoi(m_val);
        }
        int toInt()
        {
            return (int) std::stoi(m_val);
        }
        long long toLong()
        {
            return (long long) std::stoll(m_val, nullptr, 10);
        }
        float toFloat()
        {
            return (float) std::stof(m_val);
        }
        double toDouble()
        {
            return (double) std::stof(m_val);
        }
    private:
        std::string m_val;
    };
}

// row class
namespace csv
{
    class row
    {
    public:
        row() = delete;
        row(const csv::row &r)
        {
            m_colnames = m_colnames;
            m_row = r.m_row;
        }
        row(const std::vector<std::string> &cols)
        {
            
        }
        ~row()
        {
            m_colnames.clear();
            m_row.clear();
        }
    private:
        std::vector<std::string> m_colnames;
        std::vector<csv::value> m_row;
    }
}
