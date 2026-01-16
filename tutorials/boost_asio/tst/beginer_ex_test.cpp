

#include "beginer_ex.hpp" // for BeginerIOContext class definition
#include "test_utils.hpp" // for menny::test_utils::PrintTestResult

int main()
{
    BeginerIOContext* io_context_ptr = BeginerIOContext::GetInstance();

    io_context_ptr->AddSteadyTimer(std::chrono::seconds(10));
    io_context_ptr->PostLambdaTask("Hello, Boost.Asio!");

    auto start = std::chrono::high_resolution_clock::now();
    io_context_ptr->Run();
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    std::string expected = "10";
    std::string actual = std::to_string(duration);  

    PRINT_TEST_RESULT(1, "Boost.Asio Beginner Example Execution", expected, actual);

    return 0;
}
