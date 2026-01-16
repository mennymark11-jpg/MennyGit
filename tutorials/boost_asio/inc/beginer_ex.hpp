#ifndef __BEGINER_EX_HPP__
#define __BEGINER_EX_HPP__

#include <string> // for std::string
#include <chrono> // for std::chrono::seconds

#include <boost/asio.hpp> // for boost::asio::io_context and boost::asio::steady_timer

class BeginerIOContext
{
public:
    ~BeginerIOContext() = default;
    static BeginerIOContext* GetInstance();
    void AddSteadyTimer(std::chrono::seconds seconds);
    void PostLambdaTask(const std::string& message);
    void Run();
    
    
private:    
    BeginerIOContext() = default;

    boost::asio::io_context m_io_context;
}; // class BeginerIOContext

#endif // __BEGINER_EX_HPP__