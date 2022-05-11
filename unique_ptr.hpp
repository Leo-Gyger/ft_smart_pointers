#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP

namespace ft
{
  template <typename T>
  class unique_ptr
  {
    private:
    T *data;
    bool allocated;
    public:
    typedef T* pointer;
    typedef T  type;

    unique_ptr() : data(NULL), allocated(false)
    {}
    explicit unique_ptr(const pointer p)
    {
		data = new T (*p);
		allocated = true;
	}
    unique_ptr(unique_ptr& o)
    {
      data = o.data;
      allocated = o.allocated;
      o.data = NULL;
      o.allocated = false;
    }
    explicit operator bool() const
      {
        return (data != NULL);
      }
    explicit unique_ptr(T& v)
      {
        data = &v;
        allocated = false;
      }
    const pointer& get() const
      {
        return (data);
      }
    pointer& get()
      {
        return (data);
      }
    ~unique_ptr()
      {
        if (allocated)
          delete data;
      }
    void remove()
      {
        if (allocated)
          {
            delete data;
            allocated = false;
            return;
          }
          throw std::out_of_range("the pointer is empty");
      }
    unique_ptr& operator=(unique_ptr& o)
      {
        data = o.data;
        allocated = o.allocated;
        o.data = NULL;
        o.allocated = false;
        return *this;
      }
    T& operator*()
      {
        if  (data)
          return (*data);
        else
          throw std::out_of_range("the pointer is empty");
      }
    pointer release()
      {
        pointer ret = data;
        data = NULL;
        return (ret);
      }
    const T& operator*() const
      {
        if  (data)
          return (*data);
        else
          throw std::out_of_range("the pointer is empty");
      }
    pointer operator->() const
      {
        if (data)
          return (data);
        else
          return (data);
      }
   };
  template <typename T>
  bool operator==(const ft::unique_ptr<T>& f, const ft::unique_ptr<T>& l)
    {
      return (f.get() == l.get());
    }
  template <typename T>
  bool operator>(const ft::unique_ptr<T>& f, const ft::unique_ptr<T>& l)
    {
      return (f.get() > l.get());
    }
  template <typename T>
  bool operator<(const ft::unique_ptr<T>& f, const ft::unique_ptr<T>& l)
    {
      return (f.get() < l.get());
    }
  template <typename T>
  bool operator<=(const ft::unique_ptr<T>& f, const ft::unique_ptr<T>& l)
    {
      return (f.get() <= l.get());
    }
  template <typename T>
  bool operator>=(const ft::unique_ptr<T>& f, const ft::unique_ptr<T>& l)
    {
      return (f.get() >= l.get());
    }
}
#endif
