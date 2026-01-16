#include <iostream> // for std::cout
#include <memory> // for std::shared_ptr

#include "beginer_ex.hpp" // for BeginerIOContext class definition

BeginerIOContext* BeginerIOContext::GetInstance()
{
    static BeginerIOContext instance;
    return &instance;
}

void BeginerIOContext::AddSteadyTimer(std::chrono::seconds seconds)
{
    auto timer = std::make_shared<boost::asio::steady_timer>(m_io_context, seconds);
    timer->async_wait([timer](const boost::system::error_code& ec)
    {
        if (!ec)
        {
            std::cout << "Steady timer expired after " << timer->expiry().time_since_epoch().count() << " ticks." << std::endl;
        }
    });
}

void BeginerIOContext::PostLambdaTask(const std::string& message)
{
    boost::asio::post(m_io_context, [message]()
    {
        std::cout << "Lambda task executed with message: " << message << std::endl;
    });
}

void BeginerIOContext::Run()
{
    m_io_context.run();
}
