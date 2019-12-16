
template <typename T>
class LocklessRingBuffer
{
private:
    T* buf;
    voilate int read_ptr;
    voilate int write_ptr;
    int size;
    int capacity;


    void resize(int cap)
    {
        
    }

public:
    LocklessRingBuffer(int cap):
        capacity(cap),
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

    int read(int len, T* data)
    {

    }

    int write(int len, T* data)
    {

    }

};
