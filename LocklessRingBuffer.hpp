
template <typename T>
class LocklessRingBuffer
{
private:
    T* buf;
    voilate int read_ptr;
    voilate int write_ptr;
    int size;
    int capacity;

    int _IsEmpty()
    {
        return read_ptr == write_ptr;
    }

    int _IsFull()
    {
        return (write_ptr+1)%capacity == read_ptr;
    }

public:
    LocklessRingBuffer(int cap):
        capacity(cap+1),
        read_ptr(0),
        write_ptr(0),
        size(0)
    {
        buf = new T[capacity];
    }

    ~LocklessRingBuffer()
    {
        delete[] buf;
    }

    int Read(int len, T* data)
    {

    }

    int Write(int len, T* data)
    {

    }

    void Resize(int cap)
    {
        
    }

    int GetFree()
    {
        if(_IsEmpty())
            return capacity;
        else if(_IsFull())
            return 0;
        else
        {
            if(write_ptr > read_ptr)
            {
                return (capacity - write_ptr) + read_ptr;
            }
            else
            {
                return read_ptr - write_ptr;
            }
        }
    }

    int GetSize()
    {
        return capacity - GetFree();
    }
};
