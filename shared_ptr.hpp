#ifndef SHARED_PTR_HPP
#define SHARED_PTR_HPP

namespace ft
{
  template <typename T>
  class shared_ptr
  {
    private:
    T *data;
    bool allocated;
    public:
    typedef T* pointer;
    typedef T  type;

    shared_ptr() : data(NULL), allocated(false)
    {}
    explicit shared_ptr(const pointer p)
    {
		data = new T (*p);
		allocated = true;
	}
    shared_ptr(shared_ptr& o)
    {
      data = o.data;
      allocated = o.allocated;
    }
    operator bool() const
      {
        return (data != NULL);
      }
    explicit shared_ptr(T& v)
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
    ~shared_ptr()
      {
        if (allocated && data)
		{
          delete data;
		  data = NULL;
		}
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
    shared_ptr& operator=(shared_ptr& o)
      {
        data = o.data;
        allocated = o.allocated;
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
  bool operator==(const ft::shared_ptr<T>& f, const ft::shared_ptr<T>& l)
    {
      return (f.get() == l.get());
    }
  template <typename T>
  bool operator>(const ft::shared_ptr<T>& f, const ft::shared_ptr<T>& l)
    {
      return (f.get() > l.get());
    }
  template <typename T>
  bool operator<(const ft::shared_ptr<T>& f, const ft::shared_ptr<T>& l)
    {
      return (f.get() < l.get());
    }
  template <typename T>
  bool operator<=(const ft::shared_ptr<T>& f, const ft::shared_ptr<T>& l)
    {
      return (f.get() <= l.get());
    }
  template <typename T>
  bool operator>=(const ft::shared_ptr<T>& f, const ft::shared_ptr<T>& l)
    {
      return (f.get() >= l.get());
    }
}
#endif
