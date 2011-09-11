// TODO: Use delegating constructors once they are
// ready in C++0x

inline event::event(int fd) :
    m_event.data.ptr(0),
    m_event.data.fd(fd),
    m_event.data.u32(0),
    m_event.data.u64(0),
    m_event.events(0)
{
}

inline event::event(int fd, void const* data) :
    m_event.data.ptr(data),
    m_event.data.fd(fd),
    m_event.data.u32(0),
    m_event.data.u64(0),
    m_event.events(0)
{
}

inline event::event(int fd, uint32_t data) :
    m_event.data.ptr(0),
    m_event.data.fd(fd),
    m_event.data.u32(data),
    m_event.data.u64(0),
    m_event.events(0)
{
}

inline event::event(int fd, uint64_t data) :
    m_event.data.ptr(0),
    m_event.data.fd(fd),
    m_event.data.u32(0),
    m_event.data.u64(data),
    m_event.events(0)
{
}

inline event::event(int fd, void const* data_ptr, uint32_t data_u32, uint64_t data_u64) :
    m_event.data.ptr(data_ptr),
    m_event.data.fd(fd),
    m_event.data.u32(data_u32),
    m_event.data.u64(data_u64),
    m_event.events(0)
{
}

inline void event::context(void const* data)
{
    m_event.data.ptr = data;
}

inline void event::context(uint32_t data)
{
    m_event.data.u32 = data;
}

inline void event::context(uint64_t data)
{
    m_event.data.u64 = data;
}

inline void event::on_readable()
{
    m_event.events |= EPOLLIN;
}

inline void event::on_writeable()
{
    m_event.events |= EPOLLOUT;
}

inline void event::on_closed()
{
    m_event.events |= EPOLLRDHUP;
}

inline void event::on_priority_read()
{
    // TODO: Check how this works
    m_event.events |= EPOLLPRI;
}

inline void event::on_error()
{
    m_event.events |= EPOLLERR;
}

inline void event::on_hangup()
{
    m_event.events |= EPOLLHUP;
}

inline void event::report_once()
{
    m_event.events |= EPOLLONESHOT;
}

inline void event::edge_triggered()
{
    m_events.events |= EPOLLET;
}

inline void event::level_triggered()
{
    m_events.events &= ~EPOLLET;
}

inline bool event::attached()
{
    return m_event.data.fd != -1;
}
