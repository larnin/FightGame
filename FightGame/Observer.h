#pragma once

#include <functional>
#include <algorithm>
#include <vector>

template <typename T>
class Subject;

template <typename T>
class Observer
{
	template <typename U> friend class Subject;

public:
    Observer(Subject<T> & subject);
    Observer(const Observer<T> & observer);
    Observer & operator=(const Observer<T> & observer);

    virtual ~Observer();

	virtual void notify() = 0;

	void setCallBack(std::function<void(T&)> callBack)
	{
		m_callBack = callBack;
	}

protected:
	Subject<T> * m_subject;
	std::function<void(T&)> m_callBack;
};

//------------------------------------
#include <iostream>
template <typename T>
class Subject
{
    template <typename U> friend class Observer;

public:
    Subject() = default;
    Subject(const Subject &) = delete;
    Subject & operator=(const Subject &) = delete;
    Subject(Subject && s)
        : m_observers(std::move(s.m_observers))
    {
        for (auto * o : m_observers)
            o->m_subject = this;
    }
    Subject & operator=(Subject && s)
    {
        m_observers = std::move(s.m_observers);
        for (auto * o : m_observers)
            o->m_subject = this;
    }
	virtual ~Subject()
	{
		for (auto * o : m_observers)
			o->m_subject = nullptr;
	}

	T* operator->()
	{
		return static_cast<T*>(this);
	}

	T& operator*()
	{
		return *static_cast<T*>(this);
	}

protected:
    void notifyObservers()
    {
		for (unsigned int i(0); i < m_observers.size(); i++)
			m_observers[i]->notify();
    }

private:
    void registerObserver(Observer<T> & observer)
    {
        if (std::find(m_observers.begin(), m_observers.end(), &observer) != m_observers.end())
            return;
        m_observers.push_back(&observer);
    }

    void removeObserver(Observer<T> & observer)
    {
        m_observers.erase(std::find(m_observers.begin(), m_observers.end(), &observer));
    }

    std::vector<Observer<T>*> m_observers;
};

//---------------------------------------

template <typename T>
Observer<T>::Observer(Subject<T> & subject)
    : m_subject(&subject)
{
    m_subject->registerObserver(*this);
}

template <typename T>
Observer<T>::Observer(const Observer<T> & observer)
    : m_subject(observer.m_subject)
    , m_callBack(observer.m_callBack)
{
	if(m_subject != nullptr)
		m_subject->registerObserver(*this);
}

template <typename T>
Observer<T> & Observer<T>::operator=(const Observer<T> & observer)
{
	if (m_subject != nullptr)
		m_subject->removeObserver(*this);
    m_subject(observer.m_subject);
    m_callBack(observer.m_callBack);
	if (m_subject != nullptr)
		m_subject->registerObserver(*this);
}

template <typename T>
Observer<T>::~Observer()
{
	if(m_subject != nullptr)
		m_subject->removeObserver(*this);
}
