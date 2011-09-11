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
            event(int fd);
            event(int fd, void const* data);
            event(int fd, uint32_t data);
            event(int fd, uint64_t data);
            event(int fd, void const* data_ptr, uint32_t data_u32, uint64_t data_u64);

            void context(void const* data);
            void context(uint32_t data);
            void context(uint64_t data);

            void on_readable();
            void on_writeable();
            void on_closed();
            void on_priority_read();
            void on_error();
            void on_hangup();

            void report_once();

            void edge_triggered();
            void level_triggered();

        private:
            epoll_event m_event;
        };

        #include <canvas/epoll/event.tcc>

    } // ~epoll
} // ~canvas

#endif  // ~CANVAS_EPOLL_EVENT_HPP_INCLUDED
