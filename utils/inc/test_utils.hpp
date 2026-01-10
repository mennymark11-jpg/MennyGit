#ifndef __MENNY_TEST_UTILS_HPP__
#define __MENNY_TEST_UTILS_HPP__

#include <string> // for std::string

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define BLUE_TEXT "\033[34m"
#define RESET_TEXT "\033[0m"

#define PRINT_TEST_RESULT(test_number, test_name, expected, actual) \
    menny::test_utils::PrintTestResult(test_number, test_name, expected, actual, __LINE__, __FILE__, std::cout)

namespace menny
{
namespace test_utils
{

template<typename T>
void PrintTestResult(std::size_t test_number, const std::string& test_name, const T& expected, const T& actual, int line_number, const std::string& file_name, std::ostream& out = std::cout)
{
    if (expected == actual)
    {
        out << GREEN_TEXT << "[PASSED]" << BLUE_TEXT << " " << "Test " << test_number << ": " << test_name << RESET_TEXT << std::endl;
    }
    else    
    {
        out << RED_TEXT << "[FAILED]" << BLUE_TEXT << " " << "Test " << test_number << ": " << test_name << RESET_TEXT << " (Line " << line_number << " in " << file_name << ")\n";
        out << "  Expected: " << expected << "\n";
        out << "  Actual  : " << actual << std::endl;
    }
}

} // namespace test_utils
} // namespace menny             

# endif // __MENNY_TEST_UTILS_HPP__