#ifndef CANVAS_EPOLL_MANAGER_HPP_INCLUDED
#define CANVAS_EPOLL_MANAGER_HPP_INCLUDED

namespace canvas
{
    namespace epoll
    {
        class manager
        {
        public:
            manager();
            ~manager();

        private:
            int m_fd;
        };
    } // ~epoll
} // ~canvas

#endif // ~CANVAS_EPOLL_MANAGER_HPP_INCLUDED
