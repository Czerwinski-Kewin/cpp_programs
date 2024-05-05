#pragma once
class RC
{
private:
    int count;

public:
    void AddRef()
    {
        count++;
    }

    int Release()
    {
        return --count;
    }
};

template <typename T> class SmartPtr
{
private:
    T* pData;
    RC* reference;

public:
    SmartPtr() : pData(0), reference(0)
    {
        reference = new RC();
        reference->AddRef();
    }

    SmartPtr(T* pValue) : pData(pValue), reference(0)
    {
        reference = new RC();
        reference->AddRef();
    }

    SmartPtr(const SmartPtr<T>& sp) : pData(sp.pData), reference(sp.reference)
    {
        reference->AddRef();
    }

    ~SmartPtr()
    {
        if (reference->Release() == 0)
        {
            delete pData;
            delete reference;
        }
    }

    T& operator* ()
    {
        return *pData;
    }

    T* operator-> ()
    {
        return pData;
    }

    SmartPtr<T>& operator = (const SmartPtr<T>& sp)
    {
        if (this != &sp)
        {
            if (reference->Release() == 0)
            {
                delete pData;
                delete reference;
            }
            pData = sp.pData;
            reference = sp.reference;
            reference->AddRef();
        }
        return *this;
    }
};
