#ifndef CANVAS_EPOLL_EVENT_HPP_INCLUDED
#define CANVAS_EPOLL_EVENT_HPP_INCLUDED

#include <sys/epoll.h>
namespace canvas
{
    namespace epoll
    {
        class event
        {
        public:
            event();
            event(void const* data);
            event(uint32_t data);
            event(uint64_t data);
            event(void const* data_ptr, uint32_t data_32, uint64_t data_64);

            void context(void const* data);
            void context_uint32(uint32_t data);
            void context_uint64(uint64_t data);

            void on_readable();
            void on_writeable();
            void on_closed();
            void on_error();
            void on_hangup();

            void report_once();

            void edge_triggered(bool set);
            void level_triggered(bool set);
        private:
            epoll_event m_event;
        };
    } // ~epoll
} // ~canvas

#endif  // ~CANVAS_EPOLL_EVENT_HPP_INCLUDED
